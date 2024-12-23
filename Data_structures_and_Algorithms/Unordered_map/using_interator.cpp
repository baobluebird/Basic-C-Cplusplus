#include <iostream>
#include <functional> // For std::hash

// Template class for an unordered map
template <typename Key, typename Value>
class UnorderedMap {
private:
    // Custom structure for storing key-value pairs
    struct KeyValue {
        Key key;
        Value value;

        KeyValue(const Key& k, const Value& v) : key(k), value(v) {}
    };

    // Node of the linked list in each bucket
    struct Node {
        KeyValue data;
        Node* next;

        Node(const Key& k, const Value& v) : data(k, v), next(nullptr) {}
    };

    Node** buckets;   // Array of pointers to linked lists
    size_t num_buckets; // Number of buckets
    size_t num_elements; // Number of elements in the map
    double max_load_factor; // Maximum load factor before rehashing

    // Hash function
    size_t hashFunction(const Key& key) const {
        return std::hash<Key>{}(key) % num_buckets;
    }

    // Function to rehash and resize the number of buckets
    void rehash(size_t new_bucket_count) {
        Node** new_buckets = new Node*[new_bucket_count]();
        for (size_t i = 0; i < new_bucket_count; ++i) {
            new_buckets[i] = nullptr;
        }

        for (size_t i = 0; i < num_buckets; ++i) {
            Node* current = buckets[i];
            while (current) {
                size_t new_index = std::hash<Key>{}(current->data.key) % new_bucket_count;

                // Move the current node to the new bucket
                Node* next_node = current->next;
                current->next = new_buckets[new_index];
                new_buckets[new_index] = current;

                current = next_node;
            }
        }

        delete[] buckets;
        buckets = new_buckets;
        num_buckets = new_bucket_count;
    }

public:
    // Iterator class
    class Iterator {
    private:
        Node** buckets;
        size_t bucket_count;
        size_t current_bucket;
        Node* current_node;

        // Find the next bucket that contains elements
        void advance() {
            while (!current_node && current_bucket < bucket_count) {
                current_node = buckets[current_bucket++];
            }
        }

    public:
        Iterator(Node** b, size_t bucket_cnt, size_t index, Node* node)
            : buckets(b), bucket_count(bucket_cnt), current_bucket(index), current_node(node) {
            advance();
        }

        Iterator& operator++() {
            if (current_node) {
                current_node = current_node->next;
                if (!current_node) {
                    ++current_bucket;
                    advance();
                }
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current_node != other.current_node || current_bucket != other.current_bucket;
        }

        KeyValue& operator*() const {
            return current_node->data;
        }

        KeyValue* operator->() const {
            return &(current_node->data);
        }
    };

    // Constructor
    UnorderedMap(size_t bucket_count = 16, double load_factor = 0.75)
        : num_buckets(bucket_count), num_elements(0), max_load_factor(load_factor) {
        buckets = new Node*[num_buckets]();
        for (size_t i = 0; i < num_buckets; ++i) {
            buckets[i] = nullptr;
        }
    }

    // Destructor
    ~UnorderedMap() {
        clear();
        delete[] buckets;
    }

    // Insert a new element
    void insert(const Key& key, const Value& value) {
        size_t index = hashFunction(key);
        Node* current = buckets[index];

        // Search for the key in the bucket
        while (current) {
            if (current->data.key == key) {
                current->data.value = value; // Update the value if the key already exists
                return;
            }
            current = current->next;
        }

        // Add a new node at the beginning of the bucket
        Node* new_node = new Node(key, value);
        new_node->next = buckets[index];
        buckets[index] = new_node;
        ++num_elements;

        // Check and rehash if needed
        if (static_cast<double>(num_elements) / num_buckets > max_load_factor) {
            rehash(num_buckets * 2);
        }
    }

    // Find a value by key (returns an iterator)
    Iterator find(const Key& key) {
        size_t index = hashFunction(key);
        Node* current = buckets[index];

        while (current) {
            if (current->data.key == key) {
                return Iterator(buckets, num_buckets, index, current);
            }
            current = current->next;
        }

        return end();
    }

    // Begin iterator
    Iterator begin() {
        return Iterator(buckets, num_buckets, 0, nullptr);
    }

    // End iterator
    Iterator end() {
        return Iterator(buckets, num_buckets, num_buckets, nullptr);
    }

    // Clear all elements
    void clear() {
        for (size_t i = 0; i < num_buckets; ++i) {
            Node* current = buckets[i];
            while (current) {
                Node* to_delete = current;
                current = current->next;
                delete to_delete;
            }
            buckets[i] = nullptr;
        }
        num_elements = 0;
    }
};

// Main function for testing
int main() {
    UnorderedMap<std::string, int> map;
    map.insert("Alice", 25);
    map.insert("Bob", 30);
    map.insert("Charlie", 35);

    // Use find
    auto it = map.find("Bob");
    if (it != map.end()) {
        std::cout << "Found: Key: " << it->key << ", Value: " << it->value << "\n";
    } else {
        std::cout << "Key 'Bob' not found\n";
    }

    // Iterate over the entire map
    std::cout << "\nAll elements in the map:\n";
    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << "Key: " << it->key << ", Value: " << it->value << "\n";
    }

    return 0;
}

#include <iostream>
#include <string>

// Custom implementation of a hash function for various data types
struct HashFunction
{
    // Hash function for `int` type
    size_t operator()(int key) const
    {
        return key * 2654435761 % (1ULL << 31); // Uses Knuth's hash formula
    }

    // Hash function for `std::string` type
    size_t operator()(const std::string &key) const
    {
        size_t hash = 0;
        for (char c : key)
        {
            hash = hash * 31 + c; // Modified DJB2 hash formula
        }
        return hash;
    }
};

// Custom implementation of a Hash Table (UnorderedMap)
template <typename Key, typename Value, typename Hash = HashFunction>
class UnorderedMap
{
private:
    //Linked list
    struct Node
    {
        Key key;
        Value value;
        Node *next;

        Node(const Key &k, const Value &v) : key(k), value(v), next(nullptr) {}
    };

    Node **buckets;         // Array of pointers to linked lists
    size_t num_buckets;     // Number of buckets
    size_t num_elements;    // Number of elements in the map
    double max_load_factor; // Maximum load factor
    Hash hasher;            // Custom hash function

    // Hash function
    size_t hashFunction(const Key &key) const
    {
        return hasher(key) % num_buckets;
    }

    // Rehash to resize the number of buckets
    void rehash(size_t new_bucket_count)
    {
        Node **new_buckets = new Node *[new_bucket_count]();
        for (size_t i = 0; i < new_bucket_count; ++i)
        {
            new_buckets[i] = nullptr;
        }

        for (size_t i = 0; i < num_buckets; ++i)
        {
            Node *current = buckets[i];
            while (current)
            {
                size_t new_index = hasher(current->key) % new_bucket_count;

                // Move the current node to the new bucket
                Node *next_node = current->next;
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
    // Constructor
    UnorderedMap(size_t bucket_count = 11, double load_factor = 0.75)
        : num_buckets(bucket_count), num_elements(0), max_load_factor(load_factor)
    {
        buckets = new Node *[num_buckets]();
        for (size_t i = 0; i < num_buckets; ++i)
        {
            buckets[i] = nullptr;
        }
    }

    // Destructor
    ~UnorderedMap()
    {
        clear();
        delete[] buckets;
    }

    // Add a new element
    bool insert(const Key &key, const Value &value)
    {
        size_t index = hashFunction(key);
        std::cout << "Index: " << index << std::endl;

        Node *current = buckets[index];

        // Search for the key in the bucket
        while (current)
        {
            if (current->key == key)
            {
                std::cout << "Key already exists with value: " << current->value << std::endl;
                return false;
            }
            current = current->next;
        }

        // Add a new node at the beginning of the bucket
        Node *new_node = new Node(key, value);
        new_node->next = buckets[index];
        buckets[index] = new_node;
        ++num_elements;

        // Check and rehash if needed
        if (static_cast<double>(num_elements) / num_buckets > max_load_factor)
        {
            rehash(num_buckets * 2);
        }
        return true;
    }

    // Get the size of the map
    size_t size() const
    {
        return num_elements;
    }

    // Find the value by key
    Value *find(const Key &key)
    {
        size_t index = hashFunction(key);
        Node *current = buckets[index];

        while (current)
        {
            if (current->key == key)
            {
                return &current->value;
            }
            current = current->next;
        }

        return nullptr;
    }

    // Check if a key exists in the table
    size_t count(const Key &key) const
    {
        size_t index = hashFunction(key);
        Node *current = buckets[index];

        while (current)
        {
            if (current->key == key)
            {
                return 1; // Key exists
            }
            current = current->next;
        }

        return 0; // Key does not exist
    }

    // Remove an element by key
    bool erase(const Key &key)
    {
        size_t index = hashFunction(key);
        Node *current = buckets[index];
        Node *prev = nullptr;

        while (current)
        {
            if (current->key == key)
            {
                if (prev)
                {
                    prev->next = current->next;
                }
                else
                {
                    buckets[index] = current->next;
                }

                delete current;
                --num_elements;
                return true;
            }
            prev = current;
            current = current->next;
        }

        return false;
    }

    // Access or insert a value by key
    Value &operator[](const Key &key)
    {
        size_t index = hashFunction(key);
        Node *current = buckets[index];

        while (current)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }

        // Key does not exist, create a new node
        Node *new_node = new Node(key, Value());
        new_node->next = buckets[index];
        buckets[index] = new_node;
        ++num_elements;

        // Check and rehash if needed
        if (static_cast<double>(num_elements) / num_buckets > max_load_factor)
        {
            rehash(num_buckets * 2);
        }

        return new_node->value;
    }

    // Clear all elements
    void clear()
    {
        for (size_t i = 0; i < num_buckets; ++i)
        {
            Node *current = buckets[i];
            while (current)
            {
                Node *to_delete = current;
                current = current->next;
                delete to_delete;
            }
            buckets[i] = nullptr;
        }
        num_elements = 0;
    }

    // Print all elements
    void printAll() const
    {
        for (size_t i = 0; i < num_buckets; ++i)
        {
            Node *current = buckets[i];
            while (current)
            {
                std::cout << "Key: " << current->key << ", Value: " << current->value << "\n";
                current = current->next;
            }
        }
    }
};

// Main function for testing
int main()
{
    // UnorderedMap with string keys
    UnorderedMap<std::string, int> map1;
    map1.insert("Alice", 25);
    map1.insert("Bob", 30);
    map1.insert("Charlie", 35);
    map1.insert("Charlies", 35);
    map1.insert("Charlies", 50);
    // map1["Charlies"] = 40;

    std::cout << "String keys:\n";
    map1.printAll();
    std::cout << "Size: " << map1.size() << std::endl;

    std::cout << "------------------------" << std::endl;

    // UnorderedMap with integer keys
    UnorderedMap<int, std::string> map2;
    map2.insert(1, "One");
    map2.insert(2, "Two");
    map2.insert(3, "Three");
    map2[4] = "Four"; // Insert or update key 4
    map2[4] = "Bon";  // Update value of key 4
    std::cout << "\nMap 2:\n";
    map2.printAll();

    map2.erase(2); // Erase key 2
    std::cout << "\nAfter erasing key 2:\n";
    map2.printAll();

    std::cout << *map2.find(3) << std::endl; // Find key 3
    std::cout << map2.count(3) << std::endl; // Count occurrences of key 3

    map2.clear(); // Clear map2
    std::cout << "\nAfter clearing map2:\n";
    map2.printAll();

    return 0;
}

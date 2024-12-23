#include <iostream>
#include <string>

struct HashFunction {
    size_t operator()(int key) const {
        return key * 2654435761 % (1ULL << 31);
    }

    size_t operator()(const std::string& key) const {
        size_t hash = 0;
        for (char c : key) {
            hash = hash * 31 + c;
        }
        return hash;
    }
};

template <typename Key, typename Value, typename Hash = HashFunction>
class UnorderedMap {
private:
    enum State { EMPTY, OCCUPIED, DELETED };

    struct Node {
        Key key;
        Value value;
        State state;

        Node() : state(EMPTY) {}
        Node(const Key& k, const Value& v) : key(k), value(v), state(OCCUPIED) {}
    };

    Node* buckets;
    size_t num_buckets;
    size_t num_elements;
    double max_load_factor;
    Hash hasher;

    size_t hashFunction(const Key& key) const {
        return hasher(key) % num_buckets;
    }

    size_t probe(size_t index) const {
        return (index + 1) % num_buckets;
    }

    void rehash(size_t new_bucket_count) {
        Node* old_buckets = buckets;
        size_t old_num_buckets = num_buckets;

        buckets = new Node[new_bucket_count]();
        num_buckets = new_bucket_count;
        num_elements = 0;

        for (size_t i = 0; i < old_num_buckets; ++i) {
            if (old_buckets[i].state == OCCUPIED) {
                insert(old_buckets[i].key, old_buckets[i].value);
            }
        }

        delete[] old_buckets;
    }

public:
    UnorderedMap(size_t bucket_count = 11, double load_factor = 0.75)
        : num_buckets(bucket_count), num_elements(0), max_load_factor(load_factor) {
        buckets = new Node[num_buckets]();
    }

    ~UnorderedMap() {
        delete[] buckets;
    }

    void insert(const Key& key, const Value& value) {
        if (static_cast<double>(num_elements) / num_buckets > max_load_factor) {
            rehash(num_buckets * 2);
        }

        size_t index = hashFunction(key);

        while (buckets[index].state == OCCUPIED) {
            if (buckets[index].key == key) {
                buckets[index].value = value; // Update value if key exists
                return;
            }
            index = probe(index);
        }

        buckets[index] = Node(key, value);
        ++num_elements;
    }

    Value* find(const Key& key) {
        size_t index = hashFunction(key);

        while (buckets[index].state != EMPTY) {
            if (buckets[index].state == OCCUPIED && buckets[index].key == key) {
                return &buckets[index].value;
            }
            index = probe(index);
        }

        return nullptr;
    }

    bool erase(const Key& key) {
        size_t index = hashFunction(key);

        while (buckets[index].state != EMPTY) {
            if (buckets[index].state == OCCUPIED && buckets[index].key == key) {
                buckets[index].state = DELETED;
                --num_elements;
                return true;
            }
            index = probe(index);
        }

        return false;
    }

    Value& operator[](const Key& key) {
        size_t index = hashFunction(key);

        while (buckets[index].state != EMPTY) {
            if (buckets[index].state == OCCUPIED && buckets[index].key == key) {
                return buckets[index].value;
            }
            index = probe(index);
        }

        if (static_cast<double>(num_elements) / num_buckets > max_load_factor) {
            rehash(num_buckets * 2);
            return (*this)[key];
        }

        buckets[index] = Node(key, Value());
        ++num_elements;

        return buckets[index].value;
    }

    size_t size() const {
        return num_elements;
    }

    void clear() {
        delete[] buckets;
        buckets = new Node[num_buckets]();
        num_elements = 0;
    }

    void printAll() const {
        for (size_t i = 0; i < num_buckets; ++i) {
            if (buckets[i].state == OCCUPIED) {
                std::cout << "Key: " << buckets[i].key << ", Value: " << buckets[i].value << "\n";
            }
        }
    }
};

int main() {
    UnorderedMap<std::string, int> map;
    map.insert("Alice", 25);
    map.insert("Bob", 30);
    map.insert("Charlie", 35);
    map.insert("Charlie", 335);
    //map["Alice"] = 50; // Update value of "Alice"

    std::cout << "Map contents:\n";
    map.printAll();

    std::cout << "\nFind 'Alice': " << *map.find("Alice") << "\n";

    map.erase("Alice");
    std::cout << "\nAfter erasing 'Alice':\n";
    map.printAll();

    return 0;
}

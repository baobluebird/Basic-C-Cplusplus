#include <iostream>
#include <vector>
#include <list>
#include <utility>  // For std::pair
#include <functional> // For std::hash
#include <stdexcept>  // For std::out_of_range

// Template-based implementation of an unordered map (hash map)
template <typename Key, typename Value>
class UnorderedMap {
private:
    std::vector<std::list<std::pair<Key, Value>>> buckets; // Vector of buckets (each bucket is a list of key-value pairs)
    size_t num_elements; // The number of elements currently in the map
    static constexpr size_t default_bucket_count = 16; // Default number of buckets
    double max_load_factor; // Maximum load factor before resizing the buckets

    // Hash function to map a key to a bucket index
    size_t hashFunction(const Key& key) const {
        // Prints the computed hash value for debugging purposes
        std::cout << "Hash value of " << key << " is " 
                  << std::hash<Key>{}(key) % buckets.size() << std::endl;
        return std::hash<Key>{}(key) % buckets.size();
    }

    // Function to resize and rehash the buckets
    void rehash(size_t new_bucket_count) {
        std::vector<std::list<std::pair<Key, Value>>> new_buckets(new_bucket_count);

        // Re-distribute all existing elements into the new buckets
        for (const auto& bucket : buckets) {
            for (const auto& pair : bucket) {
                size_t new_index = std::hash<Key>{}(pair.first) % new_bucket_count;
                new_buckets[new_index].push_back(pair);
            }
        }

        buckets.swap(new_buckets); // Replace old buckets with the new ones
    }

public:
    // Constructor to initialize the map with a given bucket count and load factor
    UnorderedMap(size_t bucket_count = default_bucket_count, double load_factor = 0.75)
        : buckets(bucket_count), num_elements(0), max_load_factor(load_factor) {}

    // Returns the number of elements in the map
    size_t size() const {
        return num_elements;
    }

    // Checks if the map is empty
    bool empty() const {
        return num_elements == 0;
    }

    // Returns the number of buckets
    size_t bucket_count() const {
        return buckets.size();
    }

    // Computes the current load factor
    double load_factor() const {
        return static_cast<double>(num_elements) / buckets.size();
    }

    // Ensures the map has enough buckets for a given number of elements
    void reserve(size_t n) {
        if (n > buckets.size()) {
            rehash(n);
        }
    }

    // Inserts a key-value pair into the map
    std::pair<bool, typename std::list<std::pair<Key, Value>>::iterator>
    insert(const std::pair<Key, Value>& pair) {
        size_t index = hashFunction(pair.first);
        auto& bucket = buckets[index];

        // Check if the key already exists in the bucket
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == pair.first) {
                return {false, it}; // Key already exists
            }
        }

        // Add the new pair to the bucket
        bucket.push_back(pair);
        ++num_elements;

        // Resize if the load factor exceeds the maximum
        if (load_factor() > max_load_factor) {
            rehash(buckets.size() * 2);
        }

        return {true, --bucket.end()};
    }

    // Finds a key in the map and returns a pointer to its value
    Value* find(const Key& key) {
        size_t index = hashFunction(key);
        auto& bucket = buckets[index];

        for (auto& pair : bucket) {
            if (pair.first == key) {
                return &pair.second; // Return a pointer to the value
            }
        }
        return nullptr; // Key not found
    }

    // Const version of the find method
    const Value* find(const Key& key) const {
        size_t index = hashFunction(key);
        const auto& bucket = buckets[index];

        for (const auto& pair : bucket) {
            if (pair.first == key) {
                return &pair.second; // Return a pointer to the value
            }
        }
        return nullptr; // Key not found
    }

    // Checks if a key exists in the map
    bool contains(const Key& key) const {
        return find(key) != nullptr;
    }

    // Removes a key-value pair from the map
    bool erase(const Key& key) {
        size_t index = hashFunction(key);
        auto& bucket = buckets[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                --num_elements;
                return true;
            }
        }
        return false; // Key not found
    }

    // Operator to access or insert a value by key
    Value& operator[](const Key& key) {
        size_t index = hashFunction(key);
        auto& bucket = buckets[index];

        // Search for the key in the bucket
        for (auto& pair : bucket) {
            if (pair.first == key) {
                return pair.second; // Return the value if key exists
            }
        }

        // Key not found, create a new pair with default value
        bucket.push_back({key, Value()});
        ++num_elements;

        // Resize if the load factor exceeds the maximum
        if (load_factor() > max_load_factor) {
            rehash(buckets.size() * 2);
        }

        return bucket.back().second;
    }

    // Accesses a value by key with bounds checking
    Value& at(const Key& key) {
        size_t index = hashFunction(key);
        auto& bucket = buckets[index];

        for (auto& pair : bucket) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    // Const version of the at method
    const Value& at(const Key& key) const {
        size_t index = hashFunction(key);
        const auto& bucket = buckets[index];

        for (const auto& pair : bucket) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    // Clears all elements from the map
    void clear() {
        for (auto& bucket : buckets) {
            bucket.clear();
        }
        num_elements = 0;
    }

    // Prints all key-value pairs in the map
    void printAll() const {
        for (size_t i = 0; i < buckets.size(); ++i) {
            for (const auto& pair : buckets[i]) {
                std::cout << "Key: " << pair.first << ", Value: " << pair.second << "\n";
            }
        }
    }
};

// Main function for testing the UnorderedMap
int main() {
    UnorderedMap<std::string, int> map;
    map.insert({"Alice", 25});
    map.insert({"Bob", 30});
    map.insert({"Charlie", 35});
    
    std::cout << "All elements in the map:\n";
    map.printAll();

    std::cout << "\nFinding Bob:\n";
    if (auto* value = map.find("Bob")) {
        std::cout << "Found: Key: Bob, Value: " << *value << "\n";
    } else {
        std::cout << "Key not found\n";
    }

    std::cout << "\nChecking if 'Eve' exists: " 
              << (map.contains("Eve") ? "Yes" : "No") << "\n";

    map.erase("Alice");
    std::cout << "\nAfter erasing Alice:\n";
    map.printAll();

    return 0;
}

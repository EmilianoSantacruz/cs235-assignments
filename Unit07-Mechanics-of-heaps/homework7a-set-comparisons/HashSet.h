#pragma once

#include <vector>
#include <list>
#include <functional>

template<class T>
class HashSet {
public:
    HashSet() : bucket_count(16), item_count(0) {
        buckets.resize(bucket_count);
    }

    ~HashSet() {}

    bool insert(T item) {
        if (contains(item)) return false;

        if (load_factor() > 0.75) {
            rehash(bucket_count * 2);
        }

        size_t hashcode = std::hash<T>{}(item);
        size_t index = hashcode % bucket_count;

        buckets[index].push_back(item);
        item_count++;
        return true;
    }

    bool remove(T item) {
        size_t hashcode = std::hash<T>{}(item);
        size_t index = hashcode % bucket_count;

        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == item) {
                bucket.erase(it);
                item_count--;
                return true;
            }
        }

        return false;
    }

    bool contains(T item) const {
        size_t hashcode = std::hash<T>{}(item);
        size_t index = hashcode % bucket_count;

        const auto& bucket = buckets[index];
        for (const auto& elem : bucket) {
            if (elem == item) {
                return true;
            }
        }

        return false;
    }

    void clear() {
        for (auto& bucket : buckets) {
            bucket.clear();
        }
        item_count = 0;
    }

    int size() const {
        return item_count;
    }

private:
    std::vector<std::list<T>> buckets;
    size_t bucket_count;
    int item_count;

    double load_factor() const {
        return static_cast<double>(item_count) / bucket_count;
    }

    void rehash(size_t new_bucket_count) {
        std::vector<std::list<T>> new_buckets(new_bucket_count);

        for (const auto& bucket : buckets) {
            for (const auto& item : bucket) {
                size_t hashcode = std::hash<T>{}(item);
                size_t new_index = hashcode % new_bucket_count;
                new_buckets[new_index].push_back(item);
            }
        }

        buckets = std::move(new_buckets);
        bucket_count = new_bucket_count;
    }
};

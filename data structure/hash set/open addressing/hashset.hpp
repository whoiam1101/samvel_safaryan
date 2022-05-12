#ifndef __OPEN_ADDRESSING_HASHSET_H__
#define __OPEN_ADDRESSING_HASHSET_H__

#include <vector>

using namespace std;

class HashSet {
private:
    struct Pair {
        char* _key;
        int _value;

        Pair() : _key(nullptr), _value(0) {}
        Pair(char* key, int value) : _key(key), _value(value) {}
    };

    vector<Pair> _table;
    int _size;

    int firstHash(char*) const;
    int secondHash(char*) const;

public:
    HashSet();

    void insert(char*, int);
    void remove(char*);

    bool isExist(char*) const;
    int size() const;
};

HashSet::HashSet() {
    _size = 0;
    _table = vector<Pair>(128);
}

int HashSet::firstHash(char* word) const {
    const int PRIME = 65537;
    long long hash_value = (long long) word[0];
    for (int i = 1; word[i] != '\0'; i++) {
        hash_value = (hash_value * 13LL + (long long) word[i]) % PRIME;
    }
    return (int) hash_value;
}

int HashSet::secondHash(char* word) const {
    int length = 0;
    for (; word[length] != '\0'; length++) {}
    return length % (_table.size() - 1) + 1;
}

void HashSet::insert(char* key, int value) {
    int first_hash_value = firstHash(key);
    int second_hash_value = secondHash(key);
    for (int i = 0; i < (int) _table.size(); i++) {
        if (
            _table[first_hash_value]._key == nullptr ||
            _table[first_hash_value]._key == key
        ) {
            _table[first_hash_value]._key = key;
            _table[first_hash_value]._value = value;
            _size++;
            return;
        }
        first_hash_value = (first_hash_value + second_hash_value) % (int) _table.size();
    }
    _table.resize(2 * _table.size());
    insert(key, value);
}

void HashSet::remove(char* key) {
    int first_hash_value = firstHash(key);
    int second_hash_value = secondHash(key);
    for (int i = 0; i < (int) _table.size(); i++) {
        if (_table[first_hash_value]._key == key) {
            _table[first_hash_value]._key = nullptr;
            _table[first_hash_value]._value = 0;
            return;
        }
        first_hash_value = (first_hash_value + second_hash_value) % (int) _table.size();
    }
}

bool HashSet::isExist(char* key) const {
    int first_hash_value = firstHash(key);
    int second_hash_value = secondHash(key);
    for (int i = 0; i < (int) _table.size(); i++) {
        if (_table[first_hash_value]._key == key) {
            return true;
        }
        first_hash_value = (first_hash_value + second_hash_value) % (int) _table.size();
    }
    return false;
}

int HashSet::size() const {
    return _size;
}

#endif // __OPEN_ADDRESSING_HASHSET_H__
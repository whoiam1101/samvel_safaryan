#ifndef __SEPARATE_CHAINING_HASHSET_H__
#define __SEPARATE_CHAINING_HASHSET_H__

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

    const int PRIME = 65537;
    vector<vector<Pair>> _table;
    int _size;

    int hash(char*) const;

public:
    HashSet();

    void insert(char*, int);
    void remove(char*);

    bool isExist(char*) const;
    int size() const;
};

HashSet::HashSet() {
    _size = 0;
    _table = vector<vector<Pair>>(PRIME);
}

int HashSet::hash(char* word) const {
    long long hash_value = (long long) word[0];
    for (int i = 1; word[i] != '\0'; i++) {
        hash_value = (hash_value * 13LL + (long long) word[i]) % PRIME;
    }
    return (int) hash_value;
}

void HashSet::insert(char* key, int value) {
    int index = hash(key);
    for (int i = 0; i < _table[index].size(); i++) {
        if (_table[index][i]._key == key) {
            _table[index][i]._value = value;
            return;
        }
    }
    _table[index].push_back(Pair(key, value));
    _size++;
}

void HashSet::remove(char* key) {
    int index = hash(key);
    for (int i = 0; i < _table[index].size(); i++) {
        if (_table[index][i]._key == key) {
            _table[index].erase(_table[index].begin() + i);
            _size--;
            break;
        }
    }
}

bool HashSet::isExist(char* key) const {
    int index = hash(key);
    for (int i = 0; i < _table[index].size(); i++) {
        if (_table[index][i]._key == key) {
            return true;
        }
    }
    return false;
}

int HashSet::size() const {
    return _size;
}

#endif // __SEPARATE_CHAINING_HASHSET_H__
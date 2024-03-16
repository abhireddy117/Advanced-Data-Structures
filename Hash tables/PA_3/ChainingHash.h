/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

 // Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K, V> {
private:
    int Count;
    vector<list<pair<K, V>>>* Table_C;
    //vector<list<V>> * _table;

public:
    ChainingHash(int n = 11) {
        Count = 0;
        //pair<K,V> p(0, 0);
        list<pair<K, V>> l;
        
        Table_C = new vector<list<pair<K, V>>>;
        Table_C->resize(n, l);
        
        //_table = new vector<list<V>>(n, list<V>(0));
    }

    ~ChainingHash() {
        delete Table_C;
        Count = 0;
    }

    int size() {
        return Count;
    }

    V& at(const K& key) {
        for (auto it = Table_C->at(hash(key)).begin(); it != Table_C->at(hash(key)).end(); it++) {
            if (it->first == key) {
                return it->second;
            }
        }
        throw std::out_of_range("Key not in hash");

    }
    V operator[](const K& key) {
        return this->at(key);
    }

    bool insert(const std::pair<K, V>& pair) {
        int hashKey = hash(pair.first);
        if (load_factor() > 0.75) {
            rehash(101);
        }
        this->erase(pair.first);
        ++Count;
        Table_C->at(hashKey).push_front(pair);
        
        return true;
    }

    void erase(const K& key) {
        for (auto it = Table_C->at(hash(key)).begin(); it != Table_C->at(hash(key)).end(); it++) {
            if (it->first == key) {
                it = Table_C->at(hash(key)).erase(it);
                Count--;
            }
        }
    }

    void clear() {
        int tableSize = Table_C->capacity();
        delete Table_C;
        //_table = new vector<list<pair<K,V>>>(tableSize);
        Table_C = new vector<list<pair<K, V>>>(tableSize);
        Count = 0;
    }

    int bucket_count() {
        return Table_C->capacity();
    }

    float load_factor() {
        return  (float)Count / (float)Table_C->capacity();
    }
    void rehash(int n) {
        list<pair<K, V>> l;
        vector<list<pair<K, V>>> v = std::move(*Table_C);
        Table_C->resize(findNextPrime(n), l);
        for (int i = 0; i < v.capacity(); i++) {
            while (v[i].empty() == false) {
                Count--;
                insert(v[i].front());
                v[i].pop_front();
            }
        }
    }
    
private:
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        return 0;
    }

};

#endif //__CHAINING_HASH_H

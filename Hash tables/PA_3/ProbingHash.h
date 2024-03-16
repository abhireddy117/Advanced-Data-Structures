#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K, V> { // derived from Hash
private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    vector<pair<pair<K, V>, EntryState>> Table;
    int tableSize = 0;

public:
    ProbingHash(int n = 11) {
        /*list<pair<K, V>> l;
        list <pair<pair<K,V>, EntryState>> c(l);*/

        //vector<int> = new vetcotr<int>(n)
        //vctor<vector<> = new vec<vec<int>>(n, new vect<int>(n))

        tableSize = 101; //* bucket_count();
        pair<pair<K, V>, EntryState> p;
        p.second = EntryState::EMPTY;
        Table.resize(n, p);
        


       /* tableSize = 0;
        pair<pair<K, V>, EntryState> p;
        p.second = EntryState::EMPTY;
        Table.resize(n, p);*/
    }

    ~ProbingHash() {
        this->clear();
        tableSize = 0;
    }

    int size() {
        return tableSize;
    }
    V& at(const K& key) {
        if (Table[hash(key)].second != EntryState::VALID) {
            throw std::out_of_range("Key not in hash");
        }
        return Table[hash(key)].first.second;
    }

    V operator[](const K& key) {
        return this->at(key);

    }
    

    bool insert(const std::pair<K, V>& pair) 
    {
        if (load_factor() > 0.75) {
            rehash(101);
        }
        int hashKey = hash(pair.first);
        while (Table[hashKey].second == EntryState::VALID)
        {
            if (Table[hashKey].first.first == pair.first)
            {
                Table[hashKey].first.second == pair.second;
                break;

               
            }
           hashKey = (hashKey + 1) % Table.capacity();
            
        }
        if (Table[hashKey].first.first != pair.first) {
            Table[hashKey].first = pair;
            Table[hashKey].second = EntryState::VALID;
            ++tableSize;
        }


        return true;
    }
       
    

    void erase(const K& key) {
        int hashKey = hash(key);
        if (Table[hashKey].second != EntryState::EMPTY) {
            if (Table[hashKey].first.first != key) {
                hashKey = (hashKey + 1) % Table.capacity();
            }
            if (Table[hashKey].first.first == key) {
                Table[hashKey].second = EntryState::DELETED;
                tableSize--;
            }

        }
    }

    void clear() {
        for (int i = 0; i < Table.capacity(); i++) {
            this->erase(i);
        }
        tableSize = 0;

    }

    int bucket_count() {
        return Table.capacity();
    }

    float load_factor() {
        return (float)tableSize / (float)Table.capacity();
    }
    
    void rehash(int n) {
        

        vector<pair<pair<K, V>, EntryState>> v = std::move(Table);
        Table.resize(findNextPrime(Table.capacity()));
        tableSize = 0;

        for (int i = 0; i < v.capacity(); i++) {
            
            insert(std::move(v[i].first));
        }

        //Table.resize(findNextPrime(Table.capacity()));
        //Table.resize(findNextPrime(n));
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

#endif //__PROBING_HASH_H

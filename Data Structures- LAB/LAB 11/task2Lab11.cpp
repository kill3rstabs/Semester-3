#include <iostream>
#include <cmath>
using namespace std;

class HashTableEntry
{

public:
    int value;
    int key;
    HashTableEntry()
    {
        key = 0;
        value = 0;
    }
    HashTableEntry(int value, int key)
    {
        this->value = value;
        this->key = key;
    }
};

class HashMapTable
{
    HashTableEntry **H;
    HashTableEntry *dummy;
    int capacity;
    int size;

public:
    HashMapTable()
    {
        size = 0;
        capacity = 23;
        H = new HashTableEntry *[capacity];
        for (int i = 0; i < capacity; i++)
        {
            H[i] = NULL;
        }
        dummy = new HashTableEntry(-1, -1);
    }
    int divisionHash(int key)
    {
        return (key % capacity);
    }
    int multiplicationHash(int key)
    {
        return floor(capacity * key * 0.7);
    }
    int midValue(double key)
    {
        int digit = (int)log10(key) + 1;
        key = (int)(key / pow(key, digit / 2)) % 10;
        return key;
    }
    int midSquareHash(int key)
    {
        key *= key;
        return midValue(key);
    }
    int foldingHash(int key)
    {
        int v1, v2, v3;
        v1 = key / 1000000;
        v2 = key / 1000 % 1000;
        v3 = key % 1000000;
        return v1 + v2 + v3;
    }
    int baseNumber(int key)
    {
        if (key > 10000)
            return (key % 10000);
        else
            return key;
    }
    int radixHash(int key)
    {
        return (baseNumber(key));
    }
    void insertion(const int &value, const int &key)
    {
        HashTableEntry *newNode = new HashTableEntry(value, key);
        int hashIndex = divisionHash(key);
        while (H[hashIndex] != NULL && H[hashIndex]->key != key && H[hashIndex]->key != -1)
        {
            hashIndex++;
            hashIndex = divisionHash(hashIndex);
        }
        if (H[hashIndex] == NULL || H[hashIndex]->key == -1)
            size++;
        H[hashIndex] = newNode;
    }
    bool searchKey(int key)
    {
        int count = 0;
        int hashIndex = divisionHash(key);
        while (H[hashIndex] != NULL)
        {
            if (count++ > capacity)
                return false;
            if (H[hashIndex]->key == key)
                return true;
            hashIndex++;
            hashIndex = divisionHash(hashIndex);
        }
        return false;
    }
    void remove(int key)
    {
        int count = 0;
        int hashIndex = divisionHash(key);
        while (H[hashIndex] != NULL)
        {
            if (count++ > capacity)
                return;
            if (H[hashIndex]->key == key)
            {
                H[hashIndex] = dummy;
                size--;
            }
            hashIndex++;
            hashIndex = divisionHash(hashIndex);
        }
    }
    void removeAll()
    {
        for (int i = 0; i < capacity; i++)
            delete[] H[i];
        delete[] H;
        delete[] dummy;
        size = 0;
    }
    void viewValues()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (H[i] != NULL && H[i]->key != -1)
            {
                cout << H[i]->value << " ";
            }
        }
    }
    ~HashMapTable()
    {
        removeAll();
    }
};

int main()
{
    HashMapTable H1;
    H1.insertion(20, 31);
    H1.insertion(12, 32);
    H1.insertion(11, 33);
    H1.insertion(33, 34);
    H1.remove(32);
    H1.insertion(9, 35);
    H1.viewValues();
    return 0;
}
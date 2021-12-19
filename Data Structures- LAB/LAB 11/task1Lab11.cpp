#include <iostream>
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
    int hashFunc(int key)
    {
        return (key % capacity);
    }
    void insertion(int value, int key)
    {
        HashTableEntry *newNode = new HashTableEntry(value, key);
        int hashIndex = hashFunc(key);
        while (H[hashIndex] != NULL && H[hashIndex]->key != key && H[hashIndex]->key != -1)
        {
            hashIndex++;
            hashIndex %= capacity;
        }
        if (H[hashIndex] == NULL || H[hashIndex]->key == -1)
            size++;
        H[hashIndex] = newNode;
    }
    bool searchKey(int key)
    {
        int count = 0;
        int hashIndex = hashFunc(key);
        while (H[hashIndex] != NULL)
        {
            if (count++ > capacity)
                return false;
            if (H[hashIndex]->key == key)
                return true;
            hashIndex++;
            hashIndex %= capacity;
        }
        return false;
    }
    void remove(int key)
    {
        int count = 0;
        int hashIndex = hashFunc(key);
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
            hashIndex %= capacity;
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
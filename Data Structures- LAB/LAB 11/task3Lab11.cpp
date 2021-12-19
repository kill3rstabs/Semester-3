#include <iostream>
using namespace std;

class HashTableEntry
{

public:
    long long int contact_Number;
    long int student_ID;
    HashTableEntry()
    {
        student_ID = 0;
        contact_Number = 0;
    }
    HashTableEntry(long long int contact_Number, long int student_ID)
    {
        this->contact_Number = contact_Number;
        this->student_ID = student_ID;
    }
};

class contact_Book
{
    HashTableEntry **H;
    HashTableEntry *dummy;
    int capacity;
    int size;

public:
    contact_Book()
    {
        size = 0;
        capacity = 23;
        H = new HashTableEntry *[capacity];
        for (int i = 0; i < capacity; i++)
            H[i] = NULL;
        dummy = new HashTableEntry(-1, -1);
    }
    int hashFunc(long int student_ID)
    {
        return (student_ID % capacity);
    }
    void insertion(long long int contact_Number, long int student_ID)
    {
        HashTableEntry *newNode = new HashTableEntry(contact_Number, student_ID);
        int hashIndex = hashFunc(student_ID);
        while (H[hashIndex] != NULL && H[hashIndex]->student_ID != student_ID && H[hashIndex]->student_ID != -1)
        {
            hashIndex++;
            hashIndex %= capacity;
        }
        if (H[hashIndex] == NULL || H[hashIndex]->student_ID == -1)
            size++;
        H[hashIndex] = newNode;
    }
    bool searchstudent_ID(long int student_ID)
    {
        int count = 0;
        int hashIndex = hashFunc(student_ID);
        while (H[hashIndex] != NULL)
        {
            if (count++ > capacity)
                return false;
            if (H[hashIndex]->student_ID == student_ID)
                return true;
            hashIndex++;
            hashIndex %= capacity;
        }
        return false;
    }
    void remove(long int student_ID)
    {
        int count = 0;
        int hashIndex = hashFunc(student_ID);
        while (H[hashIndex] != NULL)
        {
            if (count++ > capacity)
                return;
            if (H[hashIndex]->student_ID == student_ID)
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
    void viewcontact_Numbers()
    {
        cout << "Contacts:\n";
        for (int i = 0; i < capacity; i++)
        {
            if (H[i] != NULL && H[i]->student_ID != -1)
            {
                cout << H[i]->contact_Number << endl;
            }
        }
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        if (size < 1)
            return true;
        return false;
    }
    ~contact_Book()
    {
        removeAll();
    }
};

int main()
{
    contact_Book E;
    E.insertion(923172114289, 200165);
    E.viewcontact_Numbers();
    cout << "\nSize:" << E.getSize();
    (E.isEmpty()) ? cout << "\nEmpty Contact Book" : cout << "\nNot Empty";
    return 0;
}
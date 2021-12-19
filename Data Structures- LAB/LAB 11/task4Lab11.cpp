#include <iostream>
using namespace std;

class HashTableEntry
{

public:
    long long int contact_Number;
    long int student_ID;
    HashTableEntry *next;
    HashTableEntry()
    {
        student_ID = 0;
        contact_Number = 0;
        next = NULL;
    }
    HashTableEntry(long long int contact_Number, long int student_ID)
    {
        this->contact_Number = contact_Number;
        this->student_ID = student_ID;
        next = NULL;
    }
};

class contact_Book
{
    HashTableEntry **H;
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
    }
    void insertion(long long int contact_Number, long int student_ID)
    {
        int hashIndex = hashFunc(student_ID);
        HashTableEntry *current = H[hashIndex];
        HashTableEntry *prev = NULL;
        while (current != NULL)
        {
            prev = current;
            current = current->next;
        }
        if (current == NULL)
        {
            current = new HashTableEntry(contact_Number, student_ID);
            if (prev == NULL)
                H[hashIndex] = current;
            else
                prev->next = current;
            size++;
        }
    }
    bool searchstudent_ID(long int student_ID)
    {
        int hashIndex = hashFunc(student_ID);
        if (H[hashIndex] != NULL)
        {
            HashTableEntry *temp = H[hashIndex];
            while (temp != NULL)
            {
                if (temp->student_ID == student_ID)
                {
                    cout << "\nContact Number:" << temp->contact_Number << " ";
                    return true;
                }
                temp = temp->next;
            }
        }
        return false;
    }
    void removeContact(long int student_ID)
    {
        int hashIndex = hashFunc(student_ID);
        if (H[hashIndex] != NULL)
        {
            HashTableEntry *temp = H[hashIndex];
            HashTableEntry *prev = NULL;
            if (temp->student_ID == student_ID)
            {
                prev = temp;
                H[hashIndex] = temp->next;
                delete prev;
                size--;
            }
            while (temp->next != NULL)
            {
                temp = temp->next;
                if (temp->student_ID == student_ID)
                {
                    prev = temp;
                    temp = temp->next;
                    delete prev;
                    size--;
                }
            }
        }
        else
            cout << "Element not found to delete." << endl;
    }
    int hashFunc(long int student_ID)
    {
        return (student_ID % capacity);
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
    void viewContact_Numbers()
    {
        cout << "Contact Numbers:" << endl;
        for (int i = 0; i < capacity; i++)
        {
            if (H[i] != NULL)
            {
                HashTableEntry *temp = H[i];
                while (temp != NULL)
                {
                    cout << temp->contact_Number << endl;
                    temp = temp->next;
                }
            }
        }
    }
    void removeAll()
    {
        for (int i = 0; i < capacity; i++)
            delete[] H[i];
        delete[] H;
        size = 0;
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
    E.insertion(923472701875, 200171);
    E.viewContact_Numbers();
    E.removeContact(200165);
    cout << "\nSize:" << E.getSize();
    (E.isEmpty()) ? cout << "\nEmpty Contact Book" : cout << "\nNot Empty";
    return 0;
}

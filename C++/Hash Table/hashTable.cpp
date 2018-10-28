#include<bits/stdc++.h>
using namespace std;

class HashTable{
private:
    static const int HASH_MAX = 10;

    class linkedList
    {
    public:
        string data;
        linkedList* next;
    };
    //linked list type array
    linkedList* hashTable[HASH_MAX];
public:
    HashTable();
    int hashFunction(string key);
    void insertItem(string key);
    int numberOfItemsInIndex(int index);
    void printTable();
    void search_element(string key);
    void removeItem(string key);

};


HashTable::HashTable()
{
    for(int i = 0;i < HASH_MAX;i++)
    {
        hashTable[i] = new linkedList;
        hashTable[i]->data = "empty";
        hashTable[i]->next = NULL;
    }
}


int HashTable::hashFunction(string key)
{
    int sum = 0;
    for(int i = 0;i < key.size();i++)
    {
        sum += key[i];
    }
    return sum % HASH_MAX;
}

void HashTable::insertItem(string key)
{
    int index = hashFunction(key);
    if(hashTable[index]->data=="empty")
    {
        hashTable[index]->data = key;

    }else{
        linkedList* tmp = hashTable[index];
        linkedList* x = new linkedList;
        x->data = key;
        x->next = NULL;

        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = x;
    }
}


int HashTable::numberOfItemsInIndex(int index)
{
    int count = 0;
    //this index does not contain any value
    if(hashTable[index]->data == "empty")
    {
        return count;
    }else{
        //count is now one
        count++;
        //pointing to the beginning of the index list
        linkedList* tmp = hashTable[index];
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
            count++;
        }
    }
    return count;
}
/**
* this function prints the element
* of each index of hashTable
* and the number of elements in that index
*/
void HashTable::printTable()
{
    int num;
    for(int i = 0 ;i < HASH_MAX;i++)
    {
        num = numberOfItemsInIndex(i);
        if(num!=0){
        cout<<"......index "<<i<<"......"<<endl;
        linkedList* tmp = hashTable[i];
        cout<<tmp->data<<"\n";
        while(tmp->next != NULL){
            tmp = tmp->next;
            cout<<tmp->data<<"\n";
        }
        cout<<"\nnumber of elements in this index = "<<num<<endl;
        cout<<"-------------\n";
        }
    }
}
void HashTable::search_element(string s)
{
     int index = hashFunction(s);
     linkedList *tmp =  hashTable[index];
     while(tmp != NULL)
     {
         if(tmp->data == s)
         {
             cout<<"Found\n";
             return;
         }
         tmp = tmp->next;
     }
     cout<<"Not Found\n";
}

void HashTable::removeItem(string key)
{
    int index = hashFunction(key);
    linkedList* deletePointer;
    linkedList* pointer1;
    linkedList* pointer2;

    //if the the index is empty
    if(hashTable[index]->data == "empty")
    {
        cout << key << " not found!\n";
    }

    //if only 1 item in the index
    else if(hashTable[index]->data == key && hashTable[index]->next == NULL)
    {
        hashTable[index]->data = "empty";
        cout << key << " was removed from hash table\n";
    }
    //if match is located in the 1st node of the index but there are more items in the index
     else if(hashTable[index]->data == key)
     {
         deletePointer = hashTable[index];
         hashTable[index] = hashTable[index]->next;
         delete(deletePointer);

         cout << key << " was removed from hash table\n";
     }

    //if index contains items and 1st item is not a match
    else{
        pointer1 = hashTable[index]->next;//pointer for  second item
        pointer2 = hashTable[index]; // pointer for 1st item

        while(pointer1 != NULL && pointer1->data != key)
        {
            pointer2 = pointer1;
            pointer1 = pointer1->next;
        }
        //index contains items but match not found
        if(pointer1 == NULL)
        {
            cout << key << " not found!\n";
        }
        //index contains items but match found
        else{
            deletePointer = pointer1;
            pointer1 = pointer1->next;
            pointer2->next = pointer1;
            delete(deletePointer);
            cout << key << " was removed from hash table\n";
        }
    }




}
int main()
{
    HashTable ob;
    ob.insertItem("john");
    ob.insertItem("aapo");
    ob.insertItem("paoa");
    ob.insertItem("dipty");
    ob.insertItem("dipty");
    ob.printTable();
    ob.search_element("aiiapo");
    ob.removeItem("dipty");
    ob.printTable();
    return 0;
}

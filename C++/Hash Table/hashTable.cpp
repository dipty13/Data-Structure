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
int main()
{
    HashTable ob;
    ob.insertItem("john");
    ob.insertItem("aapo");
    ob.insertItem("paoa");
    ob.printTable();
    return 0;
}

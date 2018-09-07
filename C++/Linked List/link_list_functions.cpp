#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *head;
Node  *newNode;
Node  *tmp;

void insert_elements(int n)
{
    newNode = new Node;
    if(head == NULL)
    {
        newNode->data = n;
        head = newNode;
        tmp = newNode;
    }
    else
    {

        newNode->data = n;
        tmp->next = newNode;
        tmp = tmp->next;
    }

}
void print_elements()
{
    Node *currentNode = head;
    while(currentNode != NULL)
    {
        cout<<currentNode->data<<endl;
        currentNode = currentNode->next;
    }
}
/**
* adds element to the front of the list
* Time Complexity: O(1)
*/
void pushFront(int n)
{
    Node *currentNode = new Node;
    currentNode->data = n;
    currentNode->next = head;
    head = currentNode;
}
/**
* adds element to the end of the list
* Time Complexity: O(1)
*/
void pushBack(int n)
{
   Node *currentNode = new Node();
   currentNode->data = n;
   tmp->next = currentNode;
   tmp = tmp->next;

}
/**
* returns data of first element
* Time complexity: O(1)
*/
int topFront()
{
    return head->data;
}
/**
* removes first element from the list
* Time complexity: O(1)
*/
void popFront()
{
    Node* currentNode = head;
    delete(head);
    head = currentNode->next;
}
/**
* find element from the list
* return true or false depending on
* whether the element is in the list or not
* Time complexity: O(n)
*/
bool find(int value)
{
    Node* currentNode = head;
    while(currentNode->next!=NULL)
    {
        if(currentNode->data == value)
        {
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}

int main()
{
    insert_elements(2);
    insert_elements(4);
    insert_elements(1);
    print_elements();
    pushFront(90);
    cout<<"After pushFront(): \n";
    print_elements();
    cout<<"Calling topFront(): "<<topFront()<<endl;
    popFront();
    cout<<"After popFront(): \n";
    print_elements();
     pushBack(20);
    cout<<"After pushBack(): \n";
    print_elements();
    cout<<"calling find(): "<<(find(90)==1? "found\n":"not found\n")<<endl;
    return 0;
}

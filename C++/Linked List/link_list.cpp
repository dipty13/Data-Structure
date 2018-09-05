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
int main()
{
    insert_elements(2);
    insert_elements(4);
    insert_elements(1);
    print_elements();
    return 0;
}

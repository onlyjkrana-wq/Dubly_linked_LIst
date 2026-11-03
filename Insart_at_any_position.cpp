#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
void Insert_at_any_position(Node * &head, Node * &tail, int position, int val)
{
    Node *newNode = new Node(val);
    if (position == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node *temp = head;
    for (int i = 0; i < position-1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    Insert_at_any_position(head, tail, 1, 15);
    print(head);
   
    return 0;
}
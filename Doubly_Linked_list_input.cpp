#include <bits/stdc++.h>
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
void print(Node * Head){
    Node * temp = Head;
    while (temp != NULL)
    {
        cout << temp->val <<" ";
        temp = temp->next;
    }
    
}
void cinFunction(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int main()
{
    Node *Head = NULL;
    Node *Tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        cinFunction(Head, Tail, val);
    }
    print(Head);
    return 0;
}
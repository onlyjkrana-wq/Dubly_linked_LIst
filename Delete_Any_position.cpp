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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
void Delete_at_anyPosition(Node *&head, Node *&tail, int Pos)
{

    Node *temp = head;

    for (int i = 0; i < Pos; i++)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        Node *deleteHead = head;
        head = head->next;
        head->prev = NULL;

        delete deleteHead;
        return;
    }

    if (temp == tail)
    {
        tail = tail->prev;
        tail->next = NULL;

        delete temp;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
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
    Delete_at_anyPosition(head, tail, 2);
    print(head);

    return 0;
}
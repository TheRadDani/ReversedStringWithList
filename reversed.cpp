#include<iostream>
#include <stack>
using namespace std;


struct Node
{
    char value;
    Node *next;
};

void reverse(Node** head){


    Node* temp = *head;


    if(*head == NULL) return;


    stack<struct Node*> s;


    // push to stack
    while (temp!=NULL)
    {
        s.push(temp);
        temp = temp->next;
    }


    temp = s.top();
    *head = temp;
    s.pop();
    //reverse
    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}


void push(Node **head, const char * value)
{


    Node *temphead = *head;


    Node *temp = new Node();
    temp->value = *value;
    temp->next = NULL;


    if (*head == NULL)
    { 
        *head = temp;
        return;
    }


    while (temphead->next != NULL)
    {
        temphead = temphead->next;
    }
    temphead->next = temp;
}


// To print the linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << "\n";
        temp = temp->next;
    }
}


int main(){


    Node *head = NULL;


    push(&head, "H");
    push(&head, "e");
    push(&head, "l");
    push(&head, "l");
    push(&head, "o");
    


    print(head);


    reverse(&head);
    
    cout << "rev: "<< "\n";
    print(head);


    return 0;
}
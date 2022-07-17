#include <iostream>

struct Node
{
  int data;
  Node *next;
};

struct List
{
  Node *head;
  int count;

  List()
  {
    head = nullptr;
    count = 0;
  }

  void add(int data)
  {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr)
    {
      head = newNode;
    }
    else
    {
      Node *temp = head;
      while (temp->next != nullptr)
      {
        temp = temp->next;
      }
      temp->next = newNode;
    }
    count++;
  }

  void print()
  {
    Node *temp = head;
    while (temp != nullptr)
    {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }
};

int main()
{
  List *linkedList = new List();
  linkedList -> add(1);
  linkedList -> add(2);
  linkedList -> add(3);
  linkedList -> add(4);
  linkedList -> add(5);

  linkedList -> print();
  
  return 0;
}
#include<iostream>
using namespace std;


template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};


template <typename T>
class Queue {
    
       Node<T> *head;
       Node <T> *tail;
       int size;
    public:
    
    Queue() {
       head = NULL;
       tail = NULL;
       size = 0;
      
    }
    
    void enqueue(T data) {
      Node<T> *newnode = new Node<T>(data);
        if(head == NULL)
        {
           head = newnode;
           tail = newnode;
           size++;
        }
       else
       {
         tail->next = newnode;
         tail = newnode;
         size++;
       }
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return (size == 0);
      
    }
    
    T dequeue() {
        // Return 0 if queue is empty
      if(head == NULL)
      return 0;
      else
      { Node<int> *p = head;
        T temp;
        temp = head->data;
        head = head->next;
        delete p;
        size--;
        return temp;
       
      }
    }
    
    T front()  {
        // Return 0 if queue is empty
      if(head == NULL)
      return 0;
      else
      {
        return head->data;
      }
    }
};

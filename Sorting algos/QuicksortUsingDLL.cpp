#include<iostream>
#include<stack>
using namespace std;

class Node
{
   public:
    
    int data;

    Node * next;
    Node * prev;

    Node(int data)
    {
        this -> data = data;
        this -> next = this -> prev = this;
    }

};

 Node* head = NULL;

    Node* takeinput()
    {
        cout<<"enter the elements to be sorted"<<endl;  
        int data;
        cin >> data;

        while(data != -1)
        {
         Node *newNode = new Node(data);
         if(head == NULL)            
         {
            Node * newNode = new Node(data);
            head = newNode;
         }
         else
         {
            Node * newNode = new Node(data);
            Node * tail = head -> prev;
            tail -> next = newNode;
            newNode -> next = head;
            newNode -> prev = tail;
            head -> prev = newNode;
         }
        cin >> data;
    }
    return head;
}

Node * swapTwoNodes(Node * start, Node* temp1, Node* temp2)

{
   if(temp1 == temp2)
    return head;
    
    if(temp1 -> next == temp2)

    {
        Node * prev = temp1 -> prev;
        Node * next = temp2 -> next;

        prev -> next = temp2;
        temp2 -> prev = prev;
        temp2 -> next = temp1;
        temp1 -> prev = temp2;
        temp1 -> next = next;
        next -> prev = temp1;

        if (start == temp1)
          return temp2;

    }

    if(temp2 -> next == temp1)
    {
        Node * prev = temp2 -> prev;
        Node * next = temp1 -> next;
        
        prev -> next = temp1;
        temp1 -> prev = prev;
        temp1 -> next = temp2;
        temp2 -> prev = temp1;
        temp1 -> next = next;
        next -> prev = temp2;

        if (start == temp2)
          return temp1;

    }

    Node * prev1 = temp1 -> prev;
    Node * prev2 = temp2 -> prev;
    Node * next1 = temp1 -> next;
    Node * next2 = temp2 -> next;
    
    prev1 -> next = temp2;
    temp2 -> prev = prev1;
    temp2 -> next = next1;
    next1 -> prev = temp2;
    temp1 -> next = next2;
    prev2 -> next = temp1;
    temp1 -> prev = prev2;
    next2 -> prev = temp1;

   

    if (start == temp2)
    {

        return temp1;

    }

    else if(start == temp1)

    {

        return temp2;

    }

    return start;

}
void swap_data(Node* temp1, Node* temp2)
{
    int temp = temp1 -> data;
    temp1 -> data = temp2 -> data;
    temp2 -> data = temp;
}


Node* quick(Node* head, Node* beg, Node* end)
{
    Node* left = beg;
    Node* right = end;
    Node* loc = left;

   while(1)
   { 
    while(loc -> data <= right -> data && loc != right)
     right = right -> prev;
 
     if(loc == right)
      break;       
     
      if(loc -> data > right -> data)
      {
         swap_data(loc, right);
         loc = right;
      }
      while(loc -> data >= left -> data && loc != left)
       left = left -> next;
        
        if(loc == left)
         break;


       if(loc -> data < left -> data)
       {
         swap_data(loc, left);
         loc = left;
       }
  }
  return loc;
     
}


void quickSort(Node* head)
{
    if(head == NULL || head -> next == head)
     return;

   stack<Node*> upper;
   stack<Node*> lower;

   lower.push(head);
   upper.push(head -> prev);
   
   while(!upper.empty() && !lower.empty())
   {
       Node* beg = lower.top();
       Node* end = upper.top();
       lower.pop();
       upper.pop();
       Node* loc = quick(head, beg, end);
       if(beg != loc)
       {
           lower.push(beg);
           upper.push(loc -> prev);
       }
       if(end != loc && loc -> next != end)
       {
           lower.push(loc -> next);
           upper.push(end);

       }
       
   }
}
void printList(Node* head)
{
    if(head == NULL)
     return;

     Node* ptr = head;
     cout<< ptr -> data << " ";
     ptr = ptr -> next;
     while(ptr != head)
     {
         cout << ptr -> data << " ";
         ptr = ptr -> next;
     }
}
int main()
{
    Node * head = takeinput();
    printList(head); 

    quickSort(head);
    printList(head);

}
#include <iostream>
using namespace std;
class node{
public:
    int data;
    int priority;
    node * next;
    node(int d = 0, int p = 0)
    { 
        data = d;
        priority = p;
        next = NULL;
    }
};

void build(int numpri, node * head, node ** rear) 
{

    //node * rear[numpri];
    
    node * ptr = head;
    for(int i = 1;i <= numpri; i++)
    {
        node * p= new node(10,i);
        ptr -> next=p;
        rear[i-1] = p;
        ptr = ptr -> next;
        
    }
    ptr -> next= NULL;
}

void push_q(int p, int d, node ** rear, node * head){
    node * n= new node(0,p);
    rear[p] -> data = d;
 
    node * ptr = rear[p];
    n -> next = ptr -> next;
    ptr -> next = n;
    rear[p] = n;
}
int pop_q(node * head, node ** rear)
{
    int item;
    node * ptr = head;
    node * save = NULL;
    if(ptr == NULL) return -1;
    while(ptr->data != -1 && ptr!= NULL){
        
        save = ptr;
        ptr = ptr->next;
    }
    item = ptr->data;
    if(ptr->next->priority == ((ptr->priority) + 1)){
        ptr->data = -1;
    }
    else if(save == NULL){
        head = head-> next;
    }
    else{
        save->next = ptr->next;
    }
    return item;
}





int main() {
    node * rear[5];
    
    node * n= new node(0,0);
    int i=0;
    build(5,n, rear);
    cout<<pop_q(n,rear)<<endl;
   // push_q(1, 10,rear,n);
    
    node * pt = n;
    while(pt->next != NULL){
        cout<<pt->priority<<" "<<rear[i++]->data<<" -> ";
        pt = pt->next;
    }

	//cout<<"GfG!";
	return 0;
}
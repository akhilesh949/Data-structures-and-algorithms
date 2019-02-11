#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}
/*void PrintSlash(int height)
{
	for(int i = 1; i < height; i++)
	 {
		 cout<<setw(height - i);
		 for(int i = 0; i < height - ; i++)
		 cout<<"/"<<setw(i)<<"\\"<<endl;
	 }
}*/
int height(BinaryTreeNode<int>* root)
{
	if(root == NULL)
	 return 0;

	 else return 1 + max(height(root -> left), height(root -> right));
}

 //1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	queue<BinaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    pendingnodes.push(NULL);
	int h = height(root);
	cout << setw(2*h);
	int i = 0;
	BinaryTreeNode<int>* temp;

    while(pendingnodes.size() > 1)
    {
        BinaryTreeNode<int>* front = pendingnodes.front();
        pendingnodes.pop();

        if(front == NULL)
        {
			if(pendingnodes.empty())
			 break;

            pendingnodes.push(NULL);
            cout<<endl;
              

           cout<<setw((h - i)*2);
		 //  PrintSlash(h - i);
			i++;

			
        }

        else
        {
			 
			 
              cout<<front -> data<<" ";
			  cout<<setw(h - i);

			  if(front -> left)
               pendingnodes.push(front -> left);
              
              if(front -> right)
               pendingnodes.push(front -> right);
			 
			 

             
             

              
        }
    }
	
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{

  BinaryTreeNode<int>* root = takeInputLevelWise();
  printTree(root);
    
    return 0;
}

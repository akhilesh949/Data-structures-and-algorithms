#include<iostream>
#include<queue>
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
  
  queue<BinaryTreeNode<int>*> q;
  q.push(root);
  q.push(NULL);
  while(q.size())
  {
    BinaryTreeNode<int>* front = q.front();
    
    if(front != NULL)
    {
      cout<< front -> data<<" ";
      q.pop();
      if(front -> left != NULL)
       q.push(front -> left);
      
      if(front -> right != NULL)
       q.push(front -> right);
    }
    else
    { 
       q.pop();

      if(q.empty())
        break;
      
      cout<<"\n";
      q.push(NULL);
    }

   }

}




int main()
{

  BinaryTreeNode<int>* root = takeInputLevelWise();
  printTree(root);
    
    return 0;
}

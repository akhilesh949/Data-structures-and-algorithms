#include <iostream>
#include <queue>
using namespace std;


template <typename T>
class BinaryTreeNode {
	public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		delete left;
		delete right;
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



void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}

	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}

BinaryTreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;
	return root;
}


BinaryTreeNode<int>* buildTree_1Helper(int *preorder, int *inorder, int PREs, int PREe, int INs, int INe)
{
  
  if(INs > INe)
    return NULL;
  
  int leftPREs = PREs + 1;
  int leftINs = INs;
  
  int i = INs;
   for(; i <= INe; i++)
  {
    if(inorder[i] == preorder[PREs])
      break;
  }
  
  int leftINe = i - 1; 
  int leftPREe = leftINe - leftINs + leftPREs;
   
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[PREs]);
 
  root -> left = buildTree_1Helper(preorder, inorder, leftPREs, leftPREe, leftINs, leftINe);

  
  int rightPREs = leftPREe + 1;
  int rightPREe = PREe;
  int rightINs = i + 1;
  int rightINe = INe;
  
  root -> right = buildTree_1Helper(preorder, inorder, rightPREs, rightPREe, rightINs, rightINe);
  return root;

}


BinaryTreeNode<int>* buildTree_1(int *preorder, int preLength, int *inorder, int inLength) {
   return buildTree_1Helper(preorder, inorder, 0, preLength - 1, 0, inLength - 1 );


}

BinaryTreeNode<int>* getTreeFromPostorderAndInorderHelper(int *postorder, int *inorder, int POs, int POe, int INs, int INe)
{
  
  if(INs > INe)
    return NULL;
  
  
  int leftPOs = POs;
  int leftINs = INs;
  int i = INs;
  for(; i<= INe; i++)
  {
    if(inorder[i] == postorder[POe])
      break;
  }
  int leftINe = i - 1;
  int leftPOe = leftINe - leftINs + leftPOs;
  
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postorder[POe]);
  root -> left = getTreeFromPostorderAndInorderHelper(postorder, inorder, leftPOs, leftPOe, leftINs, leftINe);
  
  int rightPOs = leftPOe + 1;
  int rightINe = INe;
  int rightINs = i + 1;

  int rightPOe = rightINe - rightINs + rightPOs;
  root -> right = getTreeFromPostorderAndInorderHelper(postorder, inorder, rightPOs, rightPOe, rightINs, rightINe);
  
  
  return root;
}



BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {

  return getTreeFromPostorderAndInorderHelper(postorder, inorder, 0, postLength - 1, 0, inLength - 1);
  

}



int main() {

	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTree(root);
	delete root;
}


#include <iostream>

using namespace std;

struct node
{
	int key;
	node * left;
	node * right;

	node(int k) {
		key = k;
		left = right = NULL;
	}
};

struct BST
{
	node * root;
	int height;
	int cnt;

	BST() {
		cnt = 0;
		height = 0;
		root = NULL;
	}

	node * add(node * root, int x, int h) {

		this->height = max(this->height, h);
		
		if(root == NULL)
		{
			node * n = new node(x);
			root = n;
			cnt++;
		}
		else if(x < root->key)
		{
			root->left = add(root->left, x, h+1);
		}
		else if(x > root->key)
		{
			root->right = add(root->right, x, h+1);
		}
		return root;
	}
};
int main() {
	BST myTree;
	int x, cnt=0;
	while(cin>>x && x!=0)
	{
		myTree.root = myTree.add(myTree.root, x, 1);
	}
	cout << myTree.cnt;
	return 0;
}
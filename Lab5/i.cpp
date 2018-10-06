#include <iostream>
#include <cmath>

using namespace std;
int mx = -1e9-10, mn = 1e9+10, c = 0;
struct node
{
	int key;
	node * left;
	node * right;
	int cnt;
	node(int k) {
		key = k;
		cnt = 1;
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
		else if(x == root->key)
		{
			root->cnt++;
		}
		return root;
	}

	void inorder(node * x, int h) {
		if(x == NULL) {
			return;}
		inorder(x->left, h+1);
		cout << x->key << ' ' << x->cnt << '\n';
		inorder(x->right, h+1);
	}
};

int main() {
	BST myTree;
	int x, cnt=0;
	while(cin>>x && x!=0)
	{
		myTree.root = myTree.add(myTree.root, x, 1);
	}
	myTree.inorder(myTree.root, 1);
	return 0;
}
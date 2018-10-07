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
	int h;

	BST() {
		h = 0;
		root = NULL;
	}

	node * add(node * root, int x, int h) {
		
		this->h = max(this->h, h);
		if(root == NULL)
		{
			node * n = new node(x);
			root = n;
		}
		else if(x <= root->key)
		{
			root->left = add(root->left, x, h+1);
		}
		else 
		{
			root->right = add(root->right, x, h+1);
		}
		return root;
	}

	node * erase(node * root, int x) {
		if(root == NULL) return root;
		else if(x < root->key)
		{
			root->left = erase(root->left, key);
		} 
		else if(x > root->key)
		{
			root->right = erase(root->right, key);
		}
		else
		{
			if(root->left == NULL && root->right == NULL)
			{
				delete root;
				root = NULL;
				return root;
			}
			else if(root->left == NULL)
			{
				node * tmp = root;
				root = root->right;
				delete tmp;
			}
			else if(root->right == NULL)
			{
				node * tmp = root;
				root = root->left;
				delete tmp;
			}
			else
			{
				root->key = root->right->key;
				root = erase(root->right, root->right->key);
			}
		}
		return root;
	}

	bool find(node * root, int x) {
		if(root == NULL) return false;
		else if(root->key == x) return true;
		else if(x < root->key) return find(root->left, x);
		else return find(root->right, x);
	}

	void inorder(node * x) {
		if(x != NULL) {
			inorder(x->left);
			cout << x->key << ' ';
			inorder(x->right);
		}
	}


};
int main() {
	BST mt;

	return 0;
}
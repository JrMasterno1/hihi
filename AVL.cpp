#include <iostream>
#include <algorithm>
using namespace std;
struct NODE{
	int key;
	NODE* left;
	NODE* right;
	int height;
};
NODE* createNODE(int data){
	NODE* p = new NODE();
	p->key = data;
	p->left = NULL;
	p->right = NULL;
	p->height = 1;
	return p;
}
int Height(NODE* root){
	if (!root){
		return 0;
	}
	return root->height;
}
NODE* LR(NODE* root){
	NODE* W = root->left;
	root->left = W->right;
	W->right = root;
	root->height = max(Height(root->left), Height(root->right)) + 1;
	W->height = max(Height(W->left), Height(root)) + 1;
	return W;
}
NODE* RL(NODE* root){
	NODE* W = root->right;
	root->right = W->left;
	W->left = root;
	root->height = max(Height(root->left), Height(root->right)) + 1;
	W->height = max(Height(W->right), Height(root)) + 1;
	return W;
}
NODE* balanceTree(NODE* root){
	if (Height(root->right) - Height(root->left) >= 2){ // right > left
		if (Height(root->right->right) > Height(root->right->left)){ // right  right case
				root = RL(root);
			}
			else {
				root->right = LR(root->right);
				root = RL(root);
			}
		}
	else if (Height(root->left) - Height(root->right) == 2){ // left > right
		if (Height(root->left->left) > Height(root->left->right)){ // left left case
				root = LR(root);
			}
			else {
				root->right = RL(root->right);
				root = LR(root);
			}
		}
	return root;
}
NODE* Insert(NODE* root, int x){
	if (root == NULL){
		root = createNODE(x);
		root->height = 1;
	}
	else{
		if (x > root->key){
			root->right = Insert(root->right, x);
		}
		else {
			root->left = Insert(root->left, x);
		}
		root = balanceTree(root);
	}
	root->height = max(Height(root->right), Height(root->left)) + 1;
	return root;
}
int main(){
	NODE* root = NULL;
	int a[] = { 30, 100, 120, 45, 50, 25 };
	for (int i = 0; i < 3; ++i){
		root = Insert(root, a[i]);
	}
	cout << root->height << endl;
	return 0;
}

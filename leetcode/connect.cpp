struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL){}

};


void connect(TreeLinkNode *root){
	if(root == NULL) return;
	else{
		if(root->left) root->left->next = root->right;
		else return;

		if(root->left->right)
			root->left->right->next = root->right->left;
		connect(root->left);
		connect(root->right);
	}
}

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode()
		: val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x)
		: val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& preorder, int left, int right)
{
	if (left > right) return nullptr;

	int idx{ left };
	while (idx <= right && preorder[idx] <= preorder[left]) {
		idx++;
	}
	TreeNode* root = new TreeNode(preorder[left]);
	root->left = buildTree(preorder, left + 1, idx - 1);
	root->right = buildTree(preorder, idx, right);
	return root;
}

void PostOrderTraversal(const TreeNode* root)
{
	if (root) {
		if (root->left) PostOrderTraversal(root->left);
		if (root->right) PostOrderTraversal(root->right);
		cout << root->val << endl;
	}
}

int main()
{
	vector<int> preorder;
	int tmp{ 0 };
	while (cin >> tmp) {
		preorder.push_back(tmp);
	}
	TreeNode* root = buildTree(preorder, 0, preorder.size() - 1);
	PostOrderTraversal(root);
	return 0;
}

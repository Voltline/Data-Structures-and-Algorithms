#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode
{
	int val;
	int cumsum;
	TreeNode* left;
	TreeNode* right;
};

vector<const TreeNode*> leaves;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	if (postorder.size() == 0) return nullptr;
	int val{ postorder[postorder.size() - 1] };
	TreeNode* root = new TreeNode{ val, val, nullptr, nullptr };
	if (postorder.size() == 1) return root;

	int k{ 0 };
	while (inorder[k] != val) k++;
	vector<int> leftInorder{ inorder.begin(), inorder.begin() + k };
	vector<int> rightInorder{ inorder.begin() + k + 1, inorder.end() };
	postorder.resize(postorder.size() - 1);

	vector<int> leftPostorder{ postorder.begin(), postorder.begin() + leftInorder.size() };
	vector<int> rightPostorder{ postorder.begin() + leftInorder.size(), postorder.end() };
	root->left = buildTree(leftInorder, leftPostorder);
	root->right = buildTree(rightInorder, rightPostorder);
	return root;
}

void PreOrderCumsum(TreeNode* root)
{
	if (root) {
		if (root->left) {
			root->left->cumsum = root->cumsum + root->left->val;
			PreOrderCumsum(root->left);
		}
		if (root->right) {
			root->right->cumsum = root->cumsum + root->right->val;
			PreOrderCumsum(root->right);
		}
	}
}

void PreOrderTraversal(const TreeNode* root)
{
	if (root) {
		if (root->left) {
			PreOrderTraversal(root->left);
		}
		if (root->right) {
			PreOrderTraversal(root->right);
		}
		if (!root->left && !root->right) {
			leaves.push_back(root);
		}
	}
}

int main()
{
	int in{ 0 };
	vector<int> inorder, postorder;
	string line;
	getline(cin, line);
	istringstream sin(line);
	while (sin >> in) {
		inorder.push_back(in);
	}
	getline(cin, line);
	sin = istringstream{ line };
	while (sin >> in) {
		postorder.push_back(in);
	}
	TreeNode* root{ buildTree(inorder, postorder) };
	PreOrderCumsum(root);
	PreOrderTraversal(root);
	const TreeNode* min_rt{ leaves[0]};
	for (int i = 0; i < leaves.size(); i++) {
		if (leaves[i]->cumsum < min_rt->cumsum) {
			min_rt = leaves[i];
		}
		else if (leaves[i]->cumsum == min_rt->cumsum) {
			if (leaves[i]->val < min_rt->val) {
				min_rt = leaves[i];
			}
		}
	}
	cout << min_rt->val << endl;
	return 0;
}

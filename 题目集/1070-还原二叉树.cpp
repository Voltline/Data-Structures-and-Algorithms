#include <iostream>
#include <string>
using namespace std;

struct BinaryTreeNode
{
	char c;
	BinaryTreeNode* lchild;
	BinaryTreeNode* rchild;

	BinaryTreeNode()
		: c(0), lchild(nullptr), rchild(nullptr) {}
};

void buildTree(BinaryTreeNode*& root, const string& preorder, const string& inorder)
{
	if (inorder.size() == 0) {
		return;
	}
	root = new BinaryTreeNode;
	int k{ 0 };
	while (preorder[0] != inorder[k]) k++;
	root->c = inorder[k];
	buildTree(root->lchild, preorder.substr(1, k), inorder.substr(0, k));
	buildTree(root->rchild, preorder.substr(k+1, 100), inorder.substr(k+1, 100));
}

int BinaryTreeDepth(BinaryTreeNode* root)
{
	if (!root) return 0;
	else {
		if ((!root->lchild) && (!root->rchild)) return 1;
		else {
			int hL = BinaryTreeDepth(root->lchild);
			int rL = BinaryTreeDepth(root->rchild);
			return max(hL, rL) + 1;
		}
	}
}

int main()
{
	BinaryTreeNode* root{ nullptr };
	int N{ 0 };
	cin >> N;
	string preorder, inorder;
	cin >> preorder >> inorder;
	buildTree(root, preorder, inorder);
	cout << BinaryTreeDepth(root) << endl;
	return 0;
}

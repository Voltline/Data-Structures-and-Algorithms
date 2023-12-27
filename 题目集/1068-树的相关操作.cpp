#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
	TreeNode* parent;
	int data;
	int level;
	vector<TreeNode*> child;
};

struct BasicTreeNode
{
	int idx;
	int parent;

	bool operator<(const BasicTreeNode& btn) const
	{
		return idx < btn.idx;
	}
};

void PreOrder(const TreeNode* root)
{
	if (root) {
		cout << root->data << " ";
		for (int i = 0; i < root->child.size(); i++) {
			PreOrder(root->child[i]);
		}
	}
}

void PostOrder(const TreeNode* root)
{
	if (root) {
		for (int i = 0; i < root->child.size(); i++) {
			PostOrder(root->child[i]);
		}
		cout << root->data << " ";
	}
}

void LevelOrder(const TreeNode* root)
{
	queue<const TreeNode*> q;
	const TreeNode* t{ nullptr };
	if (!root) return;
	q.push(root);
	while (!q.empty()) {
		t = q.front();
		q.pop();
		cout << t->data << " ";
		for (int i = 0; i < t->child.size(); i++) {
			q.push(t->child[i]);
		}
	}
}

void LevelAssign(TreeNode* root)
{
	if (root->parent) {
		root->level = root->parent->level + 1;
	}
	else {
		root->level = 0;
	}
	for (int i = 0; i < root->child.size(); i++) {
		LevelAssign(root->child[i]);
	}
}

void LeavesOrder(const TreeNode* root)
{
	if (root) {
		if (root->child.size() == 0) {
			cout << root->data << " ";
		}
		for (int i = 0; i < root->child.size(); i++) {
			LeavesOrder(root->child[i]);
		}
	}
}

int leaves(const vector<TreeNode*>& tree)
{
	int ans{ 0 };
	for (int i = 0; i < tree.size(); i++) {
		if (tree[i]->child.size() == 0) {
			ans++;
		}
	}
	return ans;
}

int height(const vector<TreeNode*>& tree)
{
	int ans{ 0 };
	for (int i = 0; i < tree.size(); i++) {
		if (tree[i]->level > ans) {
			ans = tree[i]->level;
		}
	}
	return ans;
}

int main()
{
	vector<TreeNode*> tree;
	vector<BasicTreeNode> btree;
	TreeNode* root{ nullptr };
	int idx{ 0 }, parent{ 0 }, cnt{ 0 };
	while (cin >> idx >> parent) {
		btree.push_back(BasicTreeNode{ idx, parent });
		tree.push_back(new TreeNode{ nullptr, idx, 0, vector<TreeNode*>{} });
		cnt++;
	}
	sort(btree.begin(), btree.end());
	for (int i = 0; i < cnt; i++) {
		if (btree[i].parent != -1) {
			tree[i]->parent = tree[btree[i].parent-1];
			tree[btree[i].parent-1]->child.push_back(tree[i]);
		}
		else {
			root = tree[i];
		}
	}
	LevelAssign(root);
	PreOrder(root);
	cout << endl;
	PostOrder(root);
	cout << endl;
	LevelOrder(root);
	cout << endl << cnt << endl;
	LeavesOrder(root);
	cout << endl << leaves(tree) << endl << height(tree);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct TreeNode
{
	TreeNode* parent;
	char c;
	vector<TreeNode*> child;
};

struct LevelTreeNode
{
	int level;
	char c;
};

void PostOrder(const TreeNode* root)
{
	if (!root->child.empty()) {
		for (int i = 0; i < root->child.size(); i++) {
			PostOrder(root->child[i]);
		}
		cout << root->c;
	}
	else cout << root->c;
}

void buildTree(vector<TreeNode*>& nodes, vector<LevelTreeNode*> lnodes)
{
	int current_level{ 1 };
	nodes[0]->c = lnodes[0]->c;
	TreeNode* last_root{ nodes[0] };
	for (int i = 1; i < lnodes.size(); i++) {
		if (lnodes[i]->level == current_level) {
			nodes[i]->parent = last_root;
			nodes[i]->c = lnodes[i]->c;
			last_root->child.push_back(nodes[i]);
		}
		else {
			if (lnodes[i]->level > current_level) {
				last_root = *(last_root->child.begin() + last_root->child.size() - 1);
				current_level = lnodes[i]->level;
				nodes[i]->parent = last_root;
				nodes[i]->c = lnodes[i]->c;
				last_root->child.push_back(nodes[i]);
			}
			else {
				int dif{ current_level - lnodes[i]->level };
				while (dif != 0) {
					last_root = last_root->parent;
					dif--;
				}
				current_level = lnodes[i]->level;
				nodes[i]->parent = last_root;
				nodes[i]->c = lnodes[i]->c;
				last_root->child.push_back(nodes[i]);
			}
		}
	}
}

int main()
{
	int n{ 0 }, in{ 0 };
	cin >> n;
	getchar();
	vector<TreeNode*> nodes;
	vector<LevelTreeNode*> lnodes;
	for (int i = 0; i < n; i++) {
		nodes.push_back(new TreeNode{ nullptr, 0, vector<TreeNode*>{} });
	}
	int level{ 0 }, p{ -1 };
	char c{ 0 };
	for (int i = 0; i < n; i++) {
		scanf("(%d,%c)", &level, &c);
		lnodes.push_back(new LevelTreeNode{ level, c });
		getchar();
	}
	buildTree(nodes, lnodes);

	PostOrder(nodes[0]);
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int idx;
	vector<TreeNode*> child;
};

void PostOrder(const TreeNode* root)
{
	if (!root->child.empty()) {
		for (int i = 0; i < root->child.size(); i++) {
			PostOrder(root->child[i]);
		}
		cout << root->idx << " ";
	}
	else cout << root->idx << " ";
}

int main()
{
	int n{ 0 }, in{ 0 };
	cin >> n;
	vector<int> parent(n);
	vector<TreeNode*> nodes;
	for (int i = 0; i < n; i++) {
		nodes.push_back(new TreeNode{ i, vector<TreeNode*>{} });
	}
	for (int i = 0; i < n; i++) {
		cin >> in;
		parent[i] = in;
		if (in != -1) {
			nodes[in]->child.push_back(nodes[i]);
		}
	}
	PostOrder(nodes[0]);
	return 0;
}

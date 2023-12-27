#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode
{
	string name;
	vector<TreeNode*> child;
	bool tag; // true for dir, false for file

	TreeNode(const string& s, bool tag1 = true)
		: name(s), child(vector<TreeNode*>()), tag(tag1) {}
};

struct node
{
	string name;
	bool tag; // true for dir, false for file
};

bool cmp(const TreeNode* t1, const TreeNode* t2)
{
	if (t1->tag != t2->tag) return t1->tag > t2->tag;
	else return t1->name < t2->name;
}

void PreOrderTraversalSort(TreeNode* root)
{
	if (root) {
		sort(root->child.begin(), root->child.end(), cmp);
		for (auto ptr : root->child) {
			PreOrderTraversalSort(ptr);
		}
	}
}

void PreOrderTraversal(const TreeNode* root, int depth = 0)
{
	if (root) {
		for (int i = 0; i < depth; i++) cout << "  ";
		cout << root->name << endl;
		for (int i = 0; i < root->child.size(); i++) {
			PreOrderTraversal(root->child[i], depth + 1);
		}
	}
}

int main()
{
	TreeNode* root{ new TreeNode{ "root" } };
	int n{ 0 };
	cin >> n;
	string line;
	for (int i = 0; i < n; i++) {
		TreeNode* tree_ptr{ root };
		cin >> line;
		string sline{ line };
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '\\') {
				line[i] = ' ';
			}
		}
		istringstream sin(line);
		string name;
		vector<node> allf;
		while (sin >> name) {
			allf.push_back(node{ name, true });
		}
		if (sline[sline.size() - 1] != '\\') {
			allf[allf.size() - 1].tag = false;
		}
		for (auto& ptr : allf) {
			bool isFind{ false };
			for (int i = 0; i < tree_ptr->child.size(); i++) {
				if (tree_ptr->child[i]->name == ptr.name && tree_ptr->child[i]->tag == ptr.tag) {
					isFind = true;
					tree_ptr = tree_ptr->child[i];
					break;
				}
			}
			if (!isFind) {
				tree_ptr->child.push_back(new TreeNode{ ptr.name, ptr.tag });
				if (!ptr.tag) break;
				tree_ptr = tree_ptr->child[tree_ptr->child.size() - 1];
			}
		}
	}
	PreOrderTraversalSort(root);
	PreOrderTraversal(root);
	return 0;
}

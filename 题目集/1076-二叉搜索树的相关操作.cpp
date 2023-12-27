#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct binarySortTree {
    int data;                       /**<结点键值 */
    struct binarySortTree* lchild;  /**<左子节点 */
    struct binarySortTree* rchild;  /**<右子节点 */
} BSTNODE;

int cnt{ 0 };

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void rec_buildTree(BSTNODE*& root, int data)
{
    if (!root) {
        root = new BSTNODE{ data, nullptr, nullptr };
    }
    else {
        if (data < root->data) {
            rec_buildTree(root->lchild, data);
        }
        else {
            rec_buildTree(root->rchild, data);
        }
    }
}

BSTNODE* buildTree(int* nodeArr, int arrSize)
{
    BSTNODE* root{ new BSTNODE{nodeArr[0], nullptr, nullptr} };
    for (int i = 1; i < arrSize; i++) {
        rec_buildTree(root, nodeArr[i]);
    }
    return root;
}

int depth(const BSTNODE* root)
{
    if (!root) return 0;
    return max(depth(root->lchild), depth(root->rchild)) + 1;
}

int count(const BSTNODE* root)
{
    if (!root) return 0;
    return count(root->lchild) + count(root->rchild) + 1;
}

void PreOrderTraversal(const BSTNODE* root, int level = 1)
{
    if (!root) return;
    cnt += level;
    PreOrderTraversal(root->lchild, level + 1);
    PreOrderTraversal(root->rchild, level + 1);
}

bool isBalance(BSTNODE* root)
{
    if (!root) return true;
    return abs(depth(root->lchild) - depth(root->rchild)) <= 1
        && isBalance(root->lchild)
        && isBalance(root->rchild);
}

void printAVG(BSTNODE* root)
{
    cnt = 0;
    PreOrderTraversal(root);
    printf("%.2f\n", cnt * 1.0 / count(root));
}

int main()
{
    int nodeArr[100]{ 0 };
    int arrSize{ 0 };
    cin >> arrSize;
    for (int i = 0; i < arrSize; i++) {
        int in{ 0 };
        cin >> in;
        nodeArr[i] = in;
    }
    BSTNODE* root{ buildTree(nodeArr, arrSize) };
    cout << root->data << endl;
    cout << isBalanced(root) << endl;
    printAVG(root);
    return 0;
}

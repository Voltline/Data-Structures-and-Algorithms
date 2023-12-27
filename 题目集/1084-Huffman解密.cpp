#include <iostream>
#include <string>
#include <string.h>

typedef struct huffnode {
    char data; // 值
    struct huffnode* leftChild; // 左子树
    struct huffnode* rightChild; // 右子树
    /* 其他成员变量，细节隐藏不表 */
} HUFFNODE;

void decipherHuffmanCoding(HUFFNODE* head, char cipher[])
{
    HUFFNODE* ptr{ head };
    int len = strlen(cipher);
    for (int i = 0; i <= len; i++) {
        if (ptr->leftChild || ptr->rightChild) {
            if (cipher[i] == '0') ptr = ptr->leftChild;
            else ptr = ptr->rightChild;
        }
        else {
            i--;
            printf("%c", ptr->data);
            ptr = head;
        }
    }
}

int main()
{

    return 0;
}
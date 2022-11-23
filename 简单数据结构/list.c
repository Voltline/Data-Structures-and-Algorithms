#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int value;
	struct _node* next;
} Node;

typedef Node* List;

void init(List list, int num)
{
	list->value = num;
	list->next = NULL;
}

void add_head(List* ListPtr, int num)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->next = *ListPtr;
	new->value = num;
	*ListPtr = new;
}
void add_tail(List list, int num)
{
	Node* next = (Node*)malloc(sizeof(Node));
	next->next = NULL;
	next->value = num;
	Node* temp = list;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = next;
}
void insert(List list, int index, int num)
{
	int cnt = 0, check = 0;
	Node* NodePtr = list;
	while (NodePtr) {
		if (cnt != index) {
			cnt++;
			NodePtr = NodePtr->next;
		}
		else {
			Node* temp = (Node*)malloc(sizeof(Node));
			temp->value = num;
			temp->next = NodePtr->next;
			NodePtr->next = temp;
			check = 1;
			break;
		}
	}
	if (!check) {
		printf("Insert Failed! Index out of range!\n");
	}
}

void print(List list)
{
	for (Node* it = list; it != NULL; it = it->next) {
		printf("%d ", it->value);
	}
	printf("\n");
}

Node* search(List list, int num)
{
	for (Node* it = list; it != NULL; it = it->next) {
		if (it->value == num) {
			return it;
		}
	}
	printf("Search Failed! Not Found!\n");
	return NULL;
}

int remove_head(List* listPtr)
{
	if ((*listPtr)->next != NULL) {
		Node* temp = (*listPtr);
		(*listPtr) = (*listPtr)->next;
		free(temp);
		return 1;
	}
	else {
		printf("Remove Error! Head Node is the only Node!\n");
		return 0;
	}
}
int remove_tail(List* listPtr)
{
	Node* NodePtr = *listPtr;
	if (NodePtr->next != NULL) {
		while (NodePtr->next->next) {
			NodePtr = NodePtr->next;
		}
		free(NodePtr->next);
		NodePtr->next = NULL;
		return 1;
	}
	else {
		printf("Delete Failed!\n");
		return 0;
	}
}
int remove_num(List* ListPtr, int num)
{
	int check = 0;
	for (Node* it = *ListPtr; it->next != NULL; it = it->next) {
		if (it->next->value == num) {
			Node* temp = it->next->next;
			free(it->next);
			it->next = temp;
			check = 1;
			break;
		}
	}
	if (!check) {
		printf("Delete Failed!\n");
		return 0;
	}
	return 1;
}
int remove_index(List* ListPtr, int index)
{
	int cnt = 0, check = 0;
	if (index != 0) {
		for (Node* it = *ListPtr; it != NULL; it = it->next) {
			if (cnt + 1 == index) {
				Node* temp = it->next->next;
				free(it->next);
				it->next = temp;
				check = 1;
				break;
			}
			cnt++;
		}
	}
	else {
		check = remove_head(ListPtr);
	}

	if (!check) {
		printf("Delete Failed!\n");
		return 0;
	}
	return 1;
}

void all_free(List* listPtr)
{
	Node* p = *listPtr;
	Node* q = (*listPtr)->next;
	while (q->next) {
		free(p);
		p = q;
		q = p->next;
	}
	free(q);
}

int main()
{
	List list = (List)malloc(sizeof(Node));
	init(list, 10);
	for (int i = 0; i < 14; i++) {
		add_head(&list, rand() % 100);
	}
	print(list);
	remove_head(&list);
	insert(list, 0, 1203);
	print(list);
	remove_index(&list, 0);
	remove_num(&list, 10);

	print(list);
	Node* node = search(list, 12);
	if (node) {
		printf("node->value = %d\n", node->value);
	}
	
	all_free(&list);
	return 0;
}
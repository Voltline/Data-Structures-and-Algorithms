NODE* insertLinklist(NODE* head, int tar, int val)
{
	NODE* p = (NODE*)malloc(sizeof(NODE)), * q = head;
	p->next = nullptr;
	p->data = val;
	if (head) {
		while (q->next && q->data != tar) q = q->next;
		p->next = q->next;
		q->next = p;
		return head;
	}
	return p;
}

NODE* deleteLinklist(NODE* head, int tar)
{
	NODE* p{ nullptr }, * q{ head }, * r{ nullptr };
	if (head) {
		while (q && q->next && q->data != tar) p = q, q = q->next;
		if (q) {
			if (p) {
				p->next = q->next;
				free(q);
			}
			else {
				p = q->next;
				free(q);
				return p;
			}
		}
	}
	return head;
}

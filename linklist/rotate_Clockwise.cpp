#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};
void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " -> ";
		node = node->next;
	}
	cout << "NULL";
}
Node* rightRotate(Node* head, int k)
{
	if (!head)
		return head;
	Node* tmp = head;
	int len = 1;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		len++;
	}
	if (k > len)
		k = k % len;
	k = len - k;
	if (k == 0 || k == len)
		return head;
	Node* current = head;
	int cnt = 1;
	while (cnt < k && current != NULL) {
		current = current->next;
		cnt++;
	}
	if (current == NULL)
		return head;
	Node* kthnode = current;
	tmp->next = head;
	head = kthnode->next;
	kthnode->next = NULL;
	return head;
}

int main()
{
	Node* head = NULL;
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	int k = 12;
	Node* updated_head = rightRotate(head, k);
	printList(updated_head);
	return 0;
}

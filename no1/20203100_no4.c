#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node* link;
}Linkedlist;

Linkedlist* createnode() { //�����Ҵ� �Լ� 
	Linkedlist* newnode = (Linkedlist*)malloc(sizeof(Linkedlist));
	newnode->link = NULL;
	return newnode;
}

Linkedlist* FindNode(Linkedlist* head, int pos) { // �����ϴ� ����� ���� ��带 ã�� �Լ�
	int i = 0;
	Linkedlist* tmp = head;
	for (i = 2;i < pos;i++) { //pos �ٷ� ������ Ÿ�� ���鼭 ������ ����
		tmp = tmp->link;
	}
	return tmp;
}

void Setinsert(Linkedlist** head, int value) { //�ʱ� ����Ʈ �� ����
	if (*head == NULL) {
		*head = createnode();
		(*head)->data = value;
		return;
	}
	Setinsert(&(*head)->link, value); //����Լ��� Ÿ���鼭 ���Է�
}

void Delete(Linkedlist* head, int pos) {
	Linkedlist* deletenode;
	Linkedlist* prenode = FindNode(head, pos); //������
	int deletedata;
	if (pos == 1) { // ���� ����� ù��° ����϶� 
		deletenode = head->link;
		head->link= deletenode->link;
		head->data = deletenode -> data;
		free(deletenode);
		return;
	}
	else {
		if (pos > 0 && pos <= 5) { //���Ŵ���� ù��° ��尡 �ƴҶ� 
			deletenode = prenode->link;
			prenode->link = deletenode->link;
			free(deletenode);
		}
	}
}

void PrintList(Linkedlist* head) {
	while (head != NULL) { //head �� NUL�� �� ������ Ÿ�� ���鼭 ���
		printf("%d ", head->data);
		head = head->link;
	}
	printf("\n");
}

int main() {
	Linkedlist* head = NULL;
	int value = 0, i = 0, pos = 0;

	printf("Enter 5 elements in array : ");
	for (i = 0;i < 5;i++) {
		scanf("%d", &value);
		Setinsert(&head, value);
	}
	printf("Stored element in array : ");
	PrintList(head);
	printf("Enter poss. of element to delete : "); scanf("%d", &pos);
	Delete(head, pos);
	printf("After deletion elements in array : ");
	PrintList(head);

}

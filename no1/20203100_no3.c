#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node* link;
}Linkedlist;

Linkedlist* createnode() {
	Linkedlist* newnode = (Linkedlist*)malloc(sizeof(Linkedlist));
	newnode->link = NULL;
	return newnode;
}

Linkedlist* FindNode(Linkedlist* head, int pos) { //��� ����� ������ ã�� �Լ�
	int i = 0;
	Linkedlist* tmp = head;
	if (pos == 2) {
		return tmp;
	}
	for (i = 2;i < pos;i++) {
		tmp = tmp->link;
	}
	return tmp;
}

void Setinsert(Linkedlist** head, int value) {//���鸮��Ʈ�϶�
	if (*head == NULL) {
		*head = createnode();
		(*head)->data = value;
		return;
	}
	Setinsert(&(*head)->link, value); //����Լ��� ��帵ũ Ÿ�� ���鼭 �ʱ� ��� ����
}

void insert(Linkedlist* head, int pos, int value) {
	Linkedlist* newnode = createnode();
	if (pos == 1) { //ù��° �����϶� 
		newnode->data = value;
		newnode->link = head;
		head = newnode;
	}
	else {								// �׿� ���Զ�
		if (pos > 0 && pos <= 5) { 
			
			Linkedlist* prenode = FindNode(head, pos);
			newnode->data = value;
			newnode->link = prenode->link;
			prenode->link = newnode;
			
		}
		else {
			printf("position is wrong");
		}
	}
}

void PrintList(Linkedlist* head) { //����Ʈ �� ��ü ��� �Լ�
	printf("Stored element in array : ");
	while (head != NULL) {  //head�� ���� �ɶ����� Ÿ���鼭 ���
		printf("%d ", head->data);
		head = head->link;
	}
	printf("\n");
}

int main() {
	Linkedlist* head = NULL;
	int value = 0, i = 0, pos = 0, size = 0;

	printf("Enter 5 elements in array : ");
	for (i = 0;i < 5;i++) {
		scanf("%d", &value);
		Setinsert(&head,value);
		size++;
	}
	PrintList(head);
		printf("Enter position for enter element : "); scanf("%d", &pos);
		printf("Enter new element : "); scanf("%d", &value);
		insert(head, pos, value);
		size++;
	PrintList(head);

}

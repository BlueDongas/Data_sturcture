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

Linkedlist* FindNode(Linkedlist* head, int pos) { //대상 노드의 선행노드 찾는 함수
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

void Setinsert(Linkedlist** head, int value) {//공백리스트일때
	if (*head == NULL) {
		*head = createnode();
		(*head)->data = value;
		return;
	}
	Setinsert(&(*head)->link, value); //재귀함수로 노드링크 타고 가면서 초기 노드 설정
}

void insert(Linkedlist* head, int pos, int value) {
	Linkedlist* newnode = createnode();
	if (pos == 1) { //첫번째 삽입일때 
		newnode->data = value;
		newnode->link = head;
		head = newnode;
	}
	else {								// 그외 삽입때
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

void PrintList(Linkedlist* head) { //리스트 값 전체 출력 함수
	printf("Stored element in array : ");
	while (head != NULL) {  //head가 널이 될때까지 타고가면서 출력
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

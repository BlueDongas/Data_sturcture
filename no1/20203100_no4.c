#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node* link;
}Linkedlist;

Linkedlist* createnode() { //동적할당 함수 
	Linkedlist* newnode = (Linkedlist*)malloc(sizeof(Linkedlist));
	newnode->link = NULL;
	return newnode;
}

Linkedlist* FindNode(Linkedlist* head, int pos) { // 제거하는 노드의 선행 노드를 찾는 함수
	int i = 0;
	Linkedlist* tmp = head;
	for (i = 2;i < pos;i++) { //pos 바로 전까지 타고 가면서 선행노드 리턴
		tmp = tmp->link;
	}
	return tmp;
}

void Setinsert(Linkedlist** head, int value) { //초기 리스트 값 설정
	if (*head == NULL) {
		*head = createnode();
		(*head)->data = value;
		return;
	}
	Setinsert(&(*head)->link, value); //재귀함수로 타고가면서 값입력
}

void Delete(Linkedlist* head, int pos) {
	Linkedlist* deletenode;
	Linkedlist* prenode = FindNode(head, pos); //선행노드
	int deletedata;
	if (pos == 1) { // 제가 대상이 첫번째 노드일때 
		deletenode = head->link;
		head->link= deletenode->link;
		head->data = deletenode -> data;
		free(deletenode);
		return;
	}
	else {
		if (pos > 0 && pos <= 5) { //제거대상이 첫번째 노드가 아닐때 
			deletenode = prenode->link;
			prenode->link = deletenode->link;
			free(deletenode);
		}
	}
}

void PrintList(Linkedlist* head) {
	while (head != NULL) { //head 가 NUL이 될 때까지 타고 가면서 출력
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

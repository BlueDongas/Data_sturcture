#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Queue;

Queue* createnode() { //동적할당
	Queue* newnode = (Queue*)malloc(sizeof(Queue));
	newnode->link = NULL;
	return newnode;
}

void insertion(Queue** front, Queue** rear, int data,int* size) {
	(*size) += 1; //큐의 크기를 제한하기 위해 만든 변수
	if (*front == NULL) {
		*front = createnode();
		(*front)->data = data;
		*rear = *front;
		printf("Successfully Insert");
	}
	else if (*size == 4) { //큐의 사이즈가 4가되면 사이즈값 -1 하고 노드추가 X
		(*size)-=1;
		printf("Queue is Full\n");
		return;
	}
	else{
		Queue* tmp = *rear;
		*rear = createnode();
		(*rear)->data = data;
		tmp->link = *rear;
		printf("Successfully Insert");
	}
}

int Deletion(Queue** front,int* size) {
	if (*front == NULL) { //front값이 비었을때 즉 큐가 비었을때
		printf("Queue is Empty\n");
		return -1;
	}

	Queue* tmp = *front; //front 백업
	int deletedata = (*front)->data; //삭제되는 데이터 백업
	*front = (*front)->link;
	free(tmp); //할당해제
	(*size) -= 1; // 노드 없어졌으니 size -1
	return deletedata; //삭제된 데이터 리턴
}

void Display(Queue* front) {
	printf("Items : ");
	while (front != NULL) { //front가 널이 될때까지 링크 타고가면서 출력
		printf("%d ",front->data);
		front = front->link;
	}
}

int main() {
	Queue* front = NULL;
	Queue* rear = NULL;
	int menu = 0,value = 0, size = 0; //큐의 사이즈를 재기 위한 size 변수

	while (1) {
		printf("\n");
		printf("1. Insertion\n");
		printf("2. Deletion\n");
		printf("3. Display\n");
		printf("0. Exit\n\n");
		printf("Select Option : "); scanf("%d", &menu);

		switch (menu){
		case 1:
			printf("Element : "); scanf("%d",&value);
			insertion(&front, &rear, value,&size);
			break;
		case 2:
			printf("Deleted item : %d",Deletion(&front,&size));
			break;
		case 3:
			Display(front);
			break;
		case 0:
			return;
		default:
			printf("retry");
			break;
		}
	}

}
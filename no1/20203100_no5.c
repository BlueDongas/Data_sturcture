#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Queue;

Queue* createnode() { //�����Ҵ�
	Queue* newnode = (Queue*)malloc(sizeof(Queue));
	newnode->link = NULL;
	return newnode;
}

void insertion(Queue** front, Queue** rear, int data,int* size) {
	(*size) += 1; //ť�� ũ�⸦ �����ϱ� ���� ���� ����
	if (*front == NULL) {
		*front = createnode();
		(*front)->data = data;
		*rear = *front;
		printf("Successfully Insert");
	}
	else if (*size == 4) { //ť�� ����� 4���Ǹ� ����� -1 �ϰ� ����߰� X
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
	if (*front == NULL) { //front���� ������� �� ť�� �������
		printf("Queue is Empty\n");
		return -1;
	}

	Queue* tmp = *front; //front ���
	int deletedata = (*front)->data; //�����Ǵ� ������ ���
	*front = (*front)->link;
	free(tmp); //�Ҵ�����
	(*size) -= 1; // ��� ���������� size -1
	return deletedata; //������ ������ ����
}

void Display(Queue* front) {
	printf("Items : ");
	while (front != NULL) { //front�� ���� �ɶ����� ��ũ Ÿ���鼭 ���
		printf("%d ",front->data);
		front = front->link;
	}
}

int main() {
	Queue* front = NULL;
	Queue* rear = NULL;
	int menu = 0,value = 0, size = 0; //ť�� ����� ��� ���� size ����

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
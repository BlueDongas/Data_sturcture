#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Stack;

Stack* createnode() { //��� �����Ҵ�
	Stack* newnode = (Stack*)malloc(sizeof(Stack));
	newnode->link = NULL; //���� �������� ���� ����� ��ũ�� NULL �� ���ϰ�
	return newnode;
}

void push(Stack** top, int value) {
	Stack* tmp = *top; //top ���
	*top = createnode(); //�����Ҵ�
	(*top)->data = value;
	(*top)->link = tmp; //���ο� top�� ��ũ�� ��top�� ����� �ּҸ� ���ϰ�
}

int pop(Stack** top) {
	int popdata;
	if (*top == NULL) { //������ �������
		printf("Stack is empty");
		return -1;
	}
	Stack* tmp = *top;
	popdata = (*top)->data;
	*top = (*top)->link;
	free(tmp); //�Ҵ� ����
	return popdata;
}

int AskPush(Stack** top) { //push �Ұ��� ����� �Լ�
	char answer;
	int value;
	
	while (1) {
		getchar(); //�Է¹��� ���Ƽ� ���
		printf("Pushed an element (y/n)"); scanf(" %c", &answer);
		if (answer == 'y') {
			printf("Enter element in stack : "); scanf("%d", &value);
			push(&(*top), value);//(*top)���� �ּҸ� �Ѱ��ش�.
		}
		else if (answer == 'n')
			return -1;
		else printf("retry\n");
		
	}
}

void Display(Stack* top) {//���� ��忡�� ������ �Ȱ��Բ�
	while (top != NULL) { //top�� null�� �ɶ����� link�� ��� Ÿ���鼭 ���
		printf("%d\n",top->data);
		top = top->link;
	}
}

int main() {
	Stack* top = NULL;
	int menu = 0, value = 0;
	char answer;

	while (1) {
		printf("\n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. display\n");
		printf("4. exit\n");
		printf("enter your choice : "); scanf("%d", &menu);
		printf("\n");

		switch (menu){
		case 1:
			while (1) {
				printf("Enter element in stack : "); scanf("%d", &value);
				getchar(); //���� ���ֱ�
				push(&top, value);
				printf("Pushed an element (y/n)"); scanf(" %c", &answer);
				if (answer == 'y') {
					continue;
				}
				else if (answer == 'n')
					break;
				else printf("retry\n");
			}
			break;
		case 2:
			printf("delete data is %d\n\n", pop(&top));
			AskPush(&top);
			break;
		case 3:
			Display(top);
			AskPush(&top);
			break;
		case 4:
			return;
		default:
			printf("retry\n");
			break;
		}
	}
}
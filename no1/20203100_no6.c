#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Stack;

Stack* createnode() { //노드 동적할당
	Stack* newnode = (Stack*)malloc(sizeof(Stack));
	newnode->link = NULL; //가장 마지막에 넣은 노드의 링크가 NULL 을 향하게
	return newnode;
}

void push(Stack** top, int value) {
	Stack* tmp = *top; //top 백업
	*top = createnode(); //동적할당
	(*top)->data = value;
	(*top)->link = tmp; //새로운 top의 링크가 전top의 노드의 주소를 향하게
}

int pop(Stack** top) {
	int popdata;
	if (*top == NULL) { //스택이 비었을때
		printf("Stack is empty");
		return -1;
	}
	Stack* tmp = *top;
	popdata = (*top)->data;
	*top = (*top)->link;
	free(tmp); //할당 해제
	return popdata;
}

int AskPush(Stack** top) { //push 할건지 물어보는 함수
	char answer;
	int value;
	
	while (1) {
		getchar(); //입력버퍼 남아서 비움
		printf("Pushed an element (y/n)"); scanf(" %c", &answer);
		if (answer == 'y') {
			printf("Enter element in stack : "); scanf("%d", &value);
			push(&(*top), value);//(*top)값의 주소를 넘겨준다.
		}
		else if (answer == 'n')
			return -1;
		else printf("retry\n");
		
	}
}

void Display(Stack* top) {//실제 노드에는 영향이 안가게끔
	while (top != NULL) { //top이 null이 될때까지 link를 계속 타고가면서 출력
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
				getchar(); //버퍼 없애기
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
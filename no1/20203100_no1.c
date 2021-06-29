#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct ArrayList{
	int array[100];	
	int currentsize; //list 현재 크기
}List;

void _init_(List* list, int size) { //list size 5로 초기화
	list->currentsize = size;
}

void insert(List* list, int pos, int value) { //list 임의의 위치에 요소 삽입
	int i = 0;
	pos--;
	if ((list->currentsize) < 100 && pos >= 0 && pos <= (list->currentsize)) { //pos 를 잘못입력하거나 list가 꽉찼을때 방지
		for (i = (list->currentsize - 1);i >= pos;i--) {
			list->array[i + 1] = list->array[i];
		}
		list->array[pos] = value;
		list->currentsize++;
	}
}

void PrintList(List* list) {//list 요소들 출력
	int i = 0;
	printf("Stored element in array : ");
	for (i = 0;i < list->currentsize;i++) {
		printf("%d ",list->array[i]);
	}
	printf("\n");
}

void Set(List* list) {// list 초기 요소들 세팅
	int i = 0,value;
	printf("Enter 5 elements in array : ");
	for (i = 0;i < list->currentsize;i++) {
		scanf("%d",&value);
		list->array[i] = value;
	}
}

int main() {
	List list;
	int i = 0, value = 0,pos = 0;
	_init_(&list,5);

	Set(&list);
	PrintList(&list);
	printf("Enter position for enter element : ");
	scanf("%d", &pos);
	printf("Enter new element : "); scanf("%d",&value);
	insert(&list, pos, value);
	PrintList(&list);

	
}
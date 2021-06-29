#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct ArrayList {
	int array[100];
	int currentsize; //list 현재 크기
}List;

void _init_(List* list, int size) { //list size 5로 초기화
	list->currentsize = size;
}


void PrintList(List* list) { //list 요소들 출력
	int i = 0;
	for (i = 0;i < list->currentsize;i++) {
		printf("%d ", list->array[i]);
	}
	printf("\n");
}

void Set(List* list) { // list 초기 요소들 세팅
	int i = 0, value;
	printf("Enter 5 elements in array : ");
	for (i = 0;i < list->currentsize;i++) {
		scanf("%d", &value);
		list->array[i] = value;
	}
}

void delete(List* list, int pos) {
	int i = 0;
	pos--;
	if (pos >= 0 && pos < list->currentsize) { // pos값 잘못 넣었을때 방지
		for (i = pos;i < (list->currentsize - 1);i++) {
			list->array[i] = list->array[i + 1];
		}
		list->currentsize--;
	}
}

int main() {
	List list;
	int i = 0, value = 0, pos = 0;
	_init_(&list, 5);

	Set(&list);
	printf("Stored element in array : ");
	PrintList(&list);
	printf("Enter poss. of element to delete : ");
	scanf("%d", &pos);
	delete(&list, pos);
	printf("Ater deletion elements in array : ");
	PrintList(&list);


}
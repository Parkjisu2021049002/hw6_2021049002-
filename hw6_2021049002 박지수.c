#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* first;
} headNode;


headNode* initialize(headNode* h);//초기의 singly linked list 초기화
int freeList(headNode* h);

int insertFirst(headNode* h, int key);//linked list 앞쪽에 노드 하나 더 추가
int insertNode(headNode* h, int key);//하나의 노드를 삽입
int insertLast(headNode* h, int key);//linked list 마지막에 하나 더 노드 추가

int deleteFirst(headNode* h);//앞노드 하나 삭제 
int deleteNode(headNode* h, int key);//노드 하나 삭제
int deleteLast(headNode* h);// last 노드 하나 삭제
int invertList(headNode* h);//singly linked list 역순 배열

void printList(headNode* h);

int main()
{ printf("%d \n", 2021049002);
printf("박지수");
	char command;
	int key;
	headNode* headnode=NULL;

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

headNode* initialize(headNode* h) {
/*headnode 가 NULL이 아니면, freeNode를 호출하여 할당된 메모리를 모두 해제*/

	if(h != NULL)
		freeList(h);

/*headnode에 대한 메모리를 할당하여 리턴*/
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h){
 /*h와 연결된 listNode 메모리 해제
   *headNode도 해제 되어야함*/
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}

/*list 처음에 key에 대한 노드 하나 추가*/

int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}

/*리스트를 검색하여, 입력받은 key보다 큰 값이 나오는 노드 바로 앞에 삽입*/
int insertNode(headNode* h, int key) {

	return 0;
}

/*list에 key에대한 노드 하나 추가*/
int insertLast(headNode* h, int key) {

	return 0;
}


int deleteFirst(headNode* h) {


	return 0;
}

int deleteNode(headNode* h, int key) {

	return 0;

}


int deleteLast(headNode* h) {

	return 0;
}
/*리스트의 링크를 역순으로 재배치*/
int invertList(headNode* h) {

	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}

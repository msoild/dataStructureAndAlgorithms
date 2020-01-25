#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* pNext;  
}* PNODE, NODE;

//function declation 

PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int  length_list(PNODE);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE,int,int*);
void sort_list(PNODE);

int main(void)
{
	PNODE pHead=NULL;//struct Node *pHead=NULL；
	int val;
	pHead=create_list();//creat_list()功能：创建一个非循环单链表,并将该链表的头节点的地址付给pHead
	traverse_list(pHead);
    int len = length_list(pHead);
    printf("list len %d\n", len);
    insert_list(pHead, len, len+1)
    len = length_list(pHead);
    printf("list len after insert %d\n", len);

	return 0;
}

PNODE create_list(void) {
    int len ; //save to linkedList len
    int i ;
    int tmpValue;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));

    if(pHead == NULL) 
    {
        printf("malloc phead memory failed, exit\n");
        exit(-1);
    }
    PNODE pTail = pHead;
    printf("please input the linkedlist length with int value\n");
    scanf("%d", &len);

    for(i=0; i< len; i++ ) {
        printf("pleae input the value of the node %d \n ", i+1);
        scanf("%d", &tmpValue);
        PNODE pNewNode = (PNODE)malloc(sizeof(NODE));
        pNewNode->data = tmpValue;
        pNewNode->pNext = NULL;
        pTail->pNext = pNewNode;
        pTail = pNewNode;
    }
    return pHead;
}

void traverse_list(PNODE pHead) {
    if(pHead == NULL) {
        printf("pHead is nullpointer\n");
        return;
    }
    PNODE pCurrentNode = pHead->pNext;
    while(pCurrentNode != NULL) {
        printf("%d ", pCurrentNode->data);
        pCurrentNode= pCurrentNode->pNext;
    }
    printf("\n");
}

bool is_empty(PNODE pHead) {
    if(pHead == NULL) {
        printf("phead is null");
        return false;
    }
    if(phead->pNext != NULL) {
        return false;
    } else {
        return true;
    }

}

//头节点不算有效节点
int  length_list(PNODE pHead) {
    if(pHead == NULL) {
        return -1;
    }
    int len = 0;
    PNODE pNode = pHead->pNext;
    while(pNode != NULL) {
        len ++;
        pNode = pNode->pNext;
    }
    return len;

}


//首节点pos 1
bool insert_list(PNODE pHead ,int pos,int val) {
    
    int index = 0;
    PNODE pPreInsert = pHead;
    //if indexd ==pos-1 
    while(pPreInsert != NULL &&  index <pos-1) {
        index++;
        pPreInsert = pPreInsert->pNext;
    }
    if(index > pos-1 || pPreInsert == NULL) {
        return false;
    }

    PNODE pInsertedNode = malloc(sizeof(NODE));
    if(!pInsertedNode) {
        return false;
    }
    pInsertedNode->data = val;
    pInsertedNode->pNext = pPreInsert->pNext;

    pPreInsert->pNext = pInsertedNode;
    return true;
}





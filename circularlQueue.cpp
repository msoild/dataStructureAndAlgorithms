/* 基本思想
队列算法：
    出队和入队
rear 指向队列最后一个元素的下一位置
front 指向队首的第一个元素
循环队列判断是否满 ，可以在队列里面空一个元素
*/

/* step
定义一个队列的结构体
定义队列提供的接口
*/

#include <stdio.h>
#include <malloc.h>

typedef struct Queue {
    int* pBase;
    int front;
    int rear;
    int len;
} QUEUE;

void init(QUEUE*  pQ, int len);
bool en_queue(QUEUE* pQ, int val);
bool out_queue(QUEUE* pQ, int* pVal);
void traverse(QUEUE* pQ);
bool full_queue(QUEUE* pQ);
bool empty_queue(QUEUE* pQ);

int main(void) {
    QUEUE Q;
    int len = 7;
    init(&Q, len);
    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);
    en_queue(&Q, 5);
    en_queue(&Q, 6);
    en_queue(&Q, 7);
    traverse(&Q);
    int outVal;
	if(out_queue(&Q,&outVal))
	{
		printf("out put queue successfully，out queue item val =%d\n",outVal);
	}
	else 
	{
		printf("output queue failed！\n");
	}
	traverse(&Q);

    return 0;
}


void init(QUEUE * pQ, int len) {
    //init state rear = front = 0;
    pQ->len = len;
    pQ->pBase = (int*)malloc(sizeof(int)*(pQ->len));
    pQ->front = 0;
    pQ->rear = 0;
}

bool full_queue(QUEUE* pQ) {
    if((pQ->rear+1)%(pQ->len) == pQ->front) {
        printf("full queue\n");
        return true;
    }
    else {
        return false;
    }
}

bool empty_queue(QUEUE* pQ) {
    if(pQ->front == pQ->rear) {
        printf("empty queue\n");
        return true;
    }
    else {
        return false;
    }
}

bool en_queue(QUEUE*pQ, int val) {
    if(pQ == NULL || full_queue(pQ))
    {
        return false;
    }
    pQ->pBase[pQ->rear] = val;
    pQ->rear = (pQ->rear +1)%  (pQ->len);
    return true;
}

bool out_queue(QUEUE* pQ, int* pVal) {
    if(pQ == NULL || empty_queue(pQ)) {
        return false;
    }
    *pVal = pQ->pBase[pQ->front];
    pQ->front = (pQ->front+ 1)%pQ->len;
    return true;
}

void traverse(QUEUE*pQ) {
    int index = pQ->front;
    while(index!= pQ->rear) {
        printf("%d ", pQ->pBase[index]);
        index = (index+1)%(pQ->len);
    }
    printf("\n");

}
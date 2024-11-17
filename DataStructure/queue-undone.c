# include <stdio.h>
# include <stdlib.h>
#include<stdbool.h>
#define  MAXSIZE  100
#define  ElemType  int

typedef struct SqQueue {
	int* base;//数据存储的基地址
	int front;//指向队列第一个元素
	int rear;//指向队列最后一个元素的下一个元素
	int queuesize;//队列容量
}SqQueue;

void InitSqQueue(SqQueue* Q) {//初始化队列 
	Q->base = ;
	Q->front = ;
	Q->rear = ;
	Q->queuesize = MAXSIZE;
}

int IsFullSqQueue(SqQueue* Q) {//判断队满
	return Q->front == ;
}
int IsEmptySqQueue(SqQueue* Q) {//判断队空
	return Q->front == ;
}
int SqQueuePush(SqQueue* Q, int e) {//将元素e 入队列Q
	if (IsFullSqQueue(Q)) {
		printf("Queue is full\n");
		return 0;
	}
	else {
		 = e;
		Q->rear = ;//队尾变动
		return 1;
	}
}
int SqQueuePop(SqQueue* Q) {//队列Q出队
	if (IsEmptySqQueue(Q)) {
		printf("queue is empty\n");
		exit(-1);
	}
	else {
		int e = ;//出队元素 赋值给 元素e
		Q->front = ;//队头变动
		return e;
	}
}
void main() {
	SqQueue Q;
	InitSqQueue(&Q);
	for (int i = 1; i <= 5; i++)
		SqQueuePush(&Q, i);
	for (int i = 1; i <= 5; i++)
		printf("Queue's pop elem is %d\n", SqQueuePop(&Q));

	for (int i = 3; i >= 1; i--)
		SqQueuePush(&Q, i);
	for (int i = 1; i <= 2; i++)
		printf("Queue's pop elem is %d\n", SqQueuePop(&Q));
	for (int i = 4; i <= 7; i++)
		SqQueuePush(&Q, i);
	for (int i = 1; i <= MAXSIZE + 1; i++)
		printf("Queue's pop elem is %d\n", SqQueuePop(&Q));
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100
#define ElemType int

typedef struct SqQueue {
	int* base;	// 数据存储的地址
	int front;	// 指向队列的第一个元素
	int rear;	// 指向队列最后一个元素的下一个位置
	int queuesize;	// 队列容量
} SqQueue;


void InitSqQueue(SqQueue* Q) {
	Q->base = (int*)malloc(MAXSIZE * sizeof(int));
	if (!Q->base) {
		printf("Memory allocation failed\n");
		exit(-1);
	}
	Q->front = 0;
	Q->rear = 0;
	Q->queuesize = MAXSIZE;
}

int IsFullSqQueue(SqQueue* Q) {
	return (Q->rear + 1) % Q->queuesize == Q->front;
}

int IsEmptySqQueue(SqQueue* Q) {
	return Q->front == Q->rear;
}

int SqQueuePush(SqQueue* Q, int e) {
	if (IsFullSqQueue(Q)) {
		printf("Queue is full\n");
		return 0;
	}
	else {
		Q->base[Q->rear] = e;
		Q->rear = (Q->rear + 1) % Q->queuesize;
		return 1;
	}
}

int SqQueuePop(SqQueue* Q) {
	if (IsEmptySqQueue(Q)) {
		printf("Queue is empty\n");
		exit(-1);
	}
	else {
		int e = Q->base[Q->front]; // 取出对头元素
		Q->front = (Q->front + 1) % Q->queuesize;
		return e;
	}
}

int main() {
	SqQueue Q;
    printf("任务1顺序表\n");
    printf("定义一个队列Q\n");
	InitSqQueue(&Q);
    printf("初始化队列Q InitSqQueue\n");
	for (int i = 1; i <= 5; i++) {
		SqQueuePush(&Q, i);
	}
	for (int i = 1; i <= 5; i++) {
		int n;
		n = SqQueuePop(&Q);
	}
    printf("入队第1次：3 2 1\n");
    SqQueuePush(&Q, 3);
    SqQueuePush(&Q, 2);
    SqQueuePush(&Q, 1);
    int n;
    n = SqQueuePop(&Q);
    printf("出队1次：%d\n", n);
    n = SqQueuePop(&Q);
    printf("出队2次：%d\n", n);
    printf("入队第2次：4 5 6 7\n");
    SqQueuePush(&Q, 4);
    SqQueuePush(&Q, 5);
    SqQueuePush(&Q, 6);
    SqQueuePush(&Q, 7);
    for (int i = 1; i <= MAXSIZE + 1; i++) // 注意这里会越界
        printf("Queue's 出队%d\n", SqQueuePop(&Q));
}

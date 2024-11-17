// 链队列
#include <stdio.h>
#include <stdlib.h>
#define Elemtype int
typedef struct QNode{
    Elemtype data;
    struct QNode* next;
} QNode;

typedef struct {
    QNode* front;
    QNode* rear;
} LinkQueue;

// 初始化链队列
void InitQueue(LinkQueue* Q) {
    Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));
    if (!Q->front) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    Q->front->next = NULL;
}

// 判断队列是否为空
int IsEmpty(LinkQueue* Q) {
    return Q->front == Q->rear;
}

// 入队操作
void QueuePush(LinkQueue*Q, Elemtype e) {
    QNode* newNode = (QNode*) malloc (sizeof(QNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    newNode->data = e;
    newNode->next = NULL;
    Q->rear->next = newNode;
    Q->rear = newNode;
}

// 出队操作
int QueuePop(LinkQueue* Q) {
    if (IsEmpty(Q)) {
        printf("Queue is empty\n");
    }
    QNode* p = Q->front->next;
    Elemtype e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }

    free(p);
    return e;
}
int main()
{
	LinkQueue Q;
    printf("任务2链式\n");
    printf("定义一个队列Q\n");
    InitQueue(&Q);
	// InitSqQueue(&Q);
    printf("初始化队列Q InitQueue\n");
	for (int i = 1; i <= 5; i++) {
		QueuePush(&Q, i);
	}
	for (int i = 1; i <= 5; i++) {
		int n;
		n = QueuePop(&Q);
		printf("%d\n", n);
	}
    printf("入队第1次：3 2 1\n");
    QueuePush(&Q, 3);
    QueuePush(&Q, 2);
    QueuePush(&Q, 1);
    int n;
    n = QueuePop(&Q);
    printf("出队1次：%d\n", n);
    n = QueuePop(&Q);
    printf("出队2次：%d\n", n);
    printf("入队第2次：4 5 6 7\n");
    QueuePush(&Q, 4);
    QueuePush(&Q, 5);
    QueuePush(&Q, 6);
    QueuePush(&Q, 7);
    while (!IsEmpty(&Q)) {
        printf("Queue's 出队%d\n", QueuePop(&Q));
    }        
}
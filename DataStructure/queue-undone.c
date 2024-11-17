# include <stdio.h>
# include <stdlib.h>
#include<stdbool.h>
#define  MAXSIZE  100
#define  ElemType  int

typedef struct SqQueue {
	int* base;//���ݴ洢�Ļ���ַ
	int front;//ָ����е�һ��Ԫ��
	int rear;//ָ��������һ��Ԫ�ص���һ��Ԫ��
	int queuesize;//��������
}SqQueue;

void InitSqQueue(SqQueue* Q) {//��ʼ������ 
	Q->base = ;
	Q->front = ;
	Q->rear = ;
	Q->queuesize = MAXSIZE;
}

int IsFullSqQueue(SqQueue* Q) {//�ж϶���
	return Q->front == ;
}
int IsEmptySqQueue(SqQueue* Q) {//�ж϶ӿ�
	return Q->front == ;
}
int SqQueuePush(SqQueue* Q, int e) {//��Ԫ��e �����Q
	if (IsFullSqQueue(Q)) {
		printf("Queue is full\n");
		return 0;
	}
	else {
		 = e;
		Q->rear = ;//��β�䶯
		return 1;
	}
}
int SqQueuePop(SqQueue* Q) {//����Q����
	if (IsEmptySqQueue(Q)) {
		printf("queue is empty\n");
		exit(-1);
	}
	else {
		int e = ;//����Ԫ�� ��ֵ�� Ԫ��e
		Q->front = ;//��ͷ�䶯
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
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode{
    int data;
    struct StackNode* next;
} StackNode, *LinkStack;

// 创建链栈
LinkStack CreateStack() {
    LinkStack s = (LinkStack) malloc (sizeof(StackNode));
    s->next = NULL;
    return s;
}

// 链栈为空
int StackEmpty(LinkStack s) {
    return s->next == NULL;
}

int Push(LinkStack s, int x) {
    StackNode* node = (StackNode*) malloc (sizeof(StackNode));
    if (node == NULL) {
        return 0;
    }
    node->data = x;
    node->next = s->next;
    s->next = node;
    return 1;
}

int Pop(LinkStack s, int* x) {
    if (StackEmpty(s)) {
        return 0;
    }
    StackNode* node = s->next;
    *x = node->data;
    s->next = node->next;
    free(node);
    return 1;
}

void PrintStack(LinkStack s) {
    while (!StackEmpty(s)) {
        int x;
        Pop(s, &x);
        printf("%d ", x);
    }
    printf("\n");
}

int main() {
    LinkStack s = CreateStack();

    // 1.
    for (int i=1;i<=5;i++){
        Push(s, i);
    }
    printf("出栈序列：");
    PrintStack(s);

    Push(s, 3);
    Push(s, 2);
    Push(s, 1);
    int x;
    Pop(s, &x);
    printf("出栈：%d\n", x);
    Pop(s, &x);
    printf("出栈：%d\n", x);

    Push(s, 4);
    Push(s, 5);
    Push(s, 6);
    Push(s, 7);

    printf("全部出栈：");
    PrintStack(s);
    return 0;
}

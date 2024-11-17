#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

// 单链表操作
typedef struct LinkList {
    ElemType elem;
    struct LinkList *next;
} LinkList;

// 创建单链表
void CreateList(LinkList *L, ElemType a[], int n) {
    LinkList *pre = L;
    // 前插还是后插可修改这里的循环语句
    for (int i=0;i<=n-1;i++){
        LinkList *t = (LinkList*)malloc(sizeof(LinkList));
        if (t != NULL) {
            t->elem = a[i];
            t->next = pre->next;
            pre->next = t;
        }
    }
}
// 单链表的插入算法
int ListInsert(LinkList *L, int i, ElemType e){
    int j=0;
    LinkList *p = L;
    while (p!=NULL&&j<i-1){
        p = p->next;
        j++;
    }
    if (p == NULL || j>i-1){
        return 0;
    }
    LinkList *t = (LinkList*)malloc(sizeof(LinkList));
    if (t==NULL){
        return 0;
    }
    t->elem = e;
    t->next = p->next;
    p->next = t;
    return 1;
}
// 单链表的删除算法
int ListDelete(LinkList *L, int i){
    int j=0;
    LinkList *p = L;
    LinkList *del = NULL;
    while (p->next != NULL && j<i-1){
        p = p->next;
        j++;
    }
    if (p->next==NULL||j>i-1){
        return 0;
    }
    del = p->next;
    p->next=del->next;
    free(del);
    return 1;
}

// 打印链表
void PrintList(LinkList *L) {
    LinkList *p = L->next;
    while (p != NULL) {
        printf("%d ", p->elem);
        p = p->next;
    }
    printf("\n");
}

// 释放链表

// 主函数
int main() {
    LinkList *list;
    // InitList(*list);

    int arr[] = {21, 18, 30, 75, 42, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    // 创建单链表
    printf("创建单链表\n");
    CreateList(list, arr, n);
    printf("打印链表\n");
    PrintList(list);
    if (ListInsert(list, 3, 67)){
        printf("插入成功 ");
        PrintList(list);
    } else {
        printf("插入失败 ");
        PrintList(list);
    }
    if (ListInsert(list, 9, 67)){
        printf("插入成功 ");
        PrintList(list);
    } else {
        printf("插入失败 ");
        PrintList(list);        
    }

    if (ListDelete(list, 6)) {
        printf("删除成功 ");
        PrintList(list);
    } else {
        printf("删除失败 ");
        PrintList(list);
    }

    if (ListDelete(list, 8)) {
        printf("删除成功 ");
        PrintList(list);
    } else {
        printf("删除失败 ");
        PrintList(list);
    }
}
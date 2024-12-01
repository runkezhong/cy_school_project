#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BinTreeNode {
    ElemType data;
    struct BinTreeNode *lchild;
    struct BinTreeNode *rchild;
} BinTreeNode, *BinTree;


void CreateTree(BinTree *T) {
    ElemType ch;
    scanf("%c", &ch);
    if (ch == '#') {
        *T = NULL;
    } else  {
        *T = (BinTree) malloc(sizeof(BinTreeNode));
        if (!*T) {
            return;
        }
        (*T) -> data= ch;
        CreateTree(&(*T)->lchild);
        CreateTree(&(*T)->rchild);
    }
}

void PreOrderTraverse(BinTree T) {
    if (T == NULL) {
        return;
    }
    printf("%c ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BinTree T) {
    if (T == NULL) {
        return;
    }
    InOrderTraverse(T->lchild);
    printf("%c ", T->data);
    InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BinTree T) {
    if (T == NULL) {
        return;
    }
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c ", T->data);
}

int LeafCount(BinTree T) {
    if (T==NULL) {
        return 0;
    }
    if (T->lchild==NULL && T->rchild == NULL) {
        return 1;
    } else {
        return LeafCount(T->lchild)+LeafCount(T->rchild);
    }
}

int AllNodeCount(BinTree T) {
    if (T==NULL) {
        return 0;
    } else {
        return AllNodeCount(T->lchild)+AllNodeCount(T->rchild)+1;
    }
}

int main() {
    // BinTreeNode bin;
    BinTree root = NULL;
    CreateTree(&root);
    // ABD###CE##F##
    printf("前序遍历结果为 :");
    PreOrderTraverse(root);
    printf("\n中序遍历结果为 :");
    InOrderTraverse(root);
    printf("\n后序遍历结果为 :");
    PostOrderTraverse(root);
    int n = LeafCount(root);
    printf("\n叶子数为：%d", n);
    int m = AllNodeCount(root);
    printf("\n总节点数为：%d", m);
}
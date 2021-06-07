#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct BinTreeNode *BinTree;

struct BinTreeNode
{
    ElementType data;
    BinTree Left;
    BinTree Right;
};
void preOderTraversal(BinTree BT)
{
    if(BT){
        printf("%d\t", BT->data);
        preOderTraversal(BT->Left);
        preOderTraversal(BT->Right);
    }
}

void inOrderTraversal(BinTree BT)
{
    if(BT){
        inOrderTraversal(BT->Left);
        printf("%d\t", BT->data);
        inOrderTraversal(BT->Right);
    }
}

void postOrderTraversal(BinTree BT)
{
    if(BT)
    {
        postOrderTraversal(BT->Left);
        postOrderTraversal(BT->Right);
        printf("%d\t", BT->data);
    }

}

int main()
{
    BinTree a = (BinTree)malloc(sizeof(struct BinTreeNode));
    BinTree b = (BinTree)malloc(sizeof(struct BinTreeNode));
    BinTree c = (BinTree)malloc(sizeof(struct BinTreeNode));
    a->data = 1;
    a->Left = b;
    a->Right = c;

    b->data = 2;
    b->Left = NULL;
    b->Right = NULL;

    c->data = 3;
    c->Right = NULL;
    c->Left = NULL;

    preOderTraversal(a);
    
    system("pause");
    return 0;
}
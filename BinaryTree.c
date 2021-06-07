#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef int ElementType;
typedef struct Node *binaryTree;
typedef struct stackNode *stack;
struct Node
{
    ElementType data;
    binaryTree left;
    binaryTree right;
};
struct stackNode
{
    binaryTree data;
    stack next;
};

stack initStack()
{
    stack s;
    s = (stack)malloc(sizeof(struct stackNode));
    s->next = NULL;
}
int stackIsEmpty(stack s)
{
    if(s->next == NULL)
    {
        return 1;
    }
    else return 0;
}
void push(binaryTree bt, stack s)
{
    stack temp;
    stack newStackNode;
    newStackNode = (stack)malloc(sizeof(struct stackNode));
    newStackNode->data = bt;

    newStackNode->next = s->next;
    s->next = newStackNode;
}

binaryTree pop(stack s)
{
    binaryTree bt;
    stack temp;
    if(stackIsEmpty(s) == 1)
    {
        printf("Stack is empty!\n");
        return bt;
    }
    temp = s->next;
    bt = temp->data;
    s->next = s->next->next;
    free(temp);
    return bt;
}

binaryTree initBinaryTree()
{
    binaryTree bt0;
    binaryTree bt1;
    binaryTree bt2;
    binaryTree bt3;
    binaryTree bt4;
    bt0 = (binaryTree)malloc(sizeof(struct Node));
    bt1 = (binaryTree)malloc(sizeof(struct Node));
    bt2 = (binaryTree)malloc(sizeof(struct Node));
    bt3 = (binaryTree)malloc(sizeof(struct Node));
    bt4 = (binaryTree)malloc(sizeof(struct Node));

    /* 初始化当前二叉树 */
    bt0->data = 0;
    bt1->data = 1;
    bt2->data = 2;
    bt3->data = 3;
    bt4->data = 4;
    bt0->left = bt1;
    bt0->right = bt2;
    bt1->left = bt3;
    bt1->right = bt4;
    /* 注意： 一定要给叶节点赋值空指针 */
    bt2->left = NULL;
    bt2->right = NULL;
    bt3->left = NULL;
    bt3->right = NULL;
    bt4->left = NULL;
    bt4->right = NULL;
    return bt0;
}

void InOrderTraversal(binaryTree bt)
{
    if(bt)
    {
        InOrderTraversal(bt->left);
        printf("data : %d\n", bt->data);
        InOrderTraversal(bt->right);
    }
}

void InOrderTraversal1(binaryTree bt)
{
    stack s = initStack();
    binaryTree btTemp=bt;
    /* 中序遍历的非递归算法 */
    while(btTemp || stackIsEmpty(s) == 0)
    {
        /* 注意：这里有两层循环，保证一直向左走，到二叉树的最左边 */
        while(btTemp)
        {
            push(btTemp, s);
            btTemp = btTemp->left;
        }
        /* 注意：if语句在第一层循环里面*/
        if(stackIsEmpty(s) == 0)
        {
            btTemp = pop(s);
            printf("data: %d\n", btTemp->data);
            btTemp = btTemp->right;
        }    
    }
    
}
int main()
{
    int data;
    binaryTree bt;
    bt = initBinaryTree();
    // printf("bt->left->left->data :  %d \n", bt->left->left->data);
    // InOrderTraversal(bt);
    InOrderTraversal1(bt);
    system("pause");
    return 0;
    
}
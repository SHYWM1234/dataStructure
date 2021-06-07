//TreeIsmorphic.c
#include<stdio.h>
#include<stdlib.h>
#define Null -1
#define MaxTree 10
typedef char ElementType;
typedef int tree;
/* 用静态链表表示树 */
struct TreeNode
{
	ElementType ele;
	int left;
	int right;
}T1[MaxTree], T2[MaxTree];

tree BuildTree (struct TreeNode T[])
{
	int i, N, root=-1;
	char cl, cr;
	int check[MaxTree];
	for(i=0; i<MaxTree; i++)
	{
		check[i] = 0;
	}
	// printf("please input N: ");
	scanf("%d", &N);
	// printf(" N : %d \n", N);

	if(N>0)
	{

		printf("please input nodes: \n");
		for(i=0; i<N; i++)
		{
			scanf(" %c %c %c", &T[i].ele, &cl, &cr);
			/* 处理左儿子节点 */
			// printf("T[i].ele: %c ; cl: %c ;cr:  %c\n", T[i].ele, cl, cr);
			if(cl != '-')
			{
				T[i].left = cl-'0';
				check[T[i].left] = 1; // 标记第“T[i.left”个节点为非root节点
			}
			else
			{
				T[i].left = Null; // 表示该节点没有左儿子节点
			}
			/* 处理右儿子节点 */
			if(cr != '-')
			{
				T[i].right = cr - '0';
				check[T[i].right] = 1;
			}
			else
			{
				T[i].right = Null;
			}
		}
		
		/* 遍历整个数，找到根节点*/
		for(i=0; i<N; i++)
		{
			if(check[i] == 0) break;
		}
		root = i;
		
	}
	return root;
}


int ismorphic(struct TreeNode t1, struct TreeNode t2)
{


}

int main()
{
	tree R1 , R2;

	/* 建立二叉树1 */
	R1 = BuildTree(T1);
	/* 建立二叉树2 */
	R2 = BuildTree(T2);
	/* 输出R1和R2的根节点 */
	printf("R1: %d\n", R1);
	printf("R2: %d\n", R2);

	/* 判别是否同构并输出 */
	if(isomorphic(R1, R2))
	{
		printf("Yes\n");
	}else{
		printf("No\n");
	}

	system("pause");
	return 0;
}

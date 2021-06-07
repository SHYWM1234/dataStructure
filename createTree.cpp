// 先序遍历 中序遍历 ——> 后序遍历
#include<iostream>
using namespace std;
typedef struct BiTNode{
	struct BiTNode *lchild;
	struct BiTNode *rchild;
	int data;
}BiTNode, *BiTree;
 
BiTree creatTree(int *in, int *pre, int n){
	if(n <= 0)
		return NULL;
	else{
		BiTree T = new BiTNode;
		T->data = pre[0];
		int i;
		for(i = 0; i < n; i++){
			if(pre[0] == in[i])
				break;
		}
		T->lchild = creatTree(in, pre + 1, i);
		T->rchild = creatTree(in + i + 1, pre + i + 1, n - i - 1);
		return T;
	}
}
void postorderTraversal(BiTree BT){
	if(BT){
		
		postorderTraversal(BT->lchild);
		postorderTraversal(BT->rchild);
		cout << " " << BT->data;
	}
}
int main(){
	int n; 
	cin >> n;
	int in[32];
	int pre[32];
	BiTree T;
	 for(int i = 0; i < n; i++){
	 	cin >> pre[i];
	 }	
	 for(int i = 0; i < n; i++){
	 	cin >> in[i];
	 }
	T = creatTree(in, pre, n);
	cout << "Postorder:";
	postorderTraversal(T);
    cin >> n;
	return 0;
}

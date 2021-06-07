// 先序遍历 中序遍历 ——> 后序遍历
#include<iostream>
#include <queue>
using namespace std;
typedef struct BiTNode{
	struct BiTNode *lchild;
	struct BiTNode *rchild;
	char data;
}BiTNode, *BiTree;
 
BiTree creatTree(char *in, char *pre, int n){
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

int height(BiTree BT)
{
    queue<BiTree> q;
    BiTree p=BT;
    int level=0,len;
    if(!BT)
        return 0;
    q.push(p);
    while(!q.empty())//每次只有把在同一层的所有结点出队以后才level++，因此要知道当前队列的长度，用len表示
    {
        level++;
        len=q.size();//当前队列长度就代表这一层的结点个数
        while(len--)
        {
            p=q.front();
            q.pop();
            if(p->lchild)
                q.push(p->lchild);
            if(p->rchild)
                q.push(p->rchild);
        }
    }
    return level;
}


int main(){
	int n, h; 
	cin >> n;
	char in[50];
	char pre[50];
	BiTree T;
	 for(int i = 0; i < n; i++){
	 	cin >> pre[i];
	 }	
	 for(int i = 0; i < n; i++){
	 	cin >> in[i];
	 }
	T = creatTree(in, pre, n);
    // 输出后序遍历
    /*
	cout << "Postorder:";
	postorderTraversal(T);
    */
    // 输出树的深度
    h = height(T);
    cout << h;

    // 程序暂停
    // cin >> n;
	return 0;
}

/* 基本思想
二叉树的操作主要解决非线性结构存储为线性结构的问题
主要操作
1.遍历： 先序遍历， 中序遍历， 和后序遍历
2. 已知中序求另外两种遍历方式


/* step
先访问根节点， 再访问左子树， 再访问右子树
采用递归方法
    终结条件： 左边和右边节点都是空
*/
#include <stdio.h>
#include <malloc.h>

typedef struct BTNode
{
    int data;
    struct BTNode* pLchild;
    struct BTNode* pRchild;
} BTNode;

void preTraverseBTree(BTNode* pT);
void inTraverseBTree(BTNode* pT);
void postTraverseBTree(BTNode* pT);
BTNode* CreateBTree(void);

int main(void) {
    BTNode* pT = CreateBTree();
    printf("pre seq traverse\n");
    preTraverseBTree(pT);

    printf("middle seq traverse\n");
    inTraverseBTree(pT);
    printf("post seq traverse\n");
    postTraverseBTree(pT);
}

BTNode* CreateBTree(void) {
     BTNode * pA=( BTNode *)malloc(sizeof( BTNode ));
	 BTNode * pB=( BTNode *)malloc(sizeof( BTNode ));
	 BTNode * pC=( BTNode *)malloc(sizeof( BTNode ));
	 BTNode * pD=( BTNode *)malloc(sizeof( BTNode ));
	 BTNode * pE=( BTNode *)malloc(sizeof( BTNode ));
	
	pA->data='A';
	pB->data='B';
	pC->data='C';
	pD->data='D';
	pE->data='E';

	
	pA->pLchild=pB;
	pA->pRchild=pC;
	pB->pLchild=pB->pRchild=NULL;
	pC->pLchild=pD;
	pC->pRchild=NULL;
	pD->pLchild=NULL;
	pD->pRchild=pE;
	pE->pLchild=pE->pRchild=NULL;


	return pA;
}

void preTraverseBTree(BTNode* pT){
    if(pT == NULL) {
        return;
    }
    printf("%c\n", pT->data);

   if(pT->pLchild != NULL) {
       preTraverseBTree(pT->pLchild);
   }
   if(pT->pRchild != NULL) {
       preTraverseBTree(pT->pRchild);
   }
}

void inTraverseBTree(BTNode* pT) {
    if(pT == NULL) {
        return;
    }
    if(pT->pLchild != NULL) {
        inTraverseBTree(pT->pLchild);
    }
    printf("%c\n", pT->data);
    if(pT->pRchild != NULL) 
    {
        inTraverseBTree(pT->pRchild);
    }
}

void postTraverseBTree(BTNode* pT) {
    if(pT == NULL) {
        return;
    }
    if(pT->pLchild != NULL) {
        postTraverseBTree(pT->pLchild);
    }
   
    if(pT->pRchild != NULL) 
    {
        postTraverseBTree(pT->pRchild);
    }
     printf("%c\n", pT->data);
}

#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//���������� 
CreatBiTree(BiTree *T){
	char c;
	scanf("%c", &c);
	if( ' ' == c){
		*T = NULL;
	}else{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreatBiTree(&(*T)->lchild);
		CreatBiTree(&(*T)->rchild);
	}
} 

visit(char c,int level){
	printf("%c �ڵ� %d ��\n", c, level);
}

//ǰ����������� 
Pre(BiTree T,int level){
	if( T ){
		visit(T->data, level);
		Pre(T->lchild, level+1);
		Pre(T->rchild, level+1);
	}
}

int main(){
	
	int level = 1;
	BiTree T= NULL;
	
	CreatBiTree(&T);
	Pre(T, level);
	
	return 0;
}



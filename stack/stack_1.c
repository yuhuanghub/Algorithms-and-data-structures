#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0

typedef int ElemType;

typedef struct 
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

//栈的初始化
int initStack(sqStack &s){
	s.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(sqStack));
	if ( !s.base )
	{
		exit(0);
		/* code */
	}
	s.top = s.base;
	s.stackSize = STACK_INIT_SIZE;
	return OK;
}

//进栈
int push(sqStack &s, int e){
	//如果栈空间满，追加空间
	if ( s.top - s.base >= s.stackSize)
	{
		s.base = (ElemType *)realloc(s.base, (s.stackSize + STACKINCREMENT) * sizeof(sqStack));
		//如果栈为空退出
		if ( !s.base)
		{
			exit(0);
			/* code */
		}
		/* code */
		//更新栈容量和栈顶
		s.top = s.base + s.stackSize;
		s.stackSize = s.stackSize + STACKINCREMENT;
	}

	//追加数据
	*s.top++ = e;
	return OK;
}

//出栈操作
int pop(sqStack &s, int &e){
	//栈是否为空
	if ( s.top != s.base)
	{
		e = * --s.top; //把取出的元素赋值到e,并把栈顶-1
		return OK;
		/* code */
	}
}

//得到顶部元素
void getTopElem(sqStack s, int &e){
	if ( s.top != s.base)
	{
		e = *(s.top - 1);
		/* code */
	}
}

//打印栈里所有元素
void printStackElem(sqStack s){
	while( *(s.top - 1) && s.top != s.base){
		s.top = s.top - 1;
		printf("%d ", *s.top);
	}
}

int main(int argc, char const *argv[])
{
	int e,i;
	int textData[6] = {4,5,2,42,1,6};
	sqStack s;
	initStack(s); //初始化栈s

	for (i = 0; i < 6; ++i)
	{
		push(s, textData[i]);
		/* code */
	}

	printf("初始化的数据\n");
	printStackElem(s);

	printf("得到栈顶元素\n");
	getTopElem(s, e);
	printf("栈顶元素%d\n", e);

	printf("顶部出栈后的s\n");
	pop(s, e);
	printStackElem(s);
	return 0;
}

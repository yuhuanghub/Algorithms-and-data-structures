#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;
typedef struct 
{
	ElemType *top;
	ElemType *base;
	int stackSize;
}sqStack;

void InitStack(sqStack *s){

	s->base = (ElemType *)malloc( STACK_INIT_SIZE * sizeof(sqStack) );
	if ( !s->base ) exit(0);
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

void push(sqStack *s, ElemType c){

	if ( s->top - s->base >= s->stackSize ){
		s->base = (ElemType *)realloc(s->base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(sqStack));
		if ( !s->base ) exit(0);
		s->top = s->base + s->stackSize;
		s->stackSize = s->stackSize + STACKINCREMENT;
	}

	*(s->top) = c;
	s->top++;
}

void pop(sqStack *s, ElemType c){
	if ( s-> top == s->base) return;
	c = * --(s->top);
}

int StackLen(sqStack s){
	return ( s.top - s.base);
}

void printStackElem(sqStack s){
	while( *(s.top - 1) && s.top != s.base){
		s.top = s.top - 1;
		printf("%d ", *s.top);
	}
}

int main()
{
	int i,len;
	char c;
	sqStack s;
	InitStack (&s);

	printf("input Binary number：\n");
	scanf("%c", &c);
	while( c != '#'){
		push(&s, c);    //输入进栈
		scanf("%c", &c);
		flush();
	}
	 

	len = StackLen(s);
	printStackElem(s);

	return 0;
}

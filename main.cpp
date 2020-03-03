#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;



//creat stack
typedef struct stack
{
    int capacity;
    int top;
    int *items;
} stack;

// initialization of stack

stack *init_stack(int capacity)
{

    stack *init=(stack*)malloc(sizeof(stack));
    init->top=-1;
    init->capacity=capacity;
    init ->items=(int* )malloc(sizeof(int)*capacity);

}
//function to return size of stack
int size_of_stack(stack *stk)
{
    return stk->top+1;
}
//ckeck is empty
bool stack_isempty(stack *stk)
{
    if (stk->top == -1)return true;
    else return false;
}
//check is fall
bool stack_isfall(stack *stk)
{
    if((stk->top)==(stk->capacity-1))return true;
    else return false;

}
//push element in stack
void push_stack(stack *stk,int data)
{
    if (stack_isfall(stk))return;
    stk->items[++stk->top]=data;
}
//pop element in stack
void pop_stack(stack *stk)
{
    if (stack_isempty(stk))return;
    else stk->items[--stk->top];
}
//top element in stack
int stack_top_element (stack *stk)
{
    if (!(stack_isempty(stk)))return stk->items[stk->top];
    else printf("empty can't top");
}
void print_stack(stack *stk)
{  while(!(stack_isempty(stk)))
    {

        printf("element is:%d\n",stack_top_element(stk));
        pop_stack(stk);
    }
}




int main()
{
    stack *stk = init_stack(5);
    push_stack(stk,1);
    push_stack(stk,2);
    push_stack(stk,3);
    pop_stack(stk);
    printf("element is:%d\n",stack_top_element(stk));
    print_stack(stk);


    return 0;
}


#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Stack {
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, int item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
}

int pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

int peek(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}

int main()
{   
    int m, n, povrh = 0;
	struct Stack* stack1 = createStack(100);
    struct Stack* stack2 = createStack(100);
    time_t t1, t2;

    t1 = clock();
	push(stack1, 7);
	push(stack2, 2);

    do{
        n = pop(stack1);
        m = pop(stack2);
        if(n == m || m == 0){
            povrh++;
        }else{
            push(stack1, n-1); push(stack2, m-1);
            push(stack1, n-1); push(stack2, m);
        }
    }while(!isEmpty(stack1));
    printf("Rezultat: %d\n", povrh);
    t2 = clock();
    printf("Vrijeme formiranja niza je %dms\n", t2-t1);

	return 0;
}
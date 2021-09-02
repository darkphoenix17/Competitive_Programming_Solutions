//Function to push an integer into the stack.
void push(struct Stack* stack, int item)
{
	stack->top++;
	stack->array[stack->top] = item;
}


//Function to remove an item from top of the stack.
int pop(struct Stack* stack)
{
	if (stack->top == -1) {
		return -1;
	}
	int tmp = stack->array[stack->top];
	stack->top--;
	return tmp;
}
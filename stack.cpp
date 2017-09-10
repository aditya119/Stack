#include<iostream>
#include<cstdlib>
using namespace std;

struct stack
{
	int data;
	stack *top, *next, *prev;
	void setNull();
	void push(int x);
	int pop();
	int topData();
};

void stack :: setNull()
{
	top = NULL;
}

void stack :: push(int x)
{
	stack *naya;
	naya = (stack*)malloc(sizeof(stack));
	if(!naya)
	{
		std :: cout << "memory error\n";
		return;
	}
	naya->data = x;
	naya->next = NULL;
	if(top == NULL)
	{
		naya->prev = NULL;
	}
	else
	{
		naya->prev = top;
		top->next = naya;
	}
	top = naya;
}

int stack :: pop()
{
	if(top == NULL)
	{
		std :: cout << "stack empty\n";
		return -1;
	}
	stack *temp;
	temp = top;
	int t = top->data;
	if(top->prev == NULL)
	{
		top = NULL;
	}
	else
	{
		top = temp->prev;
		top->prev = temp->prev->prev;
		top->next = NULL;	
	}
	free(temp);
	return t;
}

int stack :: topData()
{
	if(top == NULL)
	{
		std :: cout << "stack empty\n";
		return -1;
	}
	return top->data;
}

int main()
{
	stack a;
	a.setNull();
	a.push(2);
	a.push(3);
	cout << a.pop() << endl << a.topData() << endl;
	cout << a.pop() << endl;
	cout << a.pop() << endl << a.topData() << endl;
	stack b;
	b.setNull();
	b.push(2);
	b.push(3);
	cout << b.pop() << endl;
	cout << b.pop() << endl;
	cout << b.pop() << endl;
	return 0;
}

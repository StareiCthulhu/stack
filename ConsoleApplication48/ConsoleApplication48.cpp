// ConsoleApplication48.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

struct Node
{
	int value;
	Node *prev;
};

void push(int value, Node **top);
void output(Node **top);
int pop(Node **top);


int main(){
	Node *top = NULL;
	push( 1, &top );
	push( 2, &top );
	push( 3, &top );
	push( 4, &top );
	output( &top );
	std::cout << std::endl;

	for ( int i = 0; i < 4; i++ ){
		std::cout << pop(&top);
	}
	_gettch();
    return 0;
}

void push(int value, Node **top) {
	Node* elem = new Node();
	elem->value = value;

	if (*top == NULL) {
		*top = elem;
		elem->prev = NULL;
		return;
	}
	elem->prev = *top;
	*top = elem;
}

void output(Node **top) {
	Node* tmpTop = *top;

	while (tmpTop) {
		std::cout << tmpTop->value;
		tmpTop = tmpTop->prev;
	}
}

int pop(Node **top) {

	if (*top == NULL) {
		return(-1);
	}
	int tmpValue = (*top)->value;
	Node* tmpTop = *top;
	*top = (*top)->prev;
	delete tmpTop;
	return tmpValue;
}

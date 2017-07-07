/**
 * @file	Stack.h.
 *
 * @brief	Declares the stack class.
 */
#ifndef STACK_H_
#define STACK_H_

#include <iostream> /* cin/cout */
#include "ListElem.h"

//This implemetation of a stack is using the list in reverse!  

class Stack
{
private:
    ListElem* head;		//tail of the list, head of the stack
    ListElem* tail;		//head of the list, tail of the stack

public:
    Stack();
    void push(Student& student);
    bool pop(Student& student);
    void ausgabe() const;
};

#endif
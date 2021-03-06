/**
 * @file	Stack.cpp.
 *
 * @brief	Implements the stack class.
 */

#include "Stack.h"

/**
 * @fn	Stack::Stack()
 *
 * @brief	Default constructor.
 */
Stack::Stack(): head(NULL), tail(NULL)
{

}

/**
 * @fn	void Stack::push(Student &student)
 *
 * @brief	Pushes an object onto this stack.
 *
 * @param	student		The student to push.
 */
void Stack::push(Student &student)
{
	ListElem *new_element = new ListElem(student, NULL);
	if(head == NULL)									// list empty?
	{
		tail = new_element;								//set tail to first Element
	}
	else
	{
		new_element->setNext(head);						//newElem->next points to the elem before it (the old head)
	}
	head = new_element;									//new head of the stack is now the new element
}

/**
 * @fn	void Stack::ausgabe() const
 *
 * @brief	Prints this instance.
 */
void Stack::ausgabe() const
{	
	if(head == NULL)									// list empty?
	{
		std::cout << "Der Stack ist leer." << std::endl;
	}
	else
	{
		ListElem* cursor = head;
		while (cursor != NULL)
		{
			cursor->getData().print();
			cursor = cursor->getNext();
		}
	}
}

/**
 * @fn	bool Stack::pop(Student &student)
 *
 * @brief	Removes and returns the top-of-stack object.
 *
 * @param	student	The student to pop.
 *
 * @return	True if it succeeds, false if it fails.
 */
bool Stack::pop(Student &student)
{
    if (head == NULL)							//list empty???
	{ 
        return false;
	}
    else
	{
        student = head->getData();				//read Data from head
        ListElem* cursor = head;
        head = head->getNext();					//new head is one before old head (head->sN())
        delete cursor;							//delete old head
	}
    return true;
}

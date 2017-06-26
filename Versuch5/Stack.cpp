#include "Stack.h"

Stack::Stack(): head(NULL), tail(NULL)
{

}

void Stack::push(Student &n)
{
	ListElem *newElem = new ListElem(n, NULL);
	if(head == NULL)									// list empty?
	{
		tail = newElem;									//set tail to first Element
	}
	else
	{
		newElem->gN(head);								//newElem->next points to the elem before it (the old head)
	}
	head = newElem;										//new head of the stack is now the new element
}

void Stack::ausgabe() const
{	
	if(head == NULL)													 // list empty?
	{
		std::cout << "Der Stack ist leer." << std::endl;
	}
	else
	{
		ListElem* l = head;
		while (l != NULL)
		{
			l->sD().print();
			l = l->sN();
		}
	}
}

bool Stack::pop(Student &n)
{
    if (head == NULL)						//list empty???
	{ 
        return false;
	}
    else
	{
        n = head->sD();						//read Data from head
        ListElem* l = head;
        head = head->sN();					//new head is one before old head (head->sN())
        delete l;							//delete old head
	}
    return true;
}

/**
 * @file List.cpp
 * content: linked list data structure
 */

#include "List.h"

List::List(): head(NULL), tail(NULL)
{
}

ListElem *List::getFirst()
{
	return head;
}

/**
* @brief Dequeue an element from the end of the list.
*
* This is the double linked version.
*
* @param pData The data will be stored here.
* @return bool
*/
bool List::remove(ListElem* elem)
{
	if (head == NULL || elem == NULL)						// list empty? / elem not valid?
	{
		return false;
	}
	else if (head == elem)
	{
		elem->getNext()->setPrev(NULL);
		head = elem->getNext();
		delete elem;
	}
	else if (tail == elem)
	{
		tail->getPrev()->setNext(NULL);
		tail = elem->getPrev();
		delete elem;
	}
	else if (head == tail)                                  // only one element
	{
		if (head == elem)
		{
			head = NULL;
			tail = NULL;
			delete elem;
		}
	}
	else
	{
		ListElem *cursor = this->head;
		do
		{
			cursor = cursor->getNext();
			if (cursor == NULL)
				return false;
		} while (cursor != elem);

		cursor->getNext()->setPrev(cursor->getPrev());
		cursor->getPrev()->setNext(cursor->getNext());
		delete elem;
	}

	return true;
}

/**
* @brief Enqueue an element at the beginning of the list.
*
* @param pData The @ref Student to be added.
* @return void
*/
void List::enqueue_tail(const Student &pData)
{
	ListElem* new_element = new ListElem(pData, tail, NULL);

	if (head == NULL)                                       // list empty?
	{
		tail = new_element;									//list now only contains one element
		head = new_element;									//head and tail both pointing to it
	}
	else
	{
		tail->setNext(new_element);							//link old head and new element
	}

	tail = new_element;										//update head pointer
}

/**
 * @brief Enqueue an element at the beginning of the list.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::enqueue_head(const Student &pData)
{
    ListElem* new_element = new ListElem(pData, NULL, head);

    if (head == NULL)                                       // list empty?
    {
        tail = new_element;									//list now only contains one element
		head =  new_element;								//head and tail both pointing to it
    }
    else
    {
		head->setPrev(new_element);							//link old head and new element
    }

    head = new_element;										//update head pointer
}

/**
 * @brief Dequeue an element from the end of the list.
 *
 * This is the double linked version.
 *
 * @param pData The data will be stored here.
 * @return bool
 */
bool List::dequeue(Student& pData)
{
    if (head == NULL)                                       // list empty?
    {
        return false;
    }
    else if (head == tail)                                  // only one element
    {
        pData = head->getData();
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
	{
        pData = tail->getData();		//read data from tail
        tail = tail->getPrev();			//decrement tail
        delete tail->getNext();			//delete old tail
        tail->setNext(NULL);			//remove reference to old tail from new tail
    }

    return true;
}

/**
 * @brief Print content from first to last element.
 *
 * Prints to cout.
 *
 * @return void
 */
void List::print_forwards()
{
    ListElem* cursor = head;

    while (cursor != NULL)
    {
        cursor->getData().print();

        cursor = cursor->getNext();
    }
}

/**
* @brief Print content from last to first element.
*
* Prints to cout.
*
* @return void
*/
void List::print_backwards()
{
	ListElem* cursor = tail;

	while (cursor != NULL)
	{
		cursor->getData().print();

		cursor = cursor->getPrev();
	}
}

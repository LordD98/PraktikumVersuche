/**
* @file ListElem.cpp
*
* content: List element to be used in a data structure
*/

#include "ListElem.h"

/**
* @fn	ListElem::ListElem(const Student &new_elem, ListElem* const next)
*
* @brief	Constructor for ListElem.
*
* @param 		  	new_elem	The new element.
* @param			next		The next element.
*/
ListElem::ListElem(const Student &new_elem, ListElem* const prev, ListElem* const next) : data(new_elem), prev(prev), next(next)
{

}

/**
* @fn	void ListElem::setData(const Student &student)
*
* @brief	Sets the data of a ListElem.
*
* @param	student		The Student.
*/
void ListElem::setData(const Student &student)
{
	this->data = student;
}

/**
* @fn	void ListElem::setNext(ListElem* const next)
*
* @brief	Sets the next Element.
*
* @param	next
*/
void ListElem::setNext(ListElem* const next)
{
	this->next = next;
}


/**
* @fn	void ListElem::setPrev(ListElem* const prev)
*
* @brief	Sets the previous Element.
*
* @param	prev	The new previos Element
*/
void ListElem::setPrev(ListElem* const prev)
{
	this->prev = prev;
}

/**
* @fn	Student ListElem::getData() const
*
* @brief	Gets the saved Student.
*
* @return	The saved Student.
*/
Student ListElem::getData() const
{
	return this->data;
}

/**
* @fn	ListElem* ListElem::getNext() const
*
* @brief	Gets the next item.
*
* @return	Null if it fails, else the next.
*/
ListElem* ListElem::getNext() const
{
	return this->next;
}

/**
 * @fn	ListElem* ListElem::getPrev() const
 *
 * @brief	Gets the previous item.
 *
 * @return	Null if it fails, else the previous.
 */
ListElem* ListElem::getPrev() const
{
	return prev;
}

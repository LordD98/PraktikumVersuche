/**
 * @file ListElem.cpp
 *
 * content: List element to be used in a data structure
 */

#include "ListElem.h"

ListElem::ListElem(const Student &new_elem, ListElem* const prev, ListElem* const next): data(new_elem), next(next), prev(prev)
{

}

void ListElem::setData(const Student &s)
{
    data = s;
}


void ListElem::setNext(ListElem* const n)
{
    next = n;
}

void ListElem::setPrev(ListElem* const n)
{
	prev = n;
}


Student ListElem::getData() const
{
    return data;
}


ListElem* ListElem::getNext() const
{
    return next;
}

ListElem* ListElem::getPrev() const
{
	return prev;
}

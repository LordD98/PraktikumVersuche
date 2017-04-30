/**
 * @file ListElem.cpp
 *
 * content: List element to be used in a data structure
 */

#include "ListElem.h"

ListElem::ListElem(const Student &s, ListElem* const q):
    data(s), next(q)
{
}

void ListElem::gD(const Student &s)
{
    data = s;
}


void ListElem::gN(ListElem* const q)
{
    next = q;
}


Student ListElem::sD() const
{
    return data;
}


ListElem* ListElem::sN() const
{
    return next;
}

/**
 * @file ListElem.h
 *
 * content: List element to be used in a data structure
 */

#ifndef _LISTELEM_H_
#define _LISTELEM_H_

#include "Student.h"

class ListElem
{
private:
	Student data;
    ListElem* next;

public:
    ListElem(const Student &s, ListElem* const q);

    void gD(const Student &s);
    void gN(ListElem* const q);

    Student sD() const;
    ListElem* sN() const;
};

#endif

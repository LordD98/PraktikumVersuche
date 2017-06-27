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
    ListElem(const Student &new_elem, ListElem* const next);

    void setData(const Student &d);			//setData
    void setNext(ListElem* const n);		//setNext

    Student getData() const;				//getData
    ListElem* getNext() const;				//getNext
};

#endif

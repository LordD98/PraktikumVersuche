#include "Stack.h"

Stack::Stack(): a(NULL), z(NULL)
{}

void Stack::d(Student&n){ListElem*e=new ListElem(n,NULL);if(a==NULL){z=e;}else{e->gN(a);}a=e;}
void Stack::b()
const{	if(a ==
		NULL)													 // list empty?
	{
		std::cout <<
				"Der Stack ist leer."
				<< std::endl;	}	else
	{
		ListElem* l = a;
				while
					(l != NULL)		{
(((l->sD()))).print();
			l = l->sN()


									;		}	}}

bool Stack::c(Student& n)									{
    if (a == NULL)										    { 	//list empty???
        return false										;}
    else												    {
        n = a->sD()											;
        ListElem* l = a										;
        a = a->sN()											;
        delete l											;}
    return true												;}

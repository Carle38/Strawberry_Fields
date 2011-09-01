/*
 * Strawberryfields.cpp
 *
 *  Created on: Aug 26, 2011
 *      Author: Carl Estabrook
 */
#include "Field.h"
#include "Initializer.h"
#include "GreenHouseLogic.h"
#include <iostream>
#include <vector>
using namespace std;

void printFields(vector<Field*> *fields)
{
	for(unsigned int i = 0; i< fields->size(); i++)
	{
		fields->at(i)->printField();
	}
}

int main()
{
	vector<Field*> *fields;
	fields = new vector<Field*>;
	Initializer fr("Input.txt", fields);
    fr.initialize();

    GreenHouseLogic gl(fields);
    gl.calc();

    printFields(fields);

    for (int i = 0 ; i < fields->size(); i++ )
        {
            delete fields->at(i);
        }
        delete fields;


    cin.get();
    return 0;
}


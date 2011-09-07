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
	int total = 0;
	
	for(int i = 0; i< fields->size(); i++)
	{
		total += fields->at(i)->getTotal();
		fields->at(i)->printField();
	}

	cout<<endl;
	cout<<endl;

	cout<<"Total cost  = "<<total;
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


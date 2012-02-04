/*
 * Strawberryfields.cpp
 *
 *  Created on: Aug 26, 2011
 *      Author: Carl Estabrook
 *
 * This program solves the Strawberry fields problem at:
 * http://www.itasoftware.com/careers/work-at-ita/hiring-puzzles.html
 */
#include "Field.h"
#include "Initializer.h"
#include "GreenHouseLogic.h"
#include <iostream>
#include <vector>
using namespace std;
/*
 * Prints output by calling printField() 
 * on each individual field
 *
 * @param - *fields - vector of individual Field objects 
 *           calculations completed at this point
 */
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
    fr.initialize();                      // Initialize input line by line

    GreenHouseLogic gl(fields);
    gl.calc();                             // Greenhouse combination logic

    printFields(fields);

    for (int i = 0 ; i < fields->size(); i++ )
        {
            delete fields->at(i);
        }
        delete fields;


    cin.get();
    return 0;
}


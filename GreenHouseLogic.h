/*
 * GreenHouseLogic.h
 *
 *  Created on: Aug 28, 2011
 *      Author: Carl Estabrook
 */
#include "Field.h"

class GreenHouseLogic
{
public:
	GreenHouseLogic(std::vector<Field*> *vf);
	void calc();

private:
	void calcGreenHouses(Field*);
	void combineGreenHouses(Field*, int);
	int combineforCost(Greenhouse*, Greenhouse*, Field*);
	void firstCombine(Field*);
	void finalComb(Field*);
	void getHeight(Field*, Greenhouse*);
	void combine(Field*, int, int);
	int getvecSize(Field *F);
	int ghstats[5];
	int ghstat[5];
	std::vector<Field*> *m_fields;
	bool rec;
	bool right;
	bool bottom;
	bool finalCombine;

};

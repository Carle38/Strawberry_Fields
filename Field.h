/*
 * Field.h
 *
 *  Created on: Aug 26, 2011
 *      Author: Carl Estabrook
 */
#ifndef FIELD_H
#define FIELD_H

#include<vector>
#include "Plot.h"

static char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};

class Field
{
public:
	Field(int i);
	~Field();
	//void addPlot(Plot *p,int,int);
	void printField();
	void updatePlot(char, int, int);
	void addGreenHouses(Greenhouse*);
	int getTotalRecs() {return m_totalRecs;};
	Plot* getPlot(int, int);
	int getFieldLength() {return m_fieldPlots.size();};
	int getTotal();
	std::vector<Greenhouse*>* getGreenhouses() {return &m_Greenhouses;};
	int ploth,plotw;
private:
	void nullField();
	std::vector< std::vector<Plot*> > m_fieldPlots;
	std::vector<Greenhouse*> m_Greenhouses;
	int m_totalRecs;
	const static int m_height = 50;
	const static int m_width = 50;
	int m_ghnum;


};

#endif

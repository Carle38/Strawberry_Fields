/*
 * Plot.h
 *
 *  Created on: Aug 26, 2011
 *      Author: Carl Estabrook
 */
#ifndef PLOT_H
#define PLOT_H
#include "Greenhouse.h"

class Plot
{
public:
	Plot(){m_Greenhouse = 0;};
	Plot(char ch) {m_plotContents = ch; m_Greenhouse = 0;};
	void enclose(Greenhouse *g) {m_Greenhouse = g;};
	void setPlotContents(char ch) {m_plotContents = ch;};
	char getPlotContents() {return m_plotContents;};
	Greenhouse* getGreenhouse() {return m_Greenhouse;};

private:
	Greenhouse *m_Greenhouse;
	char m_plotContents;
	//bool inHouse;
};

#endif

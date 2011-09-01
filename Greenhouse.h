/*
 * Greenhouse.h
 *
 *  Created on: Aug 26, 2011
 *      Author: Carl Estabrook
 */
#ifndef GREENHOUSE_H
#define GREENHOUSE_H

class Greenhouse
{
public:
	Greenhouse(int, int);
	void setleft(int);
	int getleft() {return left;};
	void setRight(int b) {right = b;};
	int getRight() {return right;};
	void setTop(int b) {top = b;};
	int getTop() {return top;};
	void setBottom(int b) {bottom = b;};
	int getBottom() {return bottom;};
	void setNum(int n) { GhNum = n;};
	int getNum() { return GhNum;};
	//void setPlotNum(int b) {m_PlotNum = b;};
private:
	int left;
	int right;
	int top;
	int bottom;
	int GhNum;
	//int m_PlotNum;
};

#endif

/*
 * Field.cpp
 *
 *  Created on: Aug 27, 2011
 *      Author: Carl Estabrook
 */
#include "Field.h"
#include "Greenhouse.h"
#include <iostream>
using namespace std;
/*
 * Constructor of Field object
 * @param - i - number of rectangles to consider for individual field
 *
 */
Field::Field(int i) :m_totalRecs(i)
{
	 m_ghnum = 0;
	 m_fieldPlots.resize(m_height);
	 for (int i = 0; i < m_height; ++i)
	    m_fieldPlots[i].resize(m_width);

	 nullField();

}
Field::~Field()
{
	for(int i = 0; i < ploth; i++)
	  for(int k =0; k < plotw; k++)
	  {
		  delete m_fieldPlots[i][k];
	  }
	for(int i = 0; i < (int)m_Greenhouses.size(); i++)
	{
		delete m_Greenhouses.at(i);
	}
}
/*
 * Sets all plots in Field to null('-')
 *
 */
void Field::nullField()
{
	for (int i = 0; i < m_height; ++i)
		for(int j = 0; j < m_width; j++)
		{
			m_fieldPlots[i][j] = new Plot('-');

		}
}
/*
 * Sets contents of Plot
 *
 * @param - ch - either '-' or '@'
 * @param - height - width - specifies location of plot in 2d arraym_fieldPlots
 *
 */
void Field::updatePlot(char ch, int height, int width)
{
	m_fieldPlots[height][width]->setPlotContents(ch);
}
/*
 * Prints output of calculated field with optimal greenhouses
 */
void Field::printField()
{
	cout<<"Input";
	for (int i = 0; i < plotw-1; ++i)
		{
			cout<<" ";
		}
		cout<<" ";
		cout<<"Output"<<endl;
	cout<<m_totalRecs;

	for (int i = 0; i < plotw-1; ++i)
	{
		cout<<" ";
	}
	cout<<"     ";
	cout<<getTotal()<<endl;
	for (int i = 0; i < ploth; ++i)
	{
			    for(int j = 0; j < plotw; j++)
			    {
			        	cout<<m_fieldPlots[i][j]->getPlotContents();
			    }
			    cout<<"     ";
			    for(int j = 0; j < plotw; j++)
			   	{
			    	if(m_fieldPlots[i][j]->getGreenhouse() != 0)
			    	{
			    		cout<<letters[m_fieldPlots[i][j]->getGreenhouse()->getNum()-1];
			    	}
			    	else
			    	{

			   			cout<<m_fieldPlots[i][j]->getPlotContents();
			    	}
			   	}

			    cout<<endl;
	}
	 cout<<endl;
	 cout<<endl;
}
/*
 * adds Greenhouse to field
 *
 */
void Field::addGreenHouses(Greenhouse *gh)
{
	++m_ghnum;
	gh->setNum(m_ghnum);
	m_Greenhouses.push_back(gh);
}
Plot* Field::getPlot(int h, int w)
{
	return m_fieldPlots[h][w];
}
/*
 * calculates total cost expended on greenhouses for field
 * 10 for individual greenhouse
 * 1 for each plot covered by greenhouse
 *
 */
int Field::getTotal()
{
	int temp=0;
	int test = 0;
	int a = (int)m_Greenhouses.size();//test
	for(int i = 0; i < (int)m_Greenhouses.size(); i++)
	{
		if(m_Greenhouses.at(i) != 0)
		{
			temp+=10;
			for(int j = m_Greenhouses.at(i)->getTop(); j <= m_Greenhouses.at(i)->getBottom(); j++)
				for(int k = m_Greenhouses.at(i)->getleft(); k <= m_Greenhouses.at(i)->getRight(); k++)
					temp += 1;

		}
	}

	
	return temp;

}

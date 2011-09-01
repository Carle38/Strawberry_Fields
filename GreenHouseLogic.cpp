/*
 * GreenHouseLogic.cpp
 *
 *  Created on: Aug 28, 2011
 *      Author: Carl Estabrook
 */

#include "GreenHouseLogic.h"
#include "Field.h"
#include "Greenhouse.h"
#include <vector>
#include <iostream>
using namespace std;

GreenHouseLogic::GreenHouseLogic(vector<Field*> *vf)
{
	m_fields = vf;
	rec = false;
	right = false;
	bottom = false;
}

void GreenHouseLogic::calc()
{
	for(int i = 0; i < (int)m_fields->size(); i++)
	{
		calcGreenHouses(m_fields->at(i));
	    firstCombine(m_fields->at(i));
	    finalComb(m_fields->at(i));
	}
}

void GreenHouseLogic::firstCombine(Field *F)
{
	while(getvecSize(F) > F->getTotalRecs())
	{
		combineGreenHouses(F,100);
	}
}
void GreenHouseLogic::finalComb(Field *F)
{
	finalCombine = true;
	while(finalCombine)
	{
		finalCombine = false;
		combineGreenHouses(F,9);
	}
}
void GreenHouseLogic::combineGreenHouses(Field *F, int c)
{
	int high;
	int low;
	int cost = c;
	bool fcombine = false;

		for(int i =0; i < (F->getGreenhouses()->size()); i++)
		{
				for(int k = 0; k < (F->getGreenhouses()->size()); k++)
				{
					if(i != k && F->getGreenhouses()->at(i) != 0 && F->getGreenhouses()->at(k) != 0)
					{
						int temp = combineforCost(F->getGreenhouses()->at(i), F->getGreenhouses()->at(k), F);
						if(temp != -1)
						{
							if(temp <= cost)
							{
								fcombine = true;
								cost = temp;
								if(i < k)
								{
									low = i;
									high = k;
								}
								else
								{
									low = k;
									high = i;
								}
								ghstat[0]=ghstats[0];
								ghstat[1]=ghstats[1];
								ghstat[2]=ghstats[2];
								ghstat[3]=ghstats[3];
								ghstat[4]=ghstats[4];
							}
						}
					}
				}
			}
		if(fcombine)
		combine(F, low, high);
}


int GreenHouseLogic::getvecSize(Field *F)
{
	int size = 0;
	for(int i = 0; i < (int)F->getGreenhouses()->size(); i++)
	{
		if(F->getGreenhouses()->at(i)  != 0)
		{
			size +=1;
		}
	}
	return size;
}

void GreenHouseLogic::combine(Field *F, int low, int high)
{
	finalCombine = true;
	F->getGreenhouses()->at(low)->setTop(ghstat[0]);
	F->getGreenhouses()->at(low)->setleft(ghstat[1]);
	F->getGreenhouses()->at(low)->setRight(ghstat[2]);
	F->getGreenhouses()->at(low)->setBottom(ghstat[3]);

	for(int i = ghstat[0]; i <= ghstat[3]; i++)
		for(int j = ghstat[1]; j <= ghstat[2]; j++)
		{
			F->getPlot(i,j)->enclose(F->getGreenhouses()->at(low));
		}

	F->getGreenhouses()->at(high) = 0;
	int temp = 1;
	for(int i = 0; i < (int)F->getGreenhouses()->size(); i++)
	{
		if(F->getGreenhouses()->at(i)  != 0)
		{
			F->getGreenhouses()->at(i)->setNum(temp);
			temp += 1;
		}
	}
}

int GreenHouseLogic::combineforCost(Greenhouse *gh1, Greenhouse *gh2, Field *F)
{
	int count = 0;
	int plots = 0;

	if(gh1->getTop() < gh2->getTop())
		ghstats[0] = gh1->getTop();
	else
		ghstats[0] = gh2->getTop();

	if(gh1->getleft() < gh2->getleft())
		ghstats[1] = gh1->getleft();
	else
		ghstats[1] = gh2->getleft();

	if(gh1->getRight() > gh2->getRight())
		ghstats[2] = gh1->getRight();
	else
		ghstats[2] = gh2->getRight();

	if(gh1->getBottom() > gh2->getBottom())
		ghstats[3] = gh1->getBottom();
	else
		ghstats[3] = gh2->getBottom();

	for(int i = ghstats[0]; i <= ghstats[3]; i++)
		for(int j = ghstats[1]; j <= ghstats[2]; j++)
		{
			if(F->getPlot(i, j)->getGreenhouse() != 0)
			{
				if((F->getPlot(i, j)->getGreenhouse()->getNum() != gh1->getNum()) && (F->getPlot(i, j)->getGreenhouse()->getNum() != gh2->getNum()))
				{
					return -1;
				}
			}
			if(F->getPlot(i, j)->getPlotContents() == '.' && F->getPlot(i, j)->getGreenhouse() == 0)
				count += 1;

			plots += 1;
		}
	ghstats[4] = plots;
	return count;
}

void GreenHouseLogic::calcGreenHouses(Field *F)
{
	int h = F->ploth;
	int w = F->plotw;
	int i;
	Greenhouse *gh;
	rec = false;

	for(i = 0; i < h; i++)
	    for(int k =0; k < w; k++)
		{
	    	if((rec == false) && (F->getPlot(i,k)->getPlotContents() == '@') && (F->getPlot(i,k)->getGreenhouse() == NULL))
	    	{
	    		gh = new Greenhouse(i, k);
	    		F->addGreenHouses(gh);
	    		F->getPlot(i,k)->enclose(gh);
	    		rec = true;
	    		if(k == F->plotw)
	    		{
	    			right = true;
	    			rec = false;
	    			getHeight(F, gh);
	    			i = 0;
	    			break;
	    		}
	    	}
	    	else if((rec == true))
	    	{
	    		if((F->getPlot(i,k)->getPlotContents() == '@') && (F->getPlot(i,k)->getGreenhouse() == NULL))
		        {
	    			F->getPlot(i,k)->enclose(gh);
	    			gh->setRight(k);

	    			if(k == F->plotw)
					{
						right = true;
						rec = false;
						getHeight(F, gh);
						i = 0;
						break;
					}
		        }
	    		else if((F->getPlot(i,k)->getPlotContents() == '.'))
	    		{
	    			right = true;
    			    rec = false;
    			    getHeight(F, gh);
    			    i = 0;
    			    break;
	    		}
	    		else if((F->getPlot(i,k)->getGreenhouse() != NULL))
	    		{
	    			right = true;
					rec = false;
					getHeight(F, gh);
					i = 0;
					break;

	    		}
	    	}
		}
}

void GreenHouseLogic::getHeight(Field *F, Greenhouse *gh)
{
	int left = gh->getleft();
	int right = gh->getRight();
	int top = gh->getTop();
	int i, k;
	bool badline = false;

	for(i = (top+1); i< F->ploth; i++ )
	{
		badline = false;
		if((left > 0) && (right < F->plotw))
		{
			if(((F->getPlot(i, left-1)->getPlotContents() == '@') && (F->getPlot(i, right+1)->getPlotContents() == '@' )) && ((F->getPlot(i, left -1)->getGreenhouse() == 0) && (F->getPlot(i, right+1)->getGreenhouse() == 0)))
			{
				gh->setBottom(i - 1);
				return;
			}
			else
			{
				for(k = left; k <= right; k++)
				{
					if(F->getPlot(i, k)->getPlotContents() == '.')
						badline = true;
				}
				if(badline == false)
				{
					for(k = left; k <= right; k++)
					{
						F->getPlot(i, k)->enclose(gh);
					}
					gh->setBottom(i);
				}
				else
				{
				   return;
				}
			}
		}
		else
		{
			for(k = left; k <= right; k++)
			{
				if(F->getPlot(i, k)->getPlotContents() == '.')
					badline = true;
			}
			if(badline == false)
			{
				for(k = left; k <= right; k++)
				{
					F->getPlot(i, k)->enclose(gh);
				}
				gh->setBottom(i);
			}
		}
	}
}

/*
 * Greenhouse.cpp
 *
 *  Created on: Aug 28, 2011
 *      Author: Carl Estabrook
 */
#include "Greenhouse.h"
/*
 * constructor for Greenhouse
 * @param - i - initializes top and bottom location in 2d array
 * @param - k - initializes left and right positions
 *
 */
Greenhouse::Greenhouse(int i, int k)
{
	left = k;
	right = k;
	top = i;
	bottom = i;
}
void Greenhouse::setleft(int l)
{
	left = l;
}

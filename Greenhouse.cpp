/*
 * Greenhouse.cpp
 *
 *  Created on: Aug 28, 2011
 *      Author: Carl Estabrook
 */
#include "Greenhouse.h"

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

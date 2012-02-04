/*
 * Initializer.cpp
 *
 *  Created on: Aug 28, 2011
 *      Author: Carl Estabrook
 */

#include "Initializer.h"
#include "Field.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
/*
 * constructor 
 * @param - s - input file name
 * @param - *vf - pointer to vector of fields
 *
 */
Initializer::Initializer(string s, vector<Field*> *vf)
{
	m_filename = s;
	m_fields = vf;
	m_linenum = 0;
}
/*
 * Processes input line by line
 */
void Initializer::initialize()
{
	string str;
	ifstream  textfile (m_filename.c_str());

	while(textfile.good())
	{
		getline (textfile,str);
		processline(str);
		++m_linenum;
	}
	textfile.close();
}
// process line
void Initializer::processline(string st)
{
	string buff;
	stringstream ss(st);
	int plot = 0;

	while(ss>>buff)
	{
		  if(buff.find_first_not_of( "0123456789" )  == string::npos)
		  {
			  m_linenum = 0;
			  m_field = new Field(stringtoint(buff));
			  m_fields->push_back(m_field);
		  }
		  else
		  {
			  for(int i = 0; i < (int)buff.size(); i++)
			  {

				  m_field->updatePlot(buff[i], (m_linenum-1), plot);
				  ++plot;
			  }
			  m_field->plotw = plot;
			  m_field->ploth = m_linenum;
		  }
	}
}

int Initializer::stringtoint(string st)
{
	istringstream buffer(st);
	int value;
	buffer >> value;
	return value;
}

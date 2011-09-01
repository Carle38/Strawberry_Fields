/*
 * Initializer.h
 *
 *  Created on: Aug 28, 2011
 *      Author: Carl Estabrook
 */

#include "Field.h"
#include "Plot.h"
#include <string>


class Initializer
{
public:
	Initializer(std::string, std::vector<Field*> *vf);
	void initialize();
	void processline(std::string);
private:
	//void print();
	int stringtoint(std::string);
	std::string m_filename;
	std::string m_line;
	Plot *m_plot;
	Field *m_field;
	char ch;
	std::vector<Field*> *m_fields;
	int m_linenum;

};

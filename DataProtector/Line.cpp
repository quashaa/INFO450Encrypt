#include <iostream>
#include <string>
#include "Line.h"
using namespace std;

Line::Line()
{
	line = "";
}

string Line::getLine()
{
	return line;
}

void Line::setLine(string l)
{
	line = l;
}

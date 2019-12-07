#pragma once
#include <iostream>
#include <string>
#include "Line.h"
using namespace std;

class File
{
public:
	Line **content = new Line*[10000];
	int numLines;

	File();
	int encryptFile(string filename, string key);
	int decryptFile(string filename, string key);
};

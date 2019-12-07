#include <iostream>
#include <string>
#include <fstream>
#include "Line.h"
#include "File.h"
using namespace std;

File::File()
{
	numLines = 0;
}

int File::encryptFile(string filename, string key)
{
	// Read file
	ifstream iFile;

	iFile.open(filename, ios::in);

	if (!iFile)
	{
		cout << "\n[ERROR: File Open Failed!]" << endl;
		return -1;
	}

	// Temp holders
	int i = 0;
	string lineCapture;

	// Loops until eond of file
	while (!iFile.eof())
	{
		// Reads from the file
		getline(iFile, lineCapture, '\n');

		// Sets new line of content
		content[i] = new Line();
		content[i]->setLine(lineCapture);
		i++;
	}

	numLines = i;
	int lineChar;

	iFile.close();

	// Encryption algorithm
	for (i = 0; i < numLines; i++)
	{
		lineCapture = content[i]->getLine();

		for (lineChar = 0; lineChar < lineCapture.size(); lineChar++)
		{
			lineCapture[lineChar] = lineCapture[lineChar] + (key[lineChar%key.size()] + key.size());
		}

		content[i]->setLine(lineCapture);
	}

	// Write file
	ofstream oFile;

	oFile.open(filename, ios::in);

	if (!oFile)
	{
		cout << "\n[ERROR: File Open Failed!]" << endl;
		return -1;
	}

	i = 0;

	// Loops until no more lines
	while (i < numLines)
	{
		oFile << content[i]->getLine() << endl;
		i++;
	}

	oFile.close();

	cout << "\nFile " << filename << " was encrypted successfully!" << endl;

	return 0;
}

int File::decryptFile(string filename, string key)
{
	// Read file
	ifstream iFile;

	iFile.open(filename, ios::in);

	if (!iFile)
	{
		cout << "\n[ERROR: File Open Failed!]" << endl;
		return -1;
	}

	// Temp holders
	int i = 0;
	string lineCapture;

	// Loops until eond of file
	while (!iFile.eof())
	{
		// Reads from the file
		getline(iFile, lineCapture, '\n');

		// Sets new line of content
		content[i] = new Line();
		content[i]->setLine(lineCapture);
		i++;
	}

	numLines = i - 1;
	int lineChar;

	iFile.close();

	// Decryption algorithm
	for (i = 0; i < numLines; i++)
	{
		lineCapture = content[i]->getLine();

		for (lineChar = 0; lineChar < lineCapture.size(); lineChar++)
		{
			lineCapture[lineChar] = lineCapture[lineChar] - (key[lineChar%key.size()] + key.size());
		}

		content[i]->setLine(lineCapture);
	}

	// Write file
	ofstream oFile;

	oFile.open(filename, ios::trunc);

	if (!oFile)
	{
		cout << "\n[ERROR: File Open Failed!]" << endl;
		return -1;
	}

	i = 0;

	// Loops until no more lines
	while (i < numLines)
	{
		oFile << content[i]->getLine() << endl;
		i++;
	}

	oFile.close();

	cout << "\nFile " << filename << " was decrypted successfully!" << endl;

	return 0;
}

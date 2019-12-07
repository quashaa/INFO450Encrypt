#include <iostream>
#include <string>
#include "File.h"
using namespace std;

int main() 
{
	// Intro
	cout << "*** ********************* ***" << endl;
	cout << "***                       ***" << endl;
	cout << "***       Welcome To      ***" << endl;
	cout << "***    Data Protector!    ***" << endl;
	cout << "***                       ***" << endl;
	cout << "***     This app will     ***" << endl;
	cout << "***   enrypt a file or,   ***" << endl;
	cout << "***   decrypt a file of   ***" << endl;
	cout << "***     your choice!      ***" << endl;
	cout << "***                       ***" << endl;
	cout << "*** ********************* ***" << endl;
	cout << endl;

	system("pause");
	system("CLS");

	int option = 0;
	File *file = new File;

	// Loops until user exits
	while (option != 3)
	{
		cout << "\n***   Please choose one of the menu options below by entering the correspnding number  ***" << endl;
		cout << "1. Encrypt" << endl;
		cout << "2. Decrypt" << endl;
		cout << "3. Exit\n" << endl;
		cin >> option;
		cin.ignore();

		// Encrypt
		if (option == 1)
		{
			string eFile, key;

			cout << "\n(File Format: C:\\users\\path\\file.txt)" << endl;
			cout << "Enter the full path of the file to encrypt: ";
			getline(cin, eFile, '\n');

			cout << "Create a decryption key: ";
			getline(cin, key, '\n');

			file->encryptFile(eFile, key);
		}

		// Decrypt
		if (option == 2)
		{
			char answer = 'N';

			cout << "\nWas the file encrypted using this program? [Y/N]: ";
			cin >> answer;
			cin.ignore();
			
			if (answer == 'Y' || answer == 'y')
			{
				string dFile, key;

				cout << "\n(File Format: C:\\users\\path\\file.txt)" << endl;
				cout << "Enter the full path of the file to decrypt: ";
				getline(cin, dFile, '\n');

				cout << "Enter the decryption key for this file: ";
				getline(cin, key, '\n');

				file->decryptFile(dFile, key);
			}
			else 
			{
				cout << "\n The file needs to be encrypted by this program first!" << endl;
			}
			
		}
	}

	// Garbage collection
	for (int i = 0; i < file->numLines; i++)
	{
		delete file->content[i];
	}
	delete[] file->content;
	delete file;

	// Exit
	cout << "\n\n*** ********************* ***" << endl;
	cout << "***                       ***" << endl;
	cout << "***       GOOD BYE        ***" << endl;
	cout << "***                       ***" << endl;
	cout << "*** ********************* ***\n\n" << endl;

	system("pause");
	return 0;

	system("pause");
	return 0;
}
#include <iostream>
#include <fstream>
#include "bookinfo.h"
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"
#include "bookdata.h"

using namespace std;

const int NUM_BOOKS = 20;
BookData book[NUM_BOOKS];
const char FNAME[] = "inventory.dat";
fstream invFile;

int main()
{
	int choice = 0;

	invFile.open(FNAME, ios::in | ios::binary);

	if (invFile.fail())
	{
		invFile.open(FNAME, ios::out | ios::binary);
		invFile.close();
		invFile.clear();
		cout << "File created. You first need to add books to the inventory!\nPress enter to continue...";
		addBook();
	}
	else
	{
		int counter = 0;
		while (!invFile.eof() && counter < NUM_BOOKS)
		{
			invFile.seekg(counter * sizeof(book), ios::beg);
			invFile.read(reinterpret_cast<char*>(&book), sizeof(book));
			book[counter];
			counter++;
		}
		invFile.close();
		invFile.clear();
	}

	while (choice != 4)
	{
		cout << "Serendipity Booksellers\n";
		cout << "\tMain Menu\n\n";

		cout << "1. Cashier Module\n";
		cout << "2. Inventory Database Module\n";
		cout << "3. Report Module\n";
		cout << "4. Exit\n\n";

		cout << "Enter Your Choice: ";
		cin >> choice;

		//validate input
		while (choice < 1 || choice > 4)
		{
			cout << "\nPlease enter a number in the range 1 - 4\n";
			cout << "Enter your choice: ";
			cin >> choice;
		}

			switch (choice)
			{
			case 1:
				cashier();
				break;
			case 2:
				invMenu();
				break;
			case 3:
				reports();
				break;
			case 4:
				invFile.open(FNAME, ios::out | ios::binary);
				for (int i = 0; i < NUM_BOOKS; i++)
				{
					invFile.seekp(i * sizeof(book), ios::beg);
					invFile.write(reinterpret_cast<char*>(&book), sizeof(book));
				}
				invFile.close();
				invFile.clear();
				break;
			}

		cout << endl;
	}

	return 0;
}
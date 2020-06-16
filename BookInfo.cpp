#include "bookinfo.h"
#include <iostream>

using namespace std;
const int STR_SIZE = 51;

void bookInfo(char isbn[STR_SIZE], char title[STR_SIZE], char author[STR_SIZE], char publisher[STR_SIZE], char date[STR_SIZE], int qty, double wholesale, double retail)
{
	cout << "Serendipity Booksellers\n";
	cout << "   Book Information\n\n";

	cout << "ISBN: " << isbn << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Publisher: " << publisher << endl;
	cout << "Date Added: " << date << endl;
	cout << "Quantity on Hand: " << qty << endl;
	cout << "Wholesale Cost: " << wholesale << endl;
	cout << "Retail Price: " << retail << endl;

	cout << "Enter Your Choice: ";
}
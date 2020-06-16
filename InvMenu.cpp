#include "invmenu.h"
#include "bookinfo.h"
#include <iostream>
#include "strupper.h"
#include "bookdata.h"

using namespace std;
const int NUM_BOOKS = 20;
extern BookData book[NUM_BOOKS];

void invMenu()
{
	int choice = 0;

	while (choice != 5)
	{
		cout << "Serendipity Booksellers\n";
		cout << "   Inventory Database\n\n";

		cout << "1. Look Up a Book\n";
		cout << "2. Add a Book\n";
		cout << "3. Edit a Book's Record\n";
		cout << "4. Delete a Book\n";
		cout << "5. Return to the Main Menu\n\n";

		cout << "Enter Your Choice: ";
		cin >> choice;


		//validate input
		while (choice < 1 || choice > 5)
		{
			cout << "\nPlease enter a number in the range 1 - 5\n";
			cout << "Enter your choice: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			lookUpBook();
			break;
		case 2:
			addBook();
			break;
		case 3:
			editBook();
			break;
		case 4:
			deleteBook();
			break;
		case 5:
			cout << "\nYou selected item 5";
			break;
		}

		cout << endl;
	}//end while choice !=5
}

void lookUpBook()
{
	char YesNo = ' ';
	int row = 0;
	char title[STR_SIZE];

	cin.ignore();

	cout << "Enter the title of the book to search for: ";
	cin.getline(title, STR_SIZE);

	strUpper(title);

	for (row = 0; row < NUM_BOOKS; row++)
	{
		if (strstr(book[row].bookTitle,title))
		{
			cout << "\nPossible Match found: " << book[row].bookTitle << "\n\n";
			cout << "Is this a correct match? (Y or N)  ";
			cin >> YesNo;

			while (YesNo != 'Y' && YesNo != 'y' && YesNo != 'N' && YesNo != 'n')
			{
				cout << "Please enter Y or N\n\n";
				cout << "\nPossible Match found: " << book[row].bookTitle << "\n\n";
				cout << "Is this a correct match? (Y or N)  ";
				cin >> YesNo;
			}

			if (YesNo == 'Y' || YesNo == 'y')
			{
				bookInfo(book[row].isbn, book[row].bookTitle, book[row].author, 
					book[row].publisher, book[row].dateAdded, book[row].qtyOnHand, 
					book[row].wholesale, book[row].retail);
				break;
			}
		}
	}
	if (row > NUM_BOOKS -1)
		cout << "The book you searched for is not in the inventory" << endl;

}

void addBook()
{
	char title[STR_SIZE];
	char isbn[STR_SIZE];
	char publisher[STR_SIZE];
	char author[STR_SIZE];
	char date[STR_SIZE];
	int  quantity;
	double wholesale;
	double retail;
	int row;

	for (row = 0; row < NUM_BOOKS; row++)
	{
		//find the first book whose element is 0
		if (isEmpty(row))
		{
			cin.ignore();
			cout << "Enter Title: ";
			cin.getline(title, STR_SIZE);
			setTitle(title, row);

			cout << "Enter ISBN :";
			cin.getline(isbn, STR_SIZE);
			setISBN(isbn, row);

			cout << "Enter Author :";
			cin.getline(author, STR_SIZE);
			setAuthor(author, row);

			cout << "Enter Publisher :";
			cin.getline(publisher, STR_SIZE);
			setPub(publisher, row);

			cout << "Enter Date Added to Inventory :";
			cin.getline(date, STR_SIZE);
			setDateAdded(date, row);

			cout << "Enter Quantity Added :";
			cin >> quantity;
			setQty(quantity, row);

			cout << "Enter Wholesale Price :";
			cin >> wholesale;
			setWholesale(wholesale, row);

			cout << "Enter Retail Price:";
			cin >> retail;
			setRetail(retail, row);

			cout << "\n\nRecord was entered.";
			break;
		} //end if	
		cout << "No more books may be added\n";
	} //end for loop
}

void editBook()
{
	char title[STR_SIZE];
	char isbn[STR_SIZE];
	char publisher[STR_SIZE];
	char author[STR_SIZE];
	char date[STR_SIZE];
	int  quantity;
	double wholesale;
	double retail;
	int row;
	int choice = 0;
	char YesNo = ' ';

	cin.ignore();

	cout << "Enter thetitle of the book to edit: ";
	cin.getline(title, STR_SIZE);
	strUpper(title);

	for (row = 0; row < NUM_BOOKS; row++)
	{
		if (strstr(book[row].bookTitle, title))
		{
			cout << "\nPossible Match found: " << book[row].bookTitle << "\n\n";
			cout << "Is this a correct match? (Y or N)  ";
			cin >> YesNo;

			while (YesNo != 'Y' && YesNo != 'y' && YesNo != 'N' && YesNo != 'n')
			{
				cout << "Please enter Y or N\n\n";
				cout << "\nPossible Match found: " << book[row].bookTitle << "\n\n";
				cout << "Is this a correct match? (Y or N)  ";
				cin >> YesNo;
			}

			if (YesNo == 'Y' || YesNo == 'y')
			{
				bookInfo(book[row].isbn, book[row].bookTitle, book[row].author,
					book[row].publisher, book[row].dateAdded, book[row].qtyOnHand,
					book[row].wholesale, book[row].retail);

				do
				{
					cout << "\nYou may edit any of the following: " << endl;
					cout << "1. ISBN\n";
					cout << "2. Title\n";
					cout << "3. Author\n";
					cout << "4. Publisher\n";
					cout << "5. Date book was added to inventory\n";
					cout << "6. Quantity on hand\n";
					cout << "7. Wholesale cost\n";
					cout << "8. Retail Price\n";
					cout << "9. Exit\n\n";
					cin >> choice;

					while (choice < 1 || choice > 9)
					{
						cout << "\nPlease enter a number in the range between 1 and 9." << endl;
						cout << "Enter your choice :";
						cin >> choice;
					}

					switch (choice)
					{
					case 1:
						cout << "\nCurrent ISBN: ";
						cout << book[row].isbn << endl;
						cin.ignore();
						cout << "Enter new ISBN: ";
						cin.getline(isbn, STR_SIZE);
						setISBN(isbn, row);
						break;
					case 2:
						cout << "\nCurrent Title: ";
						cout << book[row].bookTitle << endl;
						cin.ignore();
						cout << "Enter new Title: ";
						cin.getline(title, STR_SIZE);
						setTitle(title, row);
						break;
					case 3:
						cout << "\nCurrent Author: ";
						cout << book[row].author << endl;
						cin.ignore();
						cout << "Enter new Author: ";
						cin.getline(author, STR_SIZE);
						setAuthor(author, row);
						break;
					case 4:
						cout << "\nCurrent Publisher: ";
						cout << book[row].publisher << endl;
						cin.ignore();
						cout << "Enter new Publisher: ";
						cin.getline(publisher, STR_SIZE);
						setPub(publisher, row);
						break;
					case 5:
						cout << "\nCurrent Date Added: ";
						cout << book[row].dateAdded << endl;
						cin.ignore();
						cout << "Enter new Date: ";
						cin.getline(date, STR_SIZE);
						setDateAdded(date, row);
						break;
					case 6:
						cout << "\nCurrent Quantity on Hand: ";
						cout << book[row].qtyOnHand << endl;
						cin.ignore();
						cout << "Enter new Quantity On Hand: ";
						cin >> quantity;
						setQty(quantity, row);
						break;
					case 7:
						cout << "\nCurrent Wholesale Cost: ";
						cout << book[row].wholesale << endl;
						cin.ignore();
						cout << "Enter new Wholesale Cost: ";
						cin >> wholesale;
						setWholesale(wholesale, row);
						break;
					case 8:
						cout << "\nCurrent Retail Price: ";
						cout << book[row].retail << endl;
						cin.ignore();
						cout << "Enter new Retail Price: ";
						cin >> retail;
						setRetail(retail, row);
						break;
					}
				} while (choice != 9);
				break;
			}// end if yesno
		}
	} //end for loop
	if (row > NUM_BOOKS - 1)
		cout << "\nSorry, no title matching: " << title << " was found\n\n";
}


void deleteBook()
{
	char title[STR_SIZE];
	int row = 0;
	char YesNo = ' ';

	cin.ignore();

	cout << "Enter the title of the book to delete: ";
	cin.getline(title,STR_SIZE);

	strUpper(title);

	for (row = 0; row < NUM_BOOKS; row ++)
	{
		if (strstr(book[row].bookTitle, title))
		{
			cout << "\nPossible Match found: " << book[row].bookTitle << "\n\n";
			cout << "Is this a correct match? (Y or N)  ";
			cin >> YesNo;

			while (YesNo != 'Y' && YesNo != 'y' && YesNo != 'N' && YesNo != 'n')
			{
				cout << "Please enter Y or N\n\n";
				cout << "\nPossible Match found: " << book[row].bookTitle << "\n\n";
				cout << "Is this a correct match? (Y or N)  ";
				cin >> YesNo;
			}

			if (YesNo == 'Y' || YesNo == 'y')
			{
				bookInfo(book[row].isbn, book[row].bookTitle, book[row].author,
					book[row].publisher, book[row].dateAdded, book[row].qtyOnHand,
					book[row].wholesale, book[row].retail);
				cout << "Would you like to delete entire record? Y/N\: ";
				cin >> YesNo;

				while (YesNo != 'Y' && YesNo != 'y' && YesNo != 'N' && YesNo != 'n')
				{
					cout << "Please enter Y or N\n\n";
					cout << "\nPossible Match found: " << book[row].bookTitle << "\n\n";
					cout << "Would you like to delete entire record? Y/N\: ";
					cin >> YesNo;
				}

				if (YesNo == 'Y' || YesNo == 'y')
				{
					removeBook(row);
					cout << "\nRecord was deleted\n";
				}
				else
					cout << "\nRecord was NOT deleted\n";
				break;
			}			
		}
	}
	if (row > NUM_BOOKS - 1)
		cout << "\nSorry, no title matching: " << title << " was found\n\n";
}
#include "reports.h"
#include <iostream>
#include <iomanip>
#include "bookdata.h"

using namespace std;
const int NUM_BOOKS = 20;
extern BookData book[NUM_BOOKS];

void reports()
{
	int choice = 0;

	while (choice != 7)
	{

		cout << "Serendipity Booksellers\n";
		cout << "\tReports\n\n";

		cout << "1. Inventory Listing\n";
		cout << "2. Inventory Wholesale Value\n";
		cout << "3. Inventory Retail Value\n";
		cout << "4. Listing by Quantity\n";
		cout << "5. Listing by Cost\n";
		cout << "6. Listing by Age\n";
		cout << "7. Return to the Main Menu\n\n";

		cout << "Enter Your Choice: ";
		cin >> choice;

		//validate input
		while (choice < 1 || choice > 7)
		{
			cout << "\nPlease enter a number in the range 1 - 7\n";
			cout << "Enter your choice: ";
			cin >> choice;
		}
			switch (choice)
			{
			case 1:
				repListing();
				break;
			case 2:
				repWholesale();
				break;
			case 3:
				repRetail();
				break;
			case 4:
				repQty();
				break;
			case 5:
				repCost();
				break;
			case 6:
				repAge();
				break;
			case 7:
				cout << "\nYou selected item 7";
				break;
			}

		cout << endl;

	}//end while choice !=7
}

void repListing()
{
	char end[] = { '\0' };
	char date[STR_SIZE]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Inventory Report\n";
	cout << "Date: \t\t" << date;

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(book[i].isbn, end) != 0) //not printing empty records
		{
			cout << "\n_____________________________________________________";
			cout << "\n\n\Title:\t\t\t" << book[i].bookTitle;
			cout << "\nISBN:\t\t\t" << book[i].isbn;
			cout << "\nAuthor:\t\t\t" << book[i].author;
			cout << "\nPublisher:\t\t" << book[i].publisher;
			cout << "\nDate Added:\t\t" << book[i].dateAdded;
			cout << fixed << showpoint << left << setprecision(2);
			cout << "\nQuantity on Hand:\t" << book[i].qtyOnHand;
			cout << "\nWholesale Cost: \t\t$ " << book[i].wholesale;
			cout << "\nRetail Price:\t\t $" << book[i].retail;
		}
	}

	cout << "\n\n________________________________________________________";
	cout << "\n\nEnd of Inventory Report\n\n\n";

	//pause report on screen
	cout << "Press Enter to continue";
	cin.ignore();
	cin.get();
}

void repWholesale()
{
	char end[] = { '\0' };
	char date[STR_SIZE]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Wholesale Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tWholesale\n";
	cout << "\t__________________________________________________\n\n";

	double itemSubTotal;
	double subTotal = 0;

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(book[i].isbn, end) != 0) //not printing empty records
		{
			cout << "\n\t" << left << setw(26) << book[i].bookTitle;
			cout << left << setw(14) << book[i].isbn;
			cout << right << setw(6) << book[i].qtyOnHand << "\t";
			cout << fixed << showpoint << right << setprecision(2);
			cout << setw(6) << "\t$ " << book[i].wholesale;

			itemSubTotal = book[i].qtyOnHand * book[i].wholesale;
			subTotal += itemSubTotal;
		}
	}

	cout << "\n\n\n\tTotal Wholesale Value: $ " << subTotal << endl;
	cout << "\t_____________________________________________________________\n";
	cout << "\n\tEnd of Wholesale Report\n\n\n";

	//pause report on screen
	cout << "Press Enter to continue";
	cin.ignore();
	cin.get();
}

void repRetail()
{
	char end[] = { '\0' };
	char date[STR_SIZE]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Retail Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tRetail\n";
	cout << "\t__________________________________________________\n\n";

	double itemSubTotal;
	double subTotal = 0;

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(book[i].isbn, end) != 0) //not printing empty records
		{
			cout << "\n\t" << left << setw(26) << book[i].bookTitle;
			cout << left << setw(14) << book[i].isbn;
			cout << right << setw(6) << book[i].qtyOnHand << "\t";
			cout << fixed << showpoint << right << setprecision(2);
			cout << setw(6) << "\t$ " << book[i].retail;

			itemSubTotal = book[i].qtyOnHand * book[i].retail;
			subTotal += itemSubTotal;
		}
	}

	cout << "\n\n\n\tTotal Retail Value: $ " << subTotal << endl;
	cout << "\t_____________________________________________________________\n";
	cout << "\n\tEnd of Retail Report\n\n\n";

	//pause report on screen
	cout << "Press Enter to continue";
	cin.ignore();
	cin.get();
}

void repQty()
{
	int id[NUM_BOOKS]; //array to track original subscripts
	int* idPtr[NUM_BOOKS]; //pointer to tracking array
	int* qtyPtr[NUM_BOOKS]; //array of pointers to qtyOnHand array

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		qtyPtr[i] = &book[i].qtyOnHand;
	}

	int startScan;
	int maxIndex;
	int* tempId;
	int* maxValue;

	//selection sort to do qtyOnHand in descending order
	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = qtyPtr[startScan];
		tempId = idPtr[startScan];

		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(qtyPtr[index]) > *maxValue)
			{
				maxValue = qtyPtr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}

		qtyPtr[maxIndex] = qtyPtr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		qtyPtr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

	char date[STR_SIZE]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Quantity Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\n";
	cout << "\t__________________________________________________\n\n";

	char end[] = { '\0' };
	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(book[j].isbn, end) != 0) //not printing empty records
		{
			cout << "\n\t" << book << setw(26) << book[*(idPtr[j])].bookTitle;
			cout << left << setw(14) << book[*(idPtr[j])].isbn;
			cout << right << setw(6) << *qtyPtr[j] << "\n";
		}
	}

	cout << "\t_____________________________________________________________\n";
	cout << "\n\tEnd of Quantity Report\n\n\n";

	//pause report on screen
	cout << "Press Enter to continue";
	cin.ignore();
	cin.get();
}

void repCost()
{
	int id[NUM_BOOKS]; //array to track original subscripts
	int* idPtr[NUM_BOOKS]; //pointer to tracking array
	double* wholePtr[NUM_BOOKS]; //array of pointers to wholesale array

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		wholePtr[i] = &book[i].wholesale;
	}

	int startScan;
	int maxIndex;
	int* tempId;
	double* maxValue;

	//selection sort to do qtyOnHand in descending order
	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = wholePtr[startScan];
		tempId = idPtr[startScan];

		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(wholePtr[index]) > *maxValue)
			{
				maxValue = wholePtr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}

		wholePtr[maxIndex] = wholePtr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		wholePtr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

	char date[STR_SIZE]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Cost Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tWholesale\n";
	cout << "\t__________________________________________________\n\n";

	char end[] = { '\0' };
	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(book[j].isbn, end) != 0) //not printing empty records
		{
			cout << "\n\t" << left << setw(26) << book[*(idPtr[j])].bookTitle;
			cout << left << setw(14) << book[*(idPtr[j])].isbn;
			cout << fixed << showpoint << right << setprecision(2);
			cout << right << setw(6) << book[j].qtyOnHand;
			cout << setw(6) << "\t$ " << *wholePtr[j] << "\n";
		}
	}

	cout << "\t_____________________________________________________________\n";
	cout << "\n\tEnd of Cost Report\n\n\n";

	//pause report on screen
	cout << "Press Enter to continue";
	cin.ignore();
	cin.get();

}

void repAge()
{
	int id[NUM_BOOKS]; //array to track original subscripts
	int* idPtr[NUM_BOOKS]; //pointer to tracking array
	char* datePtr[NUM_BOOKS]; //array of pointers to date added array

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		datePtr[i] = book[i].dateAdded;
	}

	int startScan;
	int maxIndex;
	int* tempId;
	char* maxValue;

	//selection sort to do qtyOnHand in descending order
	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = datePtr[startScan];
		tempId = idPtr[startScan];

		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(datePtr[index]) > *maxValue)
			{
				maxValue = datePtr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}

		datePtr[maxIndex] = datePtr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		datePtr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

	char date[STR_SIZE]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Age Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tDateAdded\n";
	cout << "\t__________________________________________________\n\n";

	char end[] = { '\0' };
	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(book[j].isbn, end) != 0) //not printing empty records
		{
			cout << "\n\t" << left << setw(26) << book[*(idPtr[j])].bookTitle;
			cout << left << setw(14) << book[*(idPtr[j])].isbn;
			cout << fixed << showpoint << right << setprecision(2);
			cout << right << setw(6) << book[j].qtyOnHand;
			cout << setw(6) << "\t " << book[*(idPtr[j])].dateAdded << "\n";
		}
	}

	cout << "\t_____________________________________________________________\n";
	cout << "\n\tEnd of Age Report\n\n\n";

	//pause report on screen
	cout << "Press Enter to continue";
	cin.ignore();
	cin.get();
}
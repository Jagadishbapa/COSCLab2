// ListProcessor.cpp

// tom bailey   1540  30 sep 2011

// tom bailey   1030  27 jan 2012
// Exercise the List class with verbose Node constructor
//   and destructor.

#include "LinkedList.h"


int main()
{
	List cows;
    cows.insertAsLast(7.4);
	cout << "cows list  :  " << cows << endl << endl;
	cout << cows.size() << endl;

    cows.insertAsLast(2.5);
	cows.insertAsFirst(1.23);
	cows.insertAsFirst(2.34);

	cout << "cows list  :  " << cows << endl << endl;
    cout << cows.size() << endl;
    cout << cows.sum() << endl;

	cows.removeFirst();
	cout << "cows list  :  " << cows << endl << endl;
	cout << cows.size() << endl;
    cout << cows.sum() << endl;

	List horses(cows);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;
	cout << cows.size() << endl;
	cout << horses.size() << endl;
    cout << cows.sum() << endl;
    cout << horses.sum() << endl;

	horses.removeFirst();
	horses.insertAsFirst(5.67);
	cows.insertAsFirst(6.78);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;
	cout << cows.size() << endl;
	cout << horses.size() << endl;
    cout << cows.sum() << endl;
    cout << horses.sum() << endl;

	List pigs;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;
	cout << cows.size() << endl;
	cout << horses.size() << endl;
	cout << pigs.size() << endl;
    cout << cows.sum() << endl;
    cout << horses.sum() << endl;
    cout << pigs.sum() << endl;

	pigs = cows;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;
	cout << cows.size() << endl;
	cout << horses.size() << endl;
	cout << pigs.size() << endl;
    cout << cows.sum() << endl;
    cout << horses.sum() << endl;
    cout << pigs.sum() << endl;

	pigs = horses;
    cows.insertAsLast(8.9);
    pigs.insertAsLast(6);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;
	cout << cows.size() << endl;
	cout << horses.size() << endl;
	cout << pigs.size() << endl;
    cout << cows.sum() << endl;
    cout << horses.sum() << endl;
    cout << pigs.sum() << endl;

	cout << "End of code" << endl;

	return 0;
}


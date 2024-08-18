// Project6_MyStackArr 
#include <iostream>
#include "clsMyStackArr.h";
using namespace std;

int main()
{

	clsMyStackArr <string> stack1;

	stack1.push("Reda");
	stack1.push("Mohammad");
	stack1.push("Ahmed");
	stack1.push("Omar");
	stack1.push("Ali");

	cout << "\n-----Stack:\n";
	stack1.Print();

	cout << "\n\nStack Size    : " << stack1.Size() << endl;
	cout << "Stack Top     : " << stack1.Top() << endl;
	cout << "Stack Bottom  : " << stack1.Bottom() << endl;

	stack1.pop();
	cout << "\n-----Stack After pop(): \n";
	stack1.Print();

	//Extension #1
	cout << "\nGet Item(2): " << stack1.GetItem(2) << endl;

	//Extension #2
	cout << "Reverse Stack: ";
	stack1.Reverse();
	stack1.Print();

	//Extension #3
	cout << "\nUpdate Item(2): ";
	stack1.UpdateItem(2, "Khalid");
	stack1.Print();

	//Extension #4
	cout << "\nInsert After Item(2): ";
	stack1.InsertAfter(2, "Ali");
	stack1.Print();

	//Extension #5
	cout << "\nInsert At Top: ";
	stack1.InsertAtTop("Maher");
	stack1.Print();

	//Extension #6
	cout << "\nInsert At Bottom: ";
	stack1.InsertAtBottom("Yousef");
	stack1.Print();

	//Extension #7
	cout << "\nStack After Clear(): ";
	stack1.Clear();
	stack1.Print();

	system("pause>0");
	return 0;
}



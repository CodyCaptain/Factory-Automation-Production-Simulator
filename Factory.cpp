// Factory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Order;
Order* head = NULL;

class Order
{
public:
	int ID;
	int quantity;
	int priority;
	string name;
	string status;
	Order* next;

public: 
	// Order(int q, int p, string n)
	// {
	// 	ID = Identification();
	// 	quantity = q;
	// 	priority = p;
	// 	name = n;
	// 	next = NULL;
	// 	status = "Pending";
	// }

	Order()
	{
		// ID = Identification();
		quantity = 0;
		priority = 0;
		name = "";
		next = NULL;
		status = "Pending";
	}


	void request( int y, int z, string r) //  Implement a function to display all student records by traversing the linked list.

	{
		Order* fungus = new Order;
		if (head == NULL)
		{
			head = fungus;
			fungus->next = NULL;
			fungus->name = r;
			fungus->priority = z;
			fungus->quantity = y;
			fungus->ID = Identification();
			return;
		}
		else
		{
			Order* trigger = head;
			while (trigger->next != NULL)
			{
				trigger = trigger->next;
			}
			trigger->next = NULL;
			trigger->name = r;
			trigger->priority = z;
			trigger->quantity = y;
			trigger->ID = Identification();
			return;
		}
	}


	
	int Identification()
	{
		Order* trigger = head;
		if (trigger == NULL)
		{
			return 1000;
		}
			while (trigger->next != NULL)
			{
				trigger = trigger->next;
			}
			return trigger->ID + 1;
	}
};
void display()
{
	Order* trigger = head;

	
	while (trigger != NULL) // traversal
	{
		cout << "ID: " << trigger->ID;
		cout << endl;
		cout << "Name: " << trigger->name;
		cout << endl;
		cout << "Quantity: " << trigger->quantity;
		cout << endl;
		cout << "Priority: " << trigger->priority;
		cout << endl << endl;

		trigger = trigger->next;
	}

	if (trigger == NULL) // no node condition
	{
		cout << "No student enrolled. " << endl;
		return;
	}
}
int main()
{
	Order O1;
		O1.request(1, 2, "shabbiber");

	Order O2;
			O2.request(1, 2, "shabbiber");
	display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

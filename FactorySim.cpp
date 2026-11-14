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


	void request(int y, int z, string r) //places order

	{
		Order* fungus = new Order;
		fungus->ID = Identification();

		if (head == NULL)
		{
			head = fungus;
			fungus->next = NULL;
			fungus->name = r;
			fungus->priority = z;
			fungus->quantity = y;
			return;
		}
		else
		{
			Order* trigger = head;
			while (trigger->next != NULL)
			{
				trigger = trigger->next;
			}

			fungus->name = r;
			fungus->priority = z;
			fungus->quantity = y;

			trigger->next = fungus;
		}
	}

	void remove(int x) //shabbir figure this out pls i have to go basketball
	{
		Order* trigger = head;

	}

	int Identification() //assigns ID 
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

void search(int x) //searches the linked list for a particular ID
{
	Order* trigger = head;
	
	if (trigger == NULL) // no node condition
	{
		cout << "Order not found." << endl;
		return;
	}
	while (trigger != NULL)
	{
	
		if (trigger->ID == x)
		{
			cout << "ID: " << trigger->ID;
			cout << endl;
			cout << "Name: " << trigger->name;
			cout << endl;
			cout << "Quantity: " << trigger->quantity;
			cout << endl;
			cout << "Priority: " << trigger->priority;
			cout << endl;
			cout << "Status: " << trigger->status;
			cout << endl << endl;
			return;
		}

		else {
			trigger = trigger->next;
		}
	}

}

void display() // displays the linked list
{
	Order* trigger = head;

	if (trigger == NULL) // no node condition
	{
		cout << "No orders in queue." << endl;
		return;
	}

	while (trigger != NULL) // traversal
	{
		cout << "ID: " << trigger->ID;
		cout << endl;
		cout << "Name: " << trigger->name;
		cout << endl;
		cout << "Quantity: " << trigger->quantity;
		cout << endl;
		cout << "Priority: " << trigger->priority;
		cout << endl;
		cout << "Status: " << trigger->status;
		cout << endl << endl;

		trigger = trigger->next;
	}

}
int main()
{
	Order O1;
	O1.request(1, 2, "Order A");

	Order O2;
	O2.request(3, 1, "Order B");

	Order O3;
	O3.request(5, 3, "Order C");

	display();

	search(1000);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

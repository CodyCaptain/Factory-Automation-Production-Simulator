// Factory.cpp : This file contains the 'main' function. Program execution begins and ends there.

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

	Order()
	{
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
		cout << "\nOrder not found." << endl;
		return;
	}
	while (trigger != NULL)
	{

		if (trigger->ID == x)
		{
			cout << "\nID: " << trigger->ID;
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
	cout << "\nOrder ID " << x << " not found";

}

void remove(int x) 
{
	if (head == NULL) {
		cout << "\nOrder ID not found" << endl;
		return;
	}
	Order* trigger = head;

	if (trigger->ID == x) {
		head = head->next;
		delete trigger;
		return;
	}
	else {
		Order* temp2 = NULL;
		while (trigger->next != NULL and trigger->ID != x)
		{
			temp2 = trigger;
			trigger = trigger->next;
		}
		if (trigger->next == NULL and trigger->ID != x) {
			cout << "\nOrder ID Not found";
		}
		else if (trigger->ID == x) {
			temp2->next = trigger->next;
			delete trigger;
		}
	}
}
void display() // displays the linked list
{
	Order* trigger = head;

	if (trigger == NULL) // no node condition
	{
		cout << "\nNo orders in queue." << endl;
		return;
	}

	while (trigger != NULL) // traversal
	{
		cout << "\nID: " << trigger->ID;
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
	int choice_1 = 0;
	int choice_2 = 0;
	int operatingID = 0;

	do {
		cout << "\n===== Factory Automation ======\n";
		cout << "\n1. Create Order\n2. View & Manipulate Orders\n3. Process Production\n4. View Machines\n5. View Production Reports\n6. Exit\n";
		cout << "\nEnter your choice: ";
		cin >> choice_1;
		switch (choice_1) {
		case 1: {
			string product_name;
			int priority;
			int quantity;
			cout << "\nEnter Product Name: ";
			cin.ignore();
			getline(cin, product_name);
			cout << "Enter Quantity of the Product: ";
			cin >> quantity;
			cout << "Enter Priority of the Product: ";
			cin >> priority;
			Order temp;
			temp.request(quantity, priority, product_name);
			cout << "Order created succesfully\n";
			break;
		}
		case 2:
			do {
				cout << "\n----- ORDER MANAGEMENT -----\n";
				cout << "\n1. View All Orders\n2. Search Order by ID\n3. View Pending Orders\n4. View In-Progress Orders\n5. View Completed Orders\n6. Delete Pending Order\n7. Return to main menu\n";
				cout << "\nEnter Your Choice: ";
				cin >> choice_2;

				switch (choice_2) {
				case 1:
					display();
					break;
				case 2:
					cout << "Enter the order ID to search: ";
					cin >> operatingID;
					search(operatingID);
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					cout << "Enter the order ID to delete the order: ";
					cin >> operatingID;
					remove(operatingID);
					break;
				case 7:
					cout << "Exiting to Main Menu.\n";
					break;
				default:
					cout << "Invalid Choice\n";
					break;
				}
			} while (choice_2 != 7);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			cout << "Exiting the Factory Automation.\n";
			break;
		}
	} while (choice_1 != 6);
	return 0;
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
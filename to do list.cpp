#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;



struct node
{
	string data;
	node* next;
	char status='P';

};

void logo()
{

	cout << setfill('*') << setw(120);
	cout << " ";
	cout << setfill(' ') << setw(70);
	cout << "  WELCOME to 'TO DO LIST' " << endl;

	cout << setfill('*') << setw(120);
	cout << " ";


}

void input(node*& head, string new_data)


{
	int ad;
	cout << "How many Tasks Do you want to Add: ";
	cin >> ad;

	cout << "Enter Your Tasks: " << endl;

	for (int i = 1; i <= ad; i++)
	{

		string new_data;
		cout << "Enter task # " << i << " :";

		cin >> new_data;


		node* newnode = new node();

		newnode->data = new_data;

		newnode->next = nullptr;

		if (head == nullptr)
		{
			
			head = newnode;
		}
		else
		{
			
			node* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newnode;
		}

		


		cout << endl;

	}

	cout << "Tasks inserted Succesfully" << endl;



}

void display(node*& head, string new_data,char stat)
{
	

	int i = 0;
	node* temp = head;

	if (head == NULL)
	{
		cout << "list is empty" << endl;
		return;

	}

	cout << "Following are your tasks: " << endl;
	while (temp != NULL)
	{

		cout << i + 1 << ". " << temp->data << " " << "Status : " << temp->status << endl;
		temp = temp->next;
		i++;
	}

	cout << endl;

}

void deli(node*& head)
{
	int num;
	node* temp = head, * temp1 = nullptr;

	cout << "Enter Task number you want to delete : ";
	cin >> num;


	if (head == nullptr)
	{

		cout << "List is empty" << endl;
		return;

	}

	temp = head;

	if (num == 1)
	{

		head = head->next;

		delete temp;

		cout << "Task deleted succesfully" << endl << endl;
		return;
	}

	for (int i = 1; i < num && temp != nullptr; i++)
	{
		
		temp1 = temp;
		temp = temp->next;
	}

	if (temp == nullptr)
	{
		cout << "Invalid task number" << endl;
		return;
	}

	temp1->next = temp->next;


	delete temp;


	cout << "Task deleted succesfully" << endl << endl;

}

char complete(char stat)
{


	return (stat == 'P') ? 'C' : 'P';


}

void comp(node*& head,char stat)
{
	
	
	
	int ind;
	cout << "Enter index of your task you want to mark as completed:  " ;
	cin >> ind;

	if (head == nullptr)
	{
		cout << "List is empty" << endl;
		return;
	}

	node* temp = head;

	for (int i = 1; i < ind && temp != nullptr; i++)
	{

		temp = temp->next;


	}

	if (temp == nullptr)
	{
		cout << "Invalid task index" << endl;

		return;

	}

	temp->status = complete(temp->status);


	cout << "Task marked as completed successfully" << endl << endl;


}




void mainmenu()
{
	char stat = 'P';
	string task;
	node* head = nullptr;
	int choi;

	do {
		cout << "Press (1) to Input TASK " << endl;
		cout << "Press (2) to VIEW your tasks " << endl;
		cout << "Press (3) to Delete task " << endl;
		cout << "Press (4) to mark task as completed " << endl<<endl;

		cout << "Enter Your choice ";
		cin >> choi;
		cout << endl;

		switch (choi)
		{
		case 1:
			input(head, task);
			break;

		case 2:
			display(head, task, stat);
			break;

		case 3:
			deli(head);
			break;

		case 4:
			comp(head, stat);
			break;
		}
	} while (1);

}



void regi(string log, string pass)
{



	cout << "Enter Name :  ";
	cin >> log;

	cout << "Enter Password: ";
	cin >> pass;

	ofstream file;

	file.open("C://Users/msi/Desktop" + log + ".txt");

	file << log << endl << pass << endl;

	file.close();

	cout << "Registration successful " << endl;

	cout << endl;


}

void logi()
{

	string log, log1;
	string pass, pass1;


	cout << "Enter Name :  ";
	cin >> log;

	cout << "Enter Password: ";
	cin >> pass;



	ifstream read("C://Users/msi/Desktop" + log + ".txt");
	getline(read, log1);
	getline(read, pass1);

	if (log1 == log && pass1 == pass)
	{

		cout << "Login Successfull " << endl << endl;
		mainmenu();


	}
	else
	{

		cout << "Incorrect username or password try again " << endl;


	}



	cout << endl;


}






int main()
{

	

	system("color 90");
	logo();

	string log;
	string pass;

	
	int choi;

	node* head = nullptr;

	do {

		cout << "Press (1) to register " << endl;
		cout << "Press (2) to login " << endl;
		cout << "Enter your choice: ";
		cin >> choi;
		cout << endl;


		switch (choi)
		{


		case 1:
			regi(log, pass);
			break;

		case 2:

			logi();



			break;




		}
	} while (1);




	return 0;




}






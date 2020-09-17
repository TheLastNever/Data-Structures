// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
class List {
private:
	Node* head;

public:
	List() {
		head = NULL;
	}
	void Insert(int);
	void Display();
	void DeleteLast();
	int Count();
	void Max();
	bool IsEmpty();
};
bool List::IsEmpty() {
	return head == NULL;
}
void List::Insert(int val) {
	if (val % 2 == 0) {
		if (head == NULL) {
			head = new Node;
			head->data = val;
			head->next = head;
		}
		else {
			Node* temp = head;
			while (temp->next != head) {
				temp = temp->next;
			}
			Node* newNode = new Node;
			newNode->data = val;
			newNode->next = head;
			temp->next = newNode;
		}
	}
}
void List::Display() {
	if (!IsEmpty()) {
		Node* temp = head;
		do {
			cout << temp->data << endl;
			temp = temp->next;
		} while (temp != head);
	}
}
void List::DeleteLast() {
	if (!IsEmpty()) {
		Node* temp = head;
		if (temp->next == NULL) {
			head = NULL;
		}
		else {
			while (temp->next->next != head) {
				temp = temp->next;
			}
			temp->next = head;
		}
	}
}
int List::Count() {
	Node* temp = head;
	int counter = 0;
	if (!IsEmpty()) {

		do {
			counter++;
			temp = temp->next;
		} while (temp != head);

	}
	return counter;
}
void List::Max() {
	
	if (!IsEmpty()) {
		Node* temp = head;
		int max;
		max = temp->data;
		while (temp->next != head) {
			if (temp->next->data>temp->data) {
				max = temp->next->data;
			}
			temp = temp->next;
		}
		cout << max << endl;
	}
	
}
int main()
{
	List S;
	S.Insert(15);
	S.Insert(5);
	S.Insert(10);
	S.Insert(46);
	S.Insert(11);
	S.Insert(100);
	S.Insert(600);

	cout << "full display" << endl;
	S.Display();
	cout << "count: " << S.Count() << endl;
	cout << "max" << endl;
	S.Max();
}
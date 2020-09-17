#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};
Node* head;
class Dlist {
public:

	Dlist() {
		head = NULL;

	}
	Node* CreateNode(int val);
	bool IsEmpty();
	void InsertLast(int);
	void InsertFirst(int);
	void InsertAtIndex(int, int);
	void RemoveLast();
	void RemoveFirst();
	void RemoveAtIndex(int index);
	void Display();
	void DisplayReverse();
	void CountItem();
	void Find(int);
	void ChangeList();
	void FindSum();
	int CheckDuplicate(int);
	void CountEvenAndOdd();
	void Square();
};
Node* Dlist::CreateNode(int val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
bool Dlist::IsEmpty() {
	return head == NULL;
}
void Dlist::CountItem() {
	Node* temp = head;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	cout << count << endl;

}
void Dlist::Square() {
	if (!IsEmpty()) {
		Node* temp = head;
		while (temp != NULL) {
			temp->data *= temp->data;
			temp = temp->next;
		}
	}
	else {
		cout << "list is empty" << endl;
	}
}
void Dlist::CountEvenAndOdd() {
	if (!IsEmpty()) {
		Node* temp = head;
		int odd = 0;
		int even = 0;
		while (temp->next != NULL) {
			if (temp->data % 2 == 0) {
				even++;
			}
			else if (temp->data % 2 != 0) {
				odd++;
			}
			temp = temp->next;
		}
		cout << "odd: " << odd << endl;
		cout << "even" << even << endl;
	}
	else {
		cout << "list is empty" << endl;
	}
}
int Dlist::CheckDuplicate(int val) {
	if (!IsEmpty()) {
		int count = 0;
		Node* temp = head;
		while (temp->next != 0) {
			if (val == temp->data) {
				count++;
			}
			temp = temp->next;
		}
		return count;
	}
}
void Dlist::ChangeList() {
	if (!IsEmpty()) {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		if (head->data > temp->data) {
			swap(head->data, temp->data);
		}
	}
	else {
		cout << "list empty" << endl;
	}
}
void Dlist::InsertLast(int val) {
	if (IsEmpty()) {
		head = CreateNode(val);

	}
	else {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		Node* tmp = CreateNode(val);
		tmp->next = NULL;
		tmp->prev = temp;
		temp->next = tmp;

	}
}
void Dlist::InsertFirst(int val) {
	if (IsEmpty()) {
		head = CreateNode(val);
	}
	else {
		Node* temp = CreateNode(val);
		temp->next = head;
		head->prev = temp;
		head = temp;


	}
}
void Dlist::InsertAtIndex(int val, int inx) {
	Node* tmp = head;
	int count = 0;
	while (tmp != NULL) {
		count++;
		tmp = tmp->next;
	}
	if (inx > count) {
		InsertLast(val);
	}
	else {
		if (inx <= 1) {
			InsertFirst(val);
		}
		else {
			Node* temper = head;
			int idx = 1;
			while (idx != inx && temper != NULL) {
				temper = temper->next;
				idx++;
			}
			Node* previous = temper;
			Node* temp = CreateNode(val);
			temp->data = val;
			temp->next = previous->next;
			temp->prev = previous;
			previous->next = temp;
			previous->next->prev = temp;
		}
	}
}
void Dlist::RemoveLast() {
	if (!IsEmpty()) {
		Node* temp = head;
		if (temp->next == NULL) {
			head = NULL;
		}
		else {
			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			temp->next = NULL;
		}
	}
	else {
		cout << "List is Empty" << endl;
	}
}
void Dlist::RemoveFirst() {
	if (!IsEmpty()) {
		Node* temp = head;
		if (temp->next == NULL) {
			head = NULL;
		}
		else {
			head = temp->next;
			head->prev = NULL;
			delete(temp);


		}
	}
	else {
		cout << "List is empty";
	}
}
void Dlist::RemoveAtIndex(int index) {
	if (!IsEmpty()) {
		int count = 0;
		Node* temp = head;
		if (index == 0) {
			RemoveFirst();
		}
		else {
			while (count < index) {
				temp = temp->next;
				count++;
			}
			if (temp->next == NULL) {
				RemoveLast();
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete(temp);
			}
		}
	}

}
void  Dlist::Find(int index) {
	Node* tmp = head;
	int count = 0;
	while (tmp != NULL) {
		count++;
		tmp = tmp->next;
	}
	if (count < index) {
		cout << "  " << endl;
	}
	else {
		Node* temp = head;
		int idx = 1;
		while (idx != index && temp != NULL) {
			temp = temp->next;
			idx++;
		}
		cout << temp->data << endl;


	}
}
void Dlist::FindSum() {
	Node* tmp = head;
	int sum = 0;
	while (tmp != NULL) {
		sum += tmp->data;
		tmp = tmp->next;
	}
	cout << sum << endl;
}
void Dlist::Display() {
	if (!IsEmpty()) {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;

		}
	}
}
void Dlist::DisplayReverse() {
	if (!IsEmpty()) {
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->prev;
		}
	}
}


int main()
{


	Dlist S;
	S.InsertLast(15);
	S.InsertLast(10);
	S.InsertLast(45);
	S.InsertFirst(20);
	S.InsertAtIndex(23, 2);
	cout << "Displaying Normal insertions" << endl;
	S.Display();
	S.CheckDuplicate(45);
	cout << "List after changelist function" << endl;
	S.ChangeList();
	S.Display();
	S.CountEvenAndOdd();
	S.CountItem();
	cout << "displaying the list reversed" << endl;
	S.DisplayReverse();
	cout << "displaying a certain node (4th)" << endl;
	S.Find(4);
	cout << "sum of listt" << endl;
	S.FindSum();
	S.RemoveLast();
	cout << "displaying after removing the last" << endl;
	S.Display();
	S.RemoveFirst();
	cout << "Displayin after removing first" << endl;
	S.Display();
	
	S.Square();
	cout << "Displaying list after using square function" << endl;
	S.Display();





}
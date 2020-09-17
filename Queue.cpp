

#include <iostream>
using namespace std;
#define Max_Size
struct Node {
	int data;
	Node* next;
	Node* prev;
};
class Queue {
private:
	Node* front;
	Node* rear;
	int count;
	int max;
public:
	Queue() {
		front = NULL;
		rear = NULL;
		count = 0;
	}
	int GetMaxSize();
	int max_size();
	bool isEmpty();
	int isFull();
	void enqueue(int);
	void dequeue();
	int peek();
	void displayCount();
	void reverse();
};
bool Queue::isEmpty() {
	return rear == NULL;
}
int Queue::GetMaxSize() {
	cout << "give max size pls" << endl;
		cin >> max;
		return max;
}
int Queue::max_size() {
	return max;
}
int Queue::isFull() {
	return(count == max_size());
}
void Queue::enqueue(int val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	if (isFull()) {
		cout << "Queue is Full" << endl;
	}
	else if(isEmpty()){
		front = rear = newNode;
		count++;
	}
	else {
		rear->next = newNode;
		rear->next->prev = rear;
		rear = newNode;
		count++;
	}
	
}
void Queue::dequeue() {
	if (front == NULL) {
		cout << "queue is empty" << endl;
	}
	else {
		Node* temp = front;
		int data = temp->data;
		if (front == rear) {
			front = rear = NULL;
			delete(temp);
		}
		else {
			front = front->next;
			front->next->prev = NULL;
			delete(temp);
		}
		
		count--;
	}
}

void Queue::displayCount() {
	cout << "Elements in Queue: " << count << endl;
}
int Queue::peek() {
	if (!isEmpty()) {
		return front->data;
	}
}
void Queue::reverse() {
	//I wasn't able to implement it
	Stack S;
	int count2 = count;
	while (count > 0) {
		S.push(peek());
	}
	while (count2 > 0) {
		cout << S.pop()<<endl;
		count2--;
	}
	
}

int main()
{
	/
	Queue q;
	q.GetMaxSize();
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(5);
	q.enqueue(1);
	q.displayCount();
	q.peek();
}









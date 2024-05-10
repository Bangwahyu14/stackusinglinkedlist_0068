#include <iostream>
using namespace std;

// Node class representing a single node in the linked list
class Node {
public:
	int data;
	Node* next;

	Node() {
		next = NULL;
	}
};

//stack class
class stack {
private:
	Node* top;// pointer to the top node of the stack

public:
	stack() {
		top = NULL; // initialize the stack with a null top pointer
	}

	//push operation: insert an element onto the top of stack
	int push(int value) {
		Node* newNODE = new Node();//1.allocate memory for the new node
		newNODE->data = value; //2.assign value
		newNODE->next = top;//3.set the next pointer of the new node to current to node
		top = newNODE;//4. update the top pointer to the new node
		cout << "push value: " << value << endl;
		return value;
	}

	//peek/top operation retrive the value of the topmost element witout removing it
	void peek() {
		if (top == NULL) {
			cout << "List is empaty." << endl;
		}
		else {
			Node* current = top;
			while (current != NULL) {
				cout << current->data << " " << endl;
				current = current->next;
			}
			cout << endl;
		}// return the value of the top node
	}

	//isempty operation: check if the stack is empty
	bool isEmpty() {
		return top == NULL;//return true if the top pointer is null, indication an empty stack
	}
	

};

int main() {
	stack stack;

	int choice = 0;
	int value;

	while (choice != 5) {
		cout << "1.push\n";
		cout << "2.pop\n";
		cout << "3.peek\n";
		cout << "4.exit\n";
		cout << "enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter the value to push: ";
			cin >> value;
			stack.push(value); // push the entered value onto the stack
			break;
		case 2:
			if (!stack.isEmpty()) {
				stack.pop();//pop the top element from the stack
			}
			else {
				cout << "stack is empty. cannot pop." << endl;
			}
			break;
		case 3:
			if (!stack.isEmpty()) {
				stack.peek(); //get the value of the top element
			}
			else {
				cout << "stack is empty.no top value." << endl;
			}
			break;

		case 4:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "incalid choice. try again." << endl;
			break;
		}
		cout << endl;
		
	}
	return 0;

}


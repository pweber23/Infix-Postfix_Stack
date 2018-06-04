#include <string>
//#include <stack>

struct Node {
	char value;
	Node* next;
};

class Stack {
private:
	Node* head;
public:
	Stack() {
		head = NULL;
	}
	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void push(char a) {
		Node* newNode;
		newNode = new Node();
		newNode->value = a;
		newNode->next = head;
		head = newNode;
	}
	char pop() {
		Node* temp = head;
		if (head) {
			Node *temp;
			temp = head;
			delete head;
			head = head->next;
			return temp->value;
		}
		else {
			return NULL;
		}	
	}
	char peek() {
		if (isEmpty()) {
			return NULL;
		}
		else {
			return head->value;
		}
	}
};

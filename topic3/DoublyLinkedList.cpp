//using pointer
#include <iostream>
#include <string>


class Node {

private:
	int stored_value;
	Node* next_node;
	Node* prev_node;

public:

	Node() : stored_value{ -1 }, next_node{ nullptr }, prev_node{ nullptr }{}
	Node(const int value) : stored_value{ value }, next_node{ nullptr }, prev_node{ nullptr }{}

	void setNext(Node* next) { next_node = next; }
	void setPrev(Node* prev) { prev_node = prev; }

	int getValue() { return this->stored_value; }
	Node* getNext() { return next_node; }
	Node* getPrev() { return prev_node; }

};

class DoublyLikedList {

private:
    Node nil;
	Node* current_node;

public:

	DoublyLikedList() : current_node{ nullptr }{}

	Node* linearSearch(const int search_val) {

		for (Node* current_node = nil.getNext(); current_node != &nil; current_node = current_node->getNext()) {
			if (current_node->getValue() == search_val) return current_node;
		}

		return nullptr;
	}

	void insert(const int val) {

		current_node = new Node{ val };
		current_node->setPrev(&nil);

		if (nil.getNext() == nullptr) {
			current_node->setNext(&nil);
			nil.setPrev(current_node);
		}

		else {
			current_node->setNext(nil.getNext());
			nil.getNext()->setPrev(current_node);
		}

		nil.setNext(current_node);
	}

	void deleteNode(const int del_val) {

		Node* del_node;


		if (del_val == -1) del_node = nil.getNext();  //deleteFirst
		else if (del_val == -2) del_node = nil.getPrev(); 	//deleteLast
		else del_node = linearSearch(del_val);

		if (del_node == nullptr) return;

		Node* next_node = del_node->getNext();
		Node* prev_node = del_node->getPrev();


		next_node->setPrev(prev_node);
		prev_node->setNext(next_node);

		delete del_node;
	}

	void showList() {

		for (Node* current_node = nil.getNext(); current_node != &nil; current_node = current_node->getNext()) {
			if (current_node != nil.getNext()) std::cout << " ";
			std::cout << current_node->getValue();
		}

		std::cout << std::endl;
	}
};

void LinkedListApplication() {

	using std::cout;
	using std::cin;
	using std::string;

	DoublyLikedList dll;

	int num_of_command;
	cin >> num_of_command;

	string command;
	for (int i = 0; i != num_of_command; ++i) {
		cin >> command;
		
		if (command[0] == 'i') {
			
			int insert_val;
			cin >> insert_val;

			dll.insert(insert_val);
		}
		else if (command[0] == 'd') {
			
			if (command.length() > 6) {
				if (command[6] == 'F') dll.deleteNode(-1);
				if (command[6] == 'L') dll.deleteNode(-2);
			}

			else {
				int del_val;
				cin >> del_val;

				dll.deleteNode(del_val);
			}

		}
	}

	dll.showList();
	
}

int main() {
	LinkedListApplication();
}


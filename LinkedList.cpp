#include <iostream>

template <class T>
class Node {
public:
	T data;
	Node<T> *next;
	Node(const T& d) : data(d), next() {}
	Node(const Node& node) : data(node.data), next() {}
};
template <class T>
class LinkedList {
	int length;
	Node<T> *head;
	Node<T> *tail;
public:
	LinkedList() : length(0), head(NULL), tail(NULL){}
	LinkedList(Node<T> *newNode) : head(newNode), tail(newNode) {length++;}
	~LinkedList(){}

	Node<T>* pop_back() {
		Node<T> *val = NULL;
		if (head == NULL) {
			return val;
		}
		if (head->next == NULL) {
			val = head;
			head = NULL;
			tail = NULL;
			length--;
			return val;
		}
		Node<T> *current = head;
		while(current) {
			if (current->next == tail) {
				Node<T> *tmp = current->next;
				val = tmp;
				current->next = NULL;
				tail = current;
				break;
			}
			current = current->next;
		}
		length--;
		return val;
	}
	Node<T>* pop(T data) {
		Node<T> *val = NULL;
		if (head == NULL) {
			return val;
		}
		if (head->next == NULL) {
			if (head->data == data) {
				val = head;
				head = tail = NULL;
				length--;
				return val;
			}
			else {
				return val;
			}
		}
		Node<T> *current = head;
		Node<T> *temp = NULL;
		while (current) {
			if (current->data == data) {
				val = current;
				temp->next = current->next;
				if (current->next == NULL) {
					tail = temp;
				}
			}
			temp = current;
			current = current->next;
		}
		length--;
		return val;
	}
	Node<T>* pop_front() {
		Node<T> *val = NULL;
		if (head == NULL) {
			return val;
		}
		if (head->next == NULL) {
			val = head;
			head = tail = NULL;
			length--;
			return val;
		}
		val = head;
		Node<T> *current = head->next;
		delete head;
		head = current;
		length--;
		return val;
	}
	void push_front(T data) {
		Node<T> *newNode = new Node<T>(data);
		newNode->next = head;
		head = newNode;
		if (head->next == NULL) {
			tail = newNode;
		}
		length++;
	}
	void push_back(T data) {
		Node<T> *newNode = new Node<T>(data);
		if (tail == NULL) {
			newNode->next = tail;
			tail = newNode;
			head = newNode;
		}
		tail->next = newNode;
		tail = tail->next;
		length++;
	}
	Node<T>* getHead() {
		return head;
	}
	void print() {
		Node<T> *current = head;
		while (current) {
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << "\n";
	}
	void printReverse(Node<T> *node) {
		if (node != NULL) {
			if (node->next == NULL) {
				std::cout << node->data << " ";
			}
			else {
				printReverse(node->next);
				std::cout << node->data << " ";
			}
		}
	}
};

int main() {
	LinkedList<int> list(new Node<int>(3));
	list.push_back(1);
	//list.push_back(5);
	//list.push_front(7);
	//list.pop(3);
	//list.pop_back();
	//list.pop_front();
	list.print();
	list.printReverse(list.getHead());
	return 0;
}

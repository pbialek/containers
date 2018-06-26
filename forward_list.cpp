#include <iostream>

class Node {
    private:
        Node *next = 0;
        int val = 0;

	public:
		Node(int _val) {
            val = _val;
        };
        Node() {};
        void setNext(Node *_next) {
            next = _next;
        };
        Node *getNext() {return next;};
        int getValue() { return val;};
};

class List {
    private:
        int size = 0;
	    Node *front = 0;

	public:
		List(int val) {
            front = new Node(val);
            size++;
        };
        List() {};

        void push_front(int val) {
            Node *temp = front;
            front = new Node(val);
            front->setNext(temp);
        }

        int whatSize() { return size;};

        void showList() {
            Node *temp = front;
            while(temp) {
                std::cout << temp->getValue() << "\n";
                temp = temp->getNext();
            }
        };
};

int main()
{
    List l(5);
    l.push_front(7);
    l.push_front(9);

    l.showList();
}

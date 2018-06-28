#include <iostream>

template <class T>
class Node {
    private:
        Node *next = 0;
        T val = 0;

    public:
        Node(T _val) {
            val = _val;
        };
        Node() {};
        void setNext(Node *_next) {
            next = _next;
        };
        Node *getNext() {return next;};
        T getValue() { return val;};
};

template <class T>
class List {
    private:
        int size = 0;
	    Node<T> *front = 0;

    public:
        List(T val) {
            front = new Node<T>(val);
            size++;
        };
        List() {};

        void push_front(T val) {
            Node<T> *temp = front;
            front = new Node<T>(val);
            front->setNext(temp);
        }

        int whatSize() { return size;};

        void showList() {
            Node<T> *temp = front;
            while(temp) {
                std::cout << temp->getValue() << "\n";
                temp = temp->getNext();
            }
        };
};

int main()
{
    List<int> l(5);
    l.push_front(7);
    l.push_front(9);

    l.showList();

    List<double> k(2.2);
    k.push_front(1.9);
    k.push_front(12.23);
    k.showList();
}

#include <iostream>
#include <memory>

template <class T>
class Node {
    private:
        std::shared_ptr<Node> next = 0;
        T val = 0;

    public:
        Node(T _val) {
            val = _val;
        };
        Node() {};
        void setNext(std::shared_ptr<Node> _next) {
            next = _next;
        };
        std::shared_ptr<Node> getNext() {return next;};
        T getValue() { return val;};
};

template <class T>
class List {
    private:
        int size = 0;
        std::shared_ptr<Node<T>> front = 0;

    public:
        List(T val) {
            front = std::shared_ptr<Node<T>>(new Node<T>(val));
            size++;
        };
        List() {};

        void push_front(T val) {
            std::shared_ptr<Node<T>> temp = front;
            front = std::shared_ptr<Node<T>>(new Node<T>(val));
            front->setNext(temp);
        }

        int whatSize() { return size;};

        void showList() {
            std::shared_ptr<Node<T>> temp = front;
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

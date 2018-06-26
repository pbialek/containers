#include <iostream>

class Node {
	public:
        Node *next = 0;
        int val = 0;

		Node(int _val) {
            val = _val;
        };
        Node() {};
};

class List {
	int size = 0;
	Node *front = 0;
    Node *back = 0;

	public:
		List(int val) {
            front = new Node(val);
            back = front;
            size++;
        };
        List() {};

        void push_back(int val) {
            Node *newNode = new Node(val);

            if(front == 0) {
                std::cout << "front\n";
                front = newNode;
                back = front;
                size++;
            }
            else {
                Node *temp = front;
                while(temp->next) {
                    temp = temp->next;
                }
                temp->next = newNode;
                back = temp->next;
                size++;
            }
        }

        void push_front(int val) {
            Node *temp = front;
            front = new Node(val);
            front->next = temp;
        }

        int whatSize() { return size;};

        void showList() {
            Node *temp = front;
            while(temp) {
                std::cout << temp->val << "\n";
                temp = temp->next;
            }
        };

        int showBack() { return back->val; };

};

int main()
{
    List l;
    l.push_back(3);
    l.push_back(8);
    l.push_back(2);
    l.push_front(7);
    l.push_front(9);

    l.showList();

    std::cout << "Back: " << l.showBack() << "\n";
}

/* Exercici Linked Lists
1. Implement the push_back function:
    - void push_back (const int &value) {...}
2. Implement the insert function:
    - void insert (unsigned int position, const int &value) {...}
3. Implement the print function. It prints the whole list from beginning to end:
    - void print () {...}
4. From the main function, insert 5 elements in different positions and print the whole list after each insertion*/

#include <iostream>
using namespace std;

class List
{
public:
    List() = default;

    ~List()
    {
        clear();
    }

    void push_front(const int& value)
    {
        if (num_elems == 0)
        {
            first = last = new Node;
            first->value = value;
            first->prev = nullptr;
            first->next = nullptr;
        }
        else
        {
            Node* node = new Node;
            node->value = value;
            node->prev = nullptr;
            node->next = first;
            first->prev = node;
            first = node;
        }
        num_elems++;
    }

    void push_back(const int& value)
    {
        if (num_elems == 0)
        {
            last = first = new Node;
            last->value = value;
            last->prev = nullptr;
            last->next = nullptr;
        }
        else
        {
            Node* node = new Node;
            node->value = value;
            node->prev = last;
            node->next = nullptr;
            last->next = node;
            last = node;
        }
        num_elems++;
    }

    void insert(unsigned int position, const int& value)
    {
        
    }

    void print() const
    {
        Node* current = first;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void clear()
    {
        while (first != nullptr)
        {
            Node* temp = first;
            first = first->next;
            delete temp;
        }
        last = nullptr;
        num_elems = 0;
    }

private:
    struct Node
    {
        int value;
        Node* next;
        Node* prev;
    };

    Node* first = nullptr;
    Node* last = nullptr;
    unsigned int num_elems = 0;
};

int main()
{
    List my_list;

    my_list.insert(0, 10);
    my_list.print();

    my_list.insert(1, 20);
    my_list.print();

    my_list.insert(1, 15);
    my_list.print();

    my_list.insert(0, 5);
    my_list.print();

    my_list.insert(2, 12);
    my_list.print();
}


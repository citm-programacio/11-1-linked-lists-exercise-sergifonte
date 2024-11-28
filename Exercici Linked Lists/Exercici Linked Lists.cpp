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
        if (position >= num_elems)
        {
            push_back(value);
            return;
        }

        Node* new_node = new Node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = nullptr;

        if (position == 0)
        {
            new_node->next = first;
            if (first)
                first->prev = new_node;
            first = new_node;
            if (!last)
                last = new_node;
        }
        else
        {
            Node* current = first;
            for (unsigned int i = 0; i < position - 1; ++i)
            {
                current = current->next;
            }
            new_node->next = current->next;
            new_node->prev = current;
            if (current->next)
                current->next->prev = new_node;
            current->next = new_node;
            if (new_node->next == nullptr)
                last = new_node;
        }
        num_elems++;
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
        while (first)
        {
            Node* temp = first;
            first = first->next;
            delete temp;
        }
        last = nullptr;
        num_elems = 0;
    }

    bool empty() const
    {
        return num_elems == 0;
    }
    unsigned int size() const
    {
        return num_elems;
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


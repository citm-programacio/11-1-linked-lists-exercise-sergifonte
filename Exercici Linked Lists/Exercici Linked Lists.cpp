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

    void push_front(const int& value);
    void push_back(const int& value);
    void insert(unsigned int position, const int& value);
    void print() const;
    void clear();

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

void List::push_back(const int& value)
{
    Node* new_node = new Node;
    new_node->value = value;
   

}

void List::insert(unsigned int position, const int& value)
{
    if (position >= num_elems)
    {
        push_back(value);
        return;
    }

    Node* new_node = new Node;
    new_node->value = value;
    

}

void List::print() const
{
    Node* current = first;
    while (current)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void List::clear()
{
    
}

int main()
{
    List my_list;

    my_list.insert(0, 10);
    my_list.print();

    my_list.insert(1, 20);
    my_list.print();

}

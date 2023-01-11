#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;
    StackNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    StackNode *head;

public:
    Stack()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void push(int element)
    {
        StackNode *temp = new StackNode(element);
        temp->next = head;
        head = temp;
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        StackNode *temp = NULL;
        int num = head->data;
        temp = head->next;
        delete head;
        head = temp;
        return num;
    }

    int top()
    {
        if (isEmpty())
            return -1;
        return head->data;
    }

    int minElement()
    {
        if (isEmpty())
            return -1;
        StackNode *current = head;
        int mini = INT_MAX;
        while (current != NULL)
        {
            mini = min(mini, current->data);
            current = current->next;
        }
        return mini;
    }

    int maxElement()
    {
        if (isEmpty())
            return -1;
        StackNode *current = head;
        int maxi = INT_MIN;
        while (current != NULL)
        {
            maxi = max(maxi, current->data);
            current = current->next;
        }
        return maxi;
    }

    void display()
    {
        if (isEmpty())
            return;
        StackNode *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
    Stack st;

    cout << "\nEnter number of values in stack: ";
    int n;
    cin >> n;
    cout << "\nEnter the values: ";
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        st.push(k);
    }

    cout << "\nElements in the stack are: ";
    st.display();

    cout << "\nMinimum element in stack: " << st.minElement();

    cout << "\nMaximum element in stack: " << st.maxElement();
}
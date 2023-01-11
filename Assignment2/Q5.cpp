#include <iostream>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
int Common(Node *head)
{
    Node *current = head;
    unordered_map<int, int> m;

    int mostCommon, frequency = 0;
    while (current != NULL)
    {
        m[current->data]++;
        current = current->next;
    }
    for (auto i : m)
    {
        if (i.second > frequency)
        {
            mostCommon = i.first;
            frequency = i.second;
        }
    }
    return mostCommon;
}
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

int main()
{
    cout << "\nEnter number of values in linked list: ";
    int n;
    cin >> n;
    cout << "\nEnter the values: ";
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        Node *temp = new Node(k);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    cout << "\nLinked list: ";
    printList(head);

    cout << "Most common element in Linked list: " << Common(head);

    return 0;
}
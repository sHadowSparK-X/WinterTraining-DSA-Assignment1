#include <bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> &s)
{
    stack<int> temp;

    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        while (!temp.empty() && temp.top() < val)
        {
            s.push(temp.top());
            temp.pop();
        }
        temp.push(val);
    }

    return temp;
}

int main()
{
    stack<int> s;
    cout << "Enter the number of elements in stack: ";
    int n;
    cin >> n;
    cout << "\nEnter the elements in stack: ";
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        s.push(k);
    }
    stack<int> temp = sortStack(s);
    cout << "\nSorted stack with smallest at the top are: ";

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
}

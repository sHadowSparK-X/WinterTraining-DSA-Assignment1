#include <bits/stdc++.h>
using namespace std;

int reverse(int number)
{
    stack<int> st;
    while (number != 0)
    {
        st.push(number % 10);
        number = number / 10;
    }

    int reverse = 0;
    int i = 1;
    while (!st.empty())
    {
        reverse = reverse + (st.top() * i);
        st.pop();
        i = i * 10;
    }
    return reverse;
}

int main()
{
    cout << "Enter a number: ";
    int number;
    cin >> number;

    cout << "\nReverse of " << number << " is " << reverse(number);

    return 0;
}

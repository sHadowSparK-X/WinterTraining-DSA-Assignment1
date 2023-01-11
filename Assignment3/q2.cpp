#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else if(s[i] != ')')
            continue;
        else
        {
            if (st.empty())
                return false;
            if (st.top() == '(')
                st.pop();
            else
                break;
        }
    }
    return st.empty();
}
int main()
{
    cout << "Enter string to check for order of parentheses: ";
    string s;
    cin >> s;
    if (isValid(s))
        cout << "\nOrder is correct";
    else
        cout << "\nOrder is not correct";
    return 0;
}
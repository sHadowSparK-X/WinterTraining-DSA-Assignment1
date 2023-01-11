#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmaller(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int num = arr[i];
        while (s.top() != -1 && arr[s.top()] >= num)
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmaller(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        while (s.top() != -1 && arr[s.top()] >= num)
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestWidth(vector<int> &heights)
{
    int n = heights.size();
    vector<int> next(n);
    next = nextSmaller(heights, n);
    vector<int> prev(n);
    prev = prevSmaller(heights, n);
    int maxWidth = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (next[i] == -1)
            next[i] = n;
        int width = (next[i] - prev[i] - 1) * 2;
        if (width > maxWidth)
            maxWidth = width;
    }
    return maxWidth;
}
int main()
{
    cout << "Enter number of elements in histogram: ";
    int n;
    cin >> n;
    cout << "\nEnter the elements in histogram: ";
    vector<int> heights(n);
    for (int &i : heights)
        cin >> i;
    cout << "Maximum width of largest Rectangle in histogram: " << largestWidth(heights);
    return 0;
}

#include<bits/stdc++.h>
// When you pop an element x:
// A smaller element has appeared after it
// x will never be useful again
// Any future element prefers the smaller one
using namespace std;
using pi = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> x;
    x.resize(n);
    stack<pi> st;
    // monotonic incr stack
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
        while(!st.empty() && st.top().first >= x[i])
        {
            // to be able to push
            // curr should be bigger than top
            st.pop();
        }
        if(st.empty())
            cout << "0 ";
        else cout << st.top().second + 1 << " "; // position
        st.push(make_pair(x[i], i));
    }
    return 0;
}
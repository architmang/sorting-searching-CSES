#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> st;
    for(int i=1; i<=n; i++)
        st.insert(i);
    auto it = st.begin();
    while(n--)
    {
        // never dereference end
        it++;
        if(it == st.end())
            it = st.begin();
        cout << *it << " ";
        // use the iterator returned by erase, returns the next it
        it = st.erase(it);
        if(it == st.end())
            it = st.begin();
    }
    return 0;
}
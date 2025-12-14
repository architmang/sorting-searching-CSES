#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    vector<int> t; // max price for each cust
    multiset<int> h; // price of each ticket
    
    cin >> n >> m;
    t.resize(m);
    
    int x;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        h.insert(x);
    }

    for(int i=0; i<m; i++)
        cin >> t[i];

    for(int i=0; i<m; i++)
    {
        auto it = h.upper_bound(t[i]);
        if(it == h.begin())
        {
            cout << "-1" << endl;
        }
        else
        {
            it--;
            cout << *it << endl;
            h.erase(it); // erase by iter not val
        }
    }
    return 0;
}
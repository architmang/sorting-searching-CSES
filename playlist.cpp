#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> k;
    k.resize(n);
    for(int i=0; i<n; i++)
        cin >> k[i];

    set<int> st;
    int left_ptr = 0, res = 0;
    
    for(int right_ptr=0; right_ptr<n; right_ptr++)
    {
        while(st.count(k[right_ptr]))
        {
            st.erase(k[left_ptr]);
            left_ptr++;
        }
        st.insert(k[right_ptr]);
        res = max(res, right_ptr - left_ptr + 1);
    }
    cout << res;
}
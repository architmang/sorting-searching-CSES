#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> x;
    x.resize(n);
    for(int i=0; i<n; i++)
        cin >> x[i];
    int left_ptr =0, right_ptr = 0;
    set<int> st;
    long long cnt = 0;
    for(right_ptr =0; right_ptr< n; right_ptr++)
    {
        // shrink window untill right_ptr becomes unique
        while(st.count(x[right_ptr]))
        {
            st.erase(x[left_ptr]);
            left_ptr++;
        }
        // add new element
        st.insert(x[right_ptr]);
        // number of valid subarrays ending at right ptr
        cnt += right_ptr - left_ptr + 1;
    }
    cout << cnt;
}
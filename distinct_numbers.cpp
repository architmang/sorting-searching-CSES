#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    set<int> st;
    arr.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        st.insert(arr[i]);
    }
    cout << st.size();
}
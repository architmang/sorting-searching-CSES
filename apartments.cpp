// n applicants, m apartments, k max allowed diff
// [x-k, x+k]  accepted
#include<bits/stdc++.h>
using namespace std; 

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a, b;
    a.resize(n);
    b.resize(m);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int aptr = 0, bptr = 0;
    int cnt = 0;
    while(aptr < n && bptr < m)
    {
        if(abs(a[aptr] - b[bptr]) <= k)
        {
            aptr++; bptr++;
            cnt++;
        }
        else{
            if(a[aptr] < b[bptr])
                aptr++;
            else bptr++;
        }
    }
    cout << cnt;
    return 0;
}
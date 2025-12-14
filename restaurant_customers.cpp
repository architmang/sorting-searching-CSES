#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a, b;
    a.resize(n);
    b.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i =0, j=0, cnt = 0, maxcnt = 0;
    while(i<n && j<n)
    {
        if(a[i] < b[j])
        {
            i++;
            cnt++;
            if(cnt >= maxcnt)
                maxcnt = cnt;
        }
        else{
            j++;
            cnt--;
        }
    }
    cout << maxcnt;
    return 0;
}
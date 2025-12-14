#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> x, pos_arr;
    x.resize(n);
    pos_arr.resize(n+1);
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
        pos_arr[x[i]] = i;
    }
    int cnt = 1;
    for(int i=2; i<=n; i++)
    {
        if(pos_arr[i] <= pos_arr[i-1])
            cnt++;
    }
    cout << cnt;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long val = 1;
    int n;
    cin >> n;
    vector<long long> x;
    x.resize(n);
    for(int i=0; i<n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    for(auto coin:x)
    {
        if(val < coin)
            break;
        val += coin;
    }
    cout << val;
}
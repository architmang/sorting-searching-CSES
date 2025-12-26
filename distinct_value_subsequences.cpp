#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9+7;
int main()
{
    int n;
    cin >> n;
    vector<ll> x;
    x.resize(n);
    map<ll, ll> count;
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
        count[x[i]]++;
    }
    ll ans = 1;
    for(auto k: count)
    {
        ans*= (1+k.second);
        ans%= mod;
    }
    cout << ans - 1; // for the null subset
    return 0;
}
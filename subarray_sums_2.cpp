#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<ll> a;
    a.resize(n);
    // cant use sliding window as it assumes
    // right_ptr++ will incr sum
    // left_ptr++ will decr sum
    // but for negative numbers, invariant breaks
    for(int i=0; i<n; i++)
        cin >> a[i];
    ll pref = 0, ans = 0;
    map<ll, ll> fmap;
    fmap[0] = 1;
    for(int i=0; i<n; i++)
    {
        pref += a[i];
        // returns 0 or 1
        if(fmap.count(pref - x))
            ans+=fmap[pref-x];
        fmap[pref]++;
    }
    cout << ans;
    return 0;
}
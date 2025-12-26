#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<ll> a;
    a.resize(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    ll ans = 0, perf = 0;
    map<ll, ll> fmap;
    fmap[0] = 1;

    for(int i=0; i<n; i++)
    {
        // update prefix sum
        perf += a[i]; // can be -5
        perf = ((perf % n) + n) % n;
        // for arr[l ... r] to be divisible by k
        // pref[r] % k == pref[l] % k
        if(fmap.count(perf))
            ans += fmap[perf];

        fmap[perf]++;
    }
    cout << ans;
    return 0;
}
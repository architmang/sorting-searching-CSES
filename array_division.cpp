#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int check(int n, vector<ll> x, ll mid, int k)
{
    int parts =1;
    ll runningSum = 0;
    for(int i=0; i<n; i++)
    {
        runningSum += x[i];
        if(runningSum > mid)
        {
            runningSum = x[i];
            parts++;
        }
    }
    return parts <= k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> x;
    x.resize(n);
    ll hi = 0;
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
        hi += x[i];
    }
    ll lo = *max_element(x.begin(), x.end());
    ll final_ans = 0;
    while(lo <= hi)
    {
        ll mid = lo + (hi-lo)/2;
        if(check(n, x, mid, k))
        {
            final_ans = mid;
            // cout << "current ans " << final_ans << endl;
            hi = mid -1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << final_ans;
    return 0;
}
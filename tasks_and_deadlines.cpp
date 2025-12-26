#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
// deadline - finishing time
// T1 > T2 : d1 - (0 + duration1) + d2 - (0 + duration1 + duration2)
// T2 > T1 : d2 - (0 + duration2) + d1 - (0 + duration2 + duration1)

// therefroe earlier task duration gets subtracted more
// do tasks in increasing order of duration
bool cmp(pi a, pi b)
{
    if(a.first < b.first) return 1;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<pi> timings;
    timings.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> timings[i].first >> timings[i].second;
    }
    sort(timings.begin(), timings.end(), cmp);
    long long ans = 0;
    long long curr_time = 0;
    for(int i=0; i<n; i++)
    {
        curr_time += timings[i].first;
        ans += timings[i].second - curr_time;
    }
    cout << ans;
    return 0;
}
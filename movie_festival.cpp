#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> s, e;
    s.resize(n);
    e.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> s[i].first >> e[i].first;
        s[i].second = i;
        e[i].second = i;
    }
    sort(e.begin(), e.end());
    int cnt = 0, timeElapsed = 0;
    for(int i=0; i<n; i++)
    {
        int ind = e[i].second;
        if(timeElapsed <= s[ind].first)
        {
            cnt++;
            timeElapsed = e[i].first;
        }
    }
    cout << cnt;
    return 0;
}
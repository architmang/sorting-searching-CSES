#include<bits/stdc++.h>
using namespace std; 
using ll = long long;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a;
    a.resize(n);
    // can extend by normal logic: TLE
    // solve using sum of pairs
    map<int, pair<int, int> > pair_sum_map;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            pair_sum_map[a[i] + a[j]] = {i, j};
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i] + a[j] >= x) continue;
            int diff = x - a[i] - a[j];
            if(pair_sum_map.find(diff) == pair_sum_map.end()) continue;
            auto p = pair_sum_map[diff];
            set<int> st ={i+1, j+1, p.first+1, p.second+1};
            if(st.size() != 4) continue;
            for(auto c: st) cout << c << " ";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
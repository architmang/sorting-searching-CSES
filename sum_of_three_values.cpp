#include<bits/stdc++.h>
using namespace std; 
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a;
    a.resize(n);
    map<int, vector<int> > pos_map;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        pos_map[a[i]].push_back(i);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i] + a[j] >= x) continue;
            int diff = x - a[i] - a[j];
            if(pos_map.find(diff) == pos_map.end()) continue;
            for(auto v: pos_map[diff])
            {
                if(v!= i && v!=j)
                {
                    cout << i +1 << " " << j+1 << " " << v+1;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
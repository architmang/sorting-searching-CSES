#include<bits/stdc++.h>
using namespace std; 
int main()
{
    int n;
    cin >> n;
    vector<int> k;
    k.resize(n);
    for(int i=0; i<n; i++)
        cin >> k[i];
    // for each tower, store the elements
    // top of each tower, stored in a separate multiset
    // for new element, checked against upper_bound
    // update that particular tower, update multiset acc
    // if upper_bound = multiset.end(), create a new tower
    // max number of towers are n= 2e5
    int num_towers = 0;
    multiset<pair<int, int>> mt;
    for(int i=0; i<n; i++)
    {
        auto it = mt.upper_bound(make_pair(k[i], INT_MAX));
        if(it == mt.end())
        {
            vector<int> vt;
            vt = {k[i]};
            mt.insert(make_pair(k[i], num_towers));
            num_towers++;
        }
        else{
            int top = (*it).first;
            int ind = (*it).second;
            mt.erase(it);
            mt.insert(make_pair(k[i], ind));
        }
    }
    cout << num_towers;
    return 0;
}
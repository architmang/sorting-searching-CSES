#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a;
    a.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    auto u_x = upper_bound(a.begin(), a.end(), make_pair(x, INT_MAX));
    int ind = int(u_x - a.begin());
    int flag = 0;
    for(int i=0; i< ind; i++)
    {
        int curr = a[i].first;
        int comp = x - a[i].first;
        int u_comp = lower_bound(a.begin(), u_x, make_pair(comp, INT_MIN)) - a.begin();
        if(a[u_comp].first == comp && a[i].second != a[u_comp].second)
        {
            cout << min(a[i].second + 1,a[u_comp].second + 1)  << " " << max(a[i].second + 1,a[u_comp].second + 1);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        cout << "IMPOSSIBLE";
    return 0;
}
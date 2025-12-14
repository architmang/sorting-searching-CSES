#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> p;
    p.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int size = p.size();
    int median = p[size/2];
    long long ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += abs(median - p[i]);
    }
    cout << ans << endl;
    return 0;
}
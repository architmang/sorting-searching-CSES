#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> x;
    x.resize(n);
    for(int i=0; i<n; i++)
        cin >> x[i];
    long long res = x[0];
    long long maxEnding = x[0];
    for(int i=1; i<n; i++)
    {
        maxEnding = max(maxEnding + x[i], x[i]);
        res = max(maxEnding, res);
    }
    cout << res;
    return 0;
}
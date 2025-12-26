#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;

bool cmp(vi a, vi b)
{
    if(a[0] < b[0]) return a[1] > b[1];
    return 0;
}

int main()
{
    int n; cin >> n;
    vector<vi> vp;
    vp.resize(n);
    for(int i = 0; i<n; i++)
    {
        vp[i].resize(3);
        cin >> vp[i][0] >> vp[i][1];
        vp[i][2] = i;
    }
    sort(vp.begin(), vp.end(), cmp);
    return 0;
}
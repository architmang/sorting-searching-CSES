#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;

bool cmp(vi a, vi b)
{
    if(a[0] < b[0]) return true;
    else if(a[0] == b[0] && a[1] > b[1]) return true;
    return false;
}

int main()
{
    int n; cin >> n;
    vector<vi> vp;
    vp.resize(n);
    for(int i=0; i<n; i++)
    {
        vp[i].resize(3);
        cin >> vp[i][0] >> vp[i][1];
        vp[i][2] = i;
    }
    sort(vp.begin(), vp.end(), cmp);
    // for contains
    // L, R contains l, r
    // R >= r means
    // start from right end, find rmin 
    vector<int> contains(n, 0);
    int rmin = INT_MAX;
    for(int i = n-1; i>=0; i--)
    {
        if(vp[i][1] < rmin)
            rmin = vp[i][1];
        else{
            // rmin was not updated but R >= r min
            int ind = vp[i][2];
            contains[ind] = 1;
        }
    }
    for(int i = 0; i<n; i++) cout << contains[i] << " ";
    cout << endl;
    // for contained
    // L, R is contained by l, r
    // L >= l  and R <= r
    // start from left end, find rmax
    vector<int> contained(n, 0);
    int rmax = INT_MIN;
    for(int i = 0; i<n; i++)
    {
        if(vp[i][1] > rmax)
            rmax = vp[i][1];
        else{
            // rmin was not updated but R >= r min
            int ind = vp[i][2];
            contained[ind] = 1;
        }
    }
    for(int i = 0; i<n; i++) cout << contained[i] << " ";
    return 0;
}
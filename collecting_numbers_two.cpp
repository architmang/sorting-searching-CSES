#include<bits/stdc++.h>
using namespace std;
int n, m;
int bad(vector<int> &pos_arr, int num)
{
    if(num <= 1 || num > n) return 0;
    return (pos_arr[num] < pos_arr[num-1]);
}
int main()
{
    cin >> n >> m;
    vector<int> x, pos_arr;
    x.resize(n);
    pos_arr.resize(n+1);
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
        pos_arr[x[i]] = i; // i is index of x array
    }
    int round_cnt = 1;
    for(int j=2; j<=n; j++)
    {
        // j ... j-1
        if(pos_arr[j] < pos_arr[j-1])
            round_cnt++;
    }
    // cout << round_cnt << endl;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b; // index a-1, b-1
        // x[a-1], x[b-1] are the initial values we are dealing with
        int u = x[a-1];
        int v = x[b-1];
        // remove old contributions
        // duplication possible here
        set<int> st = {u, u+1, v, v+1};
        for(auto k:st)
            round_cnt -= bad(pos_arr, k);
        // update pos in pos arr
        pos_arr[x[a-1]] = b-1;
        pos_arr[x[b-1]] = a-1;
        // now swap fr
        int temp = x[a-1];
        x[a-1] = x[b-1];
        x[b-1] = temp;
        // add new contributions
        for(auto k:st)
            round_cnt += bad(pos_arr, k);
        cout << round_cnt << endl;
    }
}
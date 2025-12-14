#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x, pos_arr;
    x.resize(n);
    pos_arr.resize(n+1);
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
        pos_arr[x[i]] = i; // i is index of x array
    }
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b; // index a-1, b-1
        // update pos in pos arr
        pos_arr[x[a-1]] = b-1;
        pos_arr[x[b-1]] = a-1;
        // now swap fr
        int temp = x[a-1];
        x[a-1] = x[b-1];
        x[b-1] = temp;

        int round_cnt = 1;
        for(int j=2; j<=n; j++)
        {
            // j ... j-1
            if(pos_arr[j] < pos_arr[j-1])
                round_cnt++;
        }
        cout << round_cnt << endl;
    }
}
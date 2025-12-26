#include<bits/stdc++.h>
using namespace std;
using lint = long long;

int check(lint n, lint t, vector<lint> machines, lint mid)
{
    // mid is the amount of time, we are checking if sufficient
    lint cnt = 0;
    for(int i=0; i<n; i++)
    {
        cnt += (mid/machines[i]);
    }
    if(cnt >= t) return 1;
    return 0;
}

int main()
{
    lint n, t;
    cin >> n >> t;
    vector<lint> machines;
    machines.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> machines[i];
    }
    lint low = 1;
    lint high = t*(*min_element(machines.begin(), machines.end()));
    // guarenteed upper limit: fastes machine alone makes all
    lint final_ans = -1;
    while(low <= high)
    {
        lint mid = low + (high-low)/2;
        if(check(n,t, machines, mid))
        {
            final_ans = mid;
            // now check for lower values
            high = mid -1;
        }
        else{
            // check for higher values
            low = mid + 1;
        }
    }
    cout << final_ans;
    return 0;
}
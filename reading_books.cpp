#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> x;
    x.resize(n);
    // 1st constraint:  >= 2*max_time
    // 2nd constratint: >= sum
    long long sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
        sum+=x[i];
    }
    cout << max(sum, 2*(*max_element(x.begin(), x.end())));
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x; cin >> n >> x;
    vector<int> a;
    a.resize(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int left_ptr = 0, right_ptr = 0;
    int sum = 0;
    int cnt = 0;
    while(right_ptr < n)
    {
        while(right_ptr < n && sum < x)
        {
            sum += a[right_ptr];
            right_ptr++;
        }
        while(left_ptr < right_ptr && sum > x)
        {
            sum -= a[left_ptr];
            left_ptr++;
        }
        if(sum == x)
        {
            cnt++;
            sum -= a[left_ptr];
            left_ptr++;
        }
    }
    cout << cnt;
    return 0;
}
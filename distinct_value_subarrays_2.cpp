#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> x;
    x.resize(n);
    
    for(int i=0; i<n; i++)
        cin >> x[i];
    
    int left_ptr =0, right_ptr;
    long long ans = 0;
    map<int, int> fmap;
    
    for(right_ptr = 0;right_ptr <n; right_ptr++)
    {
        // here we insert first and then check invariant
        // insert right one
        fmap[x[right_ptr]]++;
        // shrink only when window is invalid
        while(fmap.size() > k)
        {
            fmap[x[left_ptr]]--;
            // If count becomes zero, the key must be removed
            // or fmap.size() stays incorrect.
            if(fmap[x[left_ptr]] == 0)
                fmap.erase(x[left_ptr]);
            left_ptr++;
        }
        ans+= right_ptr -left_ptr+1;
    }
    cout << ans;
    return 0;
}
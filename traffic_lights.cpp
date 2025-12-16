#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int main()
{
    int x, n;
    cin >> x >> n;
    vector<int> pos(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> pos[i];
    }
    set< pii > ranges;
    multiset<int> ranges_lengths;
    // if seg fault, make sure delete/init
    ranges.insert(make_pair(0, x));
    ranges_lengths.insert(x);
    for(int i=0; i<n; i++)
    {
        int new_pos = pos[i];
        auto it = ranges.upper_bound({new_pos, 0});
        it--;
        // upper bound and step back gives containing range
        int start = (*it).first;
        int end = (*it).second;
        ranges.erase(it);
        ranges.insert(make_pair(start, new_pos));
        ranges.insert(make_pair(new_pos, end));
        ranges_lengths.erase(ranges_lengths.find(end-start)); /// directly erasing by value is wrong
        ranges_lengths.insert(new_pos - start);
        ranges_lengths.insert(end - new_pos);
        cout << *ranges_lengths.rbegin() << " " ;
    }
    return 0;
}
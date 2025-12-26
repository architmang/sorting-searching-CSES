#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pi> timings;
    timings.resize(n);
    multiset<int> mt; // stores end time
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        cin >> timings[i].first >> timings[i].second;
    }
    sort(timings.begin(), timings.end());
    // sorts acc to incr start time
    for(int i=0; i<k; i++)
    {
        // assign first k movies, push end times
        mt.insert(timings[i].second);
    }
    for(int i=k; i<n; i++)
    {
        int curr_start = timings[i].first;
        int curr_end = timings[i].second;
        int movie_min_end = *mt.begin();

        if(curr_start >= movie_min_end)
        {
            // good thing, we can watch this
            ans++;
            mt.erase(mt.begin());
            mt.insert(curr_end);
        }
        else{
            // we cant watch this movie
            // but lets replace this movie with an unoptimal movie
            auto it = mt.end();
            it--;
            int movie_max_end = *it;
            if(curr_end < movie_max_end)
            {
                // ans remains same
                mt.erase(it);
                mt.insert(curr_end);
            }
        }
    }
    cout << ans + mt.size();
    return 0;
}
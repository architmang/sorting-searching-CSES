#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;

bool cmp(vi a, vi b)
{
    if(a[0] < b[0]) return 1;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<vi> timings;
    vector<int> roomId;
    roomId.resize(n);
    timings.resize(n);
    for(int i=0; i<n; i++)
    {
        timings[i].resize(3);
        cin >> timings[i][0] >> timings[i][1];
        timings[i][2] = i;
    }
    sort(timings.begin(), timings.end(), cmp);
    int roomCnt = 0;
    priority_queue<pi, vector<pi>, greater<pi> > pq; // stores depart time, roomIdx
    for(int i=0; i<n; i++)
    {
        int real_idx = timings[i][2];
        // current depart time is bigger than new arrival time
        if(roomCnt == 0 || pq.top().first >= timings[i][0])
        {
            roomCnt++;
            pq.push({timings[i][1], roomCnt});
            roomId[real_idx] = roomCnt;
        }
        else{
            auto curr = pq.top();
            int curr_room = curr.second;
            pq.pop();
            pq.push({timings[i][1], curr_room});
            roomId[real_idx] = curr_room;
        }
    }
    cout << roomCnt << endl;
    for(int i=0; i<n; i++)
    {
        cout << roomId[i] << " ";
    }
    return 0;
}
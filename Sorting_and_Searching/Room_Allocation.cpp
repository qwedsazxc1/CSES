#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> input(n);
    for (int i = 0; i < n; i++){
        cin >> input[i].first.first >> input[i].first.second;
        input[i].second = i;
    }
    sort(input.begin(), input.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    queue<int> empty_room;
    vector<int> room_id(n);
    int max_room = 0;
    for (int i = 0; i < n; i++){
        while (!pq.empty() && pq.top().first < input[i].first.first){
            empty_room.push(pq.top().second);
            pq.pop();
        }
        if (empty_room.empty()){
            max_room++;
            pq.push(make_pair(input[i].first.second, max_room));
            room_id[input[i].second] = max_room;
        }
        else{
            int room = empty_room.front();
            empty_room.pop();
            pq.push(make_pair(input[i].first.second, room));
            room_id[input[i].second] = room;
        }
    }
    cout << max_room << "\n";
    for (auto x: room_id){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
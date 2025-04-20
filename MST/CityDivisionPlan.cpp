// 백준 문제 : 도시 분할 계획

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    vector<pair<int,int>> adj[N+1]; // {비용, 정점}
    for(int i=0;i<M;i++){
        int A,B,C;
        cin >> A >> B >> C;

        adj[A].push_back({C,B});
        adj[B].push_back({C,A});
    }

    bool check[N+1] = {false};
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>> > pq; // {비용, 정점1, 정점2}
    check[1] = true;
    for(auto i:adj[1]){
        pq.push(make_tuple(i.first,1,i.second));   
    }

    int cnt = 0;
    int sum = 0;
    vector<int> costs;
    while(cnt < N-1){
        int a,b,c;
        tie(a,b,c) = pq.top(); pq.pop();
        if(check[c] == true) continue;
        check[c] = true;
        cnt += 1;
        sum += a;
        costs.push_back(a);

        for(auto i:adj[c]){
            if(check[i.second] == true) continue;
            pq.push(make_tuple(i.first,c,i.second));
        }
    }

    sum  -= *max_element(costs.begin(),costs.end()); // 최소 신장 트리의 경로 중 제일 비용이 큰 간선만 제거하면 두 마을의 최소 신장 트리 비용의 합이 됨
    cout << sum << "\n";
    
    return 0;
}
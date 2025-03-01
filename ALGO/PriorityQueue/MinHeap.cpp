// 백준 문제 : 최소 힙

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<int,vector<int>,greater<int>> pq;

    vector<int> answer;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        if(x == 0){
            if(pq.empty()){
                answer.push_back(0);
            } else {
                int e = pq.top();
                pq.pop();
                answer.push_back(e);
            }
        } else {
            pq.push(x);
        }
    }

    for(auto i:answer){
        cout << i << "\n";
    }
}
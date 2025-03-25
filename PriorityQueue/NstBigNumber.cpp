// 백준 문제 : N번째 큰 수

#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    priority_queue<int> pq;
    for(int i=0;i<N*N;i++){
        int e;
        cin >> e;
        if(pq.size() >= N){
            pq.push(e);
            pq.pop();
        } else {
            pq.push(e);
        }
    }

    for(int i=0;i<N-1;i++){
        pq.pop();
    }
    cout << pq.top() << "\n";
}
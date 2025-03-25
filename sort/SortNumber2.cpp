// 백준 문제 : 수 정렬하기 2

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N;
    cin >> N;

    priority_queue<int> pq;

    for(int i=0;i<N;i++){
        int e;
        cin >> e;
        pq.push(-e);
    }

    while(!pq.empty()){
        int e = pq.top(); pq.pop();
        cout << -e << "\n";
    }
}
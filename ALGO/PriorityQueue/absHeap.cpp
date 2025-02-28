// 백준 문제 : 절댓값 힙

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Compare {
    bool operator() (const int& a, const int& b){
        if(abs(a) == abs(b)){
            return a > b;
        } else {
            return abs(a) > abs(b);
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<int,vector<int>,Compare> pq;

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
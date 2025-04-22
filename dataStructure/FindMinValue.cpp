// 백준 문제 : 최솟값 찾기

#include <iostream>
#include <deque>
#include <queue>

using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, L;
	cin >> N >> L;
	
	vector<int> Ai;
	
	deque<int> dq;
	vector<int> answer;
	int cnt = 0;
	for(int i=0;i<N;i++){
		int e;
		cin >> e;
		priority_queue<int,vector<int>,greater<int>> pq;
		if(cnt < L){
			cnt++;
			dq.push_back(e);
		} else {
			dq.pop_front();
			dq.push_back(e);
		}
		for(int j=0;j<dq.size();j++){
			pq.push(dq[j]);
		}
		cout << pq.top() << " ";
	}
	
	/*
	for(auto i:answer){
		cout << i << " ";
	}
	*/
}
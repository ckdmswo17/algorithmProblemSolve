// 백준 문제 : 트리와 쿼리

#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];
vector<int> children[100001];
int st_size[100001];

void dfs(int cur, int prev) {

    for (auto i : adj[cur]) {
        if (i == prev) continue;
		children[cur].push_back(i);
        dfs(i,cur);
    }
	return;
}

void countSubtreeNodes(int node){
	st_size[node] = 1;
	for(auto i : children[node]){
		countSubtreeNodes(i);
		st_size[node] += st_size[i];
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, R, Q;
    cin >> N >> R >> Q;

    for (int i = 0;i < N-1;i++) {
        int U, V;
        cin >> U >> V;

        adj[U].push_back(V);
        adj[V].push_back(U);
    }

    vector<int> answer;
	dfs(R,-1);
	countSubtreeNodes(R);
	// cout << "before dfs" << "\n";
    for (int i = 0; i < Q;i++) {
        int q1;
        cin >> q1;

		answer.push_back(st_size[q1]);
    }
	// cout << "after dfs" << "\n";
	
	for(auto i:answer){
		cout << i << "\n";
	}

}

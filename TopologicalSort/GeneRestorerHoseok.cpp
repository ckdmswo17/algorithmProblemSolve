// 백준 문제 : 계보 복원가 호석

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);

    int N;
    cin >> N;
    string name[N+1];
    for(int i=1;i<N+1;i++){
        cin >> name[i];
    }

    stable_sort(name+1,name+N+1);

    unordered_map<string,int> um;
    for(int i=1;i<N+1;i++){
        um.insert({name[i],i});
    }

    int M;
    cin >> M;
    vector<int> adj[N+1];
    int deg[N+1];
    for(int i=1;i<N+1;i++){
        deg[i] = 0;
    }
    for(int i=0;i<M;i++){
        string s1,s2;
        cin >> s1 >> s2;

        adj[um[s2]].push_back(um[s1]);
        deg[um[s1]] += 1;
    }

    vector<string> root;
    int cnt = 0;
    for(int i=1;i<N+1;i++){
        if(deg[i] == 0) {
            root.push_back(name[i]);
            cnt++;
        }
    }

    cout << cnt << "\n";
    for(auto r:root){
        cout << r << " ";
    }
    cout << "\n";

    vector<int> c[N+1];
    for(int i=1;i<N+1;i++){
        stable_sort(adj[i].begin(),adj[i].end());
        for(auto j:adj[i]){
            if(deg[j] - deg[i] == 1) c[i].push_back(j); // 자식이 부모보다 deg가 1 더 많으면 자식으로 확정
        }
    }

    for(int i=1;i<N+1;i++){
        cout << name[i] << " " << c[i].size() << " ";
        for(auto j:c[i]){
            cout << name[j] << " ";
        }
        cout << "\n";
    }
}
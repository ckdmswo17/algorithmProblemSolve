// 백준 문제 : 트리 순회

#include <iostream>

using namespace std;

int N;
pair<char,char> c[27];

void dfs(int node, int mode){
    // cout << node << " " << mode << "\n";
    if(mode == 0){
        cout << char(node+'@');
        if(c[node].first != '.'){
            dfs(c[node].first-'@',0);
        }
        if(c[node].second != '.'){
            dfs(c[node].second-'@',0);
        }
    } else if(mode == 1){
        if(c[node].first != '.'){
            dfs(c[node].first-'@',1);
        }
        cout << char(node+'@');
        if(c[node].second != '.'){
            dfs(c[node].second-'@',1);
        }
    } else {
        if(c[node].first != '.'){
            dfs(c[node].first-'@',2);
        }
        if(c[node].second != '.'){
            dfs(c[node].second-'@',2);
        }
        cout << char(node+'@');
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=1;i<N+1;i++){
        char e1,e2,e3;
        cin >> e1 >> e2 >> e3;
        c[e1-'@'].first = e2; // 'A-Z' - '@'는 1~26
        c[e1-'@'].second = e3;
    }
    
    // for(int i=1;i<N+1;i++){
    //     cout << i << " : "<< c[i].first << " " << c[i].second << "\n";
    // }


    dfs(1,0);
    cout << "\n";
    dfs(1,1);
    cout << "\n";
    dfs(1,2);

}
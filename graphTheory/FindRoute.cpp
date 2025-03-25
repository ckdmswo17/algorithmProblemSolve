// 백준 문제 : 경로 찾기

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int dist[N+1][N+1];
    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
            int e;
            cin >> e;
            if(e == 0){
                dist[i][j] = INT_MAX;
            } else {
                dist[i][j] = e;
            }
        }
    }

    for(int k=1;k<N+1;k++){
        for(int i=1;i<N+1;i++){
            for(int j=1;j<N+1;j++){
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX){
                    continue;
                }
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }

        // for(int i=1;i<N+1;i++){
        //     for(int j=1;j<N+1;j++){
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }

    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
            if(dist[i][j] == INT_MAX){
                cout << 0 << " ";
            } else {
                cout << 1 << " ";
            }
        }
        cout << "\n";
    }
}
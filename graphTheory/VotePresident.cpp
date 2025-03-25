// 백준 문제 : 회장 뽑기

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int dist[n+1][n+1];
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            dist[i][j] = INT_MAX;
        }
    }
    while(true){
        int e1,e2;
        cin >> e1 >> e2;
        if(e1 == -1 && e2 == -1){
            break;
        }

        dist[e1][e2] = 1;
        dist[e2][e1] = 1;
    }

    // for(int i=1;i<n+1;i++){
    //     for(int j=1;j<n+1;j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int k=1;k<n+1;k++){
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX){
                    continue;
                }
                if(i == j){
                    continue;
                }
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }

        // for(int i=1;i<n+1;i++){
        //     for(int j=1;j<n+1;j++){
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }

    int president[n+1];
    for(int i=1;i<n+1;i++){
        int max = -100;
        for(int j=1;j<n+1;j++){
            if(dist[i][j] == INT_MAX){
                continue;
            }
            if(max < dist[i][j]){
                max = dist[i][j];
            }
        }
        president[i] = max;
    }

    // for(int i=1;i<n+1;i++){
    //     cout << president[i] << " ";
    // }
    // cout << "\n";

    int min = INT_MAX;
    for(int i=1;i<n+1;i++){
        if(min > president[i]){
            min = president[i];
        }
    }

    vector<int> answer;
    for(int i=1;i<n+1;i++){
        if(president[i] == min){
            answer.push_back(i);
        }
    }

    cout << min << " " << answer.size() << "\n";
    for(auto i:answer){
        cout << i << " ";
    }
    cout << "\n";

}

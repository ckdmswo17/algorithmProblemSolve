// 백준 문제 : 상범 빌딩
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int dz[6] = {-1,1,0,0,0,0}; // 위, 아래, 앞, 오, 뒤, 좌 순서
int dy[6] = {0,0,-1,0,1,0};
int dx[6] = {0,0,0,1,0,-1};
vector<int> L,R,C;

int bfs(int i, vector<vector<vector<char>>> building){
    queue<tuple<int,int,int>> qu;
    vector<vector<vector<int>>> dis(30,vector<vector<int>>(30,vector<int>(30,0))); 
    for(int j=0;j<L[i];j++){
        for(int z=0;z<R[i];z++){
            for(int q=0;q<C[i];q++){
                if(building[j][z][q] == 'S'){
                    qu.push({j,z,q});
                }
            }
        }
    }
    while(!qu.empty()){
        auto cur = qu.front(); qu.pop();
        int z = get<0>(cur);
        int y = get<1>(cur);
        int x = get<2>(cur);
        if(building[z][y][x] == 'E'){
            return dis[z][y][x];
        }
        for(int j=0;j<6;j++){
            int cz = z+dz[j];
            int cy = y+dy[j];
            int cx = x+dx[j];
            if(cz >= 0 && cz < L[i] && cy >= 0 && cy < R[i] && cx >= 0 && cx < C[i] && (building[cz][cy][cx] == '.' || building[cz][cy][cx] == 'E') && dis[cz][cy][cx] == 0){
                qu.push({cz,cy,cx});
                dis[cz][cy][cx] = dis[z][y][x] + 1;
                // cout << "============" << endl;
                // for(int z=0;z<L[i];z++){
                //     for(int q=0;q<R[i];q++){
                //         for(int w=0;w<C[i];w++){
                //             cout << dis[z][q][w];
                //         }
                //         cout << endl;
                //     }
                //     cout << "--------" << endl;
                // }
            }
        }
    }
    return -1;

}

int main(){
    int a,b,c;
    int count = 0;
    vector<vector<vector<vector<char>>>> building;
    cin >> a >> b >> c;
    while(a != 0 || b != 0 || c != 0){
        
        L.push_back(a);
        R.push_back(b);
        C.push_back(c);

        vector<vector<vector<char>>> d(30,vector<vector<char>>(30,vector<char>(30,'.')));
        for(int i=0;i<L[count];i++){
            for(int j=0;j<R[count];j++){
                string str;
                cin >> str;
                for(int z=0;z<C[count];z++){
                    d[i][j][z] = str[z];
                }
            }
        }
        building.push_back(d);

        // for(int i=0;i<L[count];i++){
        //     for(int j=0;j<R[count];j++){
        //         for(int z=0;z<C[count];z++){
        //             cout << d[i][j][z];
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }

        cin >> a >> b >> c;
        count++;
    } 

    for(int i=0;i<count;i++){
        int result = bfs(i,building[i]);
        if(result == -1){
            cout << "Trapped!" << endl;
        } else {
            cout << "Escaped in " << result << " minute(s)." << endl;
        }
    }
}
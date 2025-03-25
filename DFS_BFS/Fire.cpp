// 백준 문제 : 불

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int t;
// vector<int> w(t,0); // 크기를 초기화해준 vector는 인덱스로 접근할 수 X (segmentation fault)
// vector<int> h(t,0);

int bfs(int i,queue<pair<int,int>>& humanQu2, queue<pair<int,int>>& fireQu2,vector<vector<char>> building,vector<vector<int>> nums,int w, int h){

    while(!humanQu2.empty()){
        queue<pair<int,int>> fireQu = queue<pair<int,int>>();
        fireQu = fireQu2;
        fireQu2 = queue<pair<int,int>>();

        queue<pair<int,int>> humanQu = queue<pair<int,int>>();
        humanQu = humanQu2;
        humanQu2 = queue<pair<int,int>>();

        while(!fireQu.empty()){
            pair<int,int> cur2 = fireQu.front(); fireQu.pop();
            for(int j=0;j<4;j++){

                int fy = cur2.first + dy[j];
                int fx = cur2.second + dx[j];
                // cout << "불 이동 bfs : (" << fy << "," << fx << ")" << endl;
                if(fy >= 0 && fy < h && fx >= 0 && fx < w && (building[fy][fx] != '#' && building[fy][fx] != '*')){
                    building[fy][fx] = '*';
                    fireQu2.push({fy,fx});
                    // cout << "fireq 푸쉬!" << endl;
                    // cout << "==========================" << endl;
                    // for(int z=0;z<h;z++){
                    //     for(int q=0;q<w;q++){
                    //         cout << building[z][q];
                    //     }
                    //     cout << endl;
                    // }
                    
                }
            }
        }
        while(!humanQu.empty()){
            pair<int,int> cur = humanQu.front(); humanQu.pop();
            for(int j=0;j<4;j++){

                int hy = cur.first + dy[j];
                int hx = cur.second + dx[j];
                // cout << "사람 이동 bfs : (" << hy << "," << hx << ")" << endl;
                if(hy >= 0 && hy < h && hx >= 0 && hx < w && building[hy][hx] == '.' && nums[hy][hx] == 0){
                    nums[hy][hx] = nums[cur.first][cur.second]+1;
                    humanQu2.push({hy,hx});
                    // cout << "==========================" << endl;
                    // for(int z=0;z<h;z++){
                    //     for(int q=0;q<w;q++){
                    //         cout << nums[z][q];
                    //     }
                    //     cout << endl;
                    // }
                    // cout  <<"hq 푸쉬! : " << nums[i][hy][hx] << endl;
                } else if(hy < 0 || hy >= h || hx < 0 || hx >= w){
                    return nums[cur.first][cur.second];
                }
            }
        }
    }
    return -1;
}

int main(){
    
    cin >> t;
    int w[t];
    int h[t];
    vector<vector<vector<char>>> building;
    vector<vector<vector<int>>> nums;

    for(int i=0;i<t;i++){
        cin >> w[i] >> h[i];

        vector<vector<char>> b(h[i],vector<char>(w[i],'.'));
        vector<vector<int>> n(h[i],vector<int>(w[i],0));
        building.push_back(b);
        nums.push_back(n);

        string str;
        for(int j=0;j<h[i];j++){
            cin >> str;
            for(int z=0;z<w[i];z++){
                building[i][j][z] = str[z];
            }
        } 
    }

    for(int i=0;i<t;i++){
        queue<pair<int,int>> humanQu2 = queue<pair<int,int>>();
        queue<pair<int,int>> fireQu2 = queue<pair<int,int>>(); // 큐 초기화 진행

        for(int j=0;j<h[i];j++){
            for(int z=0;z<w[i];z++){
                if(building[i][j][z] == '@'){
                    humanQu2.push({j,z});
                    nums[i][j][z] = 1;
                } else if(building[i][j][z] == '*'){
                    fireQu2.push({j,z});
                }
            }
        }

        int result = bfs(i,humanQu2,fireQu2,building[i],nums[i],w[i],h[i]);

        if(result == -1){
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << result << endl;
        }
    }
}

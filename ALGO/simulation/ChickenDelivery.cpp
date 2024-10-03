// 백준 문제 : 치킨 배달 (재귀 방식은 시간초과, https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0D/solutions/15686.cpp 참고해서 해결)

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N,M;
int length1,length2 = 0;
vector<pair<int,int>> location1(100,{-1,-1});
vector<pair<int,int>> location2(13,{-1,-1});

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    int e;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> e;
            if(e == 2){
                location2[length2] = {i,j};
                length2 += 1;
            }
            if(e == 1){ 
                location1[length1] = {i,j};
                length1 += 1;
            }
        }
    }

    vector<int> arr(length2,1);
    fill(arr.begin(),arr.begin()+length2-M,0);

    int answer = 10000;
    do{

        int dist = 0;
        for(int h=0;h<length1;h++){
            int tmp = 10000;
            for(int i=0;i<length2;i++){
                if(arr[i] == 0) continue;
                tmp = min(tmp,abs(location2[i].first-location1[h].first)+abs(location2[i].second-location1[h].second));
            }
            dist += tmp;
        }
        // cout << answer << " " << dist << "\n";
        answer = min(answer,dist);
    } while(next_permutation(arr.begin(),arr.end()));
    cout << answer << "\n";

}
// 백준 문제 : 기타콘서트 (https://blog.encrypted.gg/1093 참고)

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N,M;
long long songs[10];

int bit_cnt(long long x){
    int ret = 0;
    for(int i=0;i<max(N,M);i++){
        ret += (x >> i) & 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        string guitar,song;
        cin >> guitar >> song;
        
        for(int j=M-1;j>=0;j--){
            songs[i] = (songs[i] << 1) | (song[j] == 'Y');
        }
    }

    pair<int,int> ans = {0, -1}; // {song 개수, 기타 수}
    for(int tmp=0;tmp<(1<<N);tmp++){ // 2^M 모든 경우의 수 고려
        long long comb = 0;
        for(int i=0;i<M;i++){
            if((tmp & (1LL << i)) == 0) continue;
            comb |= songs[i];
        }

        int song_num = bit_cnt(comb);
        int guitar_num = bit_cnt(tmp);
        if(ans.first < song_num){
            ans = {song_num, guitar_num};
        } else if(ans.first == song_num && ans.second > guitar_num){
            ans = {song_num,guitar_num};
        }
    }
    cout << ans.second << "\n";
}
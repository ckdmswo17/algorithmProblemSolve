// 백준 문제 : 멀티버스 ||

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M,N;
int arr[1000000];

int main(void){
    cin >> M >> N;

    for(int i=0;i<M*N;i++){
        cin >> arr[i];
    }
    
    for(int i=0;i<M;i++){

        // 블로그버전 (https://wikidocs.net/214469) 좌표압축
        vector<pair<int,int>> compressArr(N,{0,0});
        for(int j=0;j<N;j++){
            compressArr[j].first = j;
            compressArr[j].second = arr[i*N+j];
        }

        stable_sort(compressArr.begin(),compressArr.end(),[](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        // for(int j=0;j<N;j++){
        //     cout << compressArr[j].second << " ";
        // }
        // cout << endl;

        int count = -1;
        for(int j=0;j<N;j++){
            if(j>0){
                if(arr[i*N+compressArr[j-1].first] == arr[i*N+compressArr[j].first]){ // 동일값 동일순위로 처리
                    compressArr[j].second = count;
                } else {
                    count += 1;
                    compressArr[j].second = count;
                }
            } else {
                count += 1;
                compressArr[j].second = count;
            }
        }

        // for(int j=0;j<N;j++){
        //     cout << compressArr[j].first<<","<<compressArr[j].second << " ";
        // }
        // cout << endl;

        for(int j=0;j<N;j++){
            arr[i*N+compressArr[j].first] = compressArr[j].second;
        }

        // for(int j=0;j<N;j++){
        //     cout << arr[i*N+j] << " ";
        // }
        // cout << endl;
    }

    int answer = 0;
    for(int i=0;i<M;i++){
        for(int j=i+1;j<M;j++){
            bool isEven = true;
            for(int z=0;z<N;z++){
                if(arr[i*N+z] != arr[j*N+z]){
                    isEven = false;
                }
            }
            if(isEven == true){
                answer += 1;
            }
        }
    }
    cout << answer << endl;
}
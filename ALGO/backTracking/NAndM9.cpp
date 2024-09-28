// 백준 문제 : N과 M (9)

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N,M;
int nums[8];
vector<vector<int>> arr(40320,vector<int>(8,-1)); // 40320 = 8!
int step = 0;

void p(vector<bool> isUsed,int count){
    if(count == M){
        step += 1;
        return;
    }

    for(int i=0;i<N;i++){
        if(isUsed[i] == false){
            isUsed[i] = true;
            arr[step][count] = nums[i];
            if(count > 0){
                if(arr[step][count-1] == -1){
                    for(int j=count-1;j>=0;j--){
                        arr[step][j] = arr[step-1][j];
                    }
                }
            }
            p(isUsed,count+1);
            isUsed[i] = false;
        }
    }
}

int main(){
    cin >> N >> M;
    vector<bool> isUsed(N,false);

    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    sort(nums,nums+N);
    p(isUsed,0);

    set<vector<int>> unique_rows;
    vector<vector<int>> result;

    for(int i=0;i<step;i++){
        const auto& row = arr[i];
        if(unique_rows.insert(row).second){
            result.push_back(row);
        }
    }

    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            if(result[i][j] != -1){
                cout << result[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

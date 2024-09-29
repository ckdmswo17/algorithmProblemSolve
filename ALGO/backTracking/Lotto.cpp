// 백준 문제 : 로또

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> K;
vector<vector<int>> nums;
vector<vector<int>> ve;
vector<int> v(6,0);

void l(vector<bool> isUsed,int t, int count){

    if(count == 6){
        ve.push_back(v);
        return;
    }

    for(int i=0;i<K[t];i++){
        if(isUsed[i] == false){
            isUsed[i] = true;
            v[count] = nums[t][i];
            l(isUsed,t,count+1);
            isUsed[i] = false;
        }
    }
}

int main(){
    int e;
    cin >> e;
    while(e != 0){
        K.push_back(e);

        vector<int> num(e,0);
        for(int i=0;i<e;i++){
            cin >> num[i];
        }
        nums.push_back(num);

        cin >> e;
    }

    for(int i=0;i<K.size();i++){
        vector<bool> isUsed(K[i],false);
        ve.clear();
        l(isUsed,i,0);
        
        set<vector<int>> unique_rows;
        vector<vector<int>> result;
        for(int j=0;j<ve.size();j++){
            sort(ve[j].begin(),ve[j].end());
            if(unique_rows.insert(ve[j]).second){
                result.push_back(ve[j]);
            }
        }

        for(int j=0;j<result.size();j++){
            for(int z=0;z<6;z++){
                cout << result[j][z] << " ";
            }
            cout << "\n";
        }
        if(i != K.size()-1){
            cout << "\n";
        }

    }
}
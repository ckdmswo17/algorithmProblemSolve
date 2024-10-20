// 백준 문제 : 트리의 부모 찾기 (미완)

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> trees;
int parents[100001];

void parentsFind(int i, int beforeE)
{
    bool isEnd = false;
    int j = 0;
    while(isEnd == false){
        // cout << isEnd <<  " "<< trees[i][j] << "\n";
        if(trees[i][j] == 0){
            isEnd = true;
            break;
        }
        if(beforeE == trees[i][j]){
            parents[i] = trees[i][j];
        } else {
            parentsFind(trees[i][j],i);
        }
        j += 1;
    }
    return;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    // trees(N+1,vector<int>(N,0));
    for(int i=0;i<N-1;i++){
        int e1,e2;
        cin >> e1 >> e2;

        int j = 0;
        while(trees[e1][j] != 0){
            j += 1;
        }
        trees[e1][j] = e2;

        int z = 0;
        while(trees[e2][z] != 0){
            z += 1;
        }
        trees[e2][z] = e1;
        
    }

    parentsFind(1,0);
    for(int i=2;i<N+1;i++){
        cout << parents[i] << "\n";
    }

    
}
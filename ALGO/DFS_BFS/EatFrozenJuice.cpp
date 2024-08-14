// 이코테 문제  : 음료수 얼려먹기
#include <iostream>
#include <string>

using namespace std;

class EatFrozenJuice{

private :
    int N;
    int M;
    int** ququ;

public :
    int getN();
    int getM();
    bool dfs(int,int);
    EatFrozenJuice();
    ~EatFrozenJuice();

};

EatFrozenJuice::~EatFrozenJuice(){
    for(int i=0;i<N;i++){
        delete[] ququ[i];
    }
    delete[] ququ;
}


EatFrozenJuice::EatFrozenJuice(){
        cin >> N >> M;
        ququ = new int*[N];
        for(int i=0;i<N;i++){
            ququ[i] = new int[M];
        }

        for(int j =0;j<N;j++){
            string line;
            cin >> line;
            for(int i=0;i<line.length();i++){
                ququ[j][i] = stoi(line.substr(i,1));
            }
        }

        // cout << "\n";
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<M;j++){
        //         cout << ququ[i][j];
        //     }
        //     cout << "\n";
        // }
    }

    int EatFrozenJuice::getN(){ return N;}
    int EatFrozenJuice::getM(){return M;}

    bool EatFrozenJuice::dfs(int y,int x){
        if((y < 0 || y >= N) || (x <0 || x >= M)){
            return false;
        }
        // cout << "필터 통과" << "\n";
        if(ququ[y][x] == 0){
            ququ[y][x] = 1;
            dfs(y-1,x);
            dfs(y,x+1);
            dfs(y+1,x);
            dfs(y,x-1);
            return true;
        } else {
            return false;
        }
        
    }

int main(){
        EatFrozenJuice ef = EatFrozenJuice();

        int count = 0;
        for(int i=0;i<ef.getN();i++){
            for(int j=0;j<ef.getM();j++){
                // cout << "반복" << "\n";
                if(ef.dfs(i,j)){
                    count += 1;
                }
            }
        }
        cout << count << "\n";
        return 0;
}

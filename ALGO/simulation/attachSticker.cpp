// 백준 문제 : 스티커 붙이기

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,M,K;
    cin >> N >> M >> K;

    int notebook[N][M];
    for(int a=0;a<N;a++){
        for(int b=0;b<M;b++){
            notebook[a][b] = 0;
        }
    }

    for(int q=0;q<K;q++){

        // cout <<"\n"<< "===============" << "\n";
        // for(int a=0;a<N;a++){
        //     for(int b=0;b<M;b++){
        //         cout << notebook[a][b] << " ";
        //     }
        //     cout << "\n";
        // }

        int r,c;
        cin >> r >> c;
        vector<pair<int,int>> sticker;

        int e;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin >> e;
                if(e == 1){
                    sticker.push_back({i,j});
                }
            }
        }

        bool isEnd = false; // 스티커를 notebook배열에 위치시켰는지 지표
        for(int rotation=0;rotation<4&&isEnd==false;rotation++){
            // cout << "현재 rot : " << rotation << " " << "현재 q : " << q << "\n";
            pair startPos = {0,0};
            pair endPos = {r-1,c-1};
            while(endPos.first<N){ 

                while(endPos.second<M){
                    bool isOkay = true; // 한번에 모든 스티커가 다 붙을수 있는지 지표
                    for(int i=0;i<sticker.size()&&isOkay==true;i++){
                        if(notebook[startPos.first+sticker[i].first][startPos.second+sticker[i].second] == 1){
                            isOkay = false;
                        }
                    }
                    if(isOkay == true){
                        for(int i=0;i<sticker.size();i++){
                            notebook[startPos.first+sticker[i].first][startPos.second+sticker[i].second] = 1;
                        }
                        isEnd = true;
                    }
                    if(isEnd == true){
                        break;
                    }
                    // cout << "왼위 좌표 : "<< startPos.first << " " << startPos.second << "  오른아래 좌표 : " << endPos.first << " " << endPos.second << "\n";
                    startPos.second += 1;
                    endPos.second += 1;
                }
                startPos.second = 0;
                endPos.second = c-1;
                if(isEnd == true){
                    break;
                }
                startPos.first += 1;
                endPos.first += 1;
            }
            if(isEnd == true){
                break;
            }

            for(int j=0;j<sticker.size();j++){
                int newY = sticker[j].second;
                int newX = r-1-sticker[j].first;
                
                // cout << "회전 후 위치 : " << newY << " " << newX << "\n"; 
                sticker[j].first = newY;
                sticker[j].second = newX;
            } 
            int tempR = r;
            r = c;
            c = tempR;
        }
        
    }

    int answer = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(notebook[i][j] == 1){
                answer += 1;
            }
        }
    }
    cout << answer << "\n";
}
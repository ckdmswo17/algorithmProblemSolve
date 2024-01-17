// 이코테 문제 : 상하좌우
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main()
{
    int N;
    cin >> N;

    string guide;
    cin.ignore(); // 버퍼비우기
    getline(cin,guide); // 그냥 cin 입력은 띄어쓰기를 기준으로 받기때문에 한 라인 전체를 문자열로 받아야함
    
    int dx[4] = {0,-1,0,1};
    int dy[4] = {1,0,-1,0};
    
    int x = 0;
    int y = 0;
    
    for(int i=0;i<guide.size();i++){
        switch(guide[i]) {
            case 'L' : 
                if(y+dy[2] >= 0) {
                    x = x+dx[2];
                    y = y+dy[2];
                }
                break;
            case 'R' :
                if(y+dy[0] < N) {
                    x = x+dx[0];
                    y = y+dy[0];
                }
                break;
            case 'U' :
                if(x+dx[1] >= 0) {
                    x = x+dx[1];
                    y = y+dy[1];
                }
                break;
            case 'D' :
                if(x+dx[3] < N) {
                    x = x+dx[3];
                    y = y+dy[3];
                }
                break;
            default :
                break;
        }
    }
    
    cout << x << " " << y;
}
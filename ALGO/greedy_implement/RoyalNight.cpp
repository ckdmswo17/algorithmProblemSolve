// 이코테 문제 : 왕실의 나이트
#include <iostream>
#include <string>

using namespace std;
int main()
{
    int* dl = new int[2]; // int dx = {2,-2,1,-1,-2,2,-1,1}
    int* ds = new int[2]; // int dy = {1,-1,2,-2,1,-1,2,-2} 이렇게 설정하는게 방향벡터의 정의에 더 맞다
    dl[0] = -2;
    dl[1] = 2;
    ds[0] = -1;
    ds[1] = 1;

    string nowPosition;
    cin >> nowPosition;
    
    int y = nowPosition[1] - '1';
    int x = nowPosition[0] - 'a';
    cout << "Now Position : "<< y <<" "<< x << endl;
    
    int count = 0;
    for(int z=0;z<2;z++) {
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++) {
                if((y + dl[i] >= 0 && y+dl[i] <= 7) && (x+ ds[j] >= 0 && x+ds[j] <= 7)){
                    cout<< y+dl[i] << " " << x+ds[j] << endl; 
                    count++;
                }
            }
        }
        int* tmp = new int[2];
        tmp = dl;
        dl = ds;
        ds = tmp;    // directionVector address change
    }
    
    cout << "Move : " << count;
}
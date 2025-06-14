// 백준 문제 : 세수정렬

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    int maxN = max({n1,n2,n3});
    int minN = min({n1,n2,n3});
    int middleN = n1+n2+n3-maxN-minN;
    cout << minN << " " << middleN << " " << maxN << "\n"; 
}
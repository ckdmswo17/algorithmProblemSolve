// 백준 문제 : 2루수 이름이 뭐야

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string name;
    bool findWhat = false;
    for(int i=0;i<N;i++){
        cin >> name;
        if(name == "anj") findWhat = true;
    }

    if(findWhat == true) cout << "뭐야;\n";
    else cout << "뭐야?\n";
}
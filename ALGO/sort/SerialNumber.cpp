// 백준 문제 : 시리얼 번호

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<string> sn(N,"");
    for(int i=0;i<N;i++){
        cin >> sn[i];
    }

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(sn[i].length() > sn[j].length()){
                string tmp = sn[i];
                sn[i] = sn[j];
                sn[j] = tmp;
            } else if(sn[i].length() < sn[j].length()){
                continue;
            } else if(sn[i].length() == sn[j].length()){
                int sumi = 0;
                for(int z=0;z<sn[i].length();z++){
                    int e = sn[i].at(z)-'0';
                    if(e < 10){
                        sumi += e;
                    }
                }

                int sumj = 0;
                for(int z=0;z<sn[j].length();z++){
                    int e = sn[j].at(z)-'0';
                    if(e < 10){
                        sumj += e;
                    }
                }

                if(sumi > sumj){
                    string tmp = sn[i];
                    sn[i] = sn[j];
                    sn[j] = tmp;
                } else if(sumi == sumj){
                    int result = sn[i].compare(sn[j]);
                    if(result > 0){
                        string tmp = sn[i];
                        sn[i] = sn[j];
                        sn[j] = tmp;
                    }
                }
            }
        }
    }
    
    for(int i=0;i<N;i++){
        cout << sn[i] << "\n";
    }
}

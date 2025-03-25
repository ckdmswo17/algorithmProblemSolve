// 백준 문제 : 대칭 차집합

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <list>

using namespace std;

vector<string> split(const std::string& str) {
    istringstream iss(str);
    vector<string> result;

    for (string s; iss >> s; ) {
        result.push_back(s);
    }

    return result;
}

int main(){
    int aCount;
    int bCount;
    cin >> aCount >> bCount;
    
    vector<string> A;
    vector<string> B;

    string sentence;
    cin.ignore();
    getline(cin,sentence);
    A = split(sentence);
    sort(A.begin(),A.end());

    getline(cin,sentence);
    B = split(sentence);
    sort(B.begin(),B.end());

    int sum = aCount + bCount;
    for(int i=0;i<A.size();i++){
        bool it = binary_search(B.begin(),B.end(),A[i]);
        // cout << A[i] << " " << sum << endl;
        if(it){
            // B.erase(it);
            sum -= 2;
        }
    }
    cout << sum << endl;
    return 0;
}
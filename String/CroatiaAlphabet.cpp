// 백준 문제 : 크로아티아 알파벳

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string word;
	cin >> word;
	
	vector<string> alphabets = {"c=","c-","dz=","d-","lj","nj","s=","z="};
	int answer = 0;
	for(int i=0;i<word.length();i++){
		//cout << "i : " << i << "\n"; 
		bool isCroatia = false;
		for(int j=2;j<4&&i+j<=word.length();j++){
			//cout << word.substr(i,j) << "\n";
			if(find(alphabets.begin(),alphabets.end(),word.substr(i,j)) != alphabets.end()) {
				answer++;
				i = i+j-1;
				isCroatia = true;
				break;
			}
		}
		if(isCroatia == false){
			answer++;
		}
	}
	
	cout << answer << "\n";
	
}
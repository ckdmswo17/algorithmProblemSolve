// 백준 문제 풀이 : 친구
using System;

namespace std {
    public class Friend{
        static void Main(string[] args){
            int N = Int32.Parse(Console.ReadLine());
            char[][] friend = new char[N][N];
            for(int i=0;i<N;i++){
                string sen = Console.ReadLine();
                for(int j=0;j<N;j++){
                    friend[i][j] = sen[j];
                }
            }
            
        }
    }
}
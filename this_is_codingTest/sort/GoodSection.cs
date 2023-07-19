// 백준 문제 풀이 : 좋은 구간
using System;
using static System.Array;

namespace std {
    class GoodSection{
        static void Main(string[] args){
            int L = Int32.Parse(Console.ReadLine());
            string[] s_set = Console.ReadLine().Split(" ");
            int[] set = new int[L+2];
            for(int i=0;i<L;i++){
                set[i] = Int32.Parse(s_set[i]);
            }
            int n = Int32.Parse(Console.ReadLine());
            set[L] = n;
            set[L+1] = 0;
            Array.Sort(set);
            int n_index = Array.IndexOf(set,n);
            // for(int i=0;i<L+2;i++){
            //     Console.Write(set[i]+" ");
            // }

            int answer = 0;
            if(set[n_index] == set[n_index+1]){ // S에 n과 동일한 수가 있을 경우
                Console.WriteLine(answer);
                Environment.Exit(0);
            }
            for(int i=set[n_index-1]+1;i<n+1;i++){
                if(i<n){
                    answer += set[n_index+1]-n;
                } else {
                    answer += set[n_index+1]-1-n;
                }
            }
            Console.WriteLine(answer);
        }
    }
}
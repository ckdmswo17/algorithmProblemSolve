// 백준 문제풀이 : 소수 게임

using System;

namespace std{
    class SosuGame{
        static void Main(string[] args){
            int T = Int32.Parse(Console.ReadLine());
            int[] A = new int[T];
            int[] k = new int[T];
            for(int i=0;i<T;i++){
                string[] sen = Console.ReadLine().Split(" ");
                A[i] = Int32.Parse(sen[0]);
                k[i] = Int32.Parse(sen[1]);
            }

            for(int j=0;j<T;j++){
                List<int> eratosteneth = new List<int>();
                for(int i=2;i<=A[j];i++){
                    if(i%2 != 0 || i==2){
                        if(i%3 != 0 || i == 3){
                            if(i%5 != 0 || i== 5){
                                if(i%7 !=0 || i==7){
                                    eratosteneth.Add(i);
                                }
                            }
                        }
                    }
                }
            
                for(int i=0;i<eratosteneth.Count;i++){
                    Console.ReadLine(eratosteneth[i]);
                }
            }
        }
    }
}
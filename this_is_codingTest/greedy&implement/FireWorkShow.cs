// 백준 문제 : 폭죽쇼

using System;

namespace std{
    class FireWorkShow{
        static void Main(string[] args){
            string[] nc = Console.ReadLine().Split(" ");
            int N = Int32.Parse(nc[0]);
            int C = Int32.Parse(nc[1]);

            int[] duration = new int[N];
            for(int i=0;i<N;i++){
                duration[i] = Int32.Parse(Console.ReadLine());
            }

            // List<int> list = new List<int>(); // 메모리 초과 유발
            // for(int i=0;i<N;i++){
            //     int j = 1;
            //     while(duration[i] * j <= C){
            //         list.Add(duration[i] * j);
            //         j++;
            //     }
            //     list = list.Distinct().ToList();
            // }

            // for(int i=0;i<list.Count;i++){
            //     Console.WriteLine(list[i]);
            // }
            // Console.WriteLine(list.Count);

            int count = 0;
            for(int i=1;i<=C;i++){
               for(int j=0;j<N;j++){
                if(i % duration[j] == 0){
                    count += 1;
                    break;
                }
               }
            }
            Console.WriteLine(count);

        }
    }
}
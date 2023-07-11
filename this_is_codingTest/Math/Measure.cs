// 백준 문제 : 약수
using System;

namespace std {
    class Measure {
        static void Main(string[] args){
            int num = Int32.Parse(Console.ReadLine());
            string[] s_measures = Console.ReadLine().Split(" ");
            int[] measures = new int[num];
            for(int i =0;i<num;i++){
                measures[i] = Int32.Parse(s_measures[i]);
            }
            
            Array.Sort(measures);
            // Console.WriteLine($"{string.Join(", ",measures)}");
            int answer = measures[0] * measures[num-1];
            Console.WriteLine(answer);
        }
    }
}
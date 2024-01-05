// 백준 문제 : 별 찍기 -10 (미완)
using System;

namespace std {
    class DrawStar{
        static void Main(string[] args){
            int N = Int32.Parse(Console.ReadLine());
            draw(N);
        }

        static void draw(int pattern){
            if(pattern < 1){
                return;
            }
            if(pattern == 1){
                Console.WriteLine("*");
            }
            draw(pattern/3);
            draw(pattern/3);
            draw(pattern/3);
            draw(pattern/3);
            for(int i=0;i<pattern/3;i++){
                for(int j=0;j<pattern/3;j++){
                    Console.Write(" ");
                }
                Console.WriteLine();
            }
            draw(pattern/3);
            draw(pattern/3);
            draw(pattern/3);
            draw(pattern/3);
            return;
        }
    }
}
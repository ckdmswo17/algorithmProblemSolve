// 백준 문제 풀이 : 게임
using System;
// using System.Math;

namespace std {
    class Game {
        static void Main(string[] args){
            string[] XY = Console.ReadLine().Split(" "); 
            double X = Double.Parse(XY[0]);
            double Y = Double.Parse(XY[1]);
            double Z = Math.Truncate(100*Y/X);

            double answer = -1.0;
            if(Z >= 99){ // 99퍼에서 올리는건 무한대로 발산하므로 -1 처리 
                Console.WriteLine(answer);
                return;
            }
            // 방정식 해결방법 
            // Z + 1 = 100*(y+answer)/(x+answer)
            // answer = (100Y-ZX-X)/(Z-99)
            // answer = (100Y-(100*Y/X)X-X)/((100*Y/X)-99)
            answer = Math.Ceiling((100*Y-Z*X-X)/(Z-99)); // 최소값은 거의 실수이므로 올림해주기

            // O(n) 반복 해결방법 > 시간초과
            // while(Z == Math.Truncate(100*Y/X)){
            //     X += 1;
            //     Y += 1;
            //     answer += 1;     
            // }  
            Console.WriteLine(answer); 
        }
    }
}
// 백준 문제 : 막대기

namespace std {
    class Stick{
        static void Main(string[] args){
            int X = Int32.Parse(Console.ReadLine());
            int measure_start = 64;
            int answer = 1;
            while(X % measure_start != 0){
                if(X / measure_start == 0){
                    measure_start /= 2;
                } else {
                    X %= measure_start;
                    measure_start /= 2;
                    answer += 1;
                }
            }
            Console.WriteLine(answer);

        }
    }
}
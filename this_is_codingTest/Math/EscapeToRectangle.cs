// 백준 문제 : 직사각형에서 탈출
using iostream;
// using String;
using Math;

class EscapeToRectangle{
    static void Main(string[] args){
        string phrase = Console.ReadLine();
        string[] s_position = phrase.Split(" ");
        int[] position = new int[s_position.Length];
        for(int i =0;i<s_position.Length;i++){
            position[i] = Int32.Parse(s_position[i]); 
        }
        
        int widthMin = Math.Min(position[0],position[2]-position[0]); // 수평 최소값
        int heightMin = Math.Min(position[1],position[3]-position[1]);  // 수직 최소값
        int result = Math.Min(widthMin,heightMin); // 대각선은 직선보다 무조건 길기때문에 계산할 필요없고, 두 최소값중 더 작은값이 정답
        Console.WriteLine(result);
    }
}
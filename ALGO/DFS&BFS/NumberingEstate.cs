// 백준 문제 : 단지번호붙이기
using System;

namespace std {
    class NumberingEstate{
        static void Main(string[] args){
            int N = Int32.Parse(Console.ReadLine());
            int[,] mapInfo = new int[N,N];
            for(int i=0;i<N;i++){
                string row = Console.ReadLine();
                for(int j=0;j<N;j++){
                    mapInfo[i,j] = (int)(row[j])-48;
                    // Console.WriteLine(mapInfo[i,j]);
                }
            }

            int estateCount = 0;
            List<int> list = new List<int>();
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    int count = dfs(ref mapInfo,i,j);
                    if(count != 0){
                        estateCount += 1;
                        list.Add(count);
                    }
                    //Console.WriteLine(count);
                }
            }

            list.Sort();
            Console.WriteLine(estateCount);
            for(int i=0;i<estateCount;i++){
                Console.WriteLine(list[i]);
            }
        }

        static int dfs(ref int[,] mapInfo, int y, int x){
            if(0<=y && y < mapInfo.GetLength(0) && 0<=x && x < mapInfo.GetLength(1)){
                if(mapInfo[y,x] == 1){
                    //Console.WriteLine(y+" "+x);
                    mapInfo[y,x] = 0;
                    return 1+dfs(ref mapInfo,y-1,x)+dfs(ref mapInfo,y,x+1)+dfs(ref mapInfo,y+1,x)+dfs(ref mapInfo,y,x-1);
                }
            }
            return 0;

        }
    }
}
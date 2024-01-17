// 백준 문제 : 유기농 배추

using System;

namespace std {
    class OrganicCabbage{
        static void Main(string[] args){
            int T = Int32.Parse(Console.ReadLine());

            for(int i=0;i<T;i++){
                string[] MNK = Console.ReadLine().Split(" ");
                int M = Int32.Parse(MNK[0]);
                int N = Int32.Parse(MNK[1]);
                int K = Int32.Parse(MNK[2]);

                int[,] mapInfo = new int[N,M];
                for(int j=0;j<K;j++){
                    string[] XY = Console.ReadLine().Split(" ");
                    int X = Int32.Parse(XY[0]);
                    int Y = Int32.Parse(XY[1]);
                    mapInfo[Y,X] = 1; // 배추유무 
                }

                // Queue<int> queue = new Queue<int>();

                int count = 0;
                for(int j=0;j<N;j++){
                    for(int z=0;z<M;z++){
                        if(dfs(ref mapInfo,j,z)){
                            count += 1;
                        }
                    }
                }
                Console.WriteLine(count);  
            }

            
        }

        public static bool dfs(ref int[,] mapInfo,int y,int x){
            // Console.WriteLine(y+""+x);
            // for(int j=0;j<mapInfo.GetLength(0);j++){
            //     for(int z=0;z<mapInfo.GetLength(1);z++){
            //         Console.Write(mapInfo[j,z]);
            //     }
            //     Console.WriteLine();
            // }
            // Console.WriteLine();
                
            if((0<=y) && (y<mapInfo.GetLength(0)) && (0<=x) && (x<mapInfo.GetLength(1))){
                if(mapInfo[y,x] == 1){
                    // Console.WriteLine("들왔다");
                    mapInfo[y,x] = 0;
                    dfs(ref mapInfo,y-1,x);
                    dfs(ref mapInfo,y,x+1);
                    dfs(ref mapInfo,y+1,x);
                    dfs(ref mapInfo,y,x-1);
                    return true;
                }
                return false; 
            }
            return false;
        }
    }
}

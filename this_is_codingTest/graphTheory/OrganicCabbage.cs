// 백준 문제 : 유기농 배추(미완)

using System;

namespace std {
    class OrganicCabbage{
        static void Main(string[] args){
            int T = Int32.Parse(Console.ReadLine());
            string[] MNK = Console.ReadLine().Split(" ");
            int M = Int32.Parse(MNK[0]);
            int N = Int32.Parse(MNK[1]);
            int K = Int32.Parse(MNK[2]);

            int[,,] mapInfo = new int[N,M,2];
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    mapInfo[i,j,0] = 0; // 방문여부
                }
            }
            for(int i=0;i<K;i++){
                string[] XY = Console.ReadLine().Split(" ");
                int X = Int32.Parse(XY[0]);
                int Y = Int32.Parse(XY[1]);
                mapInfo[X,Y,1] = 1; // 배추유무 
            }

            Queue<int> queue = new Queue<int>();
            int[] dx = {0,1,0,-1};
            int[] dy = {-1,0,1,0};

            
        }
    }
}

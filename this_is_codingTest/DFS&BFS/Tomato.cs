// 백준 문제 : 토마토 (시간초과로 미해결)

using System;

namespace std {
    class Tomato{
        static void Main(string[] args){
            string[] MN = Console.ReadLine().Split(" ");
            int M = Int32.Parse(MN[0]);
            int N = Int32.Parse(MN[1]);

            int[,] mapInfo = new int[N,M];
            for(int i=0;i<N;i++){
                string[] row = Console.ReadLine().Split(" ");
                for(int j=0;j<M;j++){
                    mapInfo[i,j] = Int32.Parse(row[j]);
                    // mapInfo[i] = row;
                }
            }

            int count = 0;
            int[] dy = {-1,0,1,0};
            int[] dx = {0,1,0,-1};
            bool sucessSignal = false;
            bool failSignal = false;
            int[,] copyArray = (int[,])(mapInfo.Clone());

            while(!sucessSignal && !failSignal){
                sucessSignal = true;
                failSignal = true;
                for(int i=0;i<N;i++){
                    for(int j=0;j<M;j++){
                        if(mapInfo[i,j] == 0){
                            for(int z=0;z<4;z++){
                                if(0 <= i+dy[z] && i+dy[z]<mapInfo.GetLength(0) && 0<=j+dx[z] && j+dx[z]<mapInfo.GetLength(1)){
                                    if(mapInfo[i+dy[z],j+dx[z]] == 1){
                                        mapInfo[i,j] = 2;
                                    }    
                                }
                            }
                        }
                    }
                }
                
                for(int i=0;i<N;i++){
                    for(int j=0;j<M;j++){
                        if(copyArray[i,j] != mapInfo[i,j]){
                            failSignal = false;
                        }
                        if(mapInfo[i,j] == 2){
                            mapInfo[i,j] = 1;
                        }
                        if(mapInfo[i,j] == 0) {
                            sucessSignal = false;
                        }
                    }
                }
                copyArray = (int[,])(mapInfo.Clone());
                count += 1;
                // Console.WriteLine(count);
                // for(int i=0;i<N;i++){
                //     for(int j=0;j<M;j++){
                //         Console.Write(mapInfo[i,j]+" ");
                //     }
                //     Console.WriteLine();
                // }

            }

            if(sucessSignal && failSignal){
                Console.WriteLine(0);
            } else if(failSignal){
                Console.WriteLine(-1);
            } else {
                Console.WriteLine(count);
            }
        }
    }
}
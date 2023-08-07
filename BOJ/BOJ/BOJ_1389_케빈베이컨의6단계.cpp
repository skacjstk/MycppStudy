#include <iostream>
#include <vector>
#include <algorithm>

#define INF 9999999

std::vector<std::vector<int>> Arr; 
int N, M;

void Solution()
{
    for(int k = 0; k< N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j< N; j++){
            Arr[i][j] = std::min(Arr[i][j], Arr[i][k]+Arr[k][j]);
            }
        }  
    }
}

void Input()
{
    std::cin >> N >> M;
    
    Arr.assign(N, std::vector<int>(N, INF)); // 이중 벡터 특정값 초기화
    
    // 가중치가 없지?
    for(int i=0;i<M; ++i)
    {
        int start, end;
        std::cin >> start >> end;
        
        Arr[start-1][end-1] = 1;
        Arr[end-1][start-1] = 1;
    }
}

void Output()
{
    int output = 0;
    int compare1 = INF;
    for(int i = 0; i < N; i++){
        int compare2 = 0;
        for(int j = 0; j< N; j++){
            if(Arr[i][j] != INF)
                compare2 += Arr[i][j];
        }
        
        if(compare1 > compare2)
        {
            compare1 = compare2;
            output = i; 
        }
    }  
    
   std::cout << output+1; //반복문 특성: 1에서 시작해야 정상이니까...
}

int main()
{
    Input();
    Solution();
    Output();
    return 0;
}

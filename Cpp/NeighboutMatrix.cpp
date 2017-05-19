//
// Created by ravi on 4/27/17.
//
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

//dfs take graph, node id, visited node tracker,
void dfs(vector<int> graph[], bool visited[], int x, int* k){
    for(int i = 0; i<graph[x].size();i++)
    {
        if(!visited[graph[x][i]])
        {
            (*k)++;

            visited[graph[x][i]] = true;

            dfs(graph, visited, graph[x][i], k);
        }
    }
}

int countNotReachablePath(vector<int> graph[], int N){
    int count = 0;

    bool visited[N*N + N] = {false};

    for(int i = 1; i <= N*N; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            int k = 1;
            dfs(graph, visited, i, &k);

            count += k*(N*N - k);
        }
    }

    return count;
}

void insertpath(vector<int> graph[], int N, int x1, int y1, int x2, int y2){
    int a = (x1-1)*N + y1;
    int b = (x2-1)*N + y2;

    graph[a].push_back(b);
    graph[b].push_back(a);
}

//int main(){
//    int N = 2;
//    vector<int> graph[N*N + 1];
//
//    insertpath(graph, N, 1,1,1,2);
//    insertpath(graph, N, 1,2,2,2);
//
//    std::cout<< countNotReachablePath(graph, N)<<endl;
//    return 0;
//}

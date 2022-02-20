#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

#define INF 987654321

int minCost[20010];
vector<pair<int, int> > Vertex[20010];
int V, E, start;
int u, v, w;

void djikstra(int node){
    minCost[node] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, node));

    while(!pq.empty()){
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        for(int i = 0; i < Vertex[current].size(); i++){
            int Next = Vertex[current][i].first;
            int nextCost = Vertex[current][i].second;
            if(minCost[Next] > cost + nextCost){
                minCost[Next] = cost + nextCost;
                pq.push(make_pair(-minCost[Next], Next));
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E >> start;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        Vertex[u].push_back(make_pair(v, w));
    }
    for(int j = 1; j <= V; j++){
        minCost[j] = INF;
    }
    djikstra(start);
    for(int k = 1; k <= V; k++){
        if (minCost[k]==INF) cout << "INF\n";
        else cout << minCost[k] << "\n";
    }
}
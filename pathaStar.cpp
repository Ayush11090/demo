#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

struct node{
    int vertex;
    node* next;
    node(int v):vertex(v),next(nullptr){}
};

struct graph{
    int V;
    vector<node*> adjlist;
    graph(int v) : V(v), adjlist(v,nullptr){}
};

void addEdge(graph *g, int src, int dest){
    node* temp = new node(src);
    temp->next = g->adjlist[dest];
    g->adjlist[dest] = temp;

    temp = new node(dest);
    temp->next = g->adjlist[src];
    g->adjlist[src] = temp;
}
int heuristic(int curr, int goal){
    vector<vector<int>>v = {{0,0,4,0,0},
                            {0,0,0,1,3},
                            {4,0,0,0,3},
                            {0,1,0,0,1},
                            {0,3,3,1,0},};
    return v[curr][goal];
}
int dist(int curr, int goal){
    vector<vector<int>>v = {{0,0,4,0,0},
                            {0,0,0,1,3},
                            {4,0,0,0,3},
                            {0,1,0,0,1},
                            {0,3,3,1,0},};
    return v[curr][goal];
}
void Astar(graph * g, int start, int goal){
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<int> visited(g->V,0);
    int h = heuristic(start,goal);
    pq.push({h,{start,0}});
    visited[start] =1;
    int cost = 0;
    while (!pq.empty())
    {
        int curr  = pq.top().second.first;
        cost = pq.top().second.second;
        pq.pop();
        cout<< curr <<endl;
        if(curr == goal) return;
        
        node *temp = g->adjlist[curr];

        while (temp)
        {
            if (!visited[temp->vertex])
            {
                visited[temp->vertex] = 1;
                int h = heuristic(curr,goal);
                pq.push({h+cost+dist(curr,temp->vertex),{temp->vertex,cost+dist(curr,temp->vertex)}});
            }
            temp = temp ->next;
        }
    } 
}
int main(){
    graph *g = new graph(5);

    addEdge(g,0,2);
    addEdge(g,1,4);
    addEdge(g,1,3);
    addEdge(g,2,4);
    addEdge(g,3,4);

    Astar(g,1,0);
}
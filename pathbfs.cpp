#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct node{
    int vertex;
    node *next;
    node(int v):  vertex(v), next(nullptr){}
};

struct graph{
    int V;
    vector<node*> adjlist;
    graph(int v): V(v), adjlist(v,nullptr){}
};

void addEdge(graph* g, int src, int dest){
    node* temp = new node(dest);
    temp->next = g->adjlist[src];
    g->adjlist[src] =temp;
    
    temp = new node(src);
    temp->next = g->adjlist[dest];
    g->adjlist[dest] =temp;
}

void bfs(graph* g, int start , int goal){
  queue<int> q;
  q.push(start);
  vector<int> visited(g->V,0);
  visited[start] = 1;
  while(!q.empty()){
    int curr  = q.front();
    q.pop();
   
    std::cout << curr << " " << std::endl;
    if (curr == goal) return ;
    node * temp = g->adjlist[curr];
    while(temp){
      if(!visited[temp->vertex]){
        visited[temp->vertex]=1;
         q.push(temp->vertex);
         
      }
      temp = temp->next;
    }
  }
}
int main(){
   int V=5;
   graph* g = new graph(V);
   
   addEdge(g,0,2);
   addEdge(g,0,3);
   addEdge(g,0,4);
   addEdge(g,1,2);
   addEdge(g,1,3);
   addEdge(g,2,4);
   addEdge(g,3,4);
   
   bfs(g,0,1);
   return 0;
}

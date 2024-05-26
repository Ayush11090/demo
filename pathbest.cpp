#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;

struct node{
  int vertex;
  node* next;
  node(int v): vertex(v) , next(nullptr) {}
};
 struct graph{
   int V;
   vector<node*> adjlist;
   graph(int v) : V(v) , adjlist(v,nullptr) {}
 };
 
 void addEdge(graph * g, int src, int dest){
    node* temp = new node(src);
    temp->next = g->adjlist[dest];
    g->adjlist[dest] = temp;
    
    temp = new node(dest);
    temp->next = g->adjlist[src];
    g->adjlist[src] = temp;
 }
 
 void dfs(graph* g, int start , int goal){
    std::stack<int> st;
    st.push(start);
    vector<int> visited(g->V,0);
    visited[start] = 1;
    while(!st.empty()){
      int curr = st.top();
      st.pop();
      std::cout << curr << std::endl;
      if(curr==goal) return ;
   
      node *temp = g->adjlist[curr];
      
      while(temp){
         if(!visited[temp->vertex]){
             visited[temp->vertex]=1;
             st.push(temp->vertex);
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
   
   dfs(g,0,1);
   return 0;
}

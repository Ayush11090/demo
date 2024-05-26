#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;

struct state{
    int missionaryleft;
    int cannibleleft;
    int side;
    int missionaryright;
    int cannibleright;

    bool operator<(const state &other) const {
        if(cannibleleft != other.cannibleleft){
            return cannibleleft<other.cannibleleft;
        }
        if(cannibleright != other.cannibleright){
            return cannibleright<other.cannibleright;
        }
        if(missionaryleft != other.missionaryleft){
            return missionaryleft<other.missionaryleft;
        }
        if(missionaryright != other.missionaryright){
            return missionaryright<other.missionaryright;
        }
        return side<other.side;
    }
};

int isValid(state curr){
    if(curr.cannibleleft<0 || curr.missionaryleft<0 || curr.cannibleright<0 || curr.missionaryright<0) return 0;
    if(curr.cannibleleft>3 || curr.missionaryleft>3 || curr.cannibleright>3 || curr.missionaryright>3) return 0;
    if((curr.missionaryleft<curr.cannibleleft &&  curr.missionaryleft>0 )|| (curr.missionaryright<curr.cannibleright && curr.missionaryright>0)) return 0;

    return 1;
}
int isGoal(state cur, state goal){
    if(cur.missionaryleft != goal.missionaryleft) return 0;
    else if(cur.cannibleleft != goal.cannibleleft) return 0;
    else if(cur.missionaryright != goal.missionaryright) return 0;
    else if(cur.cannibleright != goal.cannibleright) return 0;
    else if(cur.side != goal.side) return 0;
    return 1;
}
int solve(state initial,state goal){
    queue<state> q;
    set<state> visited;
    map<state,state> parent;

    q.push(initial);
    visited.insert(initial);
    
    while (!q.empty())
    {
        state current = q.front();
        q.pop();

        if(isGoal(current,goal)){
            while (parent.find(current) != parent.end())
            {
                cout<<"("<<current.missionaryleft<<","<<current.cannibleleft<<","<<current.side<<","<<current.missionaryright<<","<<current.cannibleright<<")"<<endl;
                current = parent[current];
            }
            cout<<"("<<current.missionaryleft<<","<<current.cannibleleft<<","<<current.side<<","<<current.missionaryright<<","<<current.cannibleright<<")"<<endl;
                
            return 1;
        }
        vector<pair<int,int>> temp =  {{0,1},{1,0},{1,1},{2,0},{0,2}};
        for (auto next : temp){
            int x = next.first;
            
            int y = next.second;
            state nextstate;
            if(current.side){
                nextstate = {current.missionaryleft+x,
                            current.cannibleleft+y,
                            0,
                            current.missionaryright-x,
                            current.cannibleright-y};
            }else{
                nextstate = {current.missionaryleft-x,
                            current.cannibleleft-y,
                            1,
                            current.missionaryright+x,
                            current.cannibleright+y};
            }
            if(isValid(nextstate) && visited.find(nextstate) == visited.end()){
                visited.insert(nextstate);
                parent[nextstate] = current;
                q.push(nextstate);
            }
        }
    }
    return 0; 
}
int main(){
    state initial = {3,3,0,0,0};
    state goal = {0,0,1,3,3};

    if(!solve(initial,goal)) cout<<"No solution";
    return 0;
}
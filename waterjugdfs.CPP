#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<map>
using namespace std;

int solve(int jug1,int jug2, int target){
    stack<pair<int,int>> st;
    set<pair<int,int>> visited;
    map<pair<int,int>,pair<int,int>> mp;
    st.push(make_pair(0,0));
    visited.insert(make_pair(0,0));
    mp[{0,0}] = {-1,-1};
    while(!st.empty()){
        pair<int,int> cur = st.top();
        st.pop();
        if(cur.first==target || cur.second==target){
            while (cur.first != -1)
            {
                cout<<"("<<cur.first<<" "<<cur.second<<")"<<endl;
                cur = mp[cur];
            }
            
            return 1;
        }
        vector<pair<int,int>> state = {
                                        {jug1,cur.second},
                                        {cur.first,jug2},
                                        {0,cur.second},
                                        {cur.first,0},
                                        {cur.first-min(cur.first,jug2-cur.second),cur.second+min(cur.first,jug2-cur.second)},
                                        {cur.first+min(cur.second,jug1-cur.first),cur.second-min(cur.second,jug1-cur.first)}};
    
        for (auto st1: state)
        {
            if(visited.find(st1) == visited.end()){
                visited.insert(st1);
                st.push(st1);
                mp[st1] = cur;
            }
        }
        
     }
}
int main(){
    int jug1=3, jug2=4;
    int target =2;
    if(!solve(jug1,jug2,target)) cout<<"No Solution";
    return 0; 
}
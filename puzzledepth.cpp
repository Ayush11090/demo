#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

pair<int, int> find_zero(const vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 0) return make_pair(i, j);
        }
    }
    return {-1, -1};
}

bool isGoal(const vector<vector<int>>& board, const vector<vector<int>>& goal) {
    return board == goal;
}

bool isValid(int a, int b) {
    int n=3;
    return a >= 0 && b >= 0 && a < n && b < n;
}

void print(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (auto e : row) cout << e << " ";
        cout << endl;
    }
    cout << endl;
}

int solve(vector<vector<int>> start,  vector<vector<int>> goal){
    stack<vector<vector<int>>> st;
    map<vector<vector<int>>, vector<vector<int>>> parent;
    parent[start] = {};  
    st.push(start);
    while(!st.empty()){
        vector<vector<int>> curr = st.top();
        st.pop();
        if (curr == goal) {
            while (parent.find(curr) != parent.end())
            {
                print(curr);
                curr = parent[curr];
            }
            
            return 1;
        }
        vector<pair<int,int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        pair<int,int> pos = find_zero(curr);
        int x = pos.first;
        int y = pos.second;
        for(auto i:dir){
            int newX = x + i.first;
            int newY = y + i.second;

            if(isValid(newX,newY)){
                vector<vector<int>> next = curr;
                swap(next[x][y],next[newX][newY]);
                if(parent.find(next)==parent.end()){
                    parent[next]=curr;
                    st.push(next);
                }
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> board = {{1,2, 3},
                                 {4, 0, 5},
                                 {7, 8, 6}};
    vector<vector<int>> goal = {{1,2, 3},
                                {4, 5, 6},
                                {7, 8, 0}};
    if (!solve(board, goal)) cout << "No Solution";
    return 0;
}

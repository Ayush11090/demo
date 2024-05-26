#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

pair<int, int> find_zero(const vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 0) return make_pair(i, j);
        }
    }
    return {-1, -1};
}

bool isValid(int a, int b, int n) {
    return a >= 0 && b >= 0 && a < n && b < n;
}

void print(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (auto e : row) cout << e << " ";
        cout << endl;
    }
    cout << endl;
}

int solve(vector<vector<int>> start, vector<vector<int>> goal) {
    queue<vector<vector<int>>> q;
    map<vector<vector<int>>, vector<vector<int>>> parent;
    q.push(start);
    parent[start] = {};  // Using an empty vector to denote the root

    while (!q.empty()) {
        vector<vector<int>> curr = q.front();
        q.pop();

        if (curr == goal) {
            while (parent.find(curr) != parent.end())
            {
                print(curr);
                curr = parent[curr];
            }
            
            return 1;
        }

        static const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        pair<int, int> pos = find_zero(curr);
        int x = pos.first, y = pos.second;

        for (const auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (isValid(newX, newY, curr.size())) {
                vector<vector<int>> next = curr;
                swap(next[x][y], next[newX][newY]);
                if (parent.find(next) == parent.end()) {
                    parent[next] = curr;
                    q.push(next);
                }
            }
        }
    }

    return 0;
}

int main() {
    vector<vector<int>> start = {{1, 5, 3},
                                 {2, 4, 0},
                                 {7, 8, 6}};
    vector<vector<int>> goal = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 0}};

    if (!solve(start, goal)) {
        cout << "No Solution" << endl;
    }
    return 0;
}

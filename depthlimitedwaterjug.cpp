#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
using namespace std;

bool depthLimitedSearch(int jug1, int jug2, int target, int limit, map<pair<int, int>, pair<int, int>>& parent, set<pair<int, int>>& visited) {
    stack<pair<pair<int, int>, int>> s;  // stack of ((state), depth)
    s.push({{0, 0}, 0});
    visited.insert({0, 0});

    while (!s.empty()) {
        auto temp = s.top();
        s.pop();
        pair<int, int> state = temp.first;
        int depth = temp.second;

        int x = state.first;
        int y = state.second;

        if (x == target || y == target) {
            while (parent.find(state) != parent.end()) {
                cout << "(" << state.first << " , " << state.second << ")" << endl;
                state = parent[state];
            }
            cout << "(0 , 0)" << endl;  // start state
            return true;
        }

        if (depth < limit) {
            vector<pair<int, int>> nextState = {
                {x, jug2},  // fill jug2
                {jug1, y},  // fill jug1
                {x, 0},    // empty jug2
                {0, y},    // empty jug1
                {x - min(x, jug2 - y), y + min(x, jug2 - y)},  // pour jug1 into jug2
                {x + min(y, jug1 - x), y - min(y, jug1 - x)}   // pour jug2 into jug1
            };

            for (auto state : nextState) {
                if (visited.find(state) == visited.end()) {
                    visited.insert(state);
                    parent[state] = {x, y};
                    s.push({state, depth + 1});
                }
            }
        }
    }
    return false;
}

bool solve(int jug1, int jug2, int target, int limit) {
    map<pair<int, int>, pair<int, int>> parent;
    set<pair<int, int>> visited;

    return depthLimitedSearch(jug1, jug2, target, limit, parent, visited);
}

int main() {
    int jug1 = 3, jug2 = 4;
    int target = 2;
    int limit = 10;  // set a depth limit

    if (!solve(jug1, jug2, target, limit)) {
        cout << "No Solution" << endl;
    }

    return 0;
}

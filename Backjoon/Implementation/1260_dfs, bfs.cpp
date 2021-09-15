/*
*   1260�� - DFS, BFS ����
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

vector<int> DFS(int start, vector<int> graph[]) {
    vector<int> answer;
    set<int> visited;
    stack<int> stack;

    stack.push(start);

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        if (visited.find(current) == visited.end()) {
            visited.insert(current);
            answer.push_back(current);

            for (auto next : graph[current]) {
                if (visited.find(next) == visited.end())
                    stack.push(next);
            }
        }
    }

    return answer;
}

vector<int> BFS(int start, vector<int> graph[]) {
    vector<int> answer;
    set<int> visited;
    queue<int> queue;

    queue.push(start);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        if (visited.find(current) == visited.end()) {
            visited.insert(current);
            answer.push_back(current);

            for (auto next : graph[current]) {
                if (visited.find(next) == visited.end())
                    queue.push(next);
            }
        }
    }

    return answer;
}

int main() {

    int v, e, start;
    cin >> v >> e >> start;
    vector<int> graph[v + 1];

    for (int i = 0; i < e; i++) {
        int src, dst;
        cin >> src >> dst;

        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }

    // DFS �� �������� �������� ����
    for (int i = 0; i < v + 1; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    for (auto r : DFS(start, graph)) {
        cout << r << " ";
    }

    cout << endl;

    // BFS �� �������� �������� ����
    for (int i = 0; i < v + 1; i++) {
        sort(graph[i].begin(), graph[i].end(), less<int>());
    }

    for (auto r : BFS(start, graph)) {
        cout << r << " ";
    }

    return 0;
}
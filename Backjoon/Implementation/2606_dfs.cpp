/*
*   2606번 - 바이러스
*   DFS나 BFS로 감염된 컴퓨터 수 출력
*/

#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

int DFS(int start, vector<int> graph[]) {
    int answer;
    set<int> visited;
    stack<int> stack;

    stack.push(start);

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        if (visited.find(current) == visited.end()) {
            visited.insert(current);

            for (auto next : graph[current]) {
                if (visited.find(next) == visited.end())
                    stack.push(next);
            }
        }
    }

    answer = visited.size() - 1;

    return answer;
}

int main() {

    int v, e;
    cin >> v >> e;
    vector<int> graph[v + 1];

    for (int i = 0; i < e; i++) {
        int src, dst;
        cin >> src >> dst;

        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }

    cout << DFS(1, graph) << "\n";

    return 0;
}
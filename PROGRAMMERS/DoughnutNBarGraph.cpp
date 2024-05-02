#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph[1000001];

vector<int> solution(vector<vector<int>> edges) {
    for(int i = 0; i < edges.size(); i++)
    {
        vector<int> edge = edges[i];

        int from = edge[0];
        int to = edge[1];

        if(graph[from].size() == 0) graph[from].resize(2);
        if(graph[to].size() == 0) graph[to].resize(2);

        // 연결된
        graph[from][0].push_back(edge[1]);

        // 나를 연결하는
        graph[to][1].push_back(edge[0]);
    }

    int createIndex = 0;
    int doughnut = 0;
    int bar = 0;
    int eight = 0;

    for(int i = 1; i < 1000001; i++)
    {
        if(graph[i].size() == 0)
        {
            continue;
        }

        if(graph[i][0].size() >= 2 && graph[i][1].size() == 0)
        {
            createIndex = i;
        }

        if(graph[i][0].size() == 0 && graph[i][1].size() >= 1)
        {
            bar++;
        }

        if(graph[i][0].size() == 2 && graph[i][1].size() >= 2)
        {
            eight++;
        }
    }

    doughnut = graph[createIndex][0].size() - bar - eight;

    cout << createIndex << doughnut << bar << eight;

    vector<int> answer { createIndex, doughnut, bar, eight };
    return answer;
}

int main()
{
    solution({{2, 3}, {4, 3}, {1, 1}, {2, 1}});
//    solution({{4, 11}, {1, 12}, {8, 3}, {12, 7}, {4, 2}, {7, 11}, {4, 8}, {9, 6}, {10, 11}, {6, 10}, {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8}});
}
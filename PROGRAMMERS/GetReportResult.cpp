#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size(), 0);

    map<string, vector<string>> m;
    map<string, int> m2;

    for (int i = 0; i < report.size(); i++) {
        stringstream ss(report[i]);
        string a, b;
        ss >> a >> b;

        auto target = find(m[a].begin(), m[a].end(), b);

        if (target == m[a].end()) {
            m[a].push_back(b);
            m2[b]++;
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        for (int j = 0; j < m[id_list[i]].size(); j++) {
            if (m2[m[id_list[i]][j]] >= k) {
                answer[i]++;
            }
        }
    }

    return answer;
}

int main() {
    vector<int> sol = solution({ "1", "2", "3", "4" }, { "1 2", "3 2", "2 4", "1 4", "3 1" }, 2);

    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << "\n";
    }
}

// --------------------------

//vector<int> solution(vector<string> id_list, vector<string> report, int k) {
//    vector<int> answer;
//    answer.resize(id_list.size(), 0);
//
//    map<string, vector<string>> m;
//    map<string, int> m2;
//
//    report.erase(unique(report.begin(), report.end()), report.end());
//
//    for (int i = 0; i < report.size(); i++) {
//        stringstream ss(report[i]);
//        string a, b;
//        ss >> a >> b;
//
//        m[a].push_back(b);
//        m2[b]++;
//    }
//
//    for (int i = 0; i < id_list.size(); i++) {
//        for (int j = 0; j < m[id_list[i]].size(); j++) {
//            if (m2[m[id_list[i]][j]] >= k) {
//                answer[i]++;
//            }
//        }
//    }
//
//    return answer;
//}

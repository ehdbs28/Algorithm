#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int idx;
    int x;
    int y;
    Node* left;
    Node* right;
};

void preorder(vector<int> &v, Node* root){
    if(root == nullptr) return;

    v.push_back(root->idx);
    preorder(v, root->left);
    preorder(v, root->right);
}

void postorder(vector<int> &v, Node* root){
    if(root == nullptr) return;

    postorder(v, root->left);
    postorder(v, root->right);
    v.push_back(root->idx);
}

Node* SetTree(vector<Node> &nodes, int left, int right){
    if(left > right)
        return nullptr;

    int idx = left;
    for(int i = left + 1; i <= right; i++){
        if(nodes[idx].y < nodes[i].y){
            idx = i;
        }
    }

    Node* cur = &nodes[idx];
    cur->left = SetTree(nodes, left, idx - 1);
    cur->right = SetTree(nodes, idx + 1, right);

    return cur;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node> nodes;

    for(int i = 0; i < nodeinfo.size(); i++){
        nodes.push_back(Node{ i + 1, nodeinfo[i][0], nodeinfo[i][1], nullptr, nullptr });
    }

    sort(nodes.begin(), nodes.end(), [](Node a, Node b){
        return a.x < b.x;
    });

    Node* root = SetTree(nodes, 0, nodes.size() - 1);

    vector<vector<int>> answer;
    answer.resize(2);
    preorder(answer[0], root);
    postorder(answer[1], root);
    return answer;
}

int main(){
    auto sol = solution({{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}});
    for(auto& v : sol){
        for(auto& n : v){
            cout << n << " ";
        }
        cout << "\n";
    }
}
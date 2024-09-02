#include<iostream>
#include<vector>

using namespace std;

struct Node{
    char ch;
    Node *left;
    Node *right;
};

int n;
vector<Node> v;
vector<char> ans;

void Search1(Node* node){
    if(node == nullptr)
        return;

    ans.push_back(node->ch);
    Search1(node->left);
    Search1(node->right);
}

void Search2(Node* node){
    if(node == nullptr)
        return;

    Search2(node->left);
    ans.push_back(node->ch);
    Search2(node->right);
}

void Search3(Node* node){
    if(node == nullptr)
        return;

    Search3(node->left);
    Search3(node->right);
    ans.push_back(node->ch);
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        Node node = { (char)('A' + i), nullptr, nullptr };
        v.push_back(node);
    }

    for(int i = 0; i < n; i++){
        char nodeNum;
        cin >> nodeNum;
        Node* node = &v[nodeNum - 'A'];
        for(int j = 0; j < 2; j++){
            char input;
            cin >> input;
            if(input != '.'){
                if(j == 0){
                    node->left = &v[(int)(input - 'A')];
                }
                else if(j == 1){
                    node->right = &v[(int)(input - 'A')];
                }
            }
        }
    }

    Search1(&v[0]);
    for(int i = 0; i < n; i++){
        cout << ans[i];
    }
    cout << "\n";

    Search2(&v[0]);
    for(int i = n; i < n * 2; i++){
        cout << ans[i];
    }
    cout << "\n";

    Search3(&v[0]);
    for(int i = n * 2; i < n * 3; i++){
        cout << ans[i];
    }
}
#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int n;
    Node* left;
    Node* right;
};

vector<int> nums;
Node* tree;

void Search(Node* node){
    if(node == nullptr)
        return;

    Search(node->left);
    Search(node->right);
    cout << node->n << "\n";
}

int main(){
    while(true){
        int n;
        cin >> n;
        if(cin.eof())
            break;
        nums.push_back(n);
    }

    for(int i = 0; i < nums.size(); i++){
        int n = nums[i];

        if(tree == nullptr){
            tree = new Node({ n, nullptr, nullptr });
            continue;
        }

        Node* root = tree;

        while(true){
            if(root->n > n){
                if(root->left == nullptr){
                    root->left = new Node({ n, nullptr, nullptr });
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right == nullptr){
                    root->right = new Node({ n, nullptr, nullptr });
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
    }

    Search(tree);
}
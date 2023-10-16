#include<iostream>
#include<vector>

using namespace std;

struct node{
    int n;
    node* left;
    node* right;
};

class binary_tree{
public:
    binary_tree(){
        m_root = nullptr;
    }

    binary_tree(int n){
        m_root = new node{n, nullptr, nullptr};
    }

public:
    void addNode(int n, node* root){
        if(root->n > n){
            if(root->left == nullptr){
                root->left = new node{n, nullptr, nullptr};
                return;
            }
            else{
                addNode(n, root->left);
            }
        }
        else{
            if(root->right == nullptr){
                root->right = new node{n, nullptr, nullptr};
                return;
            }
            else{
                addNode(n, root->right);
            }
        }
    }

    void search(node* node){
        if(node == nullptr)
            return;

        search(node->left);
        search(node->right);
        cout << node->n << "\n";
    }

public:
    node* getRoot() { return m_root; }

private:
    node* m_root;

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    binary_tree tree;

    while(true){
        int n;
        cin >> n;
        if(cin.eof())
            break;

        if(tree.getRoot() == nullptr)
            tree = binary_tree(n);
        else
            tree.addNode(n, tree.getRoot());
    }

    tree.search(tree.getRoot());
}
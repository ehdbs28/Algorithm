#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void update_lazy(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end) {
    if (lazy[node] % 2 == 1) {
        tree[node] = (end-start+1) - tree[node];

        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);

    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        tree[node] = (end-start+1) - tree[node];
        if (start != end) {
            lazy[node*2] += 1;
            lazy[node*2+1] += 1;
        }
        return;
    }

    update_range(tree, lazy, node*2, start, (start+end)/2, left, right);
    update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long sum(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, lazy, node*2, start, (start+end)/2, left, right) + sum(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    vector<long long> a(n);

    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1)) - 1;

    vector<long long> tree(tree_size + 1);
    vector<long long> lazy(tree_size + 1);

    while (m--) {
        int t1;

        cin >> t1;

        if (t1 == 0) {
            int start, end;
            cin >> start >> end;
            update_range(tree, lazy, 1, 0, n-1, start-1, end-1);
        }
        else if (t1 == 1) {
            int start, end;
            cin >> start >> end;
            cout << sum(tree, lazy, 1, 0, n-1, start-1, end-1) << "\n";
        }
    }
}
// * sturct based.
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef struct Node {
    char val;
    int count;
    int depth;
    struct Node* parent;
    unordered_map<char, struct Node*> children;

    Node(char x) : val(x), count(0), depth(0), parent(nullptr) {}

}*node;

void insert(node & cur, string& word, int n, int index=0) {

    if (n == index) {
        cur->count += 1;
        return;
    };
    char c = word[index];
    node temp;
    if (cur->children.count(c)) {
        temp = cur->children[c];
    } else {
        temp = new Node(word[index]);
        cur->children[c] = temp;
    }
    temp->depth = cur->depth + 1;
    temp->parent = cur;

    insert(temp, word, n, index+1);
}

int func(node & cur, int k) {
    char c; node nd;
    int score = 0;
    for (auto child: cur->children) {
        tie(c, nd) = child;
        score += func(nd, k);
    }
    if (cur->count >=k ) {
        int groups = cur->count / k;
        cur->count %= k;
        score += groups * cur->depth;
    }

    if (cur->parent != nullptr)
        cur->parent->count += cur->count;

    return score;
}

void solve() {
    int n, k;
    cin >> n >> k;

    node root = new Node('#');

    for (int i=0; i<n; i++) {
        string temp; cin >> temp;
        insert(root, temp, temp.size(), 0);
    }

    int score = func(root, k);

    cout << score << endl;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    for (int i=1; i<=t; i++) {
        cout << "Case #" << i  << ": ";
    solve();
    }
    return 0;
}

// * Array based
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long int ll;

// ll ans, ct=0;
// int k;
// const ll mx = 2e6;
// int trie[mx][26]; // use array over class or map.
// int ters[mx]; // terminals

// void dfs(int u, int d=0) {
//     for (auto v: trie[u]) {
//         if (v) {
//             dfs(v, d+1);
//             ters[u] += ters[v]; // add the terms from lower nodes to parent.
//         }
//     }

//     int groups = ters[u] / k;
//     ters[u] -= groups * k;
//     ans += d * groups;
// }

// void build(const vector<string>& arr) {
//     for (const auto& s: arr) {
//         int temp = 0;
//         for (auto c: s) {
//             int x = c - 'A';
//             if (!trie[temp][x]) {
//                 trie[temp][x] = ++ct;
//             }
//             temp = trie[temp][x];
//         }
//         ters[temp]++;
//     }
// }

// void solve() {
//     ans = 0; ct=0;
//     memset(trie, 0, sizeof trie);
//     memset(ters, 0, sizeof ters);
//     int n; cin >> n >> k;
//     vector<string> arr(n);
//     for (auto &x: arr) cin >> x;
//     build(arr);

//     dfs(0);
//     cout << ans << endl;
// }


// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr); cout.tie(nullptr);
//     int t; cin >> t;
//     for (int i=1; i<=t; i++) {
//         cout << "Case #" << i  << ": ";
//         solve();
//     }
//     return 0;
// }

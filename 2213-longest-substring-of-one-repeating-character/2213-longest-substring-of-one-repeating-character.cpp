class Solution {
    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, maximum;

        Node() {
            leftChar = rightChar = '#';
            prefix = suffix = maximum = 0;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.maximum == 0) return b;
        if (b.maximum == 0) return a;

        Node res;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;
        res.suffix = b.suffix;
        res.maximum = max(a.maximum, b.maximum);

        if (a.rightChar == b.leftChar) {
            res.maximum = max(res.maximum, a.suffix + b.prefix);

            if (a.prefix == (/* length of a */ 0)) {
                // handled through build/update using lengths below
            }
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];
            tree[node].prefix = tree[node].suffix = tree[node].maximum = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1],
                                mid - l + 1, r - mid);
    }

    Node mergeNodes(Node a, Node b, int lenA, int lenB) {
        if (lenA == 0) return b;
        if (lenB == 0) return a;

        Node res;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;
        res.suffix = b.suffix;
        res.maximum = max(a.maximum, b.maximum);

        if (a.rightChar == b.leftChar) {
            res.maximum = max(res.maximum, a.suffix + b.prefix);

            if (a.prefix == lenA)
                res.prefix = lenA + b.prefix;

            if (b.suffix == lenB)
                res.suffix = b.suffix + a.suffix;
        }

        return res;
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node].leftChar = c;
            tree[node].rightChar = c;
            tree[node].prefix = tree[node].suffix = tree[node].maximum = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1],
            mid - l + 1,
            r - mid
        );
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            s[idx] = c;

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].maximum);
        }

        return ans;
    }
};
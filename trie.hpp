const int maxC = 26;

struct node {
    node *child[maxC];

    node() {
        for (int i = 0; i < maxC; ++i) child[i] = nullptr
    }
};

struct trie {
    node *root;

    trie() {
        root = new node();
    }
    ~trie() {
        delete root;
    }

    void insert(node *n, string &s, int pos) {
        if (pos == (int)s.size()) {
            return;
        }
        if (n->child[s[pos] - 'a'] == nullptr) {
            n->child[s[pos] - 'a'] = newnode();
        }
        insert(n->child[s[pos] - 'a'], s, pos + 1);
    }
};

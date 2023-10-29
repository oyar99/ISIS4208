#include <tree.h>
#include <functional>

Tree::Tree(const std::string& pre_order) {
    if (pre_order.size() == 0) {
        root = -1;
        return;
    }

    int n = pre_order.size() / 3;

    // node ids are one-indexed
    // adj[0] is a dummy root - not actually present in the tree
    adj = std::vector<std::vector<int>>(n + 1);
    parent = std::vector<int>(n + 1);
    labels = std::vector<int>(n + 1);
    root = 1; // There's at least one node which will be the root

    int u = 0, i = 0;
    int idx = 1;

    auto is_parenthesis = [](const char& c) {
        return c == '(' || c == ')';
    };

    while (i < pre_order.size()) {
        if (!is_parenthesis(pre_order[i])) {
            // We are seeing a new node
            std::string label;

            while (!is_parenthesis(pre_order[i])) {
                label += pre_order[i++];
            }

            adj[u].push_back(idx);
            parent[idx] = u; // current pointer is the parent of u
            u = idx; // move pointer to this node

            labels[idx++] = std::stoi(label); // map node to its label
        } else if (pre_order[i++] == ')') {
            // We will go up in the tree
            u = parent[u];
        }
    }
}

std::string Tree::pre_order() {
    if (root < 0) {
        return std::string();
    }

    std::string pre_order;

    std::function<void(int)> pre_order_inner = [&](int u) {
        pre_order += std::to_string(labels[u]);
        pre_order += "(";

        for (int v: adj[u]) {
            pre_order_inner(v);
        }

        pre_order += ")";
    };

    pre_order_inner(root);

    return pre_order;
}

std::vector<std::unordered_set<int>> Tree::decompose() {
    return std::vector<std::unordered_set<int>>();
}
---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/alfred/data_structure/binary-trie.hpp\"\n\n// Thanks\
    \ neal for this template.\n#include <bits/stdc++.h>\n\nconst int BITS = 30;\n\
    const int INF = 1e9 + 7;\nstruct BinaryTrie { // 01-Trie\n    static const int\
    \ ALPHABET = 2;\n    struct Node {\n        const int parent;\n        int words_here\
    \ = 0;    // How many words EXACTLY here.\n        int starting_with = 0; // How\
    \ many words have the PREFIX of this node.\n        int min_index = INF;   //\
    \ The minimum index of words which have PREFIX of this node.\n        int max_index\
    \ = -INF;  // The maximum index of words which have PREFIX of this node.\n   \
    \     std::array<int, ALPHABET> child;\n        Node(int p = -1) : parent(p) {\
    \ child.fill(-1); }\n    };\n    static const int ROOT = 0;\n    std::vector<Node>\
    \ tr = {Node()};\n    BinaryTrie(int total_length = -1) { // Sum of |s|, leave\
    \ -1 if don't know.\n        if (total_length >= 0) tr.reserve(total_length +\
    \ 1);\n    }\n    // Returns the Node reference of word.\n    // NOTICE: this\
    \ function creates a new Node if word isn't in the trie.\n    Node &operator[](uint64_t\
    \ word) {\n        return tr[build(word, 0)];\n    }\n    // Get or create c-th\
    \ (c = 0, 1) child of node\n    // Returns BinaryTrie node.\n    int get_or_create_child(int\
    \ node, int c) {\n        if (tr[node].child[c] == -1) {\n            tr[node].child[c]\
    \ = (int)tr.size();\n            tr.push_back(Node(node));\n        }\n      \
    \  return tr[node].child[c];\n    }\n    // Build rootpath of word, insert delta\
    \ (\u4E2A) words\n    // Returns BinaryTrie node.\n    int build(uint64_t word,\
    \ int delta) {\n        int node = ROOT;\n        for (int i = BITS - 1; i >=\
    \ 0; i--) {\n            tr[node].starting_with += delta;\n            node =\
    \ get_or_create_child(node, word >> i & 1);\n        }\n        tr[node].starting_with\
    \ += delta;\n        return node;\n    }\n    // Insert a word with the index\
    \ of index, INF if index is unknown.\n    // Returns BinaryTrie node.\n    int\
    \ insert(uint64_t word, int index = INF) {\n        int node = build(word, 1);\n\
    \        tr[node].words_here += 1;\n        for (int x = node; x != -1; x = tr[x].parent)\
    \ {\n            if (index != INF) {\n                tr[x].min_index = std::min(tr[x].min_index,\
    \ index);\n                tr[x].max_index = std::max(tr[x].max_index, index);\n\
    \            }\n        }\n        return node;\n    }\n    // Find such an x\
    \ inserted in the trie that word ^ x is minimized.\n    // Returns such x (x is\
    \ certain).\n    uint64_t query_min(uint64_t word) {\n        int node = ROOT;\n\
    \        uint64_t val = 0;\n        for (int i = BITS - 1; i >= 0; i--) {\n  \
    \          int go_bit = word >> i & 1;\n            if (tr[node].child[go_bit]\
    \ == -1) {\n                go_bit ^= 1;\n            }\n            val |= 1ull\
    \ << go_bit;\n            node = tr[node].child[go_bit];\n        }\n        return\
    \ val;\n    }\n    // Find such an x inserted in the trie that word ^ x is maximized.\n\
    \    // Returns such x (x is certain).\n    uint64_t query_max(uint64_t word)\
    \ {\n        int node = ROOT;\n        uint64_t val = 0;\n        for (int i =\
    \ BITS - 1; i >= 0; i--) {\n            int go_bit = (word >> i & 1) ^ 1;\n  \
    \          if (tr[node].child[go_bit] == -1) {\n                go_bit ^= 1;\n\
    \            }\n            val |= 1ull << go_bit;\n            node = tr[node].child[go_bit];\n\
    \        }\n        return val;\n    }\n    // CF1983F: Find such an x inserted\
    \ in the trie that word ^ x < upper_bound\n    // Returns a pair {min_index, max_index}\
    \ of x.\n    std::pair<int, int> query_ub(uint64_t word, uint64_t upper_bound)\
    \ {\n        int mn = INF, mx = -INF, node = ROOT;\n        for (int i = BITS\
    \ - 1; i >= 0; i--) {\n            int word_bit = word >> i & 1;      // digit\
    \ i of word\n            int ub_bit = upper_bound >> i & 1; // digit i of ub\n\
    \            if (ub_bit == 1 && tr[node].child[word_bit] != -1) {\n          \
    \      // if digit i of ub is 1, then we can choose either\n                //\
    \ the subtree of word_bit or word_bit ^ 1.\n                mn = std::min(mn,\
    \ tr[tr[node].child[word_bit]].min_index);\n                mx = std::max(mx,\
    \ tr[tr[node].child[word_bit]].max_index);\n            }\n            // else\
    \ if digit i of ub is 0, then we can only choose\n            // the subtree of\
    \ word_bit. (otherwise, we will violate the range)\n            node = tr[node].child[word_bit\
    \ ^ ub_bit];\n            if (node == -1) break;\n        }\n        return {mn,\
    \ mx};\n    }\n};\n"
  code: "#pragma once\n\n// Thanks neal for this template.\n#include <bits/stdc++.h>\n\
    \nconst int BITS = 30;\nconst int INF = 1e9 + 7;\nstruct BinaryTrie { // 01-Trie\n\
    \    static const int ALPHABET = 2;\n    struct Node {\n        const int parent;\n\
    \        int words_here = 0;    // How many words EXACTLY here.\n        int starting_with\
    \ = 0; // How many words have the PREFIX of this node.\n        int min_index\
    \ = INF;   // The minimum index of words which have PREFIX of this node.\n   \
    \     int max_index = -INF;  // The maximum index of words which have PREFIX of\
    \ this node.\n        std::array<int, ALPHABET> child;\n        Node(int p = -1)\
    \ : parent(p) { child.fill(-1); }\n    };\n    static const int ROOT = 0;\n  \
    \  std::vector<Node> tr = {Node()};\n    BinaryTrie(int total_length = -1) { //\
    \ Sum of |s|, leave -1 if don't know.\n        if (total_length >= 0) tr.reserve(total_length\
    \ + 1);\n    }\n    // Returns the Node reference of word.\n    // NOTICE: this\
    \ function creates a new Node if word isn't in the trie.\n    Node &operator[](uint64_t\
    \ word) {\n        return tr[build(word, 0)];\n    }\n    // Get or create c-th\
    \ (c = 0, 1) child of node\n    // Returns BinaryTrie node.\n    int get_or_create_child(int\
    \ node, int c) {\n        if (tr[node].child[c] == -1) {\n            tr[node].child[c]\
    \ = (int)tr.size();\n            tr.push_back(Node(node));\n        }\n      \
    \  return tr[node].child[c];\n    }\n    // Build rootpath of word, insert delta\
    \ (\u4E2A) words\n    // Returns BinaryTrie node.\n    int build(uint64_t word,\
    \ int delta) {\n        int node = ROOT;\n        for (int i = BITS - 1; i >=\
    \ 0; i--) {\n            tr[node].starting_with += delta;\n            node =\
    \ get_or_create_child(node, word >> i & 1);\n        }\n        tr[node].starting_with\
    \ += delta;\n        return node;\n    }\n    // Insert a word with the index\
    \ of index, INF if index is unknown.\n    // Returns BinaryTrie node.\n    int\
    \ insert(uint64_t word, int index = INF) {\n        int node = build(word, 1);\n\
    \        tr[node].words_here += 1;\n        for (int x = node; x != -1; x = tr[x].parent)\
    \ {\n            if (index != INF) {\n                tr[x].min_index = std::min(tr[x].min_index,\
    \ index);\n                tr[x].max_index = std::max(tr[x].max_index, index);\n\
    \            }\n        }\n        return node;\n    }\n    // Find such an x\
    \ inserted in the trie that word ^ x is minimized.\n    // Returns such x (x is\
    \ certain).\n    uint64_t query_min(uint64_t word) {\n        int node = ROOT;\n\
    \        uint64_t val = 0;\n        for (int i = BITS - 1; i >= 0; i--) {\n  \
    \          int go_bit = word >> i & 1;\n            if (tr[node].child[go_bit]\
    \ == -1) {\n                go_bit ^= 1;\n            }\n            val |= 1ull\
    \ << go_bit;\n            node = tr[node].child[go_bit];\n        }\n        return\
    \ val;\n    }\n    // Find such an x inserted in the trie that word ^ x is maximized.\n\
    \    // Returns such x (x is certain).\n    uint64_t query_max(uint64_t word)\
    \ {\n        int node = ROOT;\n        uint64_t val = 0;\n        for (int i =\
    \ BITS - 1; i >= 0; i--) {\n            int go_bit = (word >> i & 1) ^ 1;\n  \
    \          if (tr[node].child[go_bit] == -1) {\n                go_bit ^= 1;\n\
    \            }\n            val |= 1ull << go_bit;\n            node = tr[node].child[go_bit];\n\
    \        }\n        return val;\n    }\n    // CF1983F: Find such an x inserted\
    \ in the trie that word ^ x < upper_bound\n    // Returns a pair {min_index, max_index}\
    \ of x.\n    std::pair<int, int> query_ub(uint64_t word, uint64_t upper_bound)\
    \ {\n        int mn = INF, mx = -INF, node = ROOT;\n        for (int i = BITS\
    \ - 1; i >= 0; i--) {\n            int word_bit = word >> i & 1;      // digit\
    \ i of word\n            int ub_bit = upper_bound >> i & 1; // digit i of ub\n\
    \            if (ub_bit == 1 && tr[node].child[word_bit] != -1) {\n          \
    \      // if digit i of ub is 1, then we can choose either\n                //\
    \ the subtree of word_bit or word_bit ^ 1.\n                mn = std::min(mn,\
    \ tr[tr[node].child[word_bit]].min_index);\n                mx = std::max(mx,\
    \ tr[tr[node].child[word_bit]].max_index);\n            }\n            // else\
    \ if digit i of ub is 0, then we can only choose\n            // the subtree of\
    \ word_bit. (otherwise, we will violate the range)\n            node = tr[node].child[word_bit\
    \ ^ ub_bit];\n            if (node == -1) break;\n        }\n        return {mn,\
    \ mx};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/binary-trie.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/data_structure/binary-trie.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/binary-trie.hpp
- /library/src/alfred/data_structure/binary-trie.hpp.html
title: src/alfred/data_structure/binary-trie.hpp
---

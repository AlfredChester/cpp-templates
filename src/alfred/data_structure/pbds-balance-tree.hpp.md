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
  bundledCode: '#line 2 "src/alfred/data_structure/pbds-balance-tree.hpp"


    #include <bits/extc++.h>

    #line 5 "src/alfred/data_structure/pbds-balance-tree.hpp"


    using namespace std;

    using namespace __gnu_pbds;


    // TreeTag can also be __gnu_pbds::splay_tree_tag

    template <class T, class Cmp, class TreeTag = rb_tree_tag>

    using BalanceTree = tree<T, null_type, Cmp, TreeTag, tree_order_statistics_node_update>;

    '
  code: '#pragma once


    #include <bits/extc++.h>

    #include <bits/stdc++.h>


    using namespace std;

    using namespace __gnu_pbds;


    // TreeTag can also be __gnu_pbds::splay_tree_tag

    template <class T, class Cmp, class TreeTag = rb_tree_tag>

    using BalanceTree = tree<T, null_type, Cmp, TreeTag, tree_order_statistics_node_update>;

    '
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/pbds-balance-tree.hpp
  requiredBy: []
  timestamp: '2025-02-17 23:08:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/alfred/data_structure/pbds-balance-tree.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/pbds-balance-tree.hpp
- /library/src/alfred/data_structure/pbds-balance-tree.hpp.html
title: src/alfred/data_structure/pbds-balance-tree.hpp
---

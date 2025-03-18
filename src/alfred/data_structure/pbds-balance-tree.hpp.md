---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-pbds.test.cpp
    title: verify/verify-yosupo-ds/yosupo-pbds.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "src/alfred/data_structure/pbds-balance-tree.hpp"




    #include <ext/pb_ds/assoc_container.hpp>

    #include <ext/pb_ds/tree_policy.hpp>


    // TreeTag can also be __gnu_pbds::splay_tree_tag

    template <class T, class Cmp = std::less_equal<int>, class TreeTag = __gnu_pbds::rb_tree_tag>

    using BalanceTree = __gnu_pbds::tree<T, __gnu_pbds::null_type, Cmp, TreeTag, __gnu_pbds::tree_order_statistics_node_update>;



    '
  code: '#ifndef AFDS_PBDS_BALANCE_TREE

    #define AFDS_PBDS_BALANCE_TREE


    #include <ext/pb_ds/assoc_container.hpp>

    #include <ext/pb_ds/tree_policy.hpp>


    // TreeTag can also be __gnu_pbds::splay_tree_tag

    template <class T, class Cmp = std::less_equal<int>, class TreeTag = __gnu_pbds::rb_tree_tag>

    using BalanceTree = __gnu_pbds::tree<T, __gnu_pbds::null_type, Cmp, TreeTag, __gnu_pbds::tree_order_statistics_node_update>;


    #endif // AFDS_PBDS_BALANCE_TREE

    '
  dependsOn: []
  isVerificationFile: false
  path: src/alfred/data_structure/pbds-balance-tree.hpp
  requiredBy: []
  timestamp: '2025-03-18 20:36:59+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-pbds.test.cpp
documentation_of: src/alfred/data_structure/pbds-balance-tree.hpp
layout: document
redirect_from:
- /library/src/alfred/data_structure/pbds-balance-tree.hpp
- /library/src/alfred/data_structure/pbds-balance-tree.hpp.html
title: src/alfred/data_structure/pbds-balance-tree.hpp
---

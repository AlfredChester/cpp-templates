#ifndef AFDS_PBDS_BALANCE_TREE
#define AFDS_PBDS_BALANCE_TREE

#include <bits/extc++.h>
#include <bits/stdc++.h>

// TreeTag can also be __gnu_pbds::splay_tree_tag
template <class T, class Cmp, class TreeTag = __gnu_pbds::rb_tree_tag>
using BalanceTree = __gnu_pbds::tree<T, __gnu_pbds::null_type, Cmp, TreeTag, __gnu_pbds::tree_order_statistics_node_update>;

#endif // AFDS_PBDS_BALANCE_TREE

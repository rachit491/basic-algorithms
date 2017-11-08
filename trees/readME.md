# Trees

### No of unlabeled trees formed with N nodes
`T(n) = (2n)! / (n+1)!n!`

### No of labeled trees formed with N nodes
`T(n) = (no_of_unlabled_trees) * n!`

### BFS vs DFS
1. Extra Space can be one factor (Explained above)
2. Depth First Traversals are typically recursive and recursive code requires function call overheads.
3. The most important points is, BFS starts visiting nodes from root while DFS starts visiting nodes from leaves. So if our problem is to search something that is more likely to closer to root, we would prefer BFS. And if the target node is close to a leaf, we would prefer DFS.
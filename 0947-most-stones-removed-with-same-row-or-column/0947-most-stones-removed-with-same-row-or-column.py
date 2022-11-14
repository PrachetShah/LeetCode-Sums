class DSU:
    def __init__(self, n):
        self.parents = [i for i in range(n)]
    def find(self, x):
        if x != self.parents[x]:
            self.parents[x] = self.find(self.parents[x])
        return self.parents[x]
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px != py:
            self.parents[py] = px
    def is_connected(self, x, y):
        return self.find(x) == self.find(y)
    def get_groups(self):
        # return len(set(self.parents))
        return set([self.find(x) for x in range(len(self.parents))])

class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        n = len(stones)
        dsu = DSU(n)
        rows = {}
        cols = {}
        for idx in range(n):
            i, j = stones[idx]
            # print(idx)
            if i in rows or j in cols:
                prev_idx = -1
                # if i in rows:
                #     prev_idx = rows.get(i, None)
                # if j in cols:
                #     prev_idx = cols.get(j, None)
                # # print(idx, prev_idx)
                # dsu.union(prev_idx, idx)
                if i in rows:
                    prev_idx = rows.get(i, None)
                    dsu.union(prev_idx, idx) # FIX!
                if j in cols:
                    prev_idx = cols.get(j, None)
                    dsu.union(prev_idx, idx)                
                rows[i] = cols[j] = prev_idx
            else:
                rows[i] = cols[j] = idx
            # print(rows, cols)
        
        cnt_groups = len(dsu.get_groups())
        # print(dsu.parents)
        return n - cnt_groups
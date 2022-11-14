class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        x,y=defaultdict(list),defaultdict(list)
        for i in stones:
            x[i[0]].append(i[1])
            y[i[1]].append(i[0])
        neighbour,visited=0,set()
        for i in stones:
            if (i[0],i[1]) not in visited:
                q=deque()
                q.append(i)
                while q:
                    stonex,stoney=q.popleft()
                    if (stonex,stoney) not in visited:
                        visited.add((stonex,stoney))
                        for j in x[stonex]:
                            q.append([stonex,j])
                        for j in y[stoney]:
                            q.append([j,stoney])
                neighbour+=1
        return len(stones)-neighbour
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def _trie():
            return defaultdict(_trie)
        _trie.TERMINAL = None
        _trie.PARENT = 'pa'
        _trie.LETTER = 'le'
        #None and 2-character string to avoid overwriting traversal keys

        self.trie = _trie()
        self.trie[_trie.PARENT] = None
        #add words into trie
        for word in words:
            trie = self.trie
            for letter in word:
                if letter not in trie:
                    new_trie = trie[letter]
                    new_trie[_trie.PARENT] = trie
                    new_trie[_trie.LETTER] = letter
                trie = trie[letter]
            trie[_trie.TERMINAL] = word

        M = len(board)
        N = len(board[0])
        res = []
        seen = set()

        def search(trie, y, x):
            if y < 0 or x < 0 or y >= M or x >= N:
                return
            
            if (y, x) in seen:
                return
            seen.add((y, x))
            
            if board[y][x] not in trie:
                seen.remove((y, x))
                return

            trie = trie[board[y][x]]
            if _trie.TERMINAL in trie: #word
                res.append(trie[_trie.TERMINAL])
                del trie[_trie.TERMINAL]
                if len(trie) == 2: #only has 'PARENT' and 'LETTER', longest trie has been reached
                    while len(trie) == 2 and trie[_trie.PARENT]:
                        #since we only start removing when the longest trie has been reached
                        #we need a loop to also remove the shorter ones
                        parent_trie = trie[_trie.PARENT]
                        del parent_trie[trie[_trie.LETTER]]
                        del trie
                        trie = parent_trie
                    seen.remove((y, x))
                    return
            
            search(trie, y-1, x)
            search(trie, y+1, x)
            search(trie, y, x-1)
            search(trie, y, x+1)
            
            seen.remove((y, x))
            return

        for y in range(M):
            for x in range(N):
                search(self.trie, y, x)
        
        return res
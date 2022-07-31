We are going to start from the cell at ```sr``` and ```sc``` and **radiate** the newColor with depth first search (DFS).
<br/>
Visually speaking, it would look like this:

<img src='https://assets.leetcode.com/users/arkaung/image_1589193648.png' alt='diagram' />

We are going to radiate with our DFS in four directions (up, down, left and right) until we hit the following scenarios:

- The indices are beyond the image grid indcies (indicated by blue arrows protruding beyond the image grid)
- The new cell is of different color (indicated by red crosses in the image)
- The new cell is of same color (the arrow pointing downwards for the the topmost picture)

```
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        rows = len(image)
        cols = len(image[0])
        color_to_change = image[sr][sc]
        
        def dfs(r, c):
            nonlocal rows, cols, newColor, image
            
            if r < 0 or c < 0 or r>rows-1 or c>cols-1 or image[r][c]==newColor or image[r][c]!=color_to_change:
                return
            
            image[r][c] = newColor
            
			# radiate in four directions
            dfs(r+1,c)
            dfs(r-1,c)
            dfs(r,c+1)
            dfs(r,c-1)
        
        dfs(sr, sc)
        
        return image
```

**Solution using less lines but more time and memory**
```
def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
    """ O(N*M)TS in place """

    def fn(y, x, color):
        if 0 <= y < len(image) and 0 <= x < len(image[0]) and image[y][x] == color:
            image[y][x] = newColor
            fn(y + 1, x, color), fn(y - 1, x, color), fn(y, x + 1, color), fn(y, x - 1, color)

    return (fn(sr, sc, image[sr][sc]) or image) if image[sr][sc] != newColor else image
```

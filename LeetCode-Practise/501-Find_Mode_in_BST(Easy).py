class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        
        lst = []                            # result
        dic = {}                            # put node value in dictionary
        maxi = 0                            # the frequence of the most frequently occurred element
        
        def find(root):
            
            if not root:                    # leaf node
                return
            
            if root.val in dic:             # if node value is in the dictionry, value + 1
                dic[root.val] += 1
            else:
                dic[root.val] = 1           # if node value is not in the dictionary, value = 1
            
            find(root.left)
            find(root.right)
            
            return 
     
        find(root)
        dicval_list = list(dic.values())    # list all the values in dictionary
        maxi = max(dicval_list)             # find maximum value in dictionary
        for key, value in dic.items():
            if value == maxi:               # if value = maximum, append this key to list
                lst.append(key)
        return lst

class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        counter = Counter(tasks)
        rounds = 0
        for val, count in counter.items():
            # print(val, count)
            if count == 1:
                return -1
            
            if count%3 == 0:
                #Group all the task in triplets.
                rounds += count//3
            else:
                # If count % 3 = 1; (count / 3 - 1) groups of triplets and 2 pairs.
                # If count % 3 = 2; (count / 3) groups of triplets and 1 pair.
                rounds += count//3 + 1
        return rounds
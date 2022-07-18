def remov_nb1(n):
    num = [i+1 for i in range(n)]
    result = []
    total = sum(num)
    for i in range(len(num)//2,len(num)):
        for j in range(len(num)//2, len(num)):
            add = total - num[i] - num[j]
            product = num[i]*num[j]
            if add == product:
                result.append((num[i], num[j]))
    return result

def remov_nb2(n):
    """
    Second iteration
    Faster because:
        * we only iterate over 'the rest of the list' on second loop
        * sum is calculated once in the beginning and we just substract
          x and y from it
    < O(n^2)
    """
    result = []
    sequence_sum = sum(range(1, n + 1))
    for x in range(1, n):
        for y in range(x + 1, n + 1):
            if x * y == sequence_sum - (x + y):
                result.append((x, y))
                result.append((y, x))
    return result

def remov_nb(n):
    """
    Third iteration
    This one actually passed tests (though my first solution was in Swift)
    O(n)
    """
    result = []
    sequence_sum = n * (n + 1) // 2
    for x in range(1, n + 1):
        y = (sequence_sum - x) // (x + 1)
        if y <= n and x * y == (sequence_sum - x - y):
            result.append((x, y))
    return result

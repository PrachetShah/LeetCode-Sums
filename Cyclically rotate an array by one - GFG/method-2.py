#User function Template for python3

def rotate( arr, n):
    val = arr[-1]
    for i in range(len(arr)-1, 0, -1):
        arr[i] = arr[i-1]
    arr[0] = val


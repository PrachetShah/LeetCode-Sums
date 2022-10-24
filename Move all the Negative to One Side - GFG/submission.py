#code
def move(arr):
    low, high = 0, len(arr)-1
    while low <= high:
        if arr[low] < 0 and arr[high] < 0:
            low += 1 
        elif arr[low] > 0 and arr[high] < 0:
            arr[low], arr[high] = arr[high], arr[low]
            low += 1
            high -= 1 
        elif arr[low] > 0 and arr[high] > 0:
            high -= 1 
        else:
            low += 1
            high -= 1 
    return arr 

input = [-12, 11, -13, -5, 6, -7, 5, -3, -6]
out = move(input)
print(out)
            

import math

def keySort(array):
    # generate key 
    key = 0;
    for x in array:
        key += 2 ** x
    
    # sort using key
    sort = []
    for i in range(len(array)):
        value = math.floor(math.log(key, 2))
        sort.append(value) # highest value in array
        key -= 2 ** value
    
    # return sorted array
    return sort

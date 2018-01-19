'''
NOTE: python has very slow for loops which make this algorithm mush slower than
it is. 
'''
import math
import time

def regSort(array) :
    return array.sort()
def keySort(array) :
    key = 0;
    for x in array :
        key += 2**x
    '''
    sort = []
    for i in range(len(array)) :
        value = math.floor(math.log(key, 2))
        key -= 2**value
    '''
array = [12, 3, 4, 5, 6, 2, 9, 11, 10, 45, 234, 12, 78]

start = time.time()
regSort(array)
print (time.time() - start)
start = time.time()
keySort(array)
print (time.time() - start)
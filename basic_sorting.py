from typing import List
import random
import unittest

def insertion_sort(a: List) -> None:
    for j in range(1, len(a)):
        key = a[j]    # hand keep
        i = j-1       # sorted part
        while i >= 0 and a[i] < key:
            a[i+1] = a[i]
            i -= 1
        a[i+1] = key   # at the last for head of list maybe i reach to -1...


def linear_search(a: List, v):
    for i in range(len(a)):
        if a[i] == v:
            return i
    return None      

def add_binary(a, b):
    n = len(a)
    c = [0]*(n+1)
    carry = 0
    for i in range(n):
        c[i] = a[i] + b[i] + carry
        if c[i] > 1:
            c[i] -= 2
            carry = 1
        else:
            carry = 0
    c[n] = carry
    return c
        
        
class InsertionSortTestCase(unittest.TestCase):
    def random_array(self):
        return [random.randint(0,100) for _ in range(random.randint(0,100))]
    
    def test_random(self):
        for _ in range(10000):
            arr = self.random_array()
            sorted_arr = sorted(arr)
            sorted_arr.reverse()
            insertion_sort(arr)
            self.assertEqual(arr, sorted_arr)
            
            
if __name__ == '__main__':
    unittest.main() 



#a_t = [31,41,59,26,41,58]
#insertion_sort(a_t)
#k = linear_search(a_t, 26)
#print(k)
# res = add_binary([1, 0, 1, 1, 1], [0, 1, 1, 1, 1])
# print(res)      
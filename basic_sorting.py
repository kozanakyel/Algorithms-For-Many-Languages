from typing import List
import random, sys
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


def selection_sort(a: List):
    for i in range(len(a)):
        k = i      # k is minIndex
        for j in range(i+1, len(a)):
            if a[j] < a[k]:
                k = j
        a[i], a[k] = a[k], a[i]
        
def merge_sort_sub(arr, l, r):
    if l >= r:
        return
    mid = (l+r)//2
    merge_sort_sub(arr, l, mid+1)  
    merge_sort_sub(arr, mid+1, r)
    arr_l = [arr[i] for i in range(l, mid+1)]
    arr_r = [arr[j] for j in range(mid+1, r+1)]
    i, j = 0, 0
    for k in range(l, r+1):
        if j==len(arr_r) or (i != len(arr_l) and arr_l[i] <= arr_r[j]):
            arr[k] = arr_l[i]
            i+=1
        else:
            arr[k]=arr_r[j]
            j+=1
            
def merge_sort(arr):
    merge_sort_sub(arr, 0, len(arr)-1)      

     
# class MergeSortTestCase(unittest.TestCase):
#     def random_array(self):
#         return [random.randint(0, 10) for _ in range(random.randint(1, 10))]

#     def test_random(self):
#         for _ in range(10):
#             arr = self.random_array()
#             sorted_arr = sorted(arr)
#             merge_sort(arr)
#             self.assertEqual(arr, sorted_arr)               
        
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
            
class SelectionSortTestCase(unittest.TestCase):
    def random_array(self):
        return [random.randint(0,100) for _ in range(random.randint(0,100))]
    
    def test_random(self):
        for _ in range(10000):
            arr = self.random_array()
            sorted_arr = sorted(arr)
            selection_sort(arr)
            self.assertEqual(arr, sorted_arr)
            
class AddBinaryTestCase(unittest.TestCase):
    def test_carry(self):
        a = [1, 0, 1]
        b = [1, 1, 1]
        self.assertEqual(add_binary(a, b), [0, 0, 1, 1])
            
            
if __name__ == '__main__':
    limit = sys.getrecursionlimit()
    print('Before changing, limit of stack =', limit) 
    sys.setrecursionlimit(100000)
    unittest.main() 

    # a_t = [31,41,59,26,41,58]
    # insertion_sort(a_t)
    # k = linear_search(a_t, 26)
    # print(k)
    # res = add_binary([1, 0, 1, 1, 1], [0, 1, 1, 1, 1])
    # print(res)      
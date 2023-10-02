import sys
from typing import List, Optional

sys.setrecursionlimit(10**8)

def cut_rod(p: List, n: Optional[int]) -> int:
    """ Recursive solution Tn is exponentials"""
    if n == 0:
        return 0
    q = -2**31
    for i in range(0, n):
        q = max(q, p[i]+cut_rod(p, n-i))
    return q    


def memoized_cut_rod(p: List, n: Optional[int]) -> int:
    r = [0]*n
    for i in range(0, n):
        r[i] = -1000
    return memoized_cut_rod_aux(p,n,r)


def memoized_cut_rod_aux(p: List, n: Optional[int], r: List) -> int:
    if r[n-1] >= 0:
        return r[n-1]
    if n == 0:
        q = 0
    else:
        q = -1000
        for i in range(0, n):
           q = max(q, p[i]+memoized_cut_rod_aux(p, n-i, r)) 
    r[n-1] = q
    return q


def bottom_up_cut_rod(p: List, n: Optional[int]) -> int:
    r = [0]*n
    r[0] = 0
    for j in range(1,n):
        q = 0
        for i in range(1,j):
            q = max(q, p[i] + r[j-1])
        r[j] = q
    return r[n-1]            
    

if __name__ == '__main__':
    n = 10
    p = [1,5,8,9,10,17,17,20,24,30]
    # p = [1,5,8,9]
    q = bottom_up_cut_rod(p, n)
    print(q)
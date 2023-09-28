from random import randrange
from typing import MutableMapping

"""
@ugur akyel - kozan

CORE OF PYTHON "DICT" BUILT-IN FUNC.

Hash code larda collision detection yapilmali, obur turlu cok fazla collision
algortimasmizi islevselligini yitirir

- polynomial hash code
- cyclic-shift hash codes


for compresiion function we can use division method

Separate Chaining for avoiding collison
Also Load Factor you can use for 1/N  --- n/N   n:input array length N:bucket array sizes

Open addressing load factor always assign to O(1)
Linear Probing A[(j+1) mod N] if not occupied j+2, j+3 ....
In linear probing, sonsuz bir donguye girebilir...

Quadratic Probe, (j+i^2),... f(i)=i^2 or smotehing else, if N is prime
    quadratic probe quaranteed to find an empty slot.
    Secondary Hash function for Quadratic probing with h''(x) ...
    
Python dict implementation of openaddressing enforces load factor < 2/3,
if not resize the table

Operation     List            Hash Table
                        expected   worst case
getitem       O(n)      O(1)       O(n)
setitem       O(n)      O(1)       O(n)
delitem       O(n)      O(1)       O(n)
len           O(1)      O(1)       O(1)
iter          O(n)      O(n)       O(n)

!Yani Eegr size iyi bir Hash function kullanmazsaniz O(n)'e carparsiniz.
"""

def hash_code(s):
    mask = (1 << 32) - 1   # limit 32-bit integers
    h = 0
    for character in s:
        h = (h << 5 & mask) | (h >> 27)   # 5-bit cyclic shift
        h += ord(character)  # return Unicode int with ord()
    return h


class MapBase(MutableMapping):
    """ Our own abstract base class that includes a nonpublic Item class.
    """

        #------------------------------- nested Item class -------------------------------
    class _Item:
        """ Lightweight composite to store key-value pairs as map items."""
        __slots__ = '_key', '_value'

        def __init__ (self, k, v):
            self._key = k
            self._value = v

        def __eq__ (self, other):
            return self._key == other._key # compare items based on their keys

        def __ne__ (self, other):
            return not (self == other) # opposite of eq

        def __lt__ (self, other):
            return self._key < other._key
        
        def __hash__(self):
            return hash(self._key)
        
        
class HashMapBase(MapBase):
    
    def __init__(self, cap=11, p=109345121) -> None:
        self._table = cap*[None]
        self._n=0
        self._prime=p
        self._scale=1+randrange(p-1)
        self._shift=randrange(p)
        
    def _hash_function(self, k):
        return (hash(k)*self._sclae+self._shift)%self._prime%len(self._table)
    
    def __len__(self):
        return self._n
    
    def __getitem__(self,k):
        j=self._hash_function(k)
        return self._bucket_getitem(j,k)
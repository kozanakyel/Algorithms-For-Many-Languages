"""
Flipping matrix: for the first time when i faced this problem 

X   |   A   |   A    |   X
B   |   D   |   D    |   B
B   |   D   |   D    |   B
X   |   A   |   A    |   X    ; if you can see this same letter should only be
                                in left-upper quandratnt and mirror perpective
So, we should determine whic is max from same Letters value....
                

"""

def flipping_matrix(matrix):
    s = 0
    n = len(matrix)
    for i in range(n//2):
        for j in range(n//2):
            s += max(matrix[i][j], matrix[i][n-j-1], matrix[n-i-1][j], matrix[n-i-1][n-j-1])
    return s




if __name__ == '__main__':
    # n = [[2,3],[1,7]]
    # m = flipping_matrix(n)
    # print(m)
    from BTrees.OOBTree import OOBTree
    
    t = OOBTree()
    t.update({1: "red", 2: "green", 3: "blue", 4: "spades"})
    len(t)

    s = t.keys() # this is a "lazy" sequence object

    print(
        list(s), 
        list(t.values()), 
        list(t.values(1, 2)), 
        list(t.values(2)), 
        list(t.values(min=1, max=4)),
        list(t.values(min=1, max=4, excludemin=True, excludemax=True))
    )
    
    
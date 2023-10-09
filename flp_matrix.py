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
    # mirror matrix equation it is the ttricks
    s = 0
    n = len(matrix)
    for i in range(n//2):
        for j in range(n//2):
            s += max(matrix[i][j], matrix[i][n-j-1], matrix[n-i-1][j], matrix[n-i-1][n-j-1])
    return s


if __name__ == '__main__':
    n = [[2,3],[1,7]]
    m = flipping_matrix(n)
    print(m)
"""
Question:
    Find the Count of the submatrices from the given matrix,which gives given 'S' as sum in those submatrix
identified.

Input Description:
First line contains two numbers  N and M which represents the row and column.
Second line contains the N*M elements of that matrix,
Third line contains 'S' as the target-sum.

Output Description:
Print the count of submatrix as mentioned above.

Testcases:
Input:
3 3
0 1 0 1 1 1 0 1 0
0
Output:
4

Explanation: The four 1x1 submatrices that only contain 0.

Input:
2 2
1 -1 -1 1
0
Ouput:
5

Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

Input:
3 3
1 0 -1 2 0 -2 3 0 -3
0
Output:
12

Input:
3 3
1 2 3 1 5 1 7 8 9
1
Output:
3

Input:
1 1
0
1
Output:
0

solution:-
"""
import numpy as ma 
class Solution(object):
    def numSubmatrixSumTarget(self, matrix, S):
        m = len(matrix[0])
        n = len(matrix)
        res = 0
        
        prefix = [[0] * m for _ in range(n)]
        
        
        for i in range(n):
            for j in range(m):
                if i == 0:
                    prefix[i][j] = matrix[i][j]
                else:
                    prefix[i][j] = matrix[i][j] + prefix[i-1][j]
        
        for i in range(n):
            for j in range(i, n):
                d = {0:1}
                cur = 0
                for k in range(m):
                    if i == 0:
                        cur += prefix[j][k]
                    else:
                        cur += prefix[j][k] - prefix[i-1][k]
                
                    if cur - S in d:
                        res += d[cur-S]

                    if cur in d:
                        d[cur] += 1
                    else:
                        d[cur] = 1
        return res

if __name__ == "__main__":
    n,m=map(int,input().split())
    l=[int(v) for v in input().split()]
    S=int(input())
    matrix=ma.array(l).reshape(n,m)
    sol=Solution()
    print(sol.numSubmatrixSumTarget(matrix,S))
    

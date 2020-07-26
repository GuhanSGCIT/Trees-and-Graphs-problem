"""
This year p soccer players and q handball player have been invited to participate in handball championship leage as guests.
You have to accommodate them in r rooms such that-

    No room may remain empty.
    A room may contain either only soccer players or only handball players, not both.
    No handball players are allowed to stay alone in a room.

Find the number of ways to place the players. Note though, that all the rooms are identical. But each of the handball players
and soccer players are unique.

Since the number of ways can be very large, print the answer modulo 998,244,353.

timing:1sec
level:7

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers p , q and r denoting the number of
soccer players, handball players and rooms.

Output Description:
For each test case, output the number of ways to place the players modulo 998,244,353.

Constraints
1≤T≤100
1≤p,q,r≤100

Input:
4
2 1 4
2 4 4
2 5 4
2 8 4

Output:
0
3
10
609

Explanation:
Example case 2: Three possible ways are:
    {soccer players 1}, {soccer players 2}, {handball players 1, handball players 2}, {handball players 3, handball players 4}
    {soccer players 1}, {soccer players 2}, {handball players 1, handball players 3}, {handball players 2, handball players 4}
    {soccer players 1}, {soccer players 2}, {handball players 1, handball players 4}, {handball players 2, handball players 3}
Please note that the rooms are identical.

Input:
6
1 12 3
5 2 4
5 5 5
4 2 6
2 5 4
1 2 1

Output:
2035
25
260
0
10
0

Input:
2
12 21 12
4 2 1

Output:
439389501
0

Input:
3
2 5 8
77 5 2

Output:
0
1

Input:
3
1 5 9
0 0 0

Output:
0
0
Solution:

"""
MOD = 998244353

fball = [ [0]*101 for _ in range(101) ]

cric = [ [0]*101 for _ in range(101) ] 



def calSNum(n, r):
    if n == r or r == 1:
        fball[r][n] = 1
        return
    if n > 0 and r > 0 and n > r:
        fball[r][n] = (fball[r-1][n-1]%MOD + (r*fball[r][n-1])%MOD )%MOD
        return
    fball[r][n] = 0
        

def calASNum(n, r):
    if n == 0 and r == 0 :
        cric[r][n] = 0
        return
    if n >= 2 and r == 1:
        cric[r][n] = 1
        return 
    if r > 0 and n > 0 and n >= 2*r:
        cric[r][n] = ((r*cric[r][n-1])%MOD + ((n-1)*cric[r-1][n-2])%MOD )%MOD
        return
    cric[r][n] = 0
    

def preCompute():
    for r in range(1,101):
        for n in range(1, 101):
            calSNum(n, r)
            calASNum(n, r)

    
def main():
    
    preCompute()
    
    t = int(input())
    while True:
        
        try:
            f, c, r = list(map(int, input().split()))
        except EOFError:
            break

        ans = 0
        
        if f + (c//2) >= r:
            minv = min(f, r)
            
            for i in range(1, minv+1):
                if r-i <= c//2:
                    ans = (ans + (fball[i][f] * cric[r-i][c])%MOD )%MOD
            
        print(ans)
            
if __name__ == '__main__':
    main()

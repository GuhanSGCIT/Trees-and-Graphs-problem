/*
While other heroes from Marvel and DC Universe have resorted to competing in duels to establish their supremacy,
Batman and Dr. Strange decided to find the winner by playing a stratergy board game. The game consists of a N x M board
that has either white or black stones in each cell. The game is simple, each player is allowed to select a single white stone
anywhere on the board, and he owns that stone. However, he is also granted the ownership of every white stone present in the
immediate adjacent cell of the current cell, in all directions. Repeat this for all white stones that a player owns. Cells having
black stones cannot be owned. A player cannot change the configuration of the board. The rules are elementary, whosoever owns maximum
white stones using the rules stated above, is declared the winner. Your task is to help Batman (Yeah right !! Batman needs your help !) in calculating the maximum number of stones he can own, if he starts first.

 
Input:
The first line contains a positive integer t, denoting the number of test cases.
The first line of each test case contains two positive integers N and M, denoting the number of rows and coloumns on the board respectively.
Each line i of the n subsequent lines contain m space separate integers denoting ith row of the board where each cell has a value of either 0 or 1, where 0 denotes a black stone and 1 denotes a white stone.

 
Output:
For each test case, print a single positive integer denoting the maximum number of stones Batman can own if he starts first.

 
Constraints
    1 ≤ t ≤ 250
    1 ≤ N,M ≤ 200

Input:
1
5 5
0 0 1 1 0
0 1 0 0 0
1 1 1 0 0
0 0 0 0 1
1 0 0 0 0

Output:
6

 
Explanation
The board configuration above has 3 regions with maximum white stones as 6,1 and 1 respectively. Hence if the batman starts from the cell (1,3) he can own a maximum of 6 stones

input:
1
3 3
1 0 0
0 1 0
0 0 1

output:
3

Input:
1
2
0 0
0 0

output:
0

Input:
2
1 1
1
3 3
0 0 0
1 1 1
0 0 0

output:
1
3

Input:
1
4 4
0 0 1 0
0 1 0 0
0 1 1 1
0 0 0 0

output:
5

hint:
Use a standard Depth-First Search (DFS) algorithm but modify it to assign a unique number to each cell identified in a connected component.
Finally, keep a running maximum of the number of connected cells found by each DFS. Once the entire matrix has been searched, print this running maximum.
*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int x,int y,int c, int w[][201], int g[][201], int *dx, int *dy){
    w[x][y] = c;
    for(int i=0; i<8;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(g[nx][ny] && !w[nx][ny]) dfs(nx,ny,c,w,g,dx,dy);
    }
}

int main(){
    int row, col, set = 1,t;
    cin >> t;
    while(t--)
    {
        int g[201][201] = {0};
        int w[201][201] = {0};
        int dx[8] = {-1,0,1,1,1,0,-1,-1};
        int dy[8] = {1,1,1,0,-1,-1,-1,0};
        scanf("%d%d", &row, &col);

        for(int i=1; i<=row; i++)
            for(int j=1; j<=col; j++)
                scanf("%d", &g[i][j]);

        for(int i=1; i<=row;i++)
            for(int j=1; j<=col; j++)
                if(g[i][j] && !w[i][j])
                    dfs(i,j,set++,w,g,dx,dy);

        unordered_map<int,int> mp;
        for(int i=1; i<=row;i++){
            for(int j=1; j<=col; j++){
                if (w[i][j]) mp[w[i][j]]++;
            }
        }
        int ans = 0;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans = max(ans,it->second);
        }
        printf("%d\n",ans);
    }
    return 0;
}

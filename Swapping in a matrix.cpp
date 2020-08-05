/*
You are given a binary matrix (i.e. each element of matrix is either 0 or 1) of size n × n. You want to re-arrange
1's in such a way that they form a rectangular region. Note that the rectangular region should be made of only 1's,
and all the 1's of the entire matrix should be in this rectangular region.

For achieving rectangular region, you can swap any two elements of the matrix. Please find out the minimum number of
swaps needed. If it is not possible to re-arrange 1's in the desired way, please print -1.

timint:1sec
level:7

Input Description:
    First line of the input contains a single integer T denoting number of test cases.
    Description of T test cases follows.
    First line of each test case will contain a single integer n denoting dimension of matrix.
    Each of next n lines will contain n space separated integers denoting the ith row of the matrix.

Output description:
    For each test case, print a single line containing a single integer denoting minimum number of swaps needed or -1
depending on the situation.

Constraints

    1 ≤ T ≤ 2
    1 ≤ n ≤ 1000
    Each entry of the matrix will either be 0 or 1

Input:
2
1 
0
1
1

Output:
0
0

Explanation
Example case 1. There is no 1 in the array. So no swap is required. Hence answer is 0.
Example case 2. There is exactly one 1. It already forms a rectangular region of dimension 1 × 1. So here also, no swap is required.
Hence answer is 0.

Input:
2
2 
0 1
1 0
2
1 1 
1 0

Output:
1 
-1

Input:
1
3
1 0 1
1 1 1
0 1 0

output:
1

Input:
2
2
0 0
1 1
3
0 0 0
1 1 1
0 1 0

output:
0
1

Input:
3
1
0
0
4
1 1 1 0
0 1 0 1
0 0 0 1
0 1 0 1
2
0 1
1 1

output:
0
0
3


code:
        
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
int max(int a,int b)
{
  if(a>=b) return a;
  return b;
}
#define rep(n) for(int i=0;i<n;i++)
int main()
{
  int n,t,c1=0,x1,x2,y1,y2;
  scanf("%d",&t );
  while(t--)
  {
    int cnt[1010][1010]={0};
    bool a[1010][1010]={0};
    c1=0;
  scanf("%d",&n);
  rep(n)
  {
    for(int j=0;j<n;j++)
    {
      scanf("%d",&a[i+1][j+1]);
      if(a[i+1][j+1]) c1++;
    }
  }
  int dim[2*n][2],f=0;
  for(int i=1;i<=sqrt(c1);i++)
  {
    if(c1%i==0)
    {
      if(max(i,c1/i)<=n)
      {
        dim[f][0]=i;
        dim[f][1]=c1/i;
        f++;
        dim[f][1]=i;
        dim[f][0]=c1/i;
        f++;
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cnt[i][j]=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
      if(a[i][j]) cnt[i][j]++;
    }
  }

  // printf("ff% d\n",f );
  long long int ans=1000000000;
  for(int k=0;k<f;k++)
  {
    int x=dim[k][0],y=dim[k][1];
    // printf("x-%d,y-%d\n",x,y );
    for(int i=1;i<=n-y+1;i++)
    {
      for(int j=1;j<=n-x+1;j++)
      {
        x1=i;y1=j;x2=i+y-1;y2=j+x-1;
        int swap= c1-(cnt[x2][y2]-cnt[x2][y1-1]-cnt[x1-1][y2]+cnt[x1-1][y1-1]);
        // printf("swap %d\n",swap );
        if(swap<ans) ans=swap;
      }
    }
  }
  // printf("%d\n"  ,c1 );

  if(!c1)
  ans=0;
  if(ans!=1000000000)
  printf("%d\n",ans );
  else
  printf("-1\n" );
  // cout<<ans<<endl;
}

  return 0;
}

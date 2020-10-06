/*
Varun loves trees, he thinks that the beauty of a tree is determined by the distance between its center and centroid. If the tree has multiple centers or centroids, then the beauty is the maximum among every possible pair.

As a reward for her delicious dishes (and awesome coding skills), Guvi is going to give a present to varun, and of course it must be a tree! But not any tree, we want to give her one with n nodes, and beauty b. Help find such a tree.

Input
The first line of input contains one number T, the number of test cases.
Each test case contains two integers n and b, the desired number of vertices and beauty.

Output
For each test case, if no tree satisfies the conditions print "NO" in a new line.
Otherwise, print "YES" in a new line and describe any valid tree. Print n-1 more lines, each with two integers ui, vi (1 ≤ ui, vi ≤ n) denoting the indices of the vertices connected by an edge in the tree.

Notes
A vertex u is a centroid if after removing u from the tree, the size of any of the resulting connected components is at most n/2
Lef f(x) be the greatest distance from u to any other vertex of the tree. A vertex u is a center if f(u) ≤ f(v) for any other vertex v.


Input:
1
4 0

Output:
YES
1 2
1 3
1 4

Explanation
Vertex 1 is the center and centroid of the tree.

input:
2
8 1
5 0

output:
YES
1 2
1 3
3 4
3 5
3 6
3 7
3 8
YES
1 2
2 3
1 4
4 5

input:
3
5 0
4 3
2 5

output:
YES
1 2
2 3
1 4
4 5
NO
NO

input:
1
7 2

output:
NO

input:
5
3 0
2 5
4 8
9 5
3 1

output:
YES
1 2
1 3
NO
NO
NO
NO

hint:
After forming a chain of length 2B+1 then clearly node B+1 is the center of our tree. Attaching some nodes to our tree would make the diameter equal to 2B+2 so we have 2 centers. But we are taking the maximum distance between a center and a centroid
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
int nv;
void line(int len){
  int bef=1;
  for(int i=0;i<len;i++){
    printf("%d %d\n",bef,++nv);
    bef=nv;
  }
}
int main(){
  int t,n,d;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d",&n,&d);
    if(n==2){
      if(d==1){
        puts("YES");
        puts("1 2");
      }
      else puts("NO");
      continue;
    }
    if(d==0){
      puts("YES");
      nv=1;
      if(n%2==0){
        puts("1 2");
        nv++;
        --n;
      }
      line((n-1)/2);
      line(n/2);
      continue;
    }
    if(n<4*d)puts("NO");
    else{
      puts("YES");
      nv=1;
      line(d);
      line(d);
      int a=2*d-1;
      a+=n-4*d;
      int u=nv;
      while(a--)printf("%d %d\n",u,++nv);
    }
  }
  return 0;
}


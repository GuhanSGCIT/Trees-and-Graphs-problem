/*
This is a simple cakewalk problem.In this problem you have to print shortest path from one point to another.
Math, Backtracking, Graph

Input:
First line of the input contains an integer N denoting the number of groups. Description of N groups follows.
Next N lines will consist of a single line containing maximum M space separated integers I.
Last line of input will contain 2 space separated integers A and B.

Output:
Output is a single line containing space separated integers showing shortest path to reach from A to B.
If there is no path then print None.

Constraints:
1 <= N <= 10
2 <= M <= 10
0 <= I, A, B <= 100

Input:
6			
1 2			
3 4			
2 3 6		
3 6			
7 6			
7 8 9		
1 8			
Output:
1 2 6 7 8

Explanation:
In above example, we have to find the shortest path between 1 and 8
1 and 2 are in the same group
2 and 6 are in the same group
6 and 7 are in the same group
7 and 8 are in the same group
Hence shortest path becomes 1 2 6 7 8
Note: There are many possible paths from 1 to 8, but since we have to find the shortest one, we considered this path.

input:
5
1 2
2 3
2 4 5
3 4
2 4
1 2 3
output:
1 2

input:
6
1 3
2 4
1 2 3
2 4
4 6
1 2 3
2 5
output:
None

input:
8
1 2
4 5
2 4 6
5 6
5 7
4 6 7
4 2
6 7
2 5 8
3 8
output:
2 4 5 

input:
3
2 3
2 4
1 2 3
1 3
output:
1 3

hint:
Convert all the inputs in the form of graph & use backtracking algorithm to find shortest path from one node to another.
*/
#include <bits/stdc++.h>
using namespace std;

string ch,token;

int main() {
    int n,s,e,u,se;
    scanf("%d",&n);
    set<int> gr[n];
    int col[n];
    int pa[n];
    int paS[n];
    for(int i=0;i<n;i++)pa[i]=paS[i]=-1;

    queue<int> q;
    int ad;
    getline(cin,ch);
    for(int i=0;i<n;i++){
        getline(cin,ch);
      
        u=0;
        //printf("%d\n",l);
        
        stringstream ss;
	ss << ch;
	for(; getline(ss, token, ' ') ;){
		u=atoi(token.c_str());
		gr[i].insert(u);
	}
    }
    scanf("%d %d",&s,&e);
    
    for(int i=0;i<n;i++){
    	ad=0;
    	if(gr[i].count(s)>0){
    		pa[i]=s;
    		ad++;
    		q.push(i);
    	}
    	if(gr[i].count(e)>0)ad++;
    	if(ad==2)break;
    }
    
    int ends=-1;
		
    if(ad!=2){
        while(!q.empty()){
            se=q.front();
            q.pop();
            if(gr[se].count(e)>0){
                ends=se;
                break;
            }
            set<int>::iterator it;
            for(it = gr[se].begin();it!=gr[se].end();it++){
                u=*it;
                for(int j=0;j<n;j++){
                    if(gr[j].count(u)>0 && pa[j]==-1){
                        pa[j]=u;
                        paS[j]=se;
                        q.push(j);
                    }
                }
            }
        }

        if(ends==-1)printf("None");
        else{
            stack<int> st;
            st.push(e);
            se=ends;
            while(true){
                u=pa[se];
                se=paS[se];
                st.push(u);
                if(u==s)break;
            }
            while(!st.empty()){
                printf("%d ",st.top());
                st.pop();
            }
        }
    }else {
        printf("%d %d",s,e);
    }



	return 0;
}

/*
Problem Statement:
Captain America and Iron Man are at WAR and the rage inside Iron Man is rising.

But Iron Man faces a problem to identify the location of Captain America.

There are N buildings situtaed adjacently to each other and Captain America can be at any building.

Iron Man has to arrange the Buildings from 1 to N is such a way that Value(i.e abs(Building Number -Position of Building))=K for every building.

Can You help Iron Man to Find The Arrangement of the Buildings?

P.S- If no arrangement exist, then print “CAPTAIN AMERICA EVADES”.

Input Format:
The first line of input contains a single integer,T, denoting the number of test cases.
Each of the T  subsequent lines contains 2 space-separated integers describing the respective N and K values for a test case. 


Output Format:
On a new line for each test case,
Print the lexicographically smallest arrangement;
If no absolute arrangement exists, print “CAPTAIN AMERICA EVADES”.

Constraints:
    1<=T<=10
    1<=N<=10^5
    0<=K<=N

Sample Input:
3
2 1
3 0
3 2

Sample Output:
2 1
1 2 3
CAPTAIN AMERICA EVADES

Explanation:
Case 1:
N=2 and K=1
Therefore the arrangement is [2,1].
Case 2:
N=3 and K=0
Therefore arrangement is [1,2,3].

INput:
2
1 2
2 3

output:
CAPTAIN AMERICA EVADES
CAPTAIN AMERICA EVADES

INput:
1
21 23

output:
CAPTAIN AMERICA EVADES

INput:
3
1 2
2 1
4 5

output:
CAPTAIN AMERICA EVADES
2 1
CAPTAIN AMERICA EVADES

INput:
1
0 1
output:
<Empty>

hint:
Problem is to arrange numbers from 1 to N in such a way that absolute value of difference of the ith number from the position of ith number in the arrangement , to be equal to a certain value K.


*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int a0 = 0; a0 < t; a0++) {
            int n = in.nextInt();
            int k = in.nextInt();
            if (k == 0) {
                for (int i = 1; i <= n; i++) {
                    System.out.print(i + " ");
                }
                System.out.println("");
            } else if (n % 2 == 0 && n % k == 0) {
                Set<Integer> s = new HashSet<Integer>();
                for (int i = 1; i <= n; i++) {
                    int val = i - k;
                    if (val <= 0) {
                        val = i + k;
                    }
                    if (!s.contains(val)) {
                        s.add(val);
                        System.out.print(val + " ");
                    } else {
                        val = i + k;
                        if (!s.contains(val)) {
                            s.add(val);
                            System.out.print(val + " ");
                        }
                    }
                }
                System.out.println("");
            } else {
                System.out.println("CAPTAIN AMERICA EVADES");
            }
        }
    }
}

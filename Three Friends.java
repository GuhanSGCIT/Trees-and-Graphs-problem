/*
There are three friends; let's call them A, B, C. They made the following statements:
    A: "I have x Rupees more than B."
    B: "I have y rupees more than C."
    C: "I have z rupees more than A."

You do not know the exact values of x,y,z . Instead, you are given their absolute values, i.e. X=|x|, Y=|y| and Z=|z|. Note that x, y, z may be negative; "having −r rupees more" is the same as "having r rupees less".

Find out if there is some way to assign amounts of money to A, B, C such that all of their statements are true.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers X , Y and Z.

Output
For each test case, print a single line containing the string "yes" if the presented scenario is possible or "no" otherwise (without quotes).

Constraints
1≤T≤1,000
1≤X,Y,Z≤1,000

Example Input
2
1 2 1
1 1 1

Example Output
yes
no

Explanation
Example 1: One possible way to satisfy all conditions is: A has 10 rupees, B has 9 rupees and C has 11 rupees. Therefore, we have x=1, y=−2, z=1.
Example 2: There is no way for all conditions to be satisfied.

input:
3
2 5 4
3 2 3
1 2 1

output:
no
no
yes

input:
2
5 4 5
2 4 8

output:
no
no

input:
5
2 5 4
6 8 9
1 2 1
2 5 6
1 1 1

output:
no
no
yes
no
no

input:
1
12 24 96

output:
no

hint:
Answer is yes if and only if ∣x∣+∣y∣+∣z∣=2∗max(∣x∣,∣y∣,∣z∣).
*/
import java.util.*;
import java.io.*; 
import java.text.*;
//Solution Credits: Taranpreet Singh
public class Main{
    //SOLUTION BEGIN
    void solve(int TC) throws Exception{
        int x =ni(), y = ni(), z = ni();
        pn(x+y+z==2*Math.max(Math.max(x,y), z)?"yes":"no");
    }
    //SOLUTION ENDS
    long mod = (long)1e9+7, IINF = (long)1e17;
    final int MAX = (int)1e6+1, INF = (int)2e9, root = 3;
    DecimalFormat df = new DecimalFormat("0.000000000000");
    double PI = 3.1415926535897932384626433832792884197169399375105820974944, eps = 1e-8;
    static boolean multipleTC = true, memory = false;
    FastReader in;PrintWriter out;
    void run() throws Exception{
        in = new FastReader();
        out = new PrintWriter(System.out);
        int T = (multipleTC)?ni():1;
        //Solution Credits: Taranpreet Singh
        for(int i = 1; i<= T; i++)solve(i);
        out.flush();
        out.close();
    }
    public static void main(String[] args) throws Exception{
        if(memory)new Thread(null, new Runnable() {public void run(){try{new Main().run();}catch(Exception e){e.printStackTrace();}}}, "1", 1 << 28).start();
        else new Main().run();
    }
    long gcd(long a, long b){return (b==0)?a:gcd(b,a%b);}
    int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
    int bit(long n){return (n==0)?0:(1+bit(n&(n-1)));}
    void p(Object o){out.print(o);}
    void pn(Object o){out.println(o);}
    void pni(Object o){out.println(o);out.flush();}
    String n(){return in.next();}
    String nln(){return in.nextLine();}
    int ni(){return Integer.parseInt(in.next());}
    long nl(){return Long.parseLong(in.next());}
    double nd(){return Double.parseDouble(in.next());}

    class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String s) throws Exception{
            br = new BufferedReader(new FileReader(s));
        }

        String next(){
            while (st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch (IOException  e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine(){
            String str = "";
            try{    
                str = br.readLine();
            }catch (IOException e){
                e.printStackTrace();
            }   
            return str;
        }
    }
}        
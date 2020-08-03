"""
It is Mr.Kanjan birthday today and he is planning to host a pooja at his home, he has invited everyone for the pooja.
All the arrangements are ready for that, but the holy symbol swastik is still to be made. Pandit ji is on his way to reach
Mr. kanjan's house and he has given Mr.kanjan a number N signifying the size of symbol. Since Ms. Khan is busy cutting her
birthday cake before pandit ji arrives. So he is asking you to make the symbol on her behalf for pooja.

timing:500millsec
level:4

Input Description:
A single integer N

Output Dexcription:
Print the swastik symbol for the given size N

Constraints
    5≤N≤99
N will be odd

Sample Input:
7

Sample Output:
*  ****
*  *
*  *
*******
   *  *
   *  *
****  *

EXPLANATION:
This is the pattern of size 7.

Input:
6

Output:
* ****
* *   
* *   
******
  *  *
**** *

Input:
17

Output:
*       *********
*       *        
*       *        
*       *        
*       *        
*       *        
*       *        
*       *        
*****************
        *       *
        *       *
        *       *
        *       *
        *       *
        *       *
        *       *
*********       *

Input:
12

Output:
*    *******
*    *      
*    *      
*    *      
*    *      
*    *      
************
     *     *
     *     *
     *     *
     *     *
*******    *

Input:
22

Output:
*         ************
*         *           
*         *           
*         *           
*         *           
*         *           
*         *           
*         *           
*         *           
*         *           
*         *           
**********************
          *          *
          *          *
          *          *
          *          *
          *          *
          *          *
          *          *
          *          *
          *          *
************         *

Code:
"""
#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int i,j;
	for(i=0;i<n;i++) { cout<<endl;
	    for(j=0;j<n;j++) {
	        if(i==0 && j==0 || i==0 && j>=n/2) {cout<<"*";}
	        else if(i<n/2 && j==0 || i<n/2 && j==(n-1)/2) {cout<<"*";}
	        else if(i==n/2) {cout<<"*";}
	        else if(i>n/2 && j==n-1 || i>n/2 && j==(n-1)/2) {cout<<"*";}
	        else if(i==n-1 && j<=n/2 || i==n-1 && j==n-1) {cout<<"*";}
	        else {cout<<" ";}
	    }
	}
	return 0;
}

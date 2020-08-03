/*
 A child needs help to learn counting. As a professional software engineer, it should be your responsibility to help others
through your software. You need to take input in digits and print the equivalent word representation for the number in American name.

 Timing:1sec
 level:6
  
Input Description:
First line denotes 'T' number of test cases
It will be followed by 'T' lines containing a whole number

Output Description:
Print 'T' lines containing equivalent word representation of the specified number in American word with all in
lowercase with delimiters as space

Constraints

    1 ≤ T ≤ 100
    1 ≤ n ≤ 10^18

Input:
1
555

Output:
five hundred fifty five

Explanation
The output is representation of 555 in American name.

Input:
2
1000
10101

Output:
one thousand
ten thousand one hundred one

Input:
1
165162

Output:
one hundred sixty five thousand one hundred sixty two

Input:
11111

Output:
eleven thousand one hundred eleven

Input:
202050010102
Output:
two hundred two billion fifty million ten thousand one hundred two

Code:
*/
#include "iostream"
    #include "string"
    using namespace std;

    int main()
    {
        string num;
        string onesName[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        string teensName[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
                               "seventeen", "eighteen", "nineteen"};
        string tensName[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        string illionName[] = { "million", "billion", "trillion", "quadrillion", "quintillion"};

        char repeat = 'n';
        int t;
        cin >> t;
        while(t--){   
        cin >> num; 

            if(num.size() == 1 && num[0] == '0'){
                cout << "zero" << endl;
                continue;
            }

            while( num.size()%3 != 0 )
                num = '0' + num;

            for( int i = 0; i < num.size(); i += 3 ){
                if( num[i] == '0' && num[i+1] == '0' && num[i+2] == '0' )
                    continue;

                if( num[i] > '0' )
                    cout << onesName[ num[i] - '0' - 1 ] << " hundred ";

                if( num[i + 1] == '0' || num[i + 1] > '1' ){
                    if( num[i + 1] > '1' ) cout << tensName[ num[i + 1] - '0' - 2 ] << " ";
                    if( num[i + 2] > '0' ) cout << onesName[ num[i + 2] - '0' - 1 ] << " ";
                }
                else
                    cout << teensName[ num[i + 2] - '0' ] << " ";

                int j = ( num.size() - i )/3;
                if( j == 2 ) cout << "thousand ";
                else if( j > 2 )
                    cout << illionName[ j - 3 ] << " ";
            }
            cout << endl; 
        }
        return 0;
     }

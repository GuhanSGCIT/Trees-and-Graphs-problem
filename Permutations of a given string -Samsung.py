"""
Given a string S. The task is to print all permutations of a given string.

timing:1sec
level:6

Input:
The first line of input contains an integer T, denoting the number of test cases. Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG

Output:
ABC ACB BAC BCA CBA CAB 
ABSG ABGS ASBG ASGB AGSB AGBS BASG BAGS BSAG BSGA BGSA BGAS SBAG SBGA SABG SAGB SGAB SGBA GBSA GBAS GSBA GSAB GASB GABS 

Explanation:
Testcase 1: Given string ABC has permutations in 6 forms as ABC, ACB, BAC, BCA, CAB and CBA .

input:
3
ABBB
ABCDE
YOU

output:
ABBB ABBB ABBB ABBB ABBB ABBB BABB BABB BBAB BBBA BBBA BBAB BBAB BBBA BABB BABB BBAB BBBA BBBA BBAB BBBA BBAB BABB BABB 
ABCDE ABCED ABDCE ABDEC ABEDC ABECD ACBDE ACBED ACDBE ACDEB ACEDB ACEBD ADCBE ADCEB ADBCE ADBEC ADEBC ADECB AECDB AECBD AEDCB AEDBC AEBDC AEBCD BACDE BACED BADCE BADEC BAEDC BAECD BCADE BCAED BCDAE BCDEA BCEDA BCEAD BDCAE BDCEA BDACE BDAEC BDEAC BDECA BECDA BECAD BEDCA BEDAC BEADC BEACD CBADE CBAED CBDAE CBDEA CBEDA CBEAD CABDE CABED CADBE CADEB CAEDB CAEBD CDABE CDAEB CDBAE CDBEA CDEBA CDEAB CEADB CEABD CEDAB CEDBA CEBDA CEBAD DBCAE DBCEA DBACE DBAEC DBEAC DBECA DCBAE DCBEA DCABE DCAEB DCEAB DCEBA DACBE DACEB DABCE DABEC DAEBC DAECB DECAB DECBA DEACB DEABC DEBAC DEBCA EBCDA EBCAD EBDCA EBDAC EBADC EBACD ECBDA ECBAD ECDBA ECDAB ECADB ECABD EDCBA EDCAB EDBCA EDBAC EDABC EDACB EACDB EACBD EADCB EADBC EABDC EABCD 
YOU YUO OYU OUY UOY UYO

input:
1
121

output:
121 112 211 211 121 112

input:
2
XYXY
XXX

output:
XYXY XYYX XXYY XXYY XYXY XYYX YXXY YXYX YXXY YXYX YYXX YYXX XYXY XYYX XXYY XXYY XYXY XYYX YYXX YYXX YXYX YXXY YXXY YXYX 
XXX XXX XXX XXX XXX XXX

input:
1
GUVI

output:
GUVI GUIV GVUI GVIU GIVU GIUV UGVI UGIV UVGI UVIG UIVG UIGV VUGI VUIG VGUI VGIU VIGU VIUG IUVG IUGV IVUG IVGU IGVU IGUV 

hint:
Generate all the permutations of the string. Terminating condition will be when the passed string is empty, in that case
the function will return an empty ArrayList. Before adding the generated string, just check if it has already been generated
before to get the distinct permutations.

"""
def toString(List): 
	return ''.join(List) 
def permute(a, l, r): 
	if l==r: 
		print (toString(a),end=" ") 
	else: 
		for i in range(l,r+1): 
			a[l], a[i] = a[i], a[l] 
			permute(a, l+1, r) 
			a[l], a[i] = a[i], a[l] # backtrack 
for i in range(int(input())):
    string = input()
    n = len(string) 
    a = list(string) 
    permute(a, 0, n-1)
    print()

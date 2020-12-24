"""
Ram Al Gorithm was reading a book about climate and oceans when he encountered the word “glaciological”. He thought it was quite curious, because it has the following interesting property: For every two letters in the word, if the first appears x times and the second appears y times, then |x - y| ≤ 1.
Ram Al was happy about this and called such words 1-good words. He also generalized the concept: He said a word was K-good if for every two letters in the word, if the first appears x times and the second appears y times, then |x - y| ≤ K.
Now, the Ram likes K-good words a lot and so was wondering: Given some word w, how many letters does he have to remove to make it K-good?

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case consists of a single line containing two things: a word w and an integer K, separated by a space.

Output
For each test case, output a single line containing a single integer: the minimum number of letters he has to remove to make the word K-good.

Constraints
    1 ≤ T ≤ 30
    1 ≤ |w| ≤ 10^5
    0 ≤ K ≤ 10^5
    w contains only lowercase English letters.

Input:
4
glaciological 1
teammate 0
possessions 3
defenselessness 3

Output:
0
0
1
2

Explanation
Example case 1. The word “glaciological” is already 1-good, so the Ram doesn't have to remove any letter.
Example case 2. Similarly, “teammate” is already 0-good.
Example case 3. The word “possessions” is 4-good. To make it 3-good, the Ram can remove the last s to make “possession”.
Example case 4. The word “defenselessness” is 4-good. To make it 3-good, Ram Al can remove an s and an e to make, for example, “defenslesness”. Note that the word doesn't have to be a valid English word.

input:
1
malayalam 2

output:
1

input:
3
india 1
Guvi 0
Geek 0 

output:
0
0
1

input:
2
Programming 3
industryexperts 2

output:
0
0

input:
4
Codekata 4
personalisedapproach 1
suggestion 1
technologies 2

output:
0
2
0
0

hint:
Remove every letter that appears <m times.
For every letter that appears >m+K times, remove just enough letters so that it appears exactly m+K times.
Let the number of removed letters be F[m].

"""
from collections import Counter
for cas in range(int(input())):
    s, k = input().strip().split()
    k = int(k)
    ct = Counter(s).values()
    print(min(sum(w if w < v else max(0,w-v-k) for w in ct) for v in ct))
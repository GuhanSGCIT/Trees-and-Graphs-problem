"""
Given an integer K and an array arr[] of N integers which contains the ids of the opened apps in a system where
arr[0] is the app currently in use
arr[1] is the app which was most recently used and
arr[N – 1] is the app which was least recently used.
The task is to print the contents of the array when the user using the system presses Alt + Tab exactly K number of times. Note that after pressing Alt + Tab key, app opening pointer will move through apps from 0th index towards right, depending upon the number of presses, so the app on which the press ends will shift to 0th index, because that will become the most recently opened app.
H 7 T 2000
Tag array

In des
First line contains integer N, size of array.
Second line contains N space separated integers, denotes array elements.
Third line contains integer K,denotes the count of times pressed.

Ot des
Print the altered order

5
3 5 2 4 1
3

4 3 5 2 1

7
5 7 2 3 4 1 6
10

3 5 7 2 4 1 6

5
3 5 2 4 1
3

1 3 5 2 4

5
3 5 2 4 1
5

3 5 2 4 1

7
3 5 2 4 1 1 1
12

1 3 5 2 4 1 1 

Exp
User want to switch to the app with id 4, it’ll become the currently active app and the previously active app (with id 3) will be the most recently used app.

Hint
Get the index of the app to which the user wants to switch i.e. appIndex = K % N. Now, the current active app will be arr[appIndex] and all the other apps in the index range [0, appIndex – 1] will have to be shifted by 1 element towards the right.
"""
#include <bits/stdc++.h> 
using namespace std; 
void mostRecentlyUsedApps(int* arr, int N, int K) 
{ 
	int app_index = 0; 
	app_index = (K % N); 
	int x = app_index, app_id = arr[app_index]; 
	while (x > 0) { 
		arr[x] = arr[--x]; 
	} 
	arr[0] = app_id; 
} 
void printArray(int* arr, int N) 
{ 
	for (int i = 0; i < N; i++) 
		cout << arr[i] << " "; 
} 
int main() 
{ 
    int sizeofarray, K;
    cin >> sizeofarray;
    int arr[sizeofarray];
    for (int i = 0; i < sizeofarray; ++i)
    {
        cin >> arr[i];
        
    }
	cin >> K; 

	mostRecentlyUsedApps(arr, sizeofarray, K); 
	printArray(arr, sizeofarray); 
	return 0; 
} 
"""
Question:
 Consider today is sunday,In a restaurant,too much crowd in the cash counter the cashier need some help to calculate the bills.
that restaurant has different recipes they are,
menu:-
oniondosa-90 rs
plaindosa-40 rs
ravadosa-75 rs
idli-10 rs
vada-5 rs
poori-30 rs
chapathi -30 rs
pongal-35 rs
tea-25 rs
coffee-35 rs
meals-75 rs

Note: Price details discripted above is without GST.You need add 5 precent of GST for the total amount of a bill.

Input Discription:
Single line consists of recipes with count as shown below.

Output Discription:
Print output as "Total Price(GST inclusive):Rs xx.x"

Testcases:
Input:
tea 2
output:
Total Price(GST inclusive):Rs  52.5

Input:
vada 2 coffee 1
output:
Total Price(GST inclusive):Rs  47.25

Input:
meals 2 ravadosa 5 vada 4 poori 7 oniondosa 4 chapathi 2
output:
Total Price(GST inclusive):Rs  1233.75

Input:
masaladosa 1
Output:
Sorry,Only recipes in the menu !

Solution:
"""
def gst(v):
    v+=v*(5/100)
    print("Total Price(GST inclusive):Rs ",v)

def total(recipe,count):
    t=0
    try:
        for i,j in zip(recipe,count):
            t+=(dictt[i]*j)
        gst(t)
    except:
        print("Sorry,Only recipes in the menu !")

dictt={"oniondosa":90,"plaindosa":40,"ravadosa":75,"idli":10,"vada":5,"poori":30,"chapathi":30,"pongal":35,"tea":25,"coffee":35,"meals":75}
l=[str(b) for b in input().split()]
recipe=[]
count=[]
for i in range(len(l)):
    if i%2==0:
        recipe.append(l[i])
    else:
        count.append(int(l[i]))
total(recipe,count)

n=input("Number: ")

'''
 AMEX ako pocinje sa 34 ili 37
 MASTERCARD 51,52,53,54,55
 VISA sa 4
'''
sum=0
for i in range(len(n)):
    if i%2==0:
      i=str(int(n[i])*2)
      for j in range(len(i)):
         sum+=int(i[j])
    else:
       sum+=int(n[i])

Valid=False
print (sum)

if sum%10==0:
    Valid=True

if Valid==True:
    if int(n[0])==4:
      print('VISA')
    elif int(n[0])==3 and int(n[1])==4 or int(n[1])==7:
      print("AMEX")
    elif int(n[0])==5 and 0< int(n[1]) <6:
      print("MASTERCARD")
else:
    print("INVALID")
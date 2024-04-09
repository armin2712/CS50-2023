# TODO

def check():

    cash=input("Change owed: ")
    try:
       n=float(cash)
       if n < 0 or n==0:
           return check()
       return n
    except:
       return check()

n=check()


sum=int(n/0.25)
n=round(n%0.25,2)
sum+=int(n/0.1)
n=round(n%0.1,2)
sum+=int(n/0.05)
n=round(n%0.05,2)
sum+=int(n/0.01)


print(sum)



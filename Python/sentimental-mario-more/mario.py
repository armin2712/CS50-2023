# TODO


n=int(input("Height: "))

if n < 1 and n > 8:
    n=int(input("Height: "))

for i in range(1,n+1):
    print(" "*(n-i),end="")
    print("#"*i,end="")
    print("  ",end="")
    print("#"*i,end="")
    print(" "*(n-i))

print()



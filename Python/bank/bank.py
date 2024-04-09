greet=input("Greeting: ").strip().lower()


if greet[0:len("hello")]=="hello":
    print(0)
elif greet[0]=="h":
     print(1)
else:
     print(100)
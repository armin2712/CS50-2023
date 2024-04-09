taqueria={
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

def menu():
 total=0
 try:
  while True:
   food_input=input("Item: ")
   food = ' '.join(word.capitalize() for word in food_input.split())
   if food in taqueria:
     total+=taqueria[food]
     print(f"Total: ${total:.2f}")
   else:
     food_input=input("Item: ")

 except EOFError:
     print("\n")
     return 0


menu()

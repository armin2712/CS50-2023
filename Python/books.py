books=[]

for i in range(3):
    book={}
    book["title"]=input("Title: ").strip().lower().capitalize()
    book["author"]=input("Author: ").strip().lower().capitalize()
    books.append(book)
    print(books)
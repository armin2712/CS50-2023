text=input("Text: ")

letters=0
word=0
sentence=0

for i in range(len(text)):
    if (text[i]).isalpha():
        letters+=1
    if text[i]==' ':
        word+=1
    if text[i]=='!' or text[i]=='?' or text[i]=='.':
        sentence+=1

word+=1

l=letters/word*100
s=sentence/word*100

index= 0.0588* l - 0.296 * s - 15.8
if index < 0:
    print ("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")
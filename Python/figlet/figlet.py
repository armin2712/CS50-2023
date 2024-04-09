from pyfiglet import Figlet
import sys
import random

figlet = Figlet()
avilable_fonts=figlet.getFonts()


argc = len(sys.argv) - 1
if argc==0:
    font=random.choice(avilable_fonts)
elif( sys.argv[1]=="-f" or sys.argv[1]=="--font"):
    font=sys.argv[2]
elif (sys.argv[1]!="-f" or sys.argv[1]!="--f"):
    sys.exit()

s=input("Input: ")


f = Figlet(font=font)
print(f.renderText(s))

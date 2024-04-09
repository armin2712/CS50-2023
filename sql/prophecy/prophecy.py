from cs50 import SQL
import csv
import sys

houses={}

db=SQL("sqlite:///prophecy.db")
with open(sys.argv[1]) as file:
    students=csv.DictReader(file)
    for row in students:
      if row['house'] not in houses:
         houses[row['house']]=row['head']
    for house,head in houses.items():
        houses=db.execute("INSERT INTO houses(house_name,head) VALUES(?,?)",house,head)

with open(sys.argv[1]) as file:
    students=csv.DictReader(file)
    for row in students:
        students=db.execute("INSERT INTO students (id,student_name) VALUES(?,?)",row['id'],row['student_name'])
        info=db.execute("INSERT INTO info (students_id,houses_id) SELECT(SELECT id FROM students WHERE student_name=?),(SELECT id FROM houses WHERE house_name=?)",row['student_name'],row['house'])

import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, jsonify
from flask_session import Session
from datetime import datetime
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd
app.jinja_env.globals.update(usd=usd)
app.jinja_env.globals.update(lookup=lookup)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    rows=db.execute("SELECT * FROM shares WHERE id=?;",session["user_id"])
    users=db.execute("SELECT * FROM users WHERE id=?;",session["user_id"])
    if rows==None:
        return render_template('index.html')
    return render_template('index.html',rows=rows, users=users)




@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method=='POST':
       symbol=request.form.get('buy')
       shares=request.form.get('shares')
       date=datetime.now()

       if lookup(symbol)==None:
           return apology('Quote doesnt exists',403)
       cash=db.execute("SELECT cash FROM users where id=?;",session["user_id"])
       stocks=lookup(symbol)
       if float(cash[0]['cash']) < float(stocks['price'])*float(shares):
           return apology('Not enough money too buy the share!', 400)

       if len(db.execute("SELECT symbol FROM shares WHERE symbol=? AND id=?",symbol,session["user_id"])) == 0:
           db.execute("INSERT INTO shares(id,symbol,shares,price) VALUES(?,?,?,?);",session["user_id"],symbol,shares,lookup(symbol)['price'])
       else:
           db.execute("UPDATE shares SET shares=shares+? WHERE id=? AND symbol=?;", int(shares),session["user_id"],symbol)
       db.execute("UPDATE users SET cash=cash-? WHERE id=?",float(stocks['price'])*float(shares),session["user_id"])
       db.execute("INSERT INTO history(id,symbol,shares,price,year,month,day,hours,minutes,seconds) VALUES(?,?,?,?,?,?,?,?,?,?)",session["user_id"],symbol,shares,float(stocks['price']),date.year,date.month,date.day,date.hour,date.minute,date.second)
       flash('Bought!')
       return redirect("/")



    elif request.method=='GET':
        return render_template('buy.html')


@app.route("/history")
@login_required
def history():
    rows=db.execute("SELECT * FROM history WHERE id=? ORDER BY history_order DESC;",session["user_id"])
    if rows==None:
        return render_template('history.html')
    return render_template('history.html',rows=rows)



@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method=='POST':
        quote=request.form.get('quote')
        stock=lookup(quote)
        if lookup(quote)==None:
            return apology('Quote doesnt exists',403)
        else:
            return render_template('quote.html',stock=stock)
    elif request.method=='GET':
        return render_template('quote.html')




@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # Forget any user_id
    session.clear()

    if request.method=='GET':
        return render_template('register.html')



    if request.method=='POST':
        if not request.form.get('username'):
            return apology('must provide username',403)
        elif not request.form.get('password'):
            return apology('must provide password',403)
        elif not request.form.get('password_again'):
            return apology('must provide password again',403)
        elif not (request.form.get('password')==request.form.get('password_again')):
            return apology('passwords dont match',403)


        name=request.form.get('username')
        password=request.form.get('password')
        password_hash=generate_password_hash(password)

        rows=db.execute("SELECT * FROM users WHERE username=?",name)

        if len(rows)!=0:
            flash('Username taken')
            return render_template('register.html')
        db.execute('INSERT INTO users(username,hash) VALUES(?,?);',name,password_hash)
        rows = db.execute("SELECT * FROM users WHERE username = ?", name)

        session["user_id"] = rows[0]["id"]

        return redirect("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
      if request.method=='GET':
          rows=db.execute("SELECT * FROM shares WHERE id=?;",session["user_id"])
          return render_template('sell.html',rows=rows)
      if request.method=='POST':
          stocks=lookup(symbol)
          date=datetime.now()
          shares=db.execute("SELECT shares FROM shares WHERE id=?;",session["user_id"])
          symbol=request.form.get('symbol')
          if int(request.form.get('shares')) > int(shares[0]['shares']):
              return apology('Too many shares',400)
          db.execute("UPDATE shares SET shares=shares-? WHERE id=? AND symbol=?;", int(request.form.get('shares')),session["user_id"],symbol)
          db.execute("DELETE FROM shares WHERE shares=0;")
          db.execute("UPDATE users SET cash=cash+? WHERE id=?",float(stocks['price'])*float(request.form.get('shares')),session["user_id"])
          db.execute("INSERT INTO history(id,symbol,shares,price,year,month,day,hours,minutes,seconds) VALUES(?,?,?,?,?,?,?,?,?,?)",session["user_id"],symbol,(int(request.form.get('shares')))*(-1),float(stocks['price']),date.year,date.month,date.day,date.hour,date.minute,date.second)
          flash('Sold!')
          return redirect("/")


@app.route("/settings",methods=["GET","POST"])
@login_required
def settings():

    if request.method =="GET":
      return  render_template('settings.html')
    elif request.method =='POST':
        password=request.form.get('password')
        newPassword=request.form.get('new_password')
        newPasswordAgain=request.form.get('new_password_again')
        rows = db.execute("SELECT * FROM users WHERE id= ?", session["user_id"])

        if not password or not newPassword or not newPasswordAgain:
            return apology("Please input all fields",400)
        if not check_password_hash(rows[0]["hash"],password):
            return apology("Password not correct!",400)

        if newPassword!=newPasswordAgain:
            return apology('New password doesnt match',400)
        db.execute("UPDATE users SET hash=? WHERE id=?",generate_password_hash(newPassword),session["user_id"])

        flash('Password successfully changed!')
        return redirect("/")




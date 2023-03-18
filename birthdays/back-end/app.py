from flask import Flask, render_template, redirect, request, url_for, session, flash, jsonify
from werkzeug.security import check_password_hash, generate_password_hash
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime
from sqlalchemy import ForeignKey



app = Flask(__name__)
app.config["SQLALCHEMY_DATABASE_URI"] = 'sqlite:///project.db'
app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = False
app.config["SECRET_KEY"] = "you-will-never-guess"

db = SQLAlchemy(app)





app.config["DEBUG"] = True
app.config["TEMPLATES_AUTO_RELOAD"]=True



class users(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(80), nullable=False)
    password = db.Column(db.String(80), nullable=False, unique=True)
    date_added = db.Column(db.DateTime, default=datetime.utcnow)


class transactions(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    Type = db.db.Column(db.String(80), nullable=False)
    category = db.Column(db.String(80), nullable=False)
    amount = db.Column(db.Integer, nullable=False)
    date_added = db.Column(db.DateTime, default=datetime.utcnow)
    user_id = db.Column(db.Integer, ForeignKey('users.id'), nullable=False)



    



    

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/signup", methods=["POST", "GET"])
def signup():

    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            flash("Fill the required details.")
            return render_template("signup.html")



        # Ensure password was submitted
        elif not request.form.get("password"):
            flash("Fill the required details.")
            return render_template("signup.html")

        elif request.form.get("password")!=request.form.get("confirmation"):
            flash("Passwords dont match")
            return render_template("signup.html")

        else:
            hash = generate_password_hash(request.form.get("password"))
            user = users.query.filter_by(username=request.form.get("username")).first()
            if user is None:
                user = users(username=request.form.get("username"), password=hash)
                db.session.add(user)
                db.session.commit()
                return redirect("/login")

    else:
        return render_template("signup.html")


@app.route("/login", methods=["POST", "GET"])
def login():
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            flash("Fill the required details.")
            return render_template("login.html")

        # Ensure password was submitted
        elif not request.form.get("password"):
            flash("Fill the required details.")
            return render_template("login.html")

        # Query database for username
        rows = users.query.filter_by(username=request.form.get("username")).first()

        # Ensure username exists and password is correct
        if not rows or not check_password_hash(rows.password, request.form.get("password")):
            flash("Please check your login details and try again.")
            return render_template("login.html")

        # Remember which user has logged in
        else:

            session["id"] = rows.id
            current_session_id = session.get("id")
            user = db.session.query(users).filter_by(id=current_session_id).first()
            name = user.username if user else None

        # Redirect user to home page
            return render_template("homepage.html", name=name)

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")




@app.route("/homepage", methods=["POST", "GET"])
def homepage():
    current_session_id = session.get("id")
    user = db.session.query(users).filter_by(id=current_session_id).first()
    name = user.username if user else None


    return render_template("homepage.html",name=name)


@app.route("/add_expense", methods=["POST", "GET"])
def add_expense():
    current_session_id = session.get("id")
    user = db.session.query(users).filter_by(id=current_session_id).first()
    name = user.username if user else None

    if request.method == "POST":
        if not request.form.get("type") or not request.form.get("category") or not request.form.get("amount"):
            return render_template("add_expense.html",name=name)
        else:
            details = transactions(Type=request.form.get("type"), category=request.form.get("category"), amount=request.form.get("amount"), user_id=current_session_id)
            db.session.add(details)
            db.session.commit()
            return redirect(url_for("history", name=name))    
        
    else:
        return render_template("add_expense.html",name=name)


@app.route("/history", methods=["POST", "GET"])
def history():
    current_session_id = session.get("id")
    user = db.session.query(users).filter_by(id=current_session_id).first()
    name = user.username if user else None

    profile_1 = transactions.query.filter_by(user_id=current_session_id).all()  
    return render_template("history.html", name=name, profile_1=profile_1)        


@app.route("/delete/<int:entry_id>")
def delete(entry_id):
    entry = transactions.query.get_or_404(int(entry_id))
    db.session.delete(entry)
    db.session.commit()
    return redirect(url_for("history"))

@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")    

 
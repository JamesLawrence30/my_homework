'''
Title: EE551 Final Project
Author: James Lawrence
Cite: https://github.com/dcbriccetti/python-lessons/tree/master/Web/flask/gmap
Cite: https://developers.google.com/maps/documentation/javascript/


A Web application that shows Google Maps around schools, using
the Flask framework, and the Google Maps API.
'''
from flask import Flask, render_template, request, redirect
import requests
app = Flask(__name__)

"""
class School:
    def __init__(self, key, name, lat, lng):
        self.key  = key
        self.name = name
        self.lat  = lat
        self.lng  = lng

schools = (
    School('hv',      'Happy Valley Elementary',   37.9045286, -122.1445772),
    School('stan', 'Stanley Middle',            37.8884474, -122.1155922),
    School('wci',     'Walnut Creek Intermediate', 37.9093673, -122.0580063)
)
schools_by_key = {school.key: school for school in schools}
"""

@app.route("/")
def index():
    #return render_template('index.html', schools=schools)
    return render_template('index.html')

@app.route("/school")
def show_school():
    #first_school = schools_by_key.get(request.args['first_school_code'])
    #second_school = schools_by_key.get(request.args['second_school_code'])
    work_data = requests.get("https://maps.googleapis.com/maps/api/geocode/json?key=AIzaSyAQ5gStIZnEdlzyzu_h1gu1G5RWwFk0w54&address="+request.args['work_addr']+", New York, NY").json()
    life_data = requests.get("https://maps.googleapis.com/maps/api/geocode/json?key=AIzaSyAQ5gStIZnEdlzyzu_h1gu1G5RWwFk0w54&address="+request.args['life_addr']+", New York, NY").json()
    work = work_data["results"][0]["geometry"]["location"]
    life = life_data["results"][0]["geometry"]["location"]

    """
    if first_school and second_school:
        return render_template('map.html', work=work, life=life)
    else:
        return redirect("/") # School not found, stay on entry page
    """
    return render_template('map.html', work=work, life=life)

app.run(host='localhost', debug=True)

# http://localhost:5000/school?schoolcode=abc

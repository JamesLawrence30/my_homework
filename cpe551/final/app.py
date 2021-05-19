'''
Title: EE551 Final Project
Author: James Lawrence
Cite: https://github.com/dcbriccetti/python-lessons/tree/master/Web/flask/gmap
Cite: https://developers.google.com/maps/documentation/javascript/
'''

# Imports
from flask import Flask, render_template, request, redirect
import requests

# Create Flask app
app = Flask(__name__)

# Base route
@app.route("/")
def index():
    # Get addresses from form
    return render_template('index.html')

# Google Map display
@app.route("/map")
def show_map():

    # Addresses from form (index.html)
    address = {
        "me" : request.args['my_addr']+", New York, NY",
        "friend" : request.args['friend_addr']+", New York, NY"
    }

    # Google Geocoding API convert address to coordinate
    my_data = requests.get("https://maps.googleapis.com/maps/api/geocode/json?key=AIzaSyAQ5gStIZnEdlzyzu_h1gu1G5RWwFk0w54&address="+address["me"]).json()
    friend_data = requests.get("https://maps.googleapis.com/maps/api/geocode/json?key=AIzaSyAQ5gStIZnEdlzyzu_h1gu1G5RWwFk0w54&address="+address["friend"]).json()
    
    # Grab coordinate from Geocoding API response
    me = my_data["results"][0]["geometry"]["location"]
    friend = friend_data["results"][0]["geometry"]["location"]

    # Show data on map page (map.html)
    return render_template('map.html', me=me, friend=friend, address=address)

# Runs flask on http://localhost:5000/
app.run(host='localhost', debug=True)
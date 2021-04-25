/*
  Author (group): James Lawrence & Brittany DiFede
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;


// put your Vec3d implementation here
class Vec3d {
private:
  double x, y, z;

public:
  Vec3d() {}
  Vec3d(double _x, double _y) : x(_x), y(_y), z(0) {}

  friend ostream& operator <<(ostream& s, Vec3d vec) {
    return s << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
  }

  friend Vec3d operator -(Vec3d left, Vec3d right) {
    return Vec3d(left.x - right.x, left.y - right.y);
  }

  friend Vec3d operator +(Vec3d left, Vec3d right) {
    return Vec3d(left.x + right.x, left.y + right.y);
  }

  friend Vec3d operator *(double left, Vec3d right) {
    return Vec3d(left * right.x, left * right.y);
  }

  friend Vec3d operator *(Vec3d left, double right) {
    return Vec3d(left.x * right, left.y * right);
  }

  double mag() {
    return sqrt( pow(x,2) + pow(y,2) + pow(z,2) );
  }

  double magsq() {
    return pow(x,2) + pow(y,2) + pow(z,2);
  }

  static void setAccleration(Vec3d& aVec, float a, float r, Vec3d dpos) {
    /*
     ax = a * dpos.x/r, ay = a * dpos.y/r, az = a * dpos.z/r
     r = magnitude of dpos.
    */
    aVec.x = a * dpos.x/r;
    aVec.y = a * dpos.y/r;
  }
};


// put your Body implementation here
class Body {
private:
  string name;
  double mass;   // mass of the body
  double radius; // size of the body (assumes spherical)
  Vec3d pos;     // pos = (x,y,0) ignore z for now. x,y should be based on orbital radius
  Vec3d v;       // velocity = distance around the sun / orbital period in seconds
  Vec3d a;       // acceleration = gravitational acceleration due to all other bodies

public:
    Body() : name(), pos(), v(), a() {}
  
  friend ostream& operator <<(ostream& s, const Body& b) {
    return s << "Name: " << b.name <<  "\t" << setw(12) << "Mass: " << b.mass << "\t" << setw(12) << "Radius: " << b.radius << "\t" << setw(12) << "Pos: " << b.pos   << "\t" << setw(12) << "V: " << b.v << "\t" << setw(12) << "A: " << b.a << endl;
  }

  friend istream& operator >>(istream& s, Body&  b) {

    string garbage;
    double diam, per, aph, orbPeriod;
    double t, x, y;
    char buf[1024];

  // read in the body
  // assign name, mass, and radius to body
  s.getline(buf, sizeof(buf));
  istringstream line(buf);
  line >> b.name >> garbage >> b.mass >> diam >> per >> aph >> orbPeriod; // >> b.rotationalPeriod >> b.axialTilt;
  b.radius = diam/2; // radius of body

  // compute average distance of each body from sun (average of perihelion and aphelion)
  // pick t = a random number from 0 to 2*pi
  // calculate x,y = r cos t, r sin t
  // assign pos vector (x,y, 0) to body
  t = rand() % (int)(2.0*M_PI + 1.0);
  x = ((per+aph)/2) * cos(t); // orbit radius
  y = ((per+aph)/2) * sin(t); // orbit radius
  b.pos = Vec3d(x,y);

  // calculate V
  // pretend all orbits are circular
  // calculate the length of the circular path around the sun 2*pi * r
  // look up time it takes to orbit
  // convert to meters and seconds
  // v = distance around the sun / orbital period in seconds
  // assign velocity vector to body --> ( Xdistance/orbPer , Ydistance/orbPer , 0 )
  if (b.name == "Sun") { b.v = Vec3d(0,0); } // don't let sun have nan values for velocity
  else { b.v = Vec3d( (2*M_PI*x)/(orbPeriod*86400) , (2*M_PI*y)/(orbPeriod*86400) ); }

  return s;
  }

  static void setPosition(vector<Body>& bodies, int dt) {
    for(auto& b : bodies){
      b.pos = b.pos + b.v * dt + 0.5 * b.a * dt*dt;
    }
  }

  static void setVelocity(vector<Body>& bodies, int dt) {
    for(auto& b : bodies){
      b.v = b.v + b.a * dt;
    }
  }

  // Set acceleration of Bodies. Do not need object to use static.
  static void setAccleration(vector<Body>& bodies) { // Reference vector of bodies from solarsystem

    Vec3d dpos;
    double a, r, rsq;
    double G = 6.667 * pow(10, -11);

    /*
         for each body i
           set acceleration of body i = 0
           for each body j
             add acceleration of body j on i unless j == i
           end
         end
    */
    for(int i = 0; i < bodies.size(); i++) {
      bodies[i].a = Vec3d(0,0);
      for(int j = 0; j < bodies.size(); j++) {
        if(bodies[i].name != bodies[j].name) {
          /*
           a = Gm2/rsq,   rsq = (pos2 - pos).magsq()    (magnitude squared)

           To calculate the vector acceleration, you must break down a into components
           dpos = (pos2 - pos).normalize   (compute a unit vector in the direction of body2)
          */

          // Operations in Vec3d class
          dpos = bodies[j].pos - bodies[i].pos;
          r = dpos.mag();
          rsq = dpos.magsq();

          a = G*bodies[j].mass / rsq;

          // Add each acceleration of a bodyJ onto bodyI to the acceleration of bodyI
          Vec3d::setAccleration(bodies[i].a, a, r, dpos);
        }
      }
    }
  }
};


// This week SolarSystem implementation
class SolarSystem {
private:
  vector<Body> bodies;
public:
  SolarSystem(string fileName) {
    ifstream solarsystem(fileName);
    char buf[1024];
    solarsystem.getline(buf, sizeof(buf)); // throw out first line

    Body sun, mercury, venus, earth;
    solarsystem >> sun >> mercury >> venus >> earth;
    bodies.push_back(sun);
    bodies.push_back(mercury);
    bodies.push_back(venus);
    bodies.push_back(earth);
  }

  friend ostream& operator <<(ostream& stream, const SolarSystem& s) {
    return stream << s.bodies[0] << s.bodies[1] << s.bodies[2] << s.bodies[3];
  }

  void stepForward(int dt) {
    Body::setPosition(bodies, dt);
    Body::setVelocity(bodies, dt);
    Body::setAccleration(bodies);
  }
};

int main() {
	/*
	1. read in the solar system from the file
  2. Your SolarSystem class should have a list (vector) of Body objects
  3. for each row in the file, add a body. Calculate the initial position for 
     each body as last week. Note that for now we will not be giving you moons
     because they orbit not the sun but other planets. This will be added later.

  4. Each body should calculate the acceleration due to the gravitational pull
     of all the others bodies. This requires vector math, which you should write
     in Vec3d.
     For any body m, the accelation due to another body m2 is:

     a = Gm2/rsq,   rsq = (pos2 - pos).magsq()    (magnitude squared)
     G = universal gravitational constant 6.667E-11

     To calculate the vector acceleration, you must break down a into components
     dpos = (pos2 - pos).normalize
     (compute a unit vector in the direction of body2)

     ax = a * dpos.x/r, ay = a * dpos.y/r, az = a * dpos.z/r

     r = magnitude of dpos.

		 If you can do this calculation within Vec3d, it is a generically useful
		 one but you can also just compute it in Body if you want.

		 Sum up all accelerations.

		 for each body i
       set acceleration of body i = 0
		   for each body j
         add acceleration of body j on i unless j == i
       end
     end

     when you have the acceleration of all bodies, step forward in time for a timestep dt with:

    for each body b
     b.pos = b.pos + b.v * dt + 0.5 * b.a * dt*dt
     b.v = b.v + b.a * dt;

    dt is delta time (double precision) and should not be huge. 
    Start with 1000 seconds and see what happens. If 
    one body is in a sharply changing orbit, dt may have to be reduced.
    For the above to work you will have to implement some operators in Vec3d.


    v^2/r = a
		v = sqrt(ar)
	*/
  SolarSystem s("solarsystem.dat");
	cout << s << "=========\n\n\n"; // print the solar system at load time

	for (int i = 0; i < 31556; i++) {
  	s.stepForward(1000); // step forward in time by 1000 seconds
	}

	// the loop should step forward in time by about a year. We are simplifying
	// the orbit to a circle, so the numbers will be off a bit.
	cout << s << "=========\n\n\n"; // print the solar system after the year
}
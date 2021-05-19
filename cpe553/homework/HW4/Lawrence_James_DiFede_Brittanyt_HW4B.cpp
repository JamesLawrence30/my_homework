/*
	Author: James Lawrence & Brittany DiFede (partners)
*/

#include <time.h>
#include <iostream>
#include <cmath> // trunc

using namespace std;

class JulianDate {
private:
	static int EPOCH;
	int mon, day, year, hour, min, second;
	double jday; // number of days since epoch

public:
	// Default constructor
    JulianDate() {
		time_t result = time(nullptr); // get current time
		tm* now = localtime(&result); // create current Julian Date

		year = now->tm_year + 1900; // Set years to Gregorian
		mon = now->tm_mon + 1; // Set months to Gregorian
		day = now->tm_mday;
		hour = now->tm_hour - 5; // Set hours to EST (UTC−05:00)
        min = now->tm_min;
		second = now->tm_sec;

		setJDate(year, mon, day, hour, min, second);
		}

	// Custom constructors
    JulianDate(int year, int month, int day, int hour, int minute, int second) :
		year(year), mon(month), day(day), hour(hour), min(minute), second(second) {

		setJDate(year, mon, day, hour, min, second);
		}
	
	JulianDate(double jdate) : jday(jdate) {
		gDate();
		gTime();
	}
	
	void gDate() {
		int noDecimal = trunc(jday);

		double year = noDecimal/365; // not accounting for leap year right now
		this->year = trunc(year);
		
		double sumDays = year - trunc(year);
		sumDays = sumDays*365;
		int completedMonths = trunc(sumDays/30.5);
		this->mon = completedMonths + 1; // current month is completed months + 1

		this->day = gDay(completedMonths, sumDays);
	}

	// Obtain day of month given past months and total days
	double gDay(int pastMonths, double totalDays) {

		for ( int completedMonths = pastMonths; completedMonths > 0; completedMonths--) {
			if (completedMonths <= 7) {
				if (completedMonths == 2) {
					// Throw out: 31 days from January, 28 days from February
					totalDays - 31 - 28; // 
				}
				else if (completedMonths % 2 == 0) {
					// Throw out: 31 days from each odd month, 28 days from February, and 30 days from each even month except February
					totalDays - 31*(completedMonths/2) - 28 - (30*(completedMonths/2 - 1));
				}
				else {  // completedMonths % 2 = 1
					// 31 days
					totalDays - 31*((completedMonths+1)/2) - 28 - (30*(((completedMonths-1)/2)-1));
				}
			}
			
			else { // completedMonths >= 8 = min 243 days completed
				if (completedMonths == 8) {
					totalDays - 243;
				}
				else if (completedMonths == 9) {
					totalDays - 243 - 30;
				}
				else if (completedMonths == 11) {
					totalDays - 243 - 31 - 2*30;
				}
				else if (completedMonths % 2 == 0) {
					totalDays - 243 - 31*((completedMonths-8)/2) - (30*((completedMonths-8)/2));
				}
			}
		}

		//cout << "Past months: " << pastMonths << ", Days in past months: " << runningSumDays << endl;
		return (double)totalDays;
	}

	void gTime() {
		double decimal = jday - trunc(jday);

		double gHour = decimal*24;

		double gMin = gHour - trunc(gHour);
		gMin = gMin*60;

		double gSec = gMin - trunc(gMin);
		gSec = gSec*60;
		
		this->hour = trunc(gHour);
		this->min = trunc(gMin);
		this->second = trunc(gSec);
	}
	
	// Calculate years portion of jday
    double jYears(int year) {
    	int totalYears = year - EPOCH;
    	int LeapYearAdjustedDays = 365*(totalYears) + totalYears/4 - totalYears/100 + totalYears/400;

    	//cout << "Year: " << year << ", Days in past " << totalYears << " years: " << LeapYearAdjustedDays << endl;
        return LeapYearAdjustedDays;
    }

	// Calculate months portion of jday
	double jMonths(int pastMonths) {
		//cout << "Month: " << pastMonths;
		int runningSumDays = 0;

		for ( int remainingMonths = pastMonths; remainingMonths > 0; remainingMonths--) {
			if (remainingMonths <= 7) {
				if (remainingMonths == 2) {
					// 28 days
					runningSumDays += 28;
				}
				else if (remainingMonths % 2 == 0) {
					// 30 days
					runningSumDays += 30;
				}
				else {  // remainingMonths % 2 = 1
					// 31 days
					runningSumDays += 31;
				}
			}
			
			else { // remainingMonths > 7
				if (remainingMonths % 2 == 0) {
					// 31 days
                    runningSumDays += 31;
				}
				else { // remainingMonths % 2 == 1
					//30 days
                    runningSumDays += 30;
				}
			}
		}

		//cout << "Past months: " << pastMonths << ", Days in past months: " << runningSumDays << endl;
		return (double)runningSumDays;
	}

	double jDays(int pastDays) {
		//cout << "Past days: " << pastDays << endl;

		return (double)pastDays;
	}

	double jHours(int pastHours) {
		if (pastHours == 0) {
			return 0.0;
		}
		else {
			double pastDays = (double)pastHours / 24;
			//cout << "Past hours: " << pastHours << ", Days in past hours: " << pastDays << endl;
		
			return pastDays;
		}		
	}

	double jMins(int pastMinutes) {
		if (pastMinutes == 0) {
			return 0.0;
		}
		else {
			double pastDays = (double)pastMinutes / (24*60);
			//cout << "Past minutes: " << pastMinutes << ", Days in past minutes: " << pastDays << endl;

			return pastDays;
		}
	}

	double jSec(int pastSeconds) {
		if (pastSeconds == 0) {
			return 0.0;
		}
		else {
			double pastDays = (double)pastSeconds / (24*60*60);
			//cout << "Past seconds: " << pastSeconds << ", Days in past minutes: " << pastDays << endl;
			
			return pastDays;
		}
	}


	// Set the Julian Date given: year, mon, day, hour, min, second
	void setJDate(int year, int month, int day, int hour, int minute, int second) {

		jday =( jYears(year) ) // years (represented in seconds) since EPOCH , given current year
			+ ( jMonths(mon - 1) ) // months since beginning of year (represented in seconds), given full months past
			+ ( jDays(day - 1)   ) // days since beginning of month (represented in seconds), given full days past
			+ ( jHours(hour) ) // hours since beginning of day (represented in seconds)
			+ ( jMins(min)   ) // minutes since beginning of hour (respresented in seconds)
			+ ( jSec(second) ); // seconds since beginning of minute
	}

	// Return the raw Julian Date in seconds
	double getJDate() { return jday; }

	// Return private ints for user to read
	int getYear() { return year;}
    int getMonth() { return mon; }
    int getDay() { return day; }
	int getHour() { return hour; }
    int getMin() { return min; }
    int getSec() { return second; }

	friend double operator -(JulianDate left, JulianDate right) {
		return left.jday - right.jday;
	}

    friend JulianDate operator +(JulianDate left, double right) {
		return JulianDate(left.jday + right);
    }

    friend ostream& operator <<(ostream& s, JulianDate d) {
        return s << d.jday << endl;
    }
};

/*
	how many days in a year? 365
	leap year: if year MOD 4 == 0 LEAP EXCEPT
	           if year MOD 100 == 0 NOT LEAP YEAR Except
						 if year MOD 400 == 0 LEAP
Leap years:
 NO 1900 
 YES 1904
 YES 1908
 YES 2000
 NO 2100
 YES 2400
    days since EPOCH = 365 * (year - 2000) + years/4 - ....
2018 - 2000 = 18
seconds in a day = 24*60*60 = 86400
hh:mm:ss     
00:00:00  0.0
12:00:00  0.5
18*365+18/4 - 18/100 + 18/400
18*365+4 = 6574
6574.041666666 --> Jan 1, 2018, 01:00:00
http://aa.usno.navy.mil/faq/docs/JD_Formula.php
http://www.math.harvard.edu/~knill/3dprinter/exhibits/bc/Meeus1988.pdf
 */



int JulianDate::EPOCH = 2000; // Jan.1 2000, 00:00:00 = 0

int main() {
	JulianDate newyear(2018, 1, 1, 0,0,0); // how many days since day 0? dy = (2018 - 2000) * 365
	JulianDate valentine(2018, 2, 14, 12,0,0); // 0.5
	JulianDate today; // get it from the system time: time(nullptr)
	                  // localtime

	double days = valentine - newyear;
	JulianDate due = today + 7;
	cout << due << '\n';

	cout << "\nyear: " << due.getYear()
			 << "\nmonth: " << due.getMonth()
			 << "\nday: " << due.getDay()
			 << "\nhour: " << due.getHour()
			 << "\nmin: " << due.getMin()
			 << "\nsec: " << due.getSec() << '\n';
	JulianDate d1(2019, 1, 1, 0,0,0);
	for (int i = 0; i < 100; i++)
		cout << d1 + i;

}

		
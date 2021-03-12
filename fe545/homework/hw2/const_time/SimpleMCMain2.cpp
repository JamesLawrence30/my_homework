//
//
//	                	SimpleMCMain2.cpp
//
//     
// 

/*
requires 
         PayOff1.cpp
         Random1.cpp, 
         SimpleMC.cpp, 
*/

#include "SimpleMC.h"
#include "iostream"
using namespace std;

int main()
{

	double Expiry;
	double StrikeArr[2] = {0.0,0.0}; //initialize array for strikes
	double Spot; 
	double Vol; 
	double r; 
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter strike (Upper then Lower)\n";
	cin >> StrikeArr[0]; //first entry set to first position of array
	cin >> StrikeArr[1]; //second entry set to second position of array

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nr\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

    PayOff callPayOff(StrikeArr, PayOff::call);
    PayOff putPayOff(StrikeArr, PayOff::put);
	PayOff doubleDigitalPayOff(StrikeArr, PayOff::doubleDigital); //my new PayOff object

	double resultCall = SimpleMonteCarlo2(callPayOff,
                                          Expiry,                                           
							              Spot, 
							              Vol, 
							              r, 
						                  NumberOfPaths);
	
    double resultPut = SimpleMonteCarlo2(putPayOff,
                                         Expiry,                                           
							             Spot, 
							             Vol, 
							             r, 
						                 NumberOfPaths);

	double resultDoubleDigital = SimpleMonteCarlo2(doubleDigitalPayOff, //call MonteCarlo with the new PayOff object
										Expiry,
										Spot,
										Vol,
										r,
										NumberOfPaths);


	cout << "\nThe prices are:\n";
	cout << resultDoubleDigital << " for the double digital option\n";
	cout << resultCall << " for the call (using upper strike)\n";
	cout << resultPut << " for the put (using upper strike)\n";
										

    double tmp;
    cin >> tmp;

	return 0;

}

/*
 *
 * Copyright (c) 2002
 * Mark Joshi
 *
 * Permission to use, copy, modify, distribute and sell this
 * software for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * Mark Joshi makes no representations about the
 * suitability of this software for any purpose. It is provided
 * "as is" without express or implied warranty.
*/


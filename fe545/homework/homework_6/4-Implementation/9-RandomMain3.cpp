//
//
//		RandomMain3.cpp
//
//       
//
/*
    uses source files           02/04/20_10:23 pm
    AntiThetic.cpp              copied in from   Lecture6\3-AntiThetic\6-AntiThetic.cpp
    Arrays.cpp,                 copied in from   Lecture6\0-Arrays\0.2-Arrays.cpp
    ConvergenceTable.cpp,       copied in from   Lecture5\code\3-Convergence_Table\ConvergenceTable.cpp
    MCStatistics.cpp            copied in from   Lecture5\code\3-Convergence_Table\MCStatistics.cpp 
    Normals.cpp                 copied in from   Lecture6\0.1-Normals\Normals.cpp 
    Parameters.cpp,             copied in from   Lecture5\code\3-Convergence_Table\Parameters.cpp
    ParkMiller.cpp              copied in from   Lecture6\2-LCG\4-ParkMiller.cpp
    PayOff3.cpp,                copied in from   Lecture5\code\3-Convergence_Table\PayOff3.cpp
    PayOffBridge.cpp,           copied in from   Lecture5\code\3-Convergence_Table\PayOffBridge.cpp
    Random2.cpp,                copied in from   Lecture6\1-Base Random\2-Random2.cpp"
    SimpleMC8.cpp               renamed from 8-SimpleMC8
    Vanilla3.cpp,               copied in from   Lecture5\code\1-StatisticsMC\Vanilla3.cpp
  */
#include "SimpleMC8.h"
#include "ParkMiller.h"
#include "iostream"
using namespace std;
#include "Vanilla3.h"
#include "MCStatistics.h"
#include "ConvergenceTable.h"
#include "AntiThetic.h"

int main()
{

	double Expiry;
	double Strike; 
	double Spot; 
	double Vol; 
	double r; 
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nStrike\n";
	cin >> Strike;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nr\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);

    VanillaOption theOption(thePayOff, Expiry);

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);

    RandomParkMiller generator(1);
  
    AntiThetic GenTwo(generator);

	SimpleMonteCarlo6(theOption,
                                      Spot, 
                                      VolParam,
                                      rParam,
                                      NumberOfPaths,
                                      gathererTwo,
									  GenTwo);
                                      //generator);

    vector<vector<double> > results =gathererTwo.GetResultsSoFar();

	cout <<"\nFor the call price the results are \n";
    for (unsigned long i=0; i < results.size(); i++)
    {
        for (unsigned long j=0; j < results[i].size(); j++)
            cout << results[i][j] << " ";

        cout << "\n";
    }
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


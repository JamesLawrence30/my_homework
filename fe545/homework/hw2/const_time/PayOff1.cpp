//
//
//
//                  PayOff1.cpp
//
//

#include "PayOff1.h"
#include "MinMax.h"

PayOff::PayOff(double Strike_[], OptionType TheOptionsType_) //Strike is now an array
:
	TheOptionsType(TheOptionsType_)
{
	Strike[0] = Strike_[0]; //first value of StrikeArr set to first value PayOff's private Strike[]
	Strike[1] = Strike_[1]; //second value of StrikeArr set to second value of PayOff's private Strike[]
}

double PayOff::operator ()(double spot) const
{
    switch (TheOptionsType)
    {
    case call : 
        return max(spot-Strike[0],0.0);

    case put:
        return max(Strike[0]-spot,0.0);

	case doubleDigital:
		if (spot >= Strike[0] || spot <= Strike[1]) {
			//payoff 0 if spot outside bounds of strikes
			return 0.0;
		}
		else {
			return 1.0; //payoff 1 when inside bounds of strikes
		}
		return 99999.0;

    default: 
        throw("unknown option type found.");

    }
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


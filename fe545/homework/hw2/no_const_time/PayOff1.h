//
//
//
//
//                               PayOff1.h
//
//
//


#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff
{

public:

    enum  OptionType {call, put, doubleDigital};
    PayOff(double Strike_[], OptionType TheOptionsType_);
    double operator()(double Spot);

private:
    
	double Strike[2] = { 0.0,0.0 }; //initialize private array member for Strike prices {upper, lower}
    OptionType TheOptionsType;

};

#endif

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


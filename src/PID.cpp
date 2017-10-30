#include "PID.h"
#include<iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpf, double Kif, double Kdf) {

	Kp=Kpf;
	Ki=Kif;
	Kd=Kdf;

  	p_error=0;
  	i_error=0;
  	d_error=0;

  	counter=1;

}

void PID::UpdateError(double cte) {

d_error=cte-p_error;
p_error=cte;
i_error=p_error+p_error/counter;

// i_error+=p_error;

counter=counter+1;


}

double PID::TotalError() {

	return sigmoid(-Kp * p_error - Kd * d_error - Ki * i_error);
}

#include <math.h>

double PID::sigmoid(const double value,
                    const double lower,
                    const double upper)
{
    return (upper - lower)/(1 + exp(-value)) + lower;
}
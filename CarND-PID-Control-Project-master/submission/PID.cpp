#include "PID.h"
#include <iostream>
#include <math.h>
using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    //std::cout<<"PID Init\n";
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->p_error = 0.0;
    this->i_error = 0.0;
    this->d_error = 0.0;
    this->total_square_error = 0.0;
    this->n = 1;
}

void PID::init_wo_err(double p[]) {
    //std::cout<<"init_wo_err\n";
    this->Kp = p[0];
    this->Ki = p[1];
    this->Kd = p[2];
}
void PID::UpdateError(double cte) {
    //std::cout<<"UpdateError\n";
    total_square_error += cte * cte;
    double average_error = total_square_error / n;
    cout << n-1 << ";" << average_error << ";" << cte << endl;
    n++;

    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    //std::cout<<"TotalError\n";
    double total_error= (this->Kp * this->p_error + this->Ki * this->i_error + this->Kd 	* this->d_error);
    //if (fabs(total_error) < 0.0001) {
	//total_error = 0.0001;
	//}	
	// above is attemped fir for twiddle problem
    return total_error;
}

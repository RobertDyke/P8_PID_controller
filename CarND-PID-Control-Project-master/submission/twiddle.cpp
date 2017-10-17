#include "twiddle.h"
#include <math.h>

Twiddle::Twiddle() {}

Twiddle::~Twiddle() {}

void Twiddle::Init(PID pid, double cte){
        //std::cout<<"Twiddle init\n";
   	this->pid = pid;
   	this->cte = cte;
}

void Twiddle::twiddle(double *p, double tol = 0.0005){
        //std::cout<<"twiddle\n";
	double dp[3] = {1.0,1.0,1.0};
	p[0] = 0.0;
	p[1] = 0.0;
	p[2] = 0.0;
	double sum_dp = dp[0] + dp[1] + dp[2];
	double best_err = 1.0;//try initializing it to 1 to prevent strting out at 0.0
	//best_err = fabs(pid.TotalError());
	
	double tw_err = 0.0;
	
	pid.Init(p[0],p[1],p[2]);

	while(sum_dp > tol){
                //std::cout<<"2 sum_dp = "<<sum_dp<<" tol = "<<tol<<"\n";

		for(int i = 0;i<3;i++){
			std::cout<<"i = "<<i<<"\n";
			std::cout<<"A p[0] = "<<p[0]<<" p[1] = "<<p[1]<<" p[2] = "<<p[2]<<"\n";
			p[i] += dp[i];
                	pid.init_wo_err(p);			
			pid.UpdateError(cte);			
			tw_err = fabs(pid.TotalError());
			
			std::cout<<"tw_err = "<<tw_err<<"  best_err = "<<best_err<<"\n";
			if (tw_err < best_err){
				//std::cout<<"T - 2\n";
				best_err = tw_err;
				dp[i] *= 1.1;
				
			}else{
				//std::cout<<"T - 3\n";
				p[i] -= 2 * dp[i];
				pid.init_wo_err(p);
				pid.UpdateError(cte);
				tw_err = fabs(pid.TotalError());
				std::cout<<"2 tw_err = "<<tw_err<<"  best_err = "<<best_err<<"\n";
				if(tw_err < best_err){
					//std::cout<<"T - 4\n";
					best_err = tw_err;
					dp[i] *= 1.1;
					
				} else {	
					//std::cout<<"T - 5\n"					
					p[i] += dp[i];
					dp[i] *= 0.9;	
//std::cout<<"D p[0] = "<<p[0]<<" p[1] = "<<p[1]<<" p[2] = "<<p[2]<<"\n";				
				}
			}
			//std::cout<<"dp[0] = "<<dp[0]<<" dp[1] = "<<dp[1]<<" dp[2] = "<<dp[2]<<"\n";
			std::cout<<"J p[0] = "<<p[0]<<" p[1] = "<<p[1]<<" p[2] = "<<p[2]<<"\n";
		}
		sum_dp = dp[0] + dp[1] + dp[2];
		std::cout<<"dp[0] = "<<dp[0]<<" dp[1] = "<<dp[1]<<" dp[2] = "<<dp[2]<<"\n";
		std::cout<<"sum_dp = "<<sum_dp<<" tol = "<<tol<<"\n";

	}
	std::cout<<"***************************************************************\n";
        std::cout<<"p[0] = "<<p[0]<<" p[1] = "<<p[1]<<" p[2] = "<<p[2]<<"\n";
	//std::cout<<"test end of twiddle\n";       
}





























			

//***********************************************
//Supersonic Flow Calculator
//Joseph Engh
//Date: 11/26/2019
//Purpose: Supersonic FLow Calculator
//Problem Statement: In supersonic flow over a 2D wedge, determine mach number and shock angles for oblique shock waves with different angle of attacks.
//***********************************************


#include <iostream>
#include <cmath> 
#include <ostream>
#include <math.h>		//LIBRARIES
using namespace std;
double g=1.4; //gamma
double pi=3.14; //pi	
double theta;
double th;
double beta;
double M1;
double M2;
double Mn1;
double Mn2;				////GLOBAL VARIABLES (contstants)


double root(double tolerance, double estimate, double (*f)(double), double(*df)(double)) {

        double h = -1 * (f(estimate) / df(estimate));
        double r = estimate + h;
        double h_previous = h;

        while (true) {
                h = -1 * (f(r) / df(r));
                r += h; // xn+1 = xn + h
                if (abs(h) <= tolerance) {
                       return r;
                }
        }
}


double f(double x) {
        return tan(theta) * (pow(M1, 2) * (g + cos(2 * x)) + 2) - (2 * (1 / tan(x))) * (pow(M1, 2) * pow(sin(x), 2) - 1);
}


double df(double x) {
        return -2 * ((2 * pow(M1, 2) * pow(cos(x), 2)) + pow((1 / sin(x)), 2) + pow(M1, 2) * (-1 + sin(2 * x) * tan(theta))); //FUNCTION ONE
}


double Fmn1(double M1, double beta){
Mn1=(M1*(sin(beta))); //FUNCTION TWO 
return Mn1;
}


double FMn2(double Mn1){
Mn2=sqrt(1 + (((g - 1) / 2) * pow(Mn1, 2))) / sqrt((g * pow(Mn1, 2)) - ((g - 1) / 2)); //FUNCTION THREE	
return Mn2;
}


double FM2 (double theta, double beta, double Mn2){ //FUNCTION FOUR 
M2=(Mn2)/(sin(beta-theta));
return M2;
}


int main ()  	//MAIN BODY
{	
 
        cout << "Enter Initial AoA Theta (degrees):  " ;
        cin >> th;
        theta = (th * pi) / 180;				//angles now in radians, will carry as radians throughout all functions
        cout << "Enter Initial Mach Number:  " ;
        cin >> M1;
        cout<<endl<<endl;
        beta = (root(0.001, theta, f, df));
       
       
Mn1=Fmn1(M1, beta);
Mn2=FMn2(Mn1);
M2=FM2(theta, beta, Mn2);

cout<<"Intermediate Values: "<<endl<<endl;
cout<<"Mn1= "<<Mn1<<endl;
cout<<"Mn2= "<<Mn2<<endl<<endl<<endl;

cout<<"Calculated Resultant Values: "<<endl;
cout<<endl;
cout<<"Final Mach Number= "<<M2<<endl;
cout <<"Beta (shock angle)= "<< beta * 180 / pi <<" degrees";	//convert beta from radians to degrees
cout<<endl<<endl<<endl<<endl<<endl<<endl;


return 0;


}





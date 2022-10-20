#include <iostream>
#include <math.h>
using namespace std;

// Realized with <3 by Italian Open Rocketry Association (ORA) - Published by Roti (2022) under MIT License. 
// An open source project. 

// Thanks to http://www.rocketmime.com/rockets/rckt_eqn.html




// GLOBAL VARIABLES:
float rho=1.2; // density of air in kg/m^3(kostant)
float Cd=0.75; // rocket drag coefficient (estimated) For a more detailed value: http://www.rocketmime.com/rockets/ModelRocketDragAnalysis.pdf
float g=9.81; // gravitational force
float pi=3.14159;

void output(float t,float q,float v,float y,float mf,float yt,float Fd,float vmph,float yfeet,float vkmh)
{
    cout << endl;
    cout << "Burnout time: " << t << " s." << endl;
    cout << "Burnout velocity: " << q << " m/s." << endl;
    cout << "Velocity: " << v << " m/s ("<< vkmh << " km/h / "<< vmph << " mp/h)" << endl;
    cout << "Distance: " << y << " m." << endl;
    cout << "Final mass: " << mf << " kg." << endl;
    cout << "Max altitude: " << yt << " m ("<< yfeet << " feet)" << endl;
    cout << "Max drag: " << Fd << " newton." << endl;

}

void calc(float mr, float me, float mp, float d, float I, float F)
{
    float A=pi*(d/2)*(d/2); // area
    float k=0.5*rho*Cd*A; // drag fact
    float t=I/F; // burnout time
    float ms=mr+me-(mp/2); // mass
    float q=sqrt((F-(ms*g))/k); // term vel
    float x=2*k*(q/ms); // exponent
    float v=q*(1-exp(-x*t))/(1+exp(-x*t)); // velocity
    float y=(-ms/2/k)*log((F-(ms*g)-(k*v*v))/(F-ms*g)); // distance (vert) (??)
    float mf=mr+me-mp; // final mass
    float yc=(mf/2/k)*log(((mf*g)+(k*v*v))/(mf*g)); // coast y
    float yt=y+yc; // total y
    float qa=sqrt((mf*g)/k);
    float qb=sqrt((g*k)/mf);
    float ta=(atan(v/qa)/qb);
    float Fd=k*v*v; // max drag
    // conversions for americans with their stupid ass measurement systems
    float vmph=2.237*v; // max vel in mph
    float yfeet=3.28*yt; // max alt in feet
    // conversions for europeans (they're great)
    float vkmh=3.6*v;

    // TODO acc/vel/temp di ricaduta

    output(t,q,v,y,mf,yt,Fd,vmph,yfeet,vkmh);

}


//////// TEMPORARLY REMOVED (tbh i think it's useless but i'm too scared about deleting it lmaoo) ////////

//void calc(float mass, float diam, float impul, float thru)
//{
//    cout << "Processing data..." << endl;
//    float area=0;
//    area=pi*pow((diam*2),2);
//
//    float k=0; // wind resistance factor (approx calc)
//    k=0.5*rho*Cd*area;
//
//    float burn_t=0; //burn time
//    burn_t=impul/thru;
//
//    float gP=0; // weight (due to gravitaional force applied)
//    gP=mass*g;
//
//    // MANCA UN PEZZOOOO !!!!!!! il terzultimo punto del primo paragrafo
//
//    float q=0; // NOT WORKING
//    q=sqrt((thru-(mass*g))/k);
//
//    float x=0; // NOT WORKING pt 2
//    x=(2*k*q)/mass;
//
//    cout << "Executing final equations..." << endl;
//
//    float v=0; // NOT WORKING pt.3
//    v=q*(1-exp(-x*burn_t))/(1+exp(-x*burn_t)); //meters/second
//
//    float yb=0;
//    yb=(-1*mass/(2*k))*log((thru-(mass*g)-pow(k*v,2))/(thru-(mass*g))); // meters
//
//    float yc=0;
//    yc=((mass/(2*k))*log((mass*g) + pow(k*v,2)))/(mass*g);
//
//    float maxAlt=0; // max altitude
//    maxAlt=yb+yc;
//
//    // TIME TO APOGEE
//    float qa=0;
//    qa=sqrt(mass*g/k);
//    float qb=0;
//    qb=sqrt(g*k/mass);
//    float ta=0;
//    ta=atan(v/qa)/qb;
//
//    // FORCES
//
//    float dragForce=0;
//    dragForce=(0.5*rho*Cd*area*v*v);
//
//    float netForce=0;
//    netForce=(thru-(mass*g)-(k*v*v));
//
//    // VELOCITY AT BURNOUT
//
//    float vBurnOut=0;
//    vBurnOut=q*(1-exp(-x*burn_t))/(1+exp(-x*burn_t));
//
//    // DISTANCE TRAVELLED FROM vBurnOut TO APOGEE
//
//    float deltaDistance=0;
//    deltaDistance=(mass/(2*k))*log(((mass*g)+(k*vBurnOut*vBurnOut))/(mass*g));
//
//    // EXAUST VELOCITY (speed of propellant leaving rocket)
//
//
//    cout << "Elaborating output..." << endl;
//    cout << endl;
//    cout << endl;
//    output(maxAlt,ta,dragForce,netForce,deltaDistance,vBurnOut);
//
//}

////////////////////////////////////////////////////////////////////////////////

void inputData (float mr, float me, float mp, float d, float I, float F)
{
    cout << "Insert data: " << endl;
    cout << "Rocket mass (kg): ";
    cin >> mr;
    cout << "Engine initial mass (kg): ";
    cin >> me;
    cout << "Propellant mass (kg): ";
    cin >> mp;
    cout << "Diameter (m): ";
    cin >> d;
    cout << "Impulse: ";
    cin >> I;
    cout << "Thrust: ";
    cin >> F;

    cout << "Running calculations..." << endl;
    calc(mr,me,mp,d,I,F);
}

int main ()
{
    cout << "Simply Rocket Simulator - ORA Space Association (C) 2022" << endl;
    cout << endl;
    cout << endl;
    //chooseSim();
    inputData(0,0,0,0,0,0);
}

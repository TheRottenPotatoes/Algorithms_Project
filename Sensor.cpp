#include "Sensor.h"

Sensor::Sensor()
{
    //ctor
}

Sensor::Sensor(int Xcoor,int Ycoor):m_X(Xcoor),m_Y(Ycoor),m_Radius(5),m_Battery(300) {}



void Sensor::round_done(){
m_Battery=-1;
return;
}

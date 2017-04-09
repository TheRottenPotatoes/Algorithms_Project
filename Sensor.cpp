#include "Sensor.h"

Sensor::Sensor()
{
    m_X=0;
    m_Y=0;
    m_Radius=0;
    m_Battery=0;
}

Sensor::Sensor(int Xcoor,int Ycoor):m_X(Xcoor),m_Y(Ycoor),m_Radius(5),m_Battery(300) {}



void Sensor::round_done(){
m_Battery=m_Battery-1;
return;
}

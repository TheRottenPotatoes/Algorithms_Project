#include "Sensor.h"

Sensor::Sensor()
{
    //ctor
}

Sensor::Sensor(int Xcoor,int Ycoor,int Rad,int Bat)
{
    int m_X=Xcoor;
    int m_Y=Ycoor;
    int m_Radius=Rad;
    int m_Battery=Bat;
}

ostream& operator<<(ostream& os, Sensor& A)
{
    os <<"X coordinate: "<< A.m_X <<"\tY coordinate: " <<A.m_Y <<"\tRadius: "<< A.m_Radius<<"\tBattery: "<<A.m_Battery<<endl;
    return os;
}

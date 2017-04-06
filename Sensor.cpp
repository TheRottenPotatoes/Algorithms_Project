#include "Sensor.h"

Sensor::Sensor()
{
    //ctor
}

Sensor::Sensor(int Xcoor,int Ycoor,int Rad,int Bat):m_X(Xcoor),m_Y(Ycoor),m_Radius(Rad),m_Battery(Bat) {}



/*std::ostream& operator<<(Sensor& A,std::ostream fout){
fout<<m_X<<","<<m_Y<<","<<m_Radius<<","<<m_Battery<<"\n";

return fout;
}*/

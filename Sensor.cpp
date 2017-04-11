#include "Sensor.h"

Sensor::Sensor()
{
    m_X=0;
    m_Y=0;
    m_Radius=0;
    m_Battery=0;
}

Sensor::Sensor(float Xcoor,float Ycoor):m_X(Xcoor),m_Y(Ycoor),m_Radius(5),m_Battery(300) {}

void Sensor::round_done()
{
    if(m_Battery > 0)
        m_Battery--;
    return;
}

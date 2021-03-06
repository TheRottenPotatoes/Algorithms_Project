#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>


class Sensor
{
    public:
        // default constructor
        Sensor();
        // made constructor to take in x and y coordinates.
        //Sets radius to 5 and battery to 5
        Sensor(int Xcoor,int Ycoor);
        int GetX() { return m_X; }
        void SetX(int val) { m_X = val; }
        int GetY() { return m_Y; }
        void SetY(int val) { m_Y = val; }
        int GetRadius() { return m_Radius; }
        void SetRadius(int val) { m_Radius = val; }
        int GetBattery() { return m_Battery; }
        void SetBattery(int val) { m_Battery = val; }
        void round_done();

    private:
        int m_X;
        int m_Y;
        int m_Radius;
        int m_Battery;

};

#endif // SENSOR_H

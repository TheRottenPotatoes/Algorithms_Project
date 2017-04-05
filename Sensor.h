#ifndef SENSOR_H
#define SENSOR_H


using namespace std::ostream;

class Sensor
{
    public:
        Sensor();
        Sensor(int Xcoor,int Ycoor,int Radius,int Battery);
        int GetX() { return m_X; }
        void SetX(int val) { m_X = val; }
        int GetY() { return m_Y; }
        void SetY(int val) { m_Y = val; }
        int GetRadius() { return m_Radius; }
        void SetRadius(int val) { m_Radius = val; }
        int GetBattery() { return m_Battery; }
        void SetBattery(int val) { m_Battery = val; }
        friend ostream& operator<<(ostream& os, Sensor &A); //dosen't work yet will overload cout to let us cout
                                                            //to output x coor, y coor, radius, and battery.
    private:
        int m_X;
        int m_Y;
        int m_Radius;
        int m_Battery;
};

#endif // SENSOR_H

#include <iostream>
#include <Sensor.h>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;
//bool checkOverlap(Sensor sensorOne, Sensor sensorTwo);

int main()
{
    ofstream fout;
    srand(time(0));
    const int NUMB_OF_SENSORS = 50;
    const int LIM_RAD = 5;
    const int LIM_BAT = 300;
    const int LIM_X = 51;
    const int LIM_Y = 51;
    Sensor List_of_Sensors[60];
    Sensor Active_Sensors[60];
    int activeSensorCount = 0;





  fout.open("SensorInfo.csv");




    for(int i = 0; i<50;i++){
            List_of_Sensors[i] = Sensor(rand()%LIM_X,rand()%LIM_Y,LIM_RAD,LIM_BAT);
    fout<<List_of_Sensors[i].GetX()<<","<<List_of_Sensors[i].GetY()<<","<<List_of_Sensors[i].GetRadius()<<","<<List_of_Sensors[i].GetBattery()<<endl;
    }
    return 0;

}

bool checkOverlap(Sensor sensorOne, Sensor sensorTwo)
{
    bool overlap = false;

    //calculate the distance betwwen both sensors
    float centerX = sensorTwo.GetX()-sensorOne.GetX();
    float centerY = sensorTwo.GetY()-sensorOne.GetY();
    float distance = sqrt((centerX*centerX) + (centerY*centerY)); //distance between sensors
    float sumRad = sensorOne.GetRadius() + sensorTwo.GetRadius();

    if(sumRad <= distance)
    {
        overlap = true;
    }
    return overlap;
}

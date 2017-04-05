#include <iostream>
#include <Sensor.h>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;
bool checkOverlap(Sensor checkSensor, Sensor existingSensor);

int main()
{
    srand(time(0));
    const int NUMB_OF_SENSORS = 50;
    const int LIM_RAD = 5;
    const int LIM_BAT = 300;
    const int LIM_X = 50;
    const int LIM_Y = 50;
    Sensor List_of_Sensors[NUMB_OF_SENSORS];
    Sensor Active_Sensors[NUMB_OF_SENSORS];
    int activeSensorCount = 0;

    cout<<"start"<<endl;
    for(int i=0;i<NUMB_OF_SENSORS;i++){
        List_of_Sensors[i]=Sensor(rand()%(LIM_X+1),rand()%(LIM_Y)+1,LIM_RAD,LIM_BAT);

    }
    return 0;
}

//function to check for overlap between two sensors
bool checkOverlap(Sensor sensorOne, Sensor sensorTwo);
{
    bool overlap = false;
    //get coordinates and radius of sensors
    float firstX = sensorOne.GetX();
    float firstY = sensorOne.GetY();
    float firstRad = sensorOne.GetRadius();
    float secondX = sensorTwo.GetX();
    float secondY = sensorTwo.GetY();
    float secondRad = sensorTwo.GetRadius();
    
    //calculate the distance betwwen both sensors
    float centerX = secondX - firstX;
    float centerY = secondY - firstY;
    float distance = sqrt((X*X) + (Y*Y)); //distance between sensors
    float sumRad = firstRad + secondRad;
    
    if(sumRad < distance)
    {
        overlap = true;
    }
    return overlap;
}

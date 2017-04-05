#include <iostream>
#include <Sensor.h>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

int main()
{
    srand(time(0));
    const int NUMB_OF_SENSORS = 50;
    const int LIM_RAD = 5;
    const int LIM_BAT = 300;
    const int LIM_X = 50;
    const int LIM_Y = 50;
    Sensor List_of_Sensors[NUMB_OF_SENSORS];

    cout<<"start"<<endl;
    for(int i=0;i<NUMB_OF_SENSORS;i++){
        List_of_Sensors[i]=Sensor(rand()%(LIM_X+1),rand()%(LIM_Y)+1,LIM_RAD,LIM_BAT);

    }
    return 0;
}

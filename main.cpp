#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
//#include <fstream>
#include <cmath>
#include "sensor.h"
using namespace std;

const int LIM_X = 51;
const int LIM_Y = 51;
const int MAX_NUMB_OF_SENSORS = 500;

void randomizeSensors(Sensor *List_of_Sensors, int numberOfSensors);

int populateActiveSensors(Sensor List_of_Sensors[], Sensor *activeSensors, int numberOfSensors);

void printData(int coverage, int round);
    
//M is the number of points to check in the AOI
float estimateCoverage(int M, Sensor activeSensors[], int activeSensorCount);

bool checkOverlap(Sensor sensorOne, Sensor sensorTwo);

bool ArrayCheckOverlap(Sensor activeSen[],int numb_of_activeSen,Sensor CheckAgainst);

bool CheckBattery(Sensor check[], int numb_sensors);

void clearActiveSensors(Sensor *activeSensors, int activeSensorCount);

int main()
{
    
    srand(time(NULL));
    
    int numberOfSensors = 0;
    Sensor List_of_Sensors[MAX_NUMB_OF_SENSORS];
    Sensor Active_Sensors[MAX_NUMB_OF_SENSORS];
    Sensor Blank(-6, -6); //-6 so their radius doesn't touch AOI
    for(int i=0;i < MAX_NUMB_OF_SENSORS;i++){
        Active_Sensors[i]= Blank;
    }
    int activeSensorCount = 0;
    Sensor *arrayPointer;
    int rounds = 0;
    float coverage = 0;
    Sensor Center(25,25);
    
    cout << "Input number of sensors: ";
    cin >> numberOfSensors;
    arrayPointer = List_of_Sensors;
   
    randomizeSensors(arrayPointer, numberOfSensors);
    cout << "here1" << endl; 
    arrayPointer = Active_Sensors;
    activeSensorCount = populateActiveSensors(List_of_Sensors, arrayPointer, numberOfSensors);
    cout << "here2";
    
    while(CheckBattery(List_of_Sensors, numberOfSensors)) // keep going until no sensors have battery
    {
        for (int x = 0; x < 300; x++)//go 300 rounds until the sensors die
        {
            for(int i = 0; i < numberOfSensors; i++)
            {
                Active_Sensors[i].round_done();
            }
            rounds++;
        }
        coverage = estimateCoverage(1000, Active_Sensors, activeSensorCount);
        printData(coverage, rounds);
        clearActiveSensors(arrayPointer, activeSensorCount);
        activeSensorCount = 0;
        activeSensorCount = populateActiveSensors(List_of_Sensors, arrayPointer, numberOfSensors);
    }
    return 0;

}

void randomizeSensors(Sensor *List_of_Sensors, int numberOfSensors)
{
    //ofstream fout;
    //creates var for outstream
    //fout.open("SensorInfo.csv");
    /*opens fout to a .csv file so we can make Excel Graph the sensors for us*/
    for(int i = 0; i < numberOfSensors; i++)
    {
        *(List_of_Sensors + i) = Sensor(rand() % LIM_X, rand() % LIM_Y); // FIX THIS, VALUES NEED TO BE DECIMALS
        cout << List_of_Sensors[i].GetX() << "," << List_of_Sensors[i].GetY() << "," << List_of_Sensors[i].GetRadius() << "," << List_of_Sensors[i].GetBattery() << endl;
    }
    // creates NUMB OF SENSORS  sensors and puts them in array List of Sensors. then outputs the list of sensors into "SensorInfo.csv"
    //fout.close();
    cout << "RANDOMIZE DONE" << endl;
    return;
}

int populateActiveSensors(Sensor List_of_Sensors[], Sensor *activeSensors, int numberOfSensors)
{
    int activeSensorCount = 0;
    while(CheckBattery(List_of_Sensors, numberOfSensors))
    {
        //add sensors to solution
        for(int i=0;i < numberOfSensors; i++)
        {
            int Add_to_solution=0;
            Sensor a = List_of_Sensors[i];
            if (a.GetBattery() > 0 && ArrayCheckOverlap(activeSensors, activeSensorCount, a))
            {
                *(activeSensors + Add_to_solution) = a;
                Add_to_solution++;
                activeSensorCount++;
            }
            
        }

    }
    return activeSensorCount;
}

void printData(int coverage, int round)
{
    int start = 0; //starting round
    int end = round; //ending round
    cout << "Round: " << start << " - " << end << "    Coverage: " << coverage << endl;    
}

bool checkOverlap(Sensor sensorOne, Sensor sensorTwo)// checks if 2 sensors overlap each other.
{
    if(sensorOne.GetX() < 0 || sensorTwo.GetX() < 0) //check if they are blank sensors
        return false;
    bool overlap = false;
    float centerX = sensorTwo.GetX()-sensorOne.GetX();
    float centerY = sensorTwo.GetY()-sensorOne.GetY();
    float distance = sqrt((centerX*centerX) + (centerY*centerY)); //distance between sensors

    if(3 > distance)
    {
        overlap = true;
    }
    return overlap;
}

bool CheckBattery(Sensor check[], int numb_sensors)//decrease battery by one. for use after rounds
{
    for(int i=0;i<numb_sensors;i++)
    {
        if(check[i].GetBattery()>0)
            return true;
    }
    return  false;
}

bool ArrayCheckOverlap(Sensor activeSen[], int numb_of_activeSen, Sensor CheckAgainst)
{
    bool isThereOverlap=false;

    for(int i=0;i<numb_of_activeSen;i++)
    {
        if(checkOverlap(activeSen[i],CheckAgainst))
        {
            isThereOverlap=true;
        }

    }
    return isThereOverlap;
}

float estimateCoverage(int M, Sensor activeSensors[], int activeSensorCount)
{
    float coverage = 0;
    float M_x = 0; //random x point to check in AOI
    float M_y = 0; //random y point to check in AOI
    for(int i = 0; i < M; i++) //loop to create random M points to check coverage
    {
        M_x = rand() % LIM_X;
        M_y = rand() % LIM_Y;
        for(int x = 0; x < activeSensorCount; x++) //loop to check each active sensor to see if it covers the point
        {
            if(sqrt((M_x * activeSensors[x].GetX()) + (M_y * activeSensors[x].GetY())) < 5) //if distance between point and sensor is < 5
            {
                coverage++;
                break;
            } 
        }
    }
    return (coverage / M);
}
    
void clearActiveSensors(Sensor *activeSensors, int activeSensorCount)
{
    Sensor Blank(-6, -6); //-6 so their radius doesn't touch AOI
    for(int i = 0; i < activeSensorCount; i++)
    {
        *(activeSensors + i) = Blank;
    }
}


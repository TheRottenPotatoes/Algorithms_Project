#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cmath>
#include "sensor.h"
using namespace std;

const int LIM_X = 51;
const int LIM_Y = 51;
const int NUMB_OF_SENSORS = 50;

int randomizeSensors(Sensor& List_of_Sensors[]);

int populateActiveSensors(Sensor List_of_Sensors[], Sensor& activeSensors[]);

void printData(int coverage, int round);
    
//M is the number of points to check in the AOI
float estimateCoverage(int M, Sensor activeSensors[], int activeSensorCount);

bool checkOverlap(Sensor sensorOne, Sensor sensorTwo);

bool ArrayCheckOverlap(Sensor activeSen[],int numb_of_activeSen,Sensor CheckAgainst);

bool CheckBattery(Sensor check[], int numb_sensors);

int main()
{

    srand(time(NULL));

    Sensor List_of_Sensors[NUMB_OF_SENSORS];
    Sensor Active_Sensors[NUMB_OF_SENSORS];
    Sensor Blank(0,0);
    for(int i=0;i<NUMB_OF_SENSORS+5;i++){
        Active_Sensors[i]= Blank;
    }
    float activeSensorCount = 0;
    float AreaTaken=2500;
    int number_of_rounds = 0;
    Sensor Center(25,25);
    
    randomizeSensors(List_of_Sensors);

    
    
    
         

         for (int i=0;i<activeSensorCount; i++)// for each round decreases the battery by 1
         {
             cout<<"Number: "<<i<<"/nXCoordinate: "<<Active_Sensors[i].GetX()<<"/nYCoordinate: "<<Active_Sensors[i].GetY()<<endl;
             Active_Sensors[i].SetBattery(Active_Sensors[i].GetBattery()-1);
         }
         number_of_rounds++;
//implementaion of greedy algorithm

cout<<"/n/nTimes Ran: "<<number_of_rounds<<endl;
bool checkOverlap(Sensor sensorOne, Sensor sensorTwo);
bool ArrayCheckOverlap(Sensor activeSen[],int numb_of_activeSen,Sensor CheckAgainst);


Sensor test[50];
Sensor blank(25,25);
Sensor test2(45,45);
for(int i=0;i<50;i++){
    test[i]=blank;
}
cout<<checkOverlap(test[1],test2);
cout<<ArrayCheckOverlap(test,50,test2);


    return 0;

}

int randomizeSensors(Sensor& List_of_Sensors[])
{
    ofstream fout;
    //creates var for outstream
    fout.open("SensorInfo.csv");
    /*opens fout to a .csv file so we can make Excel Graph the sensors for us*/
    for(int i = 0; i<NUMB_OF_SENSORS;i++)
    {
        List_of_Sensors[i] = Sensor(rand()%LIM_X,rand()%LIM_Y); // FIX THIS, VALUES NEED TO BE DECIMALS
        fout<<List_of_Sensors[i].GetX()<<","<<List_of_Sensors[i].GetY()<<","<<List_of_Sensors[i].GetRadius()<<","<<List_of_Sensors[i].GetBattery()<<endl;
    }
    // creates NUMB OF SENSORS  sensors and puts them in array List of Sensors. then outputs the list of sensors into "SensorInfo.csv"
    fout.close();
}

int populateActiveSensors(Sensor List_of_Sensors[], Sensor& activeSensors[])
{
    while(CheckBattery(List_of_Sensors,NUMB_OF_SENSORS)==true && ((LIM_X*LIM_Y)/2)<AreaTaken)//while a sensor in the array still has battery and area taken is more than half
    {
         //add sensors to solution
         for(int i=0;i<NUMB_OF_SENSORS;i++)
         {
            int Add_to_solution=0;
            Sensor a = List_of_Sensors[i];
            if (a.GetBattery() > 0 && ArrayCheckOverlap(Active_Sensors, activeSensorCount, a))
            {
                Active_Sensors[Add_to_solution] = a;
                Add_to_solution++;
                activeSensorCount++;
            }
            
         }

     }
}

void printData(int coverage, int round)
{
}

bool checkOverlap(Sensor sensorOne, Sensor sensorTwo)// checks if 2 sensors overlap each other.
{
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

bool CheckBattery(Sensor check[], int numb_sensors){//decrease battery by one. for use after rounds
{
  for(int i=0;i<numb_sensors;i++)
  {
      if(check[i].GetBattery()>0)
      {return true;}
  }
  return  false;
}

bool ArrayCheckOverlap(Sensor activeSen[],int numb_of_activeSen,Sensor CheckAgainst)
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

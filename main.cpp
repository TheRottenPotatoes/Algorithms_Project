#include <iostream>
#include "Sensor.h"
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

#define NULL 0                   // C++ definition.

using namespace std;


int main()
{
    ofstream fout;
    //creates var for outstream

    srand(time(0));
    /*initailzes srand to time NULL*/

    const int LIM_X = 51;
    const int LIM_Y = 51;
    const int NUMB_OF_SENSORS = 50;
    Sensor List_of_Sensors[NUMB_OF_SENSORS+5];
    Sensor Active_Sensors[NUMB_OF_SENSORS+5];
    Sensor Blank(0,0);
    for(int i=0;i<NUMB_OF_SENSORS+5;i++){
        Active_Sensors[i]= Blank;
    }
    float activeSensorCount = 0;
    const float AREA_OF_SENSORS=78.54;
    int number_of_rounds = 0;
    Sensor Center(25,25);

    /*creates variables that are used int the project.
    made constants for the limit of x and y for the graph for easy change.

    created sets of sensors. one for all the sensors and one for the solution set.

    created a float for the count of active sensors.
    is a float so it can do arithematic with Area taken later in program.

    made AREA OF SENSORS const to make it easier to calculate AreaTaken in the program later.

    AreaTaken is to have a place to store the amount of area the optimal set takes up at each round.

*/

    bool checkOverlap(Sensor sensorOne, Sensor sensorTwo);
    bool ArrayCheckOverlap(Sensor activeSen[],int numb_of_activeSen, Sensor j);
    bool CheckBattery(Sensor check[], int numb_sensors);
    float estimateCoverage(int M, Sensor activeSensors[], int activeSensorCount);
    //fucntion calls

fout.open("SensorInfo.csv");
/*opens fout to a .csv file so we can make Excel Graph the sensors for us*/


for(int i = 0; i<NUMB_OF_SENSORS;i++){
            List_of_Sensors[i] = Sensor(rand()%LIM_X,rand()%LIM_Y);
    fout<<List_of_Sensors[i].GetX()<<","<<List_of_Sensors[i].GetY()<<","<<List_of_Sensors[i].GetRadius()<<","<<List_of_Sensors[i].GetBattery()<<endl;
    }
    /* creates NUMB OF SENSORS  sensors and puts them in array List of Sensors. then outputs the list of sensors into "SensorInfo.csv"*/
    fout.close();

    Sensor first(50,50);
for(int i=1;i<NUMB_OF_SENSORS;i++)
    			{
    				if(abs(List_of_Sensors[i].GetX()-25)<abs(first.GetX()-25) || abs(List_of_Sensors[i].GetY()-25)< abs(first.GetY()-25))
    				{
    					first=List_of_Sensors[i];

					}
				}
				Active_Sensors[0]=first;
				cout<<Active_Sensors[0].GetX()<<","<<Active_Sensors[0].GetY()<<endl;


    do{//while a sensor in the array still has battery and
cout<<"A";
    		int Add_to_solution=0;
    		Sensor optimal= List_of_Sensors[0];


    		for(int j=0;j<NUMB_OF_SENSORS+5;j++){

            Sensor testAgainst=List_of_Sensors[j];

    		while(ArrayCheckOverlap(Active_Sensors,Add_to_solution,testAgainst)==true)
    		{//cout<<"B";
    			for(int i=1;i<NUMB_OF_SENSORS;i++)
    			{
    				if(abs(List_of_Sensors[i].GetX()-25)<abs(first.GetX()-25) || abs(List_of_Sensors[i].GetY()-25)< abs(first.GetY()-25))
    				{
    					optimal=List_of_Sensors[i];
					}
				}
			}
    		Active_Sensors[Add_to_solution]=optimal;
            Add_to_solution++;
        }
  		  }while(CheckBattery(List_of_Sensors,NUMB_OF_SENSORS+5)==true && estimateCoverage(10,Active_Sensors,activeSensorCount)>0.5);






    for (int i=0;i<activeSensorCount; i++)// for each round decreases the battery by 1
        {
            cout<<"Number: "<<i<<"/nXCoordinate: "<<Active_Sensors[i].GetX()<<"/nYCoordinate: "<<Active_Sensors[i].GetY()<<endl;
            Active_Sensors[i].SetBattery(Active_Sensors[i].GetBattery()-1);
        }
        number_of_rounds++;

/*implementaion of greedy algorithm*/

//std::cout<<"\nTimes Ran: "<<number_of_rounds<<endl;

return 0;

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

  for(int i=0;i<numb_sensors;i++)
  {
      if(check[i].GetBattery()>0)
      {return true;}
 }
 return  false;
 }

bool ArrayCheckOverlap(Sensor activeSen[],int numb_of_activeSen, Sensor j){
    bool isThereOverlap=false;

 for(int i=0;i<numb_of_activeSen;i++)
 {
 	if(checkOverlap(activeSen[i],j))
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
    M_x = rand() % 51;
    M_y = rand() % 51;
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

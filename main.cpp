#include <iostream>
#include <Sensor.h>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;


int main()
{
    ofstream fout;
    /*creates var for outstream

    srand(time(0));
    /*initailzes srand to time NULL

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
    float AreaTaken=2500;
    int number_of_rounds = 0;
    Sensor Center(25,25);

    /*creates variables that are used int the project.
    made constants for the limit of x and y for the graph for easy change.

    created sets of sensors. one for all the sensors and one for the solution set.

    created a float for the count of active sensors.
    is a float so it can do arithematic with Area taken later in program.

    made AREA OF SENSORS const to make it easier to calculate AreaTaken in the program later.

    AreaTaken is to have a place to store the amount of area the optimal set takes up at each round.



    bool checkOverlap(Sensor sensorOne, Sensor sensorTwo);
    bool ArrayCheckOverlap(Sensor activeSen[],int numb_of_activeSen,Sensor CheckAgainst);
    bool CheckBattery(Sensor check[], int numb_sensors);
    /*fucntion calls

fout.open("SensorInfo.csv");
/*opens fout to a .csv file so we can make Excel Graph the sensors for us


for(int i = 0; i<NUMB_OF_SENSORS;i++){
            List_of_Sensors[i] = Sensor(rand()%LIM_X,rand()%LIM_Y);
    fout<<List_of_Sensors[i].GetX()<<","<<List_of_Sensors[i].GetY()<<","<<List_of_Sensors[i].GetRadius()<<","<<List_of_Sensors[i].GetBattery()<<endl;
    }
    /* creates NUMB OF SENSORS  sensors and puts them in array List of Sensors. then outputs the list of sensors into "SensorInfo.csv"
    fout.close();


    while(CheckBattery(List_of_Sensors,NUMB_OF_SENSORS+5)==true && ((LIM_X*LIM_Y)/2)<AreaTaken){//while a sensor in the array still has battery and
         for(int i=0;i<NUMB_OF_SENSORS;i++){
            int Add_to_solution=0;
            Sensor a =List_of_Sensors[i];
//the area covered is more than half the AOI
        while(false==ArrayCheckOverlap(Active_Sensors,NUMB_OF_SENSORS+5,List_of_Sensors[i]))//infinite loop.
            {
                cout<<"made here"<<endl;
              int dis_x= 25;
              int dis_y=25;
              if(List_of_Sensors[i].GetX()-25<dis_x ||List_of_Sensors[i].GetY()-25<dis_y)
                {Sensor a =List_of_Sensors[i];}
            }
            Active_Sensors[Add_to_solution]=a;
            Add_to_solution++;

         }


AreaTaken= AREA_OF_SENSORS*activeSensorCount;//finds the area covered by mulitpying the area of circle rad 5 times the sensors in the opt solution.

    for (int i=0;i<activeSensorCount; i++)// for each round decreases the battery by 1
        {
            cout<<"Number: "<<i<<"/nXCoordinate: "<<Active_Sensors[i].GetX()<<"/nYCoordinate: "<<Active_Sensors[i].GetY()<<endl;
            Active_Sensors[i].SetBattery(Active_Sensors[i].GetBattery()-1);
        }
        number_of_rounds++;
}
/*implementaion of greedy algorithm

cout<<"/n/nTimes Ran: "<<number_of_rounds<<endl;*/
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

bool checkOverlap(Sensor sensorOne, Sensor sensorTwo)// checks if 2 sensors overlap each other.
{
    bool overlap = false;


    float centerX = sensorTwo.GetX()-sensorOne.GetX();
    float centerY = sensorTwo.GetY()-sensorOne.GetY();
    float distance = sqrt((centerX*centerX) + (centerY*centerY)); //distance between sensors
    float sumRad = sensorOne.GetRadius() + sensorTwo.GetRadius();

    if(sumRad < distance)
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

bool ArrayCheckOverlap(Sensor activeSen[],int numb_of_activeSen,Sensor CheckAgainst){
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

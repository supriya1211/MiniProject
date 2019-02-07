/***************START*****************
 *
 * Author : Supriya Kumari
 *
 * File : main.cpp
 *
 * Date : 29/1/2019
 *
 ***************END*****************/


#include"TempSensor.h"
#include"TempMonitor.h"
#include"ACMonitor.h"
#include<iostream>

using namespace std;

int main()
{
   
   CTempSensor *ts = new CTempSensor;
   CTempMonitor *tempObj = new CTempMonitor(1);
   CACMonitor *ac = new CACMonitor(3);
   

   ts -> NGI_addSubscriber(tempObj);
   ts -> NGI_addSubscriber(ac);

   ts -> NGI_setData();

   ts -> NGI_removeSubscriber (tempObj);

   return 0;

}


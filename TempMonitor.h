/***************START*****************
 *
 * Author : Supriya Kumari
 *
 * File : TempMonitor.h
 *
 * Date : 30/1/2019
 *
 ***************END*****************/


#ifndef _TEMPMONITOR_HPP
#define _TEMPMONITOR_HPP

#include<vector>
#include<iostream>
#include"Observer.h"
#include"MainController.h"

using namespace std;


class CTempMonitor : public IObserver
{

public:
  
    int nSubscriberId;               /**< Declared to initialise constructor>*/                  
    float fTemp, fRtemp, fWtemp;
    char szTemp_deg, szRdeg, szWdeg;

    vector< pair <char, float> > temp;       /**< Declared to store data from file>*/
    vector<pair <char, float> > :: iterator rvector;       /**< Declared to iterator the stored value >*/

    CTempMonitor(int nSubscriberId);

    static void* NGI_createThread(void *ptr);
    void NGI_convertDegree();

    void NGI_update(float , char) override;

};

#endif  // _TEMPMONITOR_HPP

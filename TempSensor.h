/***************START*****************
 *
 * Author : Supriya Kumari
 *
 * File : TempSensor.h
 *
 * Date : 29/1/2019
 *
 ***************END*****************/


#ifndef _TEMPSENSOR_HPP
#define _TEMPSENSOR_HPP

#include<vector>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstring>

#include"Subject.h"
#include"Observer.h"


using namespace std;

class CTempSensor : public ISubject
{
public:
    vector <IObserver *> v;        /**< Declared vector to list Subscriber>*/
    
    vector< pair <char, float> > v1;    /**< Declared vector to store data from file>*/
    vector< pair <char, float> > :: iterator it;   /**< Declared iterator to fetch data from vector>*/

    float fTemp = 0.0, fRtemp;
    char szDeg, szRdeg;
    
    ifstream fin;              /**< Declared object of input file stream>*/
    string strFilename, strTemp, strDeg;

    CTempSensor();
    
    void NGI_addSubscriber(IObserver *o) override;

    void NGI_removeSubscriber(IObserver *o) override;

    void NGI_notify() override;

    void NGI_setData();

};

#endif  //  _TEMPSENSOR_HPP

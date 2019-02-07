/***************START*****************
 *
 * Author : Supriya Kumari
 *
 * File : ACMointor.h
 *
 * Date : 4/2/2019
 *
 ***************END*****************/


#ifndef _ACMONITOR_HPP
#define _ACMONITOR_HPP

#include<vector>
#include<iostream>
#include"Observer.h"
#include"MainController.h"

using namespace std;

class CACMonitor : public IObserver
{
public:
    string strStatus;     /**< Declared to store status of AC>*/
    int nSubscriberId;    /**< Declared to initialise the constructor>*/
    float fRtemp;  
    char szRdeg;

    vector<string> ac;    /**< Declared to store AC status in vector>*/
    vector<string> :: iterator vac;   /**< Declared to iterate the AC status>*/

    CACMonitor( int nSubscriberId);
    
    void NGI_changeStatus();

    static void* NGI_createACThread(void *ptr);

    virtual void NGI_update(float , char) override;
};

#endif    // _ACMONITOR_HPP


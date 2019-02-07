/***************START*****************
 *
 * Author : Supriya Kumari
 *
 * File : Observer.h
 *
 * Date : 27/1/2019
 *
 ***************END*****************/


#ifndef _OBSERVER_HPP
#define _OBSERVER_HPP

#include<iostream>

using namespace std;

class IObserver
{
public:
    virtual void NGI_update(float temp, char deg) = 0;    

};

#endif    //  _OBSERVER_HPP

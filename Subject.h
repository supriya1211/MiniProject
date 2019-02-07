/***************START*****************
 *
 * Author : Supriya Kumari
 *
 * File : Subject.h
 *
 * Date : 28/1/2019
 *
 ***************END*****************/


#ifndef _SUBJECT_HPP
#define _SUBJECT_HPP

#include<iostream>
#include"Observer.h"

using namespace std;

class ISubject
{
public:
    virtual void NGI_addSubscriber(IObserver *o) = 0;

    
    virtual void NGI_removeSubscriber(IObserver *o) = 0;


    virtual void NGI_notify() = 0;
};

#endif   // _SUBJECT_HPP

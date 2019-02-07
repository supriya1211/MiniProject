/***************START*****************
 *
 * Author : Supriya Kumari
 *
 * File : MainController.h
 *
 * Date : 5/2/2019
 *
 ***************END*****************/  
 

#ifndef _MAINCONTROLLER_HPP
#define _MAINCONTROLLER_HPP

#include<iostream>
#include<fstream>

using namespace std;

class CMainController
{
public:
    
    static void NGI_writeTempData(float, char);
    static void NGI_writeACData(string);
};

#endif  // _MAINCONTROLLER_HPP

/***************START*****************
 *
 * Author : Supriya Kumari
 *
 * File : MainController.cpp
 *
 * Date : 5/2/2019
 *
 ***************END*****************/


#include"MainController.h"

/* *
 *@brief This method is used for writing the Temperature data in file.
 *
 * @param_in [1]  string
 *
 * @return none
 */
void CMainController::NGI_writeTempData(float fTemp , char szRdeg) 
{
    ofstream fout;
    fout.open("Output.txt" , ios::out|ios::app);
    fout << "Temperature : " << fTemp << " " << szRdeg << endl;
}


/* *
 *@brief This method is used for writing the AC status in file.
 *
 * @param_in [1]  string
 *
 * @return none
 */
void CMainController::NGI_writeACData(string strStatus)
{
    ofstream fout;
    fout.open("Output.txt" , ios::out|ios::app);
    fout << "AC Status : " << strStatus << endl;
    fout.close();
}

/***************START*****************
 *
 * Author : Supriya Kumari
 *
 * File : TempMonitor.cpp
 *
 * Date : 31/1/2019
 *
 ***************END*****************/


#include"TempMonitor.h"
#include<pthread.h>


/* *
 *@brief This is used for initailisation of constructor
 *
 * @param_in [1]   int
 *
 * @return none
 */

CTempMonitor::CTempMonitor(int nSubscriberId):nSubscriberId(nSubscriberId)
{
 
}


/* *
 *@brief This method is used for converting degree into another form of degree
 *
 * @param [in] none
 *
 * @return none
 */
void CTempMonitor::NGI_convertDegree ()
{ 
    if ( szRdeg == 'c' || szRdeg == 'C' )
    {
        fTemp = ( fRtemp * 9.0) / 5.0 + 32 ;
        cout << "Temperature in Fahrenheit: " << fTemp << endl;
	szRdeg = 'f';

    }
    else if ( szRdeg == 'f' || szRdeg == 'F' )
    {
        fTemp = ( fRtemp - 32 ) * 5.0 / 9.0 ;
        cout << "Temperature in Celsius: " << fTemp << endl;
     	szRdeg = 'c';

    }
    else
    {
        cout << "Invalid character : " << szRdeg << endl;
    }
    temp.push_back(make_pair(szRdeg, fTemp));

    CMainController:: NGI_writeTempData(fTemp, szRdeg);
    for(rvector = temp.begin(); rvector != temp.end(); ++rvector)
    {
        cout << rvector -> first << '\t' << rvector -> second << endl;  	          
	fWtemp = rvector -> first; 
 	szWdeg = rvector -> second;
		 
    }
}


/* *
 *@brief This method is used for creating thread and pass convertDegree() method.
 *
 * @param_in [1]  void pointer
 *
 * @return none
 */
void* CTempMonitor::NGI_createThread ( void *ptr1)
{
    CTempMonitor *ptr = static_cast <CTempMonitor *> (ptr1);
    ptr -> NGI_convertDegree ();
    return 0; 
 
}


/* *
 *@brief This method is used for update the convertDegree function.
 *
 * @param_in [1]  float
 * 
 * @param_in [2]  char
 *
 * @return none
 */
void CTempMonitor::NGI_update ( float temp, char deg)
{
    fRtemp = temp;
    szRdeg = deg;
    pthread_t t1 ;

    pthread_create ( &t1, NULL, NGI_createThread, (void*) (this));
    pthread_join ( t1, NULL );

}

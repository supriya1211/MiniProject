/***************START*****************
 *
 * Author : Supriya Kumari
 *
 * File : ACMonitor.cpp
 *
 * Date : 4/2/2019
 *
 ***************END*****************/


#include"ACMonitor.h"


/* *
 *@brief This is used for initailisation of constructor
 *
 * @param_in [1]   int
 *
 * @return none
 */
CACMonitor::CACMonitor(int nSubscriberId):nSubscriberId(nSubscriberId)
{
   
}

/* *
 *@brief This method is used for update the changeStatus function.
 *
 * @param_in [1]  float
 *
 * @param_in [2]  char
 *
 * @return none
 */
void CACMonitor::NGI_update(float temp, char deg)
{
    fRtemp = temp;
    szRdeg = deg;
    pthread_t t2 ;

    pthread_create ( &t2, NULL, NGI_createACThread, (void*) (this));
    pthread_join ( t2, NULL );

}


/* *
 *@brief This method is used for creating thread and pass convertDegree() method.
 *
 * @param_in [1]  void pointer
 *
 * @return none
 */
void* CACMonitor::NGI_createACThread(void *ptr)
{
    CACMonitor *ptr1 = static_cast <CACMonitor *> (ptr);
    ptr1 -> NGI_changeStatus();
    return 0;
}


/* *
 *@brief This method is used for changing the AC status according to temperature.
 *
 * @param [in] none
 *
 * @return none
 */
void CACMonitor::NGI_changeStatus()
{
    

    if ( fRtemp >= 0 && fRtemp <= 25 )
    {
        strStatus = "Cold" ;
    }

    else if ( fRtemp >= 26 && fRtemp <= 45 )
    {
        strStatus = "Medium" ;
    }

    else if ( fRtemp >= 46 && fRtemp <= 216 )
    {
        strStatus = "Warm" ;
    }

    CMainController::NGI_writeACData(strStatus);
    ac.push_back(strStatus);

    for(vac = ac.begin(); vac != ac.end(); ++vac)
    {
        cout << *vac << endl;
    }
}

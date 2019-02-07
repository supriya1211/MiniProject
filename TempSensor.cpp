/***************START*****************
 *
 * Author : Supriya Kumari
 *
 * File : TempSensor.cpp
 *
 * Date : 29/1/2019
 *
 ***************END*****************/


#include"TempSensor.h"

CTempSensor::CTempSensor()
{
    
}

/* *
 *@brief This method is used for adding subscriber.
 *
 * @param_in [1]  Object
 *
 * @return none
 */
void CTempSensor::NGI_addSubscriber(IObserver *o) 
{
    cout << "adding subscriber" << endl;
    v.push_back(o);
}


/* *
 *@brief This method is used for remove subscriber.
 *
 * @param_in [1]  Object
 *
 * @return none
 */	
void CTempSensor::NGI_removeSubscriber(IObserver *o)
{
    cout << "removing subscriber" << endl;
    auto iterator = find(v.begin(), v.end(), o);

    if (iterator != v.end()) 
    { 
        v.erase(iterator);
    }
}


/* *
 *@brief This method is used for notifying subscribe after getting any new
 * value.
 *
 * @param_in [in]  none
 *
 * @return none
 */
void CTempSensor::NGI_notify() 
{
    for (IObserver *o : v) 
    { 
        o -> NGI_update(fRtemp, szRdeg);
    }
}


/* *
 *@brief This method is used to store Data from file and notify subscribers.
 *
 * @param_in [in]  none
 *
 * @return none
 */
void CTempSensor::NGI_setData()
{
    strFilename = "Simulate.txt";

        fin.open ( strFilename);
        while( !fin.eof())
        {
            getline(fin, strTemp, ':') && getline(fin, strDeg);
            if(fin)
            {
                fTemp = stof (strTemp);

                char szDeg [strDeg.length() + 1];
                strcpy(szDeg, strDeg.c_str());

                v1.push_back( make_pair(szDeg[0] , fTemp));
            }
        }

	fin.close();

        for(it = v1.begin(); it != v1.end(); ++it )
        {
            cout << it->first << '\t' << it->second << endl;
        }
	

	for(it = v1.begin(); it != v1.end(); ++it)
        {
            szRdeg = it->first;
            fRtemp = it->second;

            NGI_notify();
        }
}

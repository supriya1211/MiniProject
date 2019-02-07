#include<iostream>
#include"Subscriber.h"

using namespace std;

class CSubscriber
{
public:

    CSubscriber::CSubscriber(const string& name)
    {
       	cout << "I am Subscriber" << endl;
	this->name = name;
    }

};

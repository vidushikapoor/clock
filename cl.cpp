/*
 * cl.cpp

 *
 *  Created on: Aug 27, 2015
 *      Author: vidushikapoor
 */
#include<iostream>
using namespace std;

class clockType
{
public:
    void setTime(int, int, int);
    void getTime(int&, int&, int&);
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType& otherTime) const;

private:
    int hr;
    int min;
    int sec;
};

void clockType::setTime(int hours, int minutes,
                        int seconds)
{
	if(0 <= hours && hours < 24)
	   hr = hours;
	else
	   hr = 0;

	if(0 <= minutes && minutes < 60)
	   min = minutes;
	else
	   min = 0;

	if(0 <= seconds && seconds < 60)
	   sec = seconds;
	else
	   sec = 0;
}
void clockType::printTime() const
{
	if(hr < 10)
	   cout<<"0";
	cout<<hr<<":";

	if(min < 10)
	   cout<<"0";
	cout<<min<<":";

	if(sec < 10)
	   cout<<"0";
	cout<<sec;
}

void clockType::getTime(int& hours, int& minutes,
                        int& seconds)
{
	hours = hr;
	minutes = min;
	seconds = sec;
}
void clockType::incrementHours()
{
	hr++;
	if(hr > 23)
 	   hr = 0;
}
void clockType::incrementMinutes()
{
	min++;
	if(min > 59)
	{
	   min = 0;
	   incrementHours();
	}
}

void clockType::incrementSeconds()
{
	sec++;

	if(sec > 59)
	{
	   sec = 0;
	   incrementMinutes();
	}
}

bool clockType::equalTime(const clockType& otherClock)
                                                    const
{
	return (hr == otherClock.hr
		  && min == otherClock.min
		  && sec == otherClock.sec);
}
int main()
{
	clockType myClock;
	clockType yourClock;

	int hours;
	int minutes;
	int seconds;

	myClock.setTime(5,4,30);            //Line 1
     cout<<"Line 2: myClock: ";			//Line 2
	myClock.printTime();				//Line 3
	cout<<endl;					//Line 4

	cout<<"Line 5: yourClock: ";		//Line 5
	yourClock.printTime();			//Line 6
	cout<<endl;					//Line 7

	yourClock.setTime(5,45,16);			//Line 8

	cout<<"Line 9: After setting - yourClock: ";	//Line 9
     yourClock.printTime();			//Line 10
	cout<<endl;					//Line 11
     if(myClock.equalTime(yourClock))		//Line 12
	   cout<<"Line 13: Both times are equal."<<endl; 					//Line 13
	else							//Line 14
	   cout<<"Line 15: The two times are not equal"
		 <<endl;
     cout<<"Line 16: Enter hours, minutes, and "
     	    <<"seconds: ";				//Line 16
     	cin>>hours>>minutes>>seconds;		//Line 17
     	cout<<endl;					//Line 18

     	myClock.setTime(hours,minutes,seconds);	//Line 19

     	cout<<"Line 20: New myClock: ";		//Line 20
     	myClock.printTime();				//Line 21
     	cout<<endl;					//Line 22

     	myClock.incrementSeconds();			//Line 23

     	cout<<"Line 24: After incrementing the clock by "
     	    <<"one second, myClock: ";		//Line 24
     	myClock.printTime();				//Line 25
          cout<<endl;					//Line 26
     	return 0;
     }//end main







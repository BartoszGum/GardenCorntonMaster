// timeClass.h

#ifndef _TIMECLASS_h
#define _TIMECLASS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class timeClass
{
 protected:


 public:
	 int year;
	 int month;
	 int day;
	 int hour;
	 int minute;
	 int offHour = 23;
	 int onHour = 5;
	 bool isMotionEnable = true;

	 String currentDate = "";

	 String get(){

		 String tmp_month = String(this->month);
		 String tmp_day = String(this->day);;
		 String tmp_hour = String(this->hour);;
		 String tmp_minute = String(this->minute);;

		 if (this->month < 10) { tmp_month = "0" + tmp_month; }
		 if (this->day < 10) { tmp_day = "0" + tmp_day; }
		 if (this->hour < 10) { tmp_hour = "0" + tmp_hour; }
		 if (this->minute < 10) { tmp_minute = "0" + tmp_minute; }


		 String str_date = String(this->year) + "." + tmp_month + "." + tmp_day;
		 String str_time = tmp_hour + ":" + tmp_minute;

		 return(String(str_date + ", " + str_time));
	 }

	 void setMotionStatus() {
		 if (isMotionEnable) {
			 if (this->hour < this->offHour) {
				 // do nothing
			 }
			 else {
				 this->isMotionEnable = false;
				 //generate nextDate
				 this->currentDate = String(this->day, DEC) + "." + String(this->month, DEC) + "." + String(this->year, DEC);
			 }
		 }
		 else if(!isMotionEnable) {
			 String tmpCurrentDate = String(this->day, DEC) + "." + String(this->month, DEC) + "." + String(this->year, DEC);

			 if (this->currentDate == tmpCurrentDate) {
				 //we have the same day yet - nothing to do
			 }
			 else {
				 //we habe next day
				 if (this->hour < this->onHour) {
					 //nothing to do
				 }
				 else {
					 isMotionEnable = true;
				 }
			 }
		 }
	 }

	 
};

extern timeClass time1;

#endif


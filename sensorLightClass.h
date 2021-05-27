// sensorLightClass.h

#ifndef _SENSORLIGHTCLASS_h
#define _SENSORLIGHTCLASS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class sensorLightClass
{
 public:
	 String name;
	 int light = 1900;
	 int valueToNight = 1800;

	 void setName(String x = "undefinedName") {
		 this->name = x;
	 }

	 bool isNight(){
		 if (this->light >= this->valueToNight){
			 return true;

		 }
		 else {
			 return false;
		 }

	 }

	 String get() {
		 return (String(this->name) + " value: " + String(this->light) + " valueN: " + String(this->valueToNight));
	 }
	 
};

extern sensorLightClass sensorLight;

#endif


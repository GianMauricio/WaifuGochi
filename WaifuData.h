#pragma once
#include "WaifuType.h"
#include "Gender.h"

class WaifuData {
private:
	WaifuType Type;
	Gender Sex;
	char sName[15];
	int nAffection = 20;

public:
	WaifuData(char name[], Gender gender, WaifuType newType) {
		//Copy Name
		strcpy(name, sName);

		//Set elements
		Sex = gender;
		Type = newType;
	}
};
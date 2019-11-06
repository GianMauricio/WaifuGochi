#pragma once
#include <string.h>
#include "WaifuType.h"
#include "Gender.h"

using namespace std;

class WaifuData {
private:
	WaifuType Type;
	Gender Sex;
	char sName[15];
	int nAffection = 20;

public:
	WaifuData(char name[], Gender gender, WaifuType newType) {
		//Copy Name
		strcpy_s(sName, name);

		//Set elements
		Sex = gender;
		Type = newType;
	}
};
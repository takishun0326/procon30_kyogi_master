#pragma once
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "picojson.h"
#include"../general.h"
#include"../Data/Agents.h"
#include"../Data/Map.h"
#include"../Data/Field.h"
#include"../Data/AgentsAction.h"


class CreateJson {
public:
	void createJson(string,string,string);
};
#pragma once
#include <fstream>
#include <string>
#include <stdlib.h>
#include "picojson.h"
#include "data/JsonOption.h"
#include"../general.h"

class FetchJson {
public:
	void fetch(string, string, int);
};

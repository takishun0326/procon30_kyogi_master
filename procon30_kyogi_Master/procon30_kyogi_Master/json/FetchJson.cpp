#include "FetchJson.h"

void FetchJson::fetch(string token, string query, int turn) {

	string auth = "\"Authorization: " + token + "\" ";
	string host = "http://10.10.52.252";
	string path = "/matches/" + query;
	string command = "curl -H " + auth + host + path + " > json/data/Map/turn" + to_string(turn) + ".json";
	system(command.c_str());
}


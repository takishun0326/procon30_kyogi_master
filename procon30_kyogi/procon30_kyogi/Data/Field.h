#pragma once
#include"../general.h"

class Field {
public:
	//TilePoints
	vector<vector<int>> points;
	//TiledPoints
	vector<vector<int>> tiled;


	vector<vector<vector<int>>> turnTiled;
	

	static Field* getField();

	//analusisField ‚à‚µ‚©‚µ‚½‚ç‚Â‚©‚¤‚©‚à
	vector<vector<int>> AnalysisField;

private:
	static Field* field;
};
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

	//analusisField �������������������
	vector<vector<int>> AnalysisField;

private:
	static Field* field;
};
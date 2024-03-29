#pragma once
#include "../general.h"

class Map {
public:
	static Map* getMap();
	//横
	int width;

	//縦
	int vertical;

	float startedAtUnixTime = 0;



	//自分のチームのスコア{総合点,タイル,領域},
	//相手				  {総合点,タイル,領域}
	vector<vector<int>> score;

	//ターン数
	int turn = 0;

	//最終ターン数
	int finalTurn = 20;

	//自分チームID
	int ourTeamID;

	//相手チームID
	int otherTeamID;


private:
	static Map* stayMap;
};
#pragma once
#include "../general.h"
#include"../Data/Map.h"
#include"../Data/Field.h"
#include"../Data/Agents.h"
#include"../gui/DrawMap.h"
#include"../Data/AgentsAction.h"
#include"../json/FetchJson.h"
#include"../json/ParseJson.h"
#include"../json/CreateJson.h"
#include"../Algorithm/Prefetting.h"

class DrawData {
public: 
	DrawData();
	GUI gui;
	void outputTurn();
	void drawDataManager();
	void drawTiledScore();
	void drawAreaScore();
	void drawSumScore();
	void manualDirection(const int numger);

	void PushedButton();
private:
	void tokenSetUp();
};

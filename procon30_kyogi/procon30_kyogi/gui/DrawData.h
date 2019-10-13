#pragma once
#include "../general.h"
#include"../Data/Map.h"
#include"../Data/Field.h"
#include"../Data/Agents.h"

class DrawData {
public: 
	DrawData();
	GUI gui;
	void outputTurn();
	void drawDataManager();
	void drawTiledScore();
	void drawAreaScore();
	void drawSumScore();

	void PushedButton();
private:
	void tokenSetUp();
};

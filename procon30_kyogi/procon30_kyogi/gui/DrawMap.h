#include"../Data/Agents.h"
#include"../Data/Field.h"
#include"../Data/Map.h"
#include"../gui/CreateMap.h"
#pragma once
class DrawMap {
public:
	void drawMapFrame();
	void drawMapState1();
	void drawMapState2();
	void drawMap1AgentsTurn();
	void drawMap2AgentsTurn();
	void drawMapPoint1();
	void drawMapPoint2();
	void drawMapLine1();
	void drawMapLine2();
	void drawMapManager();
};
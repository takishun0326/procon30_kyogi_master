#include"DrawMap.h"
#include"ManualInput.h"
//debug—p
//FrameMap
void DrawMap::drawMapFrame() {
	Map* map1;
	map1 = map1->getMap();
	CreateMap map;
	map.createMapFrame(map1->vertical, map1->width);
}

//StateMap
void DrawMap::drawMapState2() {
	Field* field;
	field = field->getField();
	Map* map;
	map = map->getMap();
	CreateMap create;
	for (int i = 0; i < map->vertical; i++) {
		for (int j = 0; j < map->width; j++) {
			create.createMapState1(field->tiled[i][j], i + 1, j + 1);
		}
	}
}

//AgentsMap
void DrawMap::drawMap2AgentsTurn() {
	Agents* agents;
	agents = agents->getAgents();
	Field* field;
	field = field->getField();
	CreateMap create;
	for (int i = 0; i < agents->ourAgents.size(); i++) {
			create.createMapAgent1(1, agents->ourAgents[i][1], agents->ourAgents[i][2]);
			create.createMapAgent1(2, agents->otherAgents[i][1], agents->otherAgents[i][2]);
	}
}

//PointMap
void DrawMap::drawMapPoint2() {
	Field* field;
	field = field->getField();
	Map* map;
	map = map->getMap();
	CreateMap create;
	for (int i = 0; i < map->vertical; i++) {
		for (int j = 0; j < map->width; j++) {
			create.createMapPoint1(field->points[i][j], i + 1, j + 1);
		}
	}
}

//LineMap2
void DrawMap::drawMapLine2() {
	Agents* agents;
	agents = agents->getAgents();
	Field* field;
	field = field->getField();
	Map* map;
	map = map->getMap();
	CreateMap create;
	for (int i = 0; i < agents->ourAgents.size(); i++) {
			create.createMapLine1(field->turnAgent[turn][i].first + 1, field->turnAgent[turn][i].second + 1, field->turnAgent[turn + 1][i].first + 1, field->turnAgent[turn + 1][i].second + 1);
	}
}

//DrawMapManager
void DrawMap::drawMapManager() {
	Map* map;
	map = map->getMap();
	drawMapState2();

	//manualInput
	ManualInput manualInput;
	manualInput.mousePosition();
	if (map->click == true) {
		manualInput.clickedMap(map->x, map->y);
	}

	drawMap2AgentsTurn();
	drawMapPoint2();
	drawMapLine2();
	drawMapFrame();
}
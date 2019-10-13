# include <Siv3D.hpp>
#include"..//procon30_kyogi/gui/DrawMap.h"
#include"..//procon30_kyogi/gui/DrawData.h"
	
	
void Main()
{
	//jsonなかったら無限ループ
	//iOManager.init();
	Map *map;
	map = map->getMap();

	DrawData drawData;
	Profiler::EnableWarning(false);

	DrawMap drawMap;

	while (System::Update()) {
		//drawManager
		drawData.drawDataManager();

	}
}

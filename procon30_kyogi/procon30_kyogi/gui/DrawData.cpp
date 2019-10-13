#include "DrawData.h"



DrawData::DrawData() 
	: gui(GUIStyle::Default) {

	gui.setTitle(L"kyogi");
	gui.setPos(0, 0);


	//Title
	gui.addln(L"json_option", GUIText::Create(L"JSON_option"));

	//Token
	gui.add(L"token_name", GUIText::Create(L"トークン"));
	gui.addln(L"token", GUITextArea::Create(1, 14));

	//MatchID
	gui.add(L"matchNumberText", GUIText::Create(L"試合ID"));
	gui.addln(L"matchNumber", GUITextArea::Create(1, 2));

	//analysis
	gui.addln(L"AnalysButton", GUIButton::Create(L"Analys計算"));

	//JsonFile読み込み
	gui.addln(L"getJSON", GUIButton::Create(L"MapJSON取得"));

	//Input
	//水平線
	gui.add(GUIText::Create(L"Input"));
	gui.add(L"hr", GUIHorizontalLine::Create(1));
	gui.horizontalLine(L"hr").style.color = Color(127);


	//最大ターン数
	//全探索で使う
	gui.add(L"textMT", GUIText::Create(L"終了ターン数"));
	gui.add(L"readMT", GUITextArea::Create(1, 2));
	gui.addln(L"btnMT", GUIButton::Create(L"決定"));

	//チームID
	//青
	gui.add(L"text9", GUIText::Create(L"自チームID        :"));
	gui.text(L"text9").style.color = Palette::Blue;
	gui.addln(L"blueID", GUITextArea::Create(1, 3, none, false));

	//赤
	gui.add(L"text10", GUIText::Create(L"敵チームID          :"));
	gui.text(L"text10").style.color = Palette::Red;
	gui.addln(L"redID", GUITextArea::Create(1, 3, none, false));
	//ID入力ボタン
	gui.addln(L"bt4", GUIButton::Create(L"ID入力"));


	//水平線
	gui.add(L"hr", GUIHorizontalLine::Create(1));
	gui.horizontalLine(L"hr").style.color = Color(127);

	//ポイント
	//水平線
	gui.add(GUIText::Create(L"Point"));
	gui.add(L"hr", GUIHorizontalLine::Create(1));
	gui.horizontalLine(L"hr").style.color = Color(127);

	//青Ourタイルポイント
	gui.add(L"text1", GUIText::Create(L"自タイル　:"));
	gui.text(L"text1").style.color = Palette::Blue;
	gui.add(L"OurTileScore", GUITextArea::Create(1, 5));

	//赤otherタイルポイント
	gui.add(L"text2", GUIText::Create(L"敵タイル　:"));
	gui.text(L"text2").style.color = Palette::Red;
	gui.addln(L"OtherTileScore", GUITextArea::Create(1, 5));

	//青our領域ポイント
	gui.add(L"text3", GUIText::Create(L"自領域　　:"));
	gui.text(L"text3").style.color = Palette::Blue;
	gui.add(L"OurAreaScore", GUITextArea::Create(1, 5));

	//赤other領域ポイント
	gui.add(L"text4", GUIText::Create(L"敵領域　　:"));
	gui.text(L"text4").style.color = Palette::Red;
	gui.addln(L"OtherAreaScore", GUITextArea::Create(1, 5));

	//青Our合計ポイント
	gui.add(L"text5", GUIText::Create(L"自合計　　:"));
	gui.text(L"text5").style.color = Palette::Blue;
	gui.add(L"OurSumScore", GUITextArea::Create(1, 5));

	//赤other合計ポイント
	gui.add(L"text6", GUIText::Create(L"敵合計　　:"));
	gui.text(L"text6").style.color = Palette::Red;
	gui.addln(L"OtherSumScore", GUITextArea::Create(1, 5));

	//水平線
	gui.add(L"hr", GUIHorizontalLine::Create(1));
	gui.horizontalLine(L"hr").style.color = Color(127);

	//Information
	//水平線
	gui.add(GUIText::Create(L"Information"));
	gui.add(L"hr", GUIHorizontalLine::Create(1));
	gui.horizontalLine(L"hr").style.color = Color(127);


	//ターン数
	gui.add(L"text7", GUIText::Create(L"ターン数 ："));
	gui.add(L"turn", GUITextArea::Create(1, 5));

	// Windowの設定
	Window::Resize(1920, 1080);
	const Size targetSize(1920, 1080);
	//バックグラウンドを白
	Graphics::SetBackground(Palette::Gray);
	outputTurn();
}



//一括実行
void DrawData::drawDataManager() {
	Map* map;
	map = map->getMap();
	//DrawMap drawMap;
	drawTiledScore();
	drawAreaScore();
	drawSumScore();
	
	PushedButton();
	
	//drawData();
	//drawMap.drawMapManager(map->mapChange);
	tokenSetUp();
}




//ボタン入力関連をまとめた
void DrawData::PushedButton() {
	Map* map;
	map = map->getMap();
	
	
//json	
	if (gui.button(L"getJSON").pushed) {

	}
}







//タイル点表示更新
void DrawData::drawTiledScore() {
	Map* map;
	map = map->getMap();
	String OurTileScore;
	String OtherTileScore;

	OurTileScore = Widen(to_string(map->score[0][1]));
	OtherTileScore = Widen(to_string(map->score[1][1]));

	gui.textArea(L"OurTileScore").setText(OurTileScore);
	gui.textArea(L"OtherTileScore").setText(OtherTileScore);

}
//領域表示更新
void DrawData::drawAreaScore() {
	Map* map;
	map = map->getMap();

	String OurAreaScore = Widen(to_string(map->score[0][2]));
	String OtherAreaScore = Widen(to_string(map->score[1][2]));

	gui.textArea(L"OurAreaScore").setText(OurAreaScore);
	gui.textArea(L"OtherAreaScore").setText(OtherAreaScore);
}
//総合表示更新
void DrawData::drawSumScore() {
	Map* map;
	map = map->getMap();

	String OurSumScore = Widen(to_string(map->score[0][0]));
	String OtherSumScore = Widen(to_string(map->score[1][0]));

	gui.textArea(L"OurSumScore").setText(OurSumScore);
	gui.textArea(L"OtherSumScore").setText(OtherSumScore);


	//ターン数
	gui.textArea(L"turn").setText(Widen(to_string(map->turn)));
}





//ターン表示
void DrawData::outputTurn() {
	Map *map;
	map = map->getMap();

	String Turn = Widen(to_string(map->turn));
	String Rturn = Widen(to_string(map->readTurn));


	gui.textArea(L"turn").setText(Turn);
	gui.textArea(L"ptnc").setText(Rturn);
}


void DrawData::tokenSetUp() {
	String Token = Widen("dbc07e57a1e7b1342c0570d0a4393a53bef552ac2c900f3d2c21dd68a40f3d8b");

	gui.textArea(L"token").setText(Token);
}

void DrawData::manualDirection(const int number) {
	GUI guiManual(GUIStyle::Default);
	Map* map;
	map = map->getMap();
	guiManual.add(L"btm1", GUIButton::Create(L"左上"));
	guiManual.add(L"btm2", GUIButton::Create(L"↑"));
	guiManual.addln(L"btm3", GUIButton::Create(L"右上"));
	guiManual.add(L"btm4", GUIButton::Create(L"←"));
	guiManual.add(L"btm5", GUIButton::Create(L" 待機  "));
	guiManual.addln(L"btm6", GUIButton::Create(L"→"));
	guiManual.add(L"btm7", GUIButton::Create(L"左下"));
	guiManual.add(L"btm8", GUIButton::Create(L"↓"));
	guiManual.addln(L"btm9", GUIButton::Create(L"右下"));
	guiManual.add(L"btm10", GUIButton::Create(L"キャンセル"));
	//guiManual.setPos(1500,800);
	guiManual.setPos(250, 800);

	DrawMap drawMap;
	AgentsAction* agentsAction;
	agentsAction = agentsAction->getAgentsAction();
	while (System::Update()) {
		drawMap.drawMapManager();

		//上段
		if (guiManual.button(L"btm1").pushed) {
			agentsAction->actionDxDy[number][0].second.first = -1;
			agentsAction->actionDxDy[number][0].second.second = -1;
			map->click = false;
			break;
		}
		if (guiManual.button(L"btm2").pushed) {
			agentsAction->actionDxDy[number][0].second.first = 0;
			agentsAction->actionDxDy[number][0].second.second = -1;
			map->click = false;
			break;
		}
		if (guiManual.button(L"btm3").pushed) {
			agentsAction->actionDxDy[number][0].second.first = 1;
			agentsAction->actionDxDy[number][0].second.second = -1;
			map->click = false;
			break;
		}
		//中段
		if (guiManual.button(L"btm4").pushed) {
			agentsAction->actionDxDy[number][0].second.first = -1;
			agentsAction->actionDxDy[number][0].second.second = 0;
			map->click = false;
			break;
		}
		if (guiManual.button(L"btm5").pushed) {
			agentsAction->actionDxDy[number][0].second.first = 0;
			agentsAction->actionDxDy[number][0].second.second = 0;
			map->click = false;
			break;
		}
		if (guiManual.button(L"btm6").pushed) {
			agentsAction->actionDxDy[number][0].second.first = 1;
			agentsAction->actionDxDy[number][0].second.second = 0;
			map->click = false;
			break;
		}
		//花壇
		if (guiManual.button(L"btm7").pushed) {
			agentsAction->actionDxDy[number][0].second.first = -1;
			agentsAction->actionDxDy[number][0].second.second = 1;
			map->click = false;
			break;
		}
		if (guiManual.button(L"btm8").pushed) {
			agentsAction->actionDxDy[number][0].second.first = 0;
			agentsAction->actionDxDy[number][0].second.second = 1;
			map->click = false;
			break;
		}
		if (guiManual.button(L"btm9").pushed) {
			agentsAction->actionDxDy[number][0].second.first = 1;
			agentsAction->actionDxDy[number][0].second.second = 1;
			map->click = false;
			break;
		}
		//キャンセル
		if (guiManual.button(L"btm10").pushed) {
			map->click = false;
			break;
		}
	}
}


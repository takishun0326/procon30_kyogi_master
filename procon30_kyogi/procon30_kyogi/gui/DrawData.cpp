#include "DrawData.h"


DrawData::DrawData() 
	: gui(GUIStyle::Defalut) {

	gui.setTitle(L"kyogi");
	gui.setPos(0, 0);


	//Title
	gui.addln(L"json_option", GUIText::Create(L"JSON_option"));

	//Token
	gui.add(L"token_name", GUIText::Create(L"�g�[�N��"));
	gui.addln(L"token", GUITextArea::Create(1, 14));

	//MatchID
	gui.add(L"matchNumberText", GUIText::Create(L"����ID"));
	gui.addln(L"matchNumber", GUITextArea::Create(1, 2));

	//analysis
	gui.addln(L"AnalysButton", GUIButton::Create(L"Analys�v�Z"));

	//JsonFile�ǂݍ���
	gui.addln(L"getJSON", GUIButton::Create(L"MapJSON�擾"));

	//Input
	//������
	gui.add(GUIText::Create(L"Input"));
	gui.add(L"hr", GUIHorizontalLine::Create(1));
	gui.horizontalLine(L"hr").style.color = Color(127);


	//�ő�^�[����
	//�S�T���Ŏg��
	gui.add(L"textMT", GUIText::Create(L"�I���^�[����"));
	gui.add(L"readMT", GUITextArea::Create(1, 2));
	gui.addln(L"btnMT", GUIButton::Create(L"����"));

	//�`�[��ID
	//��
	gui.add(L"text9", GUIText::Create(L"���`�[��ID        :"));
	gui.text(L"text9").style.color = Palette::Blue;
	gui.addln(L"blueID", GUITextArea::Create(1, 3, none, false));

	//��
	gui.add(L"text10", GUIText::Create(L"�G�`�[��ID          :"));
	gui.text(L"text10").style.color = Palette::Red;
	gui.addln(L"redID", GUITextArea::Create(1, 3, none, false));
	//ID���̓{�^��
	gui.addln(L"bt4", GUIButton::Create(L"ID����"));


	//������
	gui.add(L"hr", GUIHorizontalLine::Create(1));
	gui.horizontalLine(L"hr").style.color = Color(127);

	//�|�C���g
	//������
	gui.add(GUIText::Create(L"Point"));
	gui.add(L"hr", GUIHorizontalLine::Create(1));
	gui.horizontalLine(L"hr").style.color = Color(127);

	//��Our�^�C���|�C���g
	gui.add(L"text1", GUIText::Create(L"���^�C���@:"));
	gui.text(L"text1").style.color = Palette::Blue;
	gui.add(L"OurTileScore", GUITextArea::Create(1, 5));

	//��other�^�C���|�C���g
	gui.add(L"text2", GUIText::Create(L"�G�^�C���@:"));
	gui.text(L"text2").style.color = Palette::Red;
	gui.addln(L"OtherTileScore", GUITextArea::Create(1, 5));

	//��our�̈�|�C���g
	gui.add(L"text3", GUIText::Create(L"���̈�@�@:"));
	gui.text(L"text3").style.color = Palette::Blue;
	gui.add(L"OurAreaScore", GUITextArea::Create(1, 5));

	//��other�̈�|�C���g
	gui.add(L"text4", GUIText::Create(L"�G�̈�@�@:"));
	gui.text(L"text4").style.color = Palette::Red;
	gui.addln(L"OtherAreaScore", GUITextArea::Create(1, 5));

	//��Our���v�|�C���g
	gui.add(L"text5", GUIText::Create(L"�����v�@�@:"));
	gui.text(L"text5").style.color = Palette::Blue;
	gui.add(L"OurSumScore", GUITextArea::Create(1, 5));

	//��other���v�|�C���g
	gui.add(L"text6", GUIText::Create(L"�G���v�@�@:"));
	gui.text(L"text6").style.color = Palette::Red;
	gui.addln(L"OtherSumScore", GUITextArea::Create(1, 5));

	//������
	gui.add(L"hr", GUIHorizontalLine::Create(1));
	gui.horizontalLine(L"hr").style.color = Color(127);

	//Information
	//������
	gui.add(GUIText::Create(L"Information"));
	gui.add(L"hr", GUIHorizontalLine::Create(1));
	gui.horizontalLine(L"hr").style.color = Color(127);


	//�^�[����
	gui.add(L"text7", GUIText::Create(L"�^�[���� �F"));
	gui.add(L"turn", GUITextArea::Create(1, 5));

	// Window�̐ݒ�
	Window::Resize(1920, 1080);
	const Size targetSize(1920, 1080);
	//�o�b�N�O���E���h��
	Graphics::SetBackground(Palette::Gray);
	outputTurn();
}



//�ꊇ���s
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




//�{�^�����͊֘A���܂Ƃ߂�
void DrawData::PushedButton() {
	Map* map;
	map = map->getMap();
	
	
//json	
	if (gui.button(L"getJSON").pushed) {

	}
}







//�^�C���_�\���X�V
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
//�̈�\���X�V
void DrawData::drawAreaScore() {
	Map* map;
	map = map->getMap();

	String OurAreaScore = Widen(to_string(map->score[0][2]));
	String OtherAreaScore = Widen(to_string(map->score[1][2]));

	gui.textArea(L"OurAreaScore").setText(OurAreaScore);
	gui.textArea(L"OtherAreaScore").setText(OtherAreaScore);
}
//�����\���X�V
void DrawData::drawSumScore() {
	Map* map;
	map = map->getMap();

	String OurSumScore = Widen(to_string(map->score[0][0]));
	String OtherSumScore = Widen(to_string(map->score[1][0]));

	gui.textArea(L"OurSumScore").setText(OurSumScore);
	gui.textArea(L"OtherSumScore").setText(OtherSumScore);


	//�^�[����
	gui.textArea(L"turn").setText(Widen(to_string(map->turn)));
}





//�^�[���\��
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

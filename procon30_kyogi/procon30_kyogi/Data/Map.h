#pragma once
#include "../general.h"

class Map {
public:
	static Map* getMap();
	//��
	int width;

	//�c
	int vertical;

	float startedAtUnixTime = 0;



	//�����̃`�[���̃X�R�A{�����_,�^�C��,�̈�},
	//����				  {�����_,�^�C��,�̈�}
	vector<vector<int>> score;

	//�^�[����
	int turn = 0;

	//�ŏI�^�[����
	int finalTurn = 20;

	//�����`�[��ID
	int ourTeamID;

	//����`�[��ID
	int otherTeamID;

	//
	int x, y;
	bool click;


private:
	static Map* stayMap;
};
#pragma once
#include"../general.h"

class Agents {
public:
	//{{agentID,x,y},{......}}
	//�����`�[��
	//Agents() : ourAgents() {};



	vector<vector<int>> ourAgents;
	//ourAgents() {};

	//����`�[��
	vector<vector<int>> otherAgents;
	//otherAgents();

	//actiondxdy 0 agentsnum,1 x, 2 y
	vector<pair<int, pair<int,int>>>actionDxDy;


	static Agents* getAgents();

private:
	static Agents* AllAgents;

};

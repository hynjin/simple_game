/*
장애물과 부딪혀는지를 판단하는 부분
밧줄과 닿았는지
땅을 딛고 있는지
장애물과 닿았는지
등을 판단
*/
#pragma once
#include "Stdafx.h"
#include "Define.h"
#include "loading.h"

class crush
{
public:
	crush();
	~crush();

	void call();
	int badack_check(double,double,int &che);
	int rope_check(double,double,int &che);
	int tump_check(double,double,int &che);
	int home_check(double,double,int &che);
	int dark_check(double,double,int &che);

	void Getdark(D3DXVECTOR3 dark_vector);//움직이는 장애물의 좌표를 받아옴

	void fall(double &,double &);

	class obstacle ob;

	vector<node> tumph;
	vector<node> badackh;
	vector<node> ropeh;
	vector<node> homeh;

	int cnt;
	int stage;

private:
	loading load;
	
	float darkx;
	float darky;

};
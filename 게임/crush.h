/*
��ֹ��� �ε��������� �Ǵ��ϴ� �κ�
���ٰ� ��Ҵ���
���� ��� �ִ���
��ֹ��� ��Ҵ���
���� �Ǵ�
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

	void Getdark(D3DXVECTOR3 dark_vector);//�����̴� ��ֹ��� ��ǥ�� �޾ƿ�

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
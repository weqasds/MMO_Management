#pragma once
#include"..\..\pch.h"
#include "..\SqlManager\ORM.h"
class Menu
{
public:
	Menu(ORM& c);//���캯��
	void Login();//��¼
	void Main_Menu();//���˵�
	void Data_Manipulation();//���ݲ��ݹ���
	void Data_RB_Menu();//���ݱ��ݻ�ԭ�˵�
	void Advanced_Menu();//�߼��˵�
	void Data_Restore();//���ݻ�ԭ����
	void Data_Backup();//���ݱ��ݹ���
	void Console();//����̨ʹ��
	void Apply();//����
	void Data_Maintenance();//����ά��
	void Data_Migrate();//����Ǩ��
	void Add();//���ӱ��
	void Delete();//ɾ�����
	~Menu();
private:
	Admin admin;
	ORM& cache;
};


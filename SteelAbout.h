#pragma once
#ifndef _STEEL_ABOUT_H_
#define _STEEL_ABOUT_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::map;
using std::vector;
using std::string;

struct SteelInfo
{//���,		���,	����,	������,	��������,		����ʱ��
	int		 m_iNO;
	int		 m_iStandard;//guige
	int		 m_iType;//gangzhong
	int		 m_iDateYear;
	int		 m_iDateMonth;
	int		 m_iDateDay;
	int		 m_iDestination;
	double	 m_dPeriod;

	void InfoShow()
	{
		cout<<"���"<< this->m_iNO<< "\t"
			<<"���"<< this->m_iStandard<< "\t"
			<<"����"<< this->m_iType<< "\t"
			<<"������"<< this->m_iDateYear<< "/"<< this->m_iDateMonth<< "/"<< this->m_iDateDay<< "\t" 
			<<"����"<< this->m_iDestination<< "\t"
			<<"����ʱ��"<< this->m_dPeriod<< endl;
	}
};
class SteelAbout
{
public:
	SteelAbout(const string& strFileName);	
	double punishment(const int iNOold, const int iNOnew); 
	void SortByType();	
	void str2YMD(const string& strOri, int& iY, int& iM, int &D);

private:
	SteelAbout()
	{
	}

private:
	vector<SteelInfo>	m_aInfos;
	int					m_iCount;
	//map<int, int>		m_mapNoIndex;
};

#endif
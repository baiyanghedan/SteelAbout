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
{//编号,		规格,	钢种,	交货期,	发车方向,		轧制时长
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
		cout<<"编号"<< this->m_iNO<< "\t"
			<<"规格"<< this->m_iStandard<< "\t"
			<<"钢种"<< this->m_iType<< "\t"
			<<"交货期"<< this->m_iDateYear<< "/"<< this->m_iDateMonth<< "/"<< this->m_iDateDay<< "\t" 
			<<"方向"<< this->m_iDestination<< "\t"
			<<"轧制时间"<< this->m_dPeriod<< endl;
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
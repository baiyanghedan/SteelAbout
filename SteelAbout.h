#pragma once
#ifndef _STEEL_ABOUT_H_
#define _STEEL_ABOUT_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <assert.h>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::map;
using std::vector;
using std::string;

struct SteelInfo
{
	int		 m_iNO;
	int		 m_iStandard;
	int		 m_iType;
	int		 m_iDateYear;
	int		 m_iDateMonth;
	int		 m_iDateDay;
	int		 m_iDestination;
	double	 m_dPeriod;
};
class SteelAbout
{
public:
	explicit SteelAbout(string strFileName);	
	double punishment(const int iNOold, const int iNOnew); 
	bool compare(const int a, const int b)
	{
		
		//if(this->m_mapNoIndex.count(a) > 0 && this->m_mapNoIndex.count(b) > 0);
	}
private:
	SteelAbout()
	{
	}

private:
	map<int, int>		m_mapNoIndex;
	vector<SteelInfo>	m_aInfos;
	int					m_iCount;
};

#endif
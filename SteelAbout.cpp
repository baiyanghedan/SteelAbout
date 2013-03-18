#include "SteelAbout.h"

SteelAbout::SteelAbout(const string& strFileName)
{
	std::ifstream ifsFile(strFileName.c_str());
	if(NULL == ifsFile)
	{//exception
		std::cout<< "no such a file"<< std::endl;
		return;
	}

	std::string strTmp;
	std::getline(ifsFile, strTmp);//skip the first line
	struct SteelInfo infoTmp;
	this->m_iCount = 0;
	//编号,		规格,	钢种,	交货期,	发车方向,		轧制时长
	//iNO,	iStandard,	iType,	iYear+iMonth+iDay,	iDestination,	iPeriod
	while(std::getline(ifsFile, strTmp))
	{
		//std::cout<< strTmp<< std::endl;
		unsigned int iTmp1 = strTmp.find(",", 0);
		if(iTmp1 <= strTmp.length())
		{//has , in the line
			unsigned int iTmp2 = strTmp.find(",", 0 + iTmp1 + 1);
			unsigned int iTmp3 = strTmp.find(",", 0 + iTmp2 + 1);
			unsigned int iTmp4 = strTmp.find(",", 0 + iTmp3 + 1);
			unsigned int iTmp5 = strTmp.find(",", 0 + iTmp4 + 1);

			//std::cout<< strTmp.substr(0, iTmp1)//no
			//	<< " || "
			//	<<strTmp.substr(iTmp1+1, iTmp2 - iTmp1 - 1)//standard
			//	<<" || "
			//	<<strTmp.substr(iTmp2+1, iTmp3 - iTmp2 - 1)//type
			//	<<" || "
			//	<<strTmp.substr(iTmp3+1, iTmp4 - iTmp3 - 1)//time
			//	<<" || "
			//	<<strTmp.substr(iTmp4+1, iTmp5 - iTmp4 - 1)//iDestination
			//	<<" || "
			//	<<strTmp.substr(iTmp5+1, strTmp.length() - iTmp5 - 1)//period
			//	<<std::endl;
			
			//tmp initialization
			infoTmp.m_iNO = atoi(strTmp.substr(0, iTmp1).c_str());
			infoTmp.m_iStandard = atoi(strTmp.substr(iTmp1+1, iTmp2 - iTmp1 - 1).c_str());
			infoTmp.m_iType = atoi(strTmp.substr(iTmp2+1, iTmp3 - iTmp2 - 1).c_str());
			str2YMD(strTmp.substr(iTmp3+1, iTmp4 - iTmp3 - 1), 
				infoTmp.m_iDateYear, infoTmp.m_iDateMonth, infoTmp.m_iDateDay);
			infoTmp.m_iDestination = atoi(strTmp.substr(iTmp4+1, iTmp5 - iTmp4 - 1).c_str());
			infoTmp.m_dPeriod = atof(strTmp.substr(iTmp5+1, strTmp.length() - iTmp5 - 1).c_str());
			
			//tmp in cart
			this->m_aInfos.push_back(infoTmp);
			this->m_iCount++;
			/*
			if(this->m_mapNoIndex.count(infoTmp.m_iNO))
			{
#ifdef _DEBUG
				std::cerr<< "@line:"<< __LINE__;
#endif
				std::cerr<< "Bad data"<< endl;
			}
			else
			{
				this->m_mapNoIndex[infoTmp.m_iNO] = this->m_iCount - 1;
			}*/
		}
	}

	//cout<< "Total NO: "<< this->m_iCount<< endl;
	
}

int compare(const void *a, const void *b)
{
	/*assert(this->m_mapNoIndex.count(a) > 0 
		&& this->m_mapNoIndex.count(b) > 0);*/
	const SteelInfo* pa = static_cast<const SteelInfo*>(a);
	const SteelInfo* pb = static_cast<const SteelInfo*>(b);

	if(pa->m_iType != pb->m_iType)
	{
		return (pa->m_iType - pb->m_iType);
	}
	else
	{
		return (pa->m_iNO - pb->m_iNO);
	}
}

void SteelAbout::SortByType()
{
	qsort( &(this->m_aInfos[0]), this->m_iCount, sizeof(SteelInfo), compare);
	for(int i = 0; i<5 && i<this->m_iCount; ++i)
	{
		this->m_aInfos[i].InfoShow();
	}
}

void SteelAbout::str2YMD(const string& strOri, int& iY, int& iM, int&iD)
{
	int iIndex1 = strOri.find("/", 0);
	int iIndex2 = strOri.find("/", iIndex1+1);
	iY = atoi( strOri.substr( 0, iIndex1 ).c_str( ) );
	iM = atoi( strOri.substr( iIndex1+1, iIndex2-iIndex1-1 ).c_str( ) );
	iD = atoi( strOri.substr( iIndex2+1, strOri.length()-iIndex2-1 ).c_str( ) );
}
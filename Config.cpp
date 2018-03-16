/*************************************************************************
    > File Name: Config.cpp
    > Author: berli
    > Mail: libo_5@163.com 
    > Created Time: 2018年03月16日 星期五 11时33分00秒
 ************************************************************************/

#include <unistd.h> 
#include <fstream> 
#include "Config.h"
#include "easylogging++.h"

int Config::InitConfig(const string&asFile)
{
	if(access(asFile.c_str(), R_OK) != 0)
	{
		LOG(ERROR)<<"Can't access "<<asFile<<" failed!";
		return -1;
	}
	ifstream ifr(asFile.c_str(), ios::binary|ios::in);
	if( ifr.bad())
	{
		LOG(ERROR)<<"Can't read "<<asFile<<" failed!";
		return -2;
	}
	ifr.seekg (0, ios::end);
	csConfigData.reserve(ifr.tellg() );
	ifr.seekg (0, ios::beg);

	std::stringstream buffer;
	buffer<<ifr.rdbuf();
	buffer.str()>>csConfigData;

	return 0;
}

string Config::getFieldValue(const string&asField)
{
	string lsRet;
	jsonxx::Object obj;
	obj.parse(csConfigData);
	if( obj.has<String>(asField))
	{
		lsRet = obj.get<String>(asField);
	}

	return lsRet;
}

vector<string> Config::getFieldArray(const string&asField)
{
	vector<string> lVecRet;

	jsonxx::Object obj;
	obj.parse(csConfigData);
	if(obj.has<Array>(asField))
	{
		Array v = obj.get<Array>(asField);
		for(int i = 0; i < v.size(); i++)
			lVecRet.push_back(v.get<string>(i));
	}

	return lVecRet;
}

map<string, string> Config::getFieldPair(const string&asField)
{
	map<string, string> lMapRet;

	return lMapRet;
}


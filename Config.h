/*************************************************************************
    > File Name: Config.h
    > Author: berli
    > Mail: libo_5@163.com 
    > Created Time: 2018年03月16日 星期五 11时21分51秒
 ************************************************************************/
#ifndef CONFIG_H_H
#define CONFIG_H_H

#include<iostream>
using namespace std;

class Config
{
public:
	int InitConfig(const string&asFile);

	string getFieldValue(const string&asField);
	vector<string> getFieldArray(const string&asField);
	map<string, string> getFieldPair(const string&asField);

protected:

	string csConfigData;//json 

};

#endif


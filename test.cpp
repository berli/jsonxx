#include "jsonxx.h"
#include <iostream>
#include <string>
using namespace jsonxx;
using namespace std;

int main()
{
   string lsjson = "{\"sentence\":[\"x\",\"y\"]}";
   jsonxx::Object obj;
   obj.parse(lsjson);
   if(obj.has<Array>("sentence"))
   {
   Array v = obj.get<Array>("sentence");
   for(int i = 0; i < v.size(); i++)
     cout<<v.get<string>(i)<<endl;
   }
   
}

// icecli3-5.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <Ice/Ice.h>
#include "Printer.h"
using namespace Demo;
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
    int status = 0;
    Ice::CommunicatorPtr ic;
    try {
        ic = Ice::initialize();
        Ice::ObjectPrx base = ic->stringToProxy(
                "SimplePrinter:default -h 172.16.124.8 -p 10000");
        PrinterPrx printer = PrinterPrx::checkedCast(base);
        if (!printer)
            throw "Invalid proxy";

#if 1
		int i = 0;
		while(i<1000)
		{
			i++;
			char buf[100]={"Hello World "};
			sprintf(buf,"%s %d",buf,i);
			printf(buf);
			printer->printString(buf);
		}
#endif
    } catch (const Ice::Exception & ex) {
        cerr << ex << endl;
        status = 1;
    } catch (const char * msg) {
        cerr << msg << endl;
        status = 1;
    }
    if (ic)
        ic->destroy();
    return 0;
}


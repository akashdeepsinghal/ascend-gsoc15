
#include "tchar.h"
#include<iostream>
#include<Windows.h>
#include <string>
#include <xstring>
#include "C:\dtl.tlh"
using namespace DTL;


int _tmain(int argc, _TCHAR* argv[])
{
	  BSTR Comp = NULL;
	  Comp = SysAllocString ( L"Methane" );
	  BSTR Prop = NULL;
	  Prop = SysAllocString ( L"vaporPressure" );
	  int T = 0;
	  double VapPres = 0;
	  CoInitialize(NULL);
	 _CalculatorPtr ptrinterface(_uuidof(Calculator));
	 
	// Initialize COM.
	 
	
	 double x = 0;
	 ptrinterface->Initialize();
	 
	 for (T = 300;T<1000;T++)
	 {
		 ptrinterface->GetCompoundTDepProp(Comp,Prop,T,&VapPres);
		 std::cout<<VapPres<<std::endl;
	 //std::cout<< VapPres << std::endl;
	 }
	 
	 CoUninitialize();
	 SysFreeString ( Comp );
	 SysFreeString ( Prop );
    return 0;
}

	 
	


	
	
	

    // Create the interface pointer.
    
    
    // Uninitialize COM.
   // CoUninitialize();
 //   return 0;
//}


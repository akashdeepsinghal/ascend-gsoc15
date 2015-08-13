#include "C:\Python27\include\Python.h"

double Property(char *Comp, char *Prop, char *PropType, double TorP)
{
	PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *pTorP, *ptype, *pArgs, *pcomp, *pprop;
	double mw = 0.0;

	// Initialize the Python Interpreter
	Py_Initialize();

	// Build the name object
	pName = PyString_FromString("py_function");

	// Load the module object
	pModule = PyImport_Import(pName);

	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	pFunc = PyDict_GetItemString(pDict, "Properties");

	// pFunc is also a borrowed reference 
	if (PyCallable_Check(pFunc))
	{
		// Prepare the argument list for the call

		pArgs = PyTuple_New(4);
		ptype = PyString_FromString(PropType);
		pcomp = PyString_FromString(Comp);
		pprop = PyString_FromString(Prop);
		pTorP = PyFloat_FromDouble(TorP);
		PyTuple_SetItem(pArgs, 0, pcomp);
		PyTuple_SetItem(pArgs, 1, pprop);
		PyTuple_SetItem(pArgs, 2, ptype);
		PyTuple_SetItem(pArgs, 3, pTorP);

		pValue = PyObject_CallObject(pFunc, pArgs);
		mw = PyFloat_AsDouble(pValue);

		if (pArgs != NULL)
		{
			Py_DECREF(pArgs);
		}

		else
		{
			pValue = PyObject_CallObject(pFunc, NULL);
		}

		if (pValue != NULL)
		{
			Py_DECREF(pValue);
		}
		else
		{
			PyErr_Print();
		}

		// some code omitted...
	}
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	return mw;
	// Finish the Python Interpreter
	Py_Finalize();


}

void TwoPhaseProperty(double mw[][4], char *propPack, double flashAlg, double pressure, double temp, char *comp1, char *comp2, double mf1, double mf2)
{
	PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *palg, *pArgs, *pcomp1, *pcomp2, *pmf1, *pmf2, *ptemp, *ppres, *ppack, *pi, *pj;
	//double mw = 0.0;
	// Initialize the Python Interpreter
	Py_Initialize();

	// Build the name object
	pName = PyString_FromString("py_function");

	// Load the module object
	pModule = PyImport_Import(pName);

	// pDict is a borrowed reference 

	pDict = PyModule_GetDict(pModule);
	pFunc = PyDict_GetItemString(pDict, "TwoPhaseProperties");

	// pFunc is also a borrowed reference 
	if (PyCallable_Check(pFunc))
	{
		// Prepare the argument list for the call

		pArgs = PyTuple_New(10);
		ppack = PyString_FromString(propPack);
		palg = PyFloat_FromDouble(flashAlg);
		ppres = PyFloat_FromDouble(pressure);
		ptemp = PyFloat_FromDouble(temp);
		pcomp1 = PyString_FromString(comp1);
		pcomp2 = PyString_FromString(comp2);
		pmf1 = PyFloat_FromDouble(mf1);
		pmf2 = PyFloat_FromDouble(mf2);



		PyTuple_SetItem(pArgs, 0, ppack);
		PyTuple_SetItem(pArgs, 1, palg);
		PyTuple_SetItem(pArgs, 2, ppres);
		PyTuple_SetItem(pArgs, 3, ptemp);
		PyTuple_SetItem(pArgs, 4, pcomp1);
		PyTuple_SetItem(pArgs, 5, pcomp2);
		PyTuple_SetItem(pArgs, 6, pmf1);
		PyTuple_SetItem(pArgs, 7, pmf2);
		int i, j;
		for (i = 0; i < 3; ++i)
			for (j = 0; j < 4; ++j)
			{
			pi = PyInt_FromLong(i);
			pj = PyInt_FromLong(j);
			PyTuple_SetItem(pArgs, 8, pi);
			PyTuple_SetItem(pArgs, 9, pj);
			pValue = PyObject_CallObject(pFunc, pArgs);
			mw[i][j] = PyFloat_AsDouble(pValue);
			}

		if (pArgs != NULL)
		{
			Py_DECREF(pArgs);
		}

		else
		{
			pValue = PyObject_CallObject(pFunc, NULL);
		}

		if (pValue != NULL)
		{

			Py_DECREF(pValue);
		}
		else
		{
			PyErr_Print();
		}

		// some code omitted...
	}
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);

	//return mw;
	// Finish the Python Interpreter
	//PyFinalize();

}


void binaryInteractionParameters(double mw[3], char *propPack, char *comp1, char *comp2)
{
	PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *pArgs, *pcomp1, *pcomp2, *ppack, *pi;
	//double mw = 0.0;
	// Initialize the Python Interpreter
	Py_Initialize();

	// Build the name object
	pName = PyString_FromString("py_function");

	// Load the module object
	pModule = PyImport_Import(pName);

	// pDict is a borrowed reference 

	pDict = PyModule_GetDict(pModule);
	pFunc = PyDict_GetItemString(pDict, "BinaryInteractionParameters");

	// pFunc is also a borrowed reference 
	if (PyCallable_Check(pFunc))
	{
		// Prepare the argument list for the call

		pArgs = PyTuple_New(4);
		ppack = PyString_FromString(propPack);
		pcomp1 = PyString_FromString(comp1);
		pcomp2 = PyString_FromString(comp2);


		PyTuple_SetItem(pArgs, 0, ppack);
		PyTuple_SetItem(pArgs, 1, pcomp1);
		PyTuple_SetItem(pArgs, 2, pcomp2);

		int i;
		for (i = 0; i<3; ++i){
			pi = PyInt_FromLong(i);
			PyTuple_SetItem(pArgs, 3, pi);
			pValue = PyObject_CallObject(pFunc, pArgs);
			mw[i] = PyFloat_AsDouble(pValue);
		}

		if (pArgs != NULL)
		{
			Py_DECREF(pArgs);
		}

		else
		{
			pValue = PyObject_CallObject(pFunc, NULL);
		}

		if (pValue != NULL)
		{
			printf("Return of call : %d\n", PyInt_AsLong(pValue));
			Py_DECREF(pValue);
		}
		else
		{
			PyErr_Print();
		}

		// some code omitted...
	}
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);

	//return mw;
	// Finish the Python Interpreter
	//	Py_Finalize();


}
void antoine2(double mw[], const char *comp)
{
	PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *pArgs, *pcomp, *pmw, *pi;

	// Initialize the Python Interpreter
	Py_Initialize();

	// Build the name object
	pName = PyString_FromString("py_function");

	// Load the module object
	pModule = PyImport_Import(pName);

	// pDict is a borrowed reference 

	pDict = PyModule_GetDict(pModule);
	pFunc = PyDict_GetItemString(pDict, "antoine");

	// pFunc is also a borrowed reference 
	if (PyCallable_Check(pFunc))
	{
		// Prepare the argument list for the call

		pArgs = PyTuple_New(2);
		pcomp = PyString_FromString(comp);
		//pmw = PyFloat_FromDouble(mw[0:2]);

		PyTuple_SetItem(pArgs, 0, pcomp);
		//PyTuple_SetItem(pArgs, 1, pmw);
		int i;
		for (i = 0; i <= 2; ++i) {
			pi = PyInt_FromLong(i);
			PyTuple_SetItem(pArgs, 1, pi);
			pValue = PyObject_CallObject(pFunc, pArgs);
			mw[i] = PyFloat_AsDouble(pValue);
		}


		if (pArgs != NULL)
		{
			Py_DECREF(pArgs);
		}

		else
		{
			pValue = PyObject_CallObject(pFunc, NULL);
		}

		if (pValue != NULL)
		{

			Py_DECREF(pValue);
		}
		else
		{
			PyErr_Print();
		}

		// some code omitted...
	}
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);

	//return mw;
	// Finish the Python Interpreter
	//Py_Finalize();

}

double calcP(char *comp, char *property, char *propType, double T0){
	double guess[6], Tguess[6], P;
	int i;
	guess[1] = 132300;
	guess[0] = 122310;
	/*clock_t time1 =clock();
	clock_t end;
	printf("%f", time1);*/
	for (i = 0; i < 2; i++)
	{
		Tguess[i] = Property(comp, property, propType, guess[i]);
		/* end = clock();
		printf("time ra time: %f\n", ((double)(end -	time1)) / CLOCKS_PER_SEC);*/
	}

	for (i = 2; i < 6; i++){
		if (fabs(Tguess[i - 1] - 339) > 0.01){
			guess[i] = guess[i - 1] - (Tguess[i - 1] - T0) * ((guess[i - 1] - guess[i - 2]) / (Tguess[i - 1] - Tguess[i - 2]));
			Tguess[i] = Property(comp, property, propType, guess[i]);
			/*end = clock();
			printf("final time: %f\n", ((double)(end - time1)) / CLOCKS_PER_SEC);*/
		}
		else {
			P = guess[i - 1]; printf("Pfinal else wala: %f\n", P);
			double T = Property(comp, property, propType, guess[i]);
			/*end = clock();
			printf("final time: %f\n", ((double)(end - time1))/CLOCKS_PER_SEC);
			printf("\n\n%f", T);*/

			return P;

		}
	}

	P = guess[5];
	/*printf("Pfinal: %f", P);
	double T = Property(comp, "boilingPointTemperature", "constPDepProp", P);
	printf("\n\n%f", T);
	printf("%f", time(NULL) - time1); */
	return P;
}



void Stream_Properties(char *proppack, char *compounds1, char *compounds2, double T, double P, double molefractions1, double molefractions2, double Results[])
{
	PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *pArgs, *pcomp, *pprop, *pcompound1, *pcompound2, *pycompounds, *pT, *pP, *pmf1, *pmf2, *pycomp, *ii;
	int i;


	// Initialize the Python Interpreter
	Py_Initialize();

	// Build the name object
	pName = PyString_FromString("StreamProperties");

	// Load the module object
	pModule = PyImport_Import(pName);

	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	pFunc = PyDict_GetItemString(pDict, "Stream_Properties");

	// pFunc is also a borrowed reference 
	if (PyCallable_Check(pFunc))
	{
		// Prepare the argument list for the call

		pArgs = PyTuple_New(5);


		pprop = PyString_FromString(proppack);
		pcompound1 = PyString_FromString(compounds1);
		pcompound2 = PyString_FromString(compounds2);
		pycompounds = PyTuple_New(2);
		PyTuple_SetItem(pycompounds, 0, pcompound1);
		PyTuple_SetItem(pycompounds, 1, pcompound2);

		pT = PyFloat_FromDouble(T);
		pP = PyFloat_FromDouble(P);

		pmf1 = PyFloat_FromDouble(molefractions1);
		pmf2 = PyFloat_FromDouble(molefractions2);
		pycomp = PyTuple_New(2);
		PyTuple_SetItem(pycomp, 0, pmf1);
		PyTuple_SetItem(pycomp, 1, pmf2);

		pArgs = PyTuple_New(8);
		PyTuple_SetItem(pArgs, 0, pprop);
		PyTuple_SetItem(pArgs, 1, pcompound1);
		PyTuple_SetItem(pArgs, 2, pcompound2);
		PyTuple_SetItem(pArgs, 3, pT);
		PyTuple_SetItem(pArgs, 4, pP);
		PyTuple_SetItem(pArgs, 5, pmf1);
		PyTuple_SetItem(pArgs, 6, pmf2);



		for (i = 0; i < 24; ++i)

		{
			ii = PyInt_FromLong(i);
			PyTuple_SetItem(pArgs, 7, ii);
			pValue = PyObject_CallObject(pFunc, pArgs);
			
			Results[i] = PyFloat_AsDouble(pValue);
			printf("%f\n", Results[i]);
		}

		if (pArgs != NULL)
		{
			Py_DECREF(pArgs);
		}
		
		else
		{
			pValue = PyObject_CallObject(pFunc, NULL);
		}
	

		if (pValue != NULL)
		{
			//printf("Return of call : %d\n", PyInt_AsLong(pValue));
			//Py_DECREF(pValue);
		}
		else
		{
			//PyErr_Print();
		}

		// some code omitted...
	}
	// Clean up
	
	Py_DECREF(pModule);
	Py_DECREF(pName);
	
	// Finish the Python Interpreter
	//Py_Finalize();

}
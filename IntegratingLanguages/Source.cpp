#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;

// print menu
void PrintMenu() {

	cout << "1: Display a Multipication Table" << endl;
	cout << "2: Double a Value" << endl;
	cout << "3: Exit" << endl;
	cout << "Enter your selection as a number 1, 2, or 3: ";
}

// included in starter cpp file to call py file
void CallProcedure(string pName) {
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

// included in starter cpp file to call py file
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject *pName, *pModule, *pDict, *pFunc, *pValue = nullptr, *presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

// included in starter cpp file to call py file
int callIntFunc(string proc, int param)
{
	char *procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject *pName, *pModule, *pDict, *pFunc, *pValue = nullptr, *presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

void main() {
	int userInputMenu; // get user input 1, 2, or 3
	int userInput; // number for multiplication table or to double value

	PrintMenu();
	cin >> userInputMenu;

	system("CLS"); // clears output

	while (userInputMenu >= 4) { // if user input anything other than 1, 2, or 3, an error message will appear
		cout << "ERROR: Please select 1, 2, or 3" << endl << endl;
		PrintMenu();
		cin >> userInputMenu; // allow them to pick the right number
		cout << endl;
	}

	system("CLS"); // clears output

	if (userInputMenu == 1) {
		cout << "Pick a number for the multiplication table: ";
		cin >> userInput;
		cout << endl;
		cout << callIntFunc("MultiplicationTable", userInput) << endl;
	}

	else if (userInputMenu == 2) {
		cout << "Pick a number you want to double: ";
		cin >> userInput;
		cout << endl;
		cout << callIntFunc("DoubleValue", userInput) << endl; // calls function from py file
	}

	else if (userInputMenu == 3) {
		exit;
	}
	
	return;
}
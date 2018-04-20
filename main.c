#include <stdio.h>
#include <Python/Python.h>

#include <stdlib.h>
int main()
{
    char *logFN[100];
    sprintf(logFN, "%s_CWL.log", (char *) "test");
    
    printf(logFN);
    
    return 0;
    // Set PYTHONPATH TO working directory
    setenv("PYTHONPATH",".",1);
    
    PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *presult;
    
    
    // Initialize the Python Interpreter
    Py_Initialize();
    
    
    // Build the name object
    pName = PyString_FromString((char*)"arbName");
    
    // Load the module object
    pModule = PyImport_Import(pName);
    
    
    // pDict is a borrowed reference
    pDict = PyModule_GetDict(pModule);
    
    
    // pFunc is also a borrowed reference
    pFunc = PyDict_GetItemString(pDict, (char*)"someFunction");
    
    if (PyCallable_Check(pFunc))
    {
        pValue=Py_BuildValue("(z)",(char*)"something");
        PyErr_Print();
        printf("Let's give this a shot!\n");
        presult=PyObject_CallObject(pFunc,pValue);
        PyErr_Print();
    } else {
        PyErr_Print();
    }
    printf("Result is %ld\n",PyInt_AsLong(presult));
    Py_DECREF(pValue);
    
    // Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);
    
    // Finish the Python Interpreter
    Py_Finalize();
    
    
    return 0;
}

//
//long sum_list(PyObject *list)
//{
//    Py_ssize_t i, n;
//    long total = 0, value;
//    PyObject *item;
//
//    n = PyList_Size(list);
//    if (n < 0)
//        return -1;
//    for (i = 0; i < n; i++) {
//        item = PyList_GetItem(list, i);
//        if (!PyLong_Check(item)) continue;
//        value = PyLong_AsLong(item);
//        if (value == -1 && PyErr_Occurred())
//            return -1;
//        total += value;
//    }
//    return total;
//}
//
//long sum_sequence(PyObject *sequence)
//{
//    Py_ssize_t i, n;
//    long total = 0, value;
//    PyObject *item;
//    n = PySequence_Size(sequence);
//    if (n < 0)
//        return -1;
//    for (i = 0; i < n; i++) {
//        item = PySequence_GetItem(sequence, i);
//        if (item == NULL)
//            return -1;
//        if (PyLong_Check(item)) {
//            value = PyLong_AsLong(item);
//            Py_DECREF(item);
//            if (value == -1 && PyErr_Occurred())
//                return -1;
//            total += value;
//        } else {
//            Py_DECREF(item);
//        }
//    }
//    return total;
//}
//
//
//int main(int argc, char **argv)
//{
//    PyObject *t;
//
//    t = PyTuple_New(3);
//    PyTuple_SetItem(t, 0, PyLong_FromLong(1l));
//    PyTuple_SetItem(t, 0, PyLong_FromLong(2l));
//    PyTuple_SetItem(t, 0, PyUnicode_FromString("three"));
//
//    PyObject *tuple, *list;
//    tuple = Py_BuildValue("(iis)", 1, 2, "three");
//    list = Py_BuildValue("[iis]", 1, 2, "three");
//
//
//    return 0;
//}


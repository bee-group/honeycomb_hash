#include <Python.h>

#include "honeycomb.h"

static PyObject *honeycomb_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    honeycomb_hash((char *)PyBytes_AsString((PyObject*) input), (int)PyBytes_Size((PyObject*) input), output);
#else
    honeycomb_hash((char *)PyString_AsString((PyObject*) input), (int)PyString_Size((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef HoneyCombMethods[] = {
    { "getPoWHash", honeycomb_getpowhash, METH_VARARGS, "Returns the proof of work hash using honeycomb hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef HoneyCombModule = {
    PyModuleDef_HEAD_INIT,
    "honeycomb_hash",
    "...",
    -1,
    HoneyCombMethods
};

PyMODINIT_FUNC PyInit_honeycomb_hash(void) {
    return PyModule_Create(&HoneyCombModule);
}

#else

PyMODINIT_FUNC inithoneycomb_hash(void) {
    (void) Py_InitModule("honeycomb_hash", HoneyCombMethods);
}
#endif

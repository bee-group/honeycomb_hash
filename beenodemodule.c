#include <Python.h>

#include "beenode.h"

static PyObject *beenode_getpowhash(PyObject *self, PyObject *args)
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
    beenode_hash((char *)PyBytes_AsString((PyObject*) input), (int)PyBytes_Size((PyObject*) input), output);
#else
    beenode_hash((char *)PyString_AsString((PyObject*) input), (int)PyString_Size((PyObject*) input), output);
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

static PyMethodDef BeenodeMethods[] = {
    { "getPoWHash", beenode_getpowhash, METH_VARARGS, "Returns the proof of work hash using beenode hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef BeenodeModule = {
    PyModuleDef_HEAD_INIT,
    "beenode_hash",
    "...",
    -1,
    BeenodeMethods
};

PyMODINIT_FUNC PyInit_beenode_hash(void) {
    return PyModule_Create(&BeenodeModule);
}

#else

PyMODINIT_FUNC initbeenode_hash(void) {
    (void) Py_InitModule("beenode_hash", BeenodeMethods);
}
#endif

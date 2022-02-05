#include <Python.h>
#include "simulator/simulator.h"

#define GETSTATE(m) ((struct module_state*)PyModule_GetState(m))

struct module_state {
    PyObject* error;
};

struct Simulator simulator;

static PyObject* generate(PyObject* self, PyObject* args) {
    long start_time;
    long seed;
    const char *dir;
    long iter;
    int verbose;
    if (!PyArg_ParseTuple(args,
                          "llslp",
                          &start_time,
                          &seed,
                          &dir,
                          &iter,
                          &verbose)) {
        return NULL;
    }
    simulator_initialize(&simulator, start_time, seed, dir);
    simulator_run(&simulator, iter, verbose);
    Py_RETURN_NONE;
}


static PyMethodDef _base_methods[] = {
    {"generate", (PyCFunction)generate, METH_VARARGS, NULL},
    {0}
};

static int _base_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static int _base_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "sinstagram.generator._base",
    NULL,
    sizeof(struct module_state),
    _base_methods,
    NULL,
    _base_traverse,
    _base_clear,
    NULL
};

PyMODINIT_FUNC PyInit__base(void) {
    PyObject *module = PyModule_Create(&moduledef);
    if (!module) return NULL;
    return module;
}

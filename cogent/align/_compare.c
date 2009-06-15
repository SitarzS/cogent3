/* Generated by Pyrex 0.9.8.5 on Mon Jun 15 12:44:27 2009 */

#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "structmember.h"
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#if PY_VERSION_HEX < 0x02050000
  typedef int Py_ssize_t;
  #define PY_SSIZE_T_MAX INT_MAX
  #define PY_SSIZE_T_MIN INT_MIN
  #define PyInt_FromSsize_t(z) PyInt_FromLong(z)
  #define PyInt_AsSsize_t(o)	PyInt_AsLong(o)
#endif
#if !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
#endif
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif
#include <math.h>


typedef struct {PyObject **p; int i; char *s; long n;} __Pyx_StringTabEntry; /*proto*/

static PyObject *__pyx_m;
static PyObject *__pyx_b;
static int __pyx_lineno;
static char *__pyx_filename;
static char **__pyx_f;

static char __pyx_mdoc[] = "50x speedup for dotplots, but sequences must be strings and scoring is based on identity only\n";

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name); /*proto*/

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb); /*proto*/

static int __Pyx_PrintItem(PyObject *); /*proto*/
static int __Pyx_PrintNewline(void); /*proto*/

static PyObject *__Pyx_UnpackItem(PyObject *); /*proto*/
static int __Pyx_EndUnpack(PyObject *); /*proto*/

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t); /*proto*/

static void __Pyx_AddTraceback(char *funcname); /*proto*/

/* Declarations from cogent.align._compare */


/* Declarations from implementation of cogent.align._compare */

static int __pyx_f_6cogent_5align_8_compare_cmax(int,int); /*proto*/
static int __pyx_f_6cogent_5align_8_compare_cmin(int,int); /*proto*/

static char __pyx_k1[] = "max";
static char __pyx_k2[] = "range";
static char __pyx_k3[] = "min";
static char __pyx_k4[] = "pop";
static char __pyx_k5[] = "append";

static PyObject *__pyx_n_append;
static PyObject *__pyx_n_max;
static PyObject *__pyx_n_min;
static PyObject *__pyx_n_pop;
static PyObject *__pyx_n_range;


static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_n_append, 1, __pyx_k5, sizeof(__pyx_k5)},
  {&__pyx_n_max, 1, __pyx_k1, sizeof(__pyx_k1)},
  {&__pyx_n_min, 1, __pyx_k3, sizeof(__pyx_k3)},
  {&__pyx_n_pop, 1, __pyx_k4, sizeof(__pyx_k4)},
  {&__pyx_n_range, 1, __pyx_k2, sizeof(__pyx_k2)},
  {0, 0, 0, 0}
};



/* Implementation of cogent.align._compare */

static int __pyx_f_6cogent_5align_8_compare_cmax(int __pyx_v_a,int __pyx_v_b) {
  int __pyx_r;
  int __pyx_1;
  __pyx_1 = (__pyx_v_a > __pyx_v_b);
  if (__pyx_1) {
    __pyx_r = __pyx_v_a;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  /*else*/ {
    __pyx_r = __pyx_v_b;
    goto __pyx_L0;
  }
  __pyx_L2:;

  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

static int __pyx_f_6cogent_5align_8_compare_cmin(int __pyx_v_a,int __pyx_v_b) {
  int __pyx_r;
  int __pyx_1;
  __pyx_1 = (__pyx_v_a < __pyx_v_b);
  if (__pyx_1) {
    __pyx_r = __pyx_v_a;
    goto __pyx_L0;
    goto __pyx_L2;
  }
  /*else*/ {
    __pyx_r = __pyx_v_b;
    goto __pyx_L0;
  }
  __pyx_L2:;

  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

static PyObject *__pyx_f_6cogent_5align_8_compare_dotplot(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_6cogent_5align_8_compare_dotplot[] = "List of ((x1,y1), (x2,y2)) for diagonal line segments scoring >= threshold/window";
static PyObject *__pyx_f_6cogent_5align_8_compare_dotplot(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  char *__pyx_v_seq1;
  char *__pyx_v_seq2;
  int __pyx_v_window;
  int __pyx_v_threshold;
  PyObject *__pyx_v_min_gap_length = 0;
  PyObject *__pyx_v_band = 0;
  int __pyx_v_progress;
  int __pyx_v_was_high;
  int __pyx_v_score;
  int __pyx_v_i;
  int __pyx_v_i_lo;
  int __pyx_v_i_hi;
  int __pyx_v_diagonal;
  int __pyx_v_j;
  int __pyx_v_k;
  int __pyx_v_start;
  int __pyx_v_len1;
  int __pyx_v_len2;
  int __pyx_v_end;
  int __pyx_v_scores[100];
  PyObject *__pyx_v_result;
  PyObject *__pyx_v_forget1;
  PyObject *__pyx_v_jumped_end;
  PyObject *__pyx_v_forget2;
  PyObject *__pyx_r;
  PyObject *__pyx_1 = 0;
  Py_ssize_t __pyx_2;
  int __pyx_3;
  PyObject *__pyx_4 = 0;
  PyObject *__pyx_5 = 0;
  PyObject *__pyx_6 = 0;
  PyObject *__pyx_7 = 0;
  PyObject *__pyx_8 = 0;
  static char *__pyx_argnames[] = {"seq1","seq2","window","threshold","min_gap_length","band","progress",0};
  if (!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "ssiiOOi", __pyx_argnames, &__pyx_v_seq1, &__pyx_v_seq2, &__pyx_v_window, &__pyx_v_threshold, &__pyx_v_min_gap_length, &__pyx_v_band, &__pyx_v_progress)) return 0;
  Py_INCREF(__pyx_v_min_gap_length);
  Py_INCREF(__pyx_v_band);
  __pyx_v_result = Py_None; Py_INCREF(Py_None);
  __pyx_v_forget1 = Py_None; Py_INCREF(Py_None);
  __pyx_v_jumped_end = Py_None; Py_INCREF(Py_None);
  __pyx_v_forget2 = Py_None; Py_INCREF(Py_None);

  /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":33 */
  #ifndef PYREX_WITHOUT_ASSERTIONS
  if (!(__pyx_v_window < 100)) {
    PyErr_SetNone(PyExc_AssertionError);
    {__pyx_filename = __pyx_f[0]; __pyx_lineno = 33; goto __pyx_L1;}
  }
  #endif

  /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":34 */
  __pyx_1 = PyString_FromString(__pyx_v_seq1); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 34; goto __pyx_L1;}
  __pyx_2 = PyObject_Length(__pyx_1); if (__pyx_2 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 34; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_v_len1 = __pyx_2;

  /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":35 */
  __pyx_1 = PyString_FromString(__pyx_v_seq2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 35; goto __pyx_L1;}
  __pyx_2 = PyObject_Length(__pyx_1); if (__pyx_2 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 35; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_v_len2 = __pyx_2;

  /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":36 */
  __pyx_1 = PyList_New(0); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 36; goto __pyx_L1;}
  Py_DECREF(__pyx_v_result);
  __pyx_v_result = __pyx_1;
  __pyx_1 = 0;

  /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":37 */
  __pyx_3 = __pyx_v_band == Py_None;
  if (__pyx_3) {
    __pyx_1 = __Pyx_GetName(__pyx_b, __pyx_n_max); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 38; goto __pyx_L1;}
    __pyx_4 = PyInt_FromLong(__pyx_v_len1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 38; goto __pyx_L1;}
    __pyx_5 = PyInt_FromLong(__pyx_v_len2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 38; goto __pyx_L1;}
    __pyx_6 = PyTuple_New(2); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 38; goto __pyx_L1;}
    PyTuple_SET_ITEM(__pyx_6, 0, __pyx_4);
    PyTuple_SET_ITEM(__pyx_6, 1, __pyx_5);
    __pyx_4 = 0;
    __pyx_5 = 0;
    __pyx_4 = PyObject_CallObject(__pyx_1, __pyx_6); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 38; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_6); __pyx_6 = 0;
    Py_DECREF(__pyx_v_band);
    __pyx_v_band = __pyx_4;
    __pyx_4 = 0;
    goto __pyx_L2;
  }
  __pyx_L2:;

  /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":39 */
  __pyx_5 = __Pyx_GetName(__pyx_b, __pyx_n_range); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  __pyx_1 = PyInt_FromLong((-1)); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  __pyx_6 = __Pyx_GetName(__pyx_b, __pyx_n_min); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  __pyx_4 = PyInt_FromLong(__pyx_v_len1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  __pyx_7 = PyTuple_New(2); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_7, 0, __pyx_4);
  Py_INCREF(__pyx_v_band);
  PyTuple_SET_ITEM(__pyx_7, 1, __pyx_v_band);
  __pyx_4 = 0;
  __pyx_4 = PyObject_CallObject(__pyx_6, __pyx_7); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  Py_DECREF(__pyx_6); __pyx_6 = 0;
  Py_DECREF(__pyx_7); __pyx_7 = 0;
  __pyx_6 = PyNumber_Multiply(__pyx_1, __pyx_4); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_7 = __Pyx_GetName(__pyx_b, __pyx_n_min); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  __pyx_1 = PyInt_FromLong(__pyx_v_len2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_4, 0, __pyx_1);
  Py_INCREF(__pyx_v_band);
  PyTuple_SET_ITEM(__pyx_4, 1, __pyx_v_band);
  __pyx_1 = 0;
  __pyx_1 = PyObject_CallObject(__pyx_7, __pyx_4); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  Py_DECREF(__pyx_7); __pyx_7 = 0;
  Py_DECREF(__pyx_4); __pyx_4 = 0;
  __pyx_7 = PyInt_FromLong(1); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  __pyx_4 = PyNumber_Add(__pyx_1, __pyx_7); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_7); __pyx_7 = 0;
  __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  PyTuple_SET_ITEM(__pyx_1, 0, __pyx_6);
  PyTuple_SET_ITEM(__pyx_1, 1, __pyx_4);
  __pyx_6 = 0;
  __pyx_4 = 0;
  __pyx_7 = PyObject_CallObject(__pyx_5, __pyx_1); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  Py_DECREF(__pyx_5); __pyx_5 = 0;
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_6 = PyObject_GetIter(__pyx_7); if (!__pyx_6) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
  Py_DECREF(__pyx_7); __pyx_7 = 0;
  for (;;) {
    __pyx_4 = PyIter_Next(__pyx_6);
    if (!__pyx_4) {
      if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
      break;
    }
    __pyx_3 = PyInt_AsLong(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 39; goto __pyx_L1;}
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_v_diagonal = __pyx_3;

    /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":40 */
    __pyx_3 = PyErr_CheckSignals();
    if (__pyx_3) {
      __pyx_5 = PyErr_Occurred(); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 41; goto __pyx_L1;}
      __Pyx_Raise(__pyx_5, 0, 0);
      Py_DECREF(__pyx_5); __pyx_5 = 0;
      {__pyx_filename = __pyx_f[0]; __pyx_lineno = 41; goto __pyx_L1;}
      goto __pyx_L5;
    }
    __pyx_L5:;

    /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":42 */
    __pyx_v_was_high = 0;

    /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":43 */
    __pyx_1 = PyInt_FromLong((-1)); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 43; goto __pyx_L1;}
    __pyx_7 = PyInt_FromLong(1); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 43; goto __pyx_L1;}
    __pyx_4 = PyNumber_Add(__pyx_v_min_gap_length, __pyx_7); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 43; goto __pyx_L1;}
    Py_DECREF(__pyx_7); __pyx_7 = 0;
    __pyx_5 = PyNumber_Multiply(__pyx_1, __pyx_4); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 43; goto __pyx_L1;}
    Py_DECREF(__pyx_1); __pyx_1 = 0;
    Py_DECREF(__pyx_4); __pyx_4 = 0;
    __pyx_3 = PyInt_AsLong(__pyx_5); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 43; goto __pyx_L1;}
    Py_DECREF(__pyx_5); __pyx_5 = 0;
    __pyx_v_end = __pyx_3;

    /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":44 */
    for (__pyx_v_i = 0; __pyx_v_i < __pyx_v_window; ++__pyx_v_i) {
      (__pyx_v_scores[__pyx_v_i]) = 0;
    }

    /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":46 */
    __pyx_v_score = 0;

    /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":47 */
    __pyx_v_i_lo = __pyx_f_6cogent_5align_8_compare_cmax(0,(0 - __pyx_v_diagonal));

    /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":48 */
    __pyx_v_i_hi = __pyx_f_6cogent_5align_8_compare_cmin(__pyx_v_len1,(__pyx_v_len2 - __pyx_v_diagonal));

    /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":49 */
    __pyx_3 = __pyx_v_progress;
    if (__pyx_3) {
      __pyx_3 = ((__pyx_v_diagonal % 100) == 0);
      if (__pyx_3) {
        __pyx_7 = PyInt_FromLong(__pyx_v_diagonal); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        if (__Pyx_PrintItem(__pyx_7) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        Py_DECREF(__pyx_7); __pyx_7 = 0;
        __pyx_1 = PyInt_FromLong(__pyx_v_i_lo); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        __pyx_4 = PyInt_FromLong((__pyx_v_i_lo + __pyx_v_diagonal)); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        PyTuple_SET_ITEM(__pyx_5, 0, __pyx_1);
        PyTuple_SET_ITEM(__pyx_5, 1, __pyx_4);
        __pyx_1 = 0;
        __pyx_4 = 0;
        if (__Pyx_PrintItem(__pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        __pyx_7 = PyInt_FromLong(__pyx_v_i_hi); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        __pyx_1 = PyInt_FromLong((__pyx_v_i_hi + __pyx_v_diagonal)); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        PyTuple_SET_ITEM(__pyx_4, 0, __pyx_7);
        PyTuple_SET_ITEM(__pyx_4, 1, __pyx_1);
        __pyx_7 = 0;
        __pyx_1 = 0;
        if (__Pyx_PrintItem(__pyx_4) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        Py_DECREF(__pyx_4); __pyx_4 = 0;
        __pyx_2 = PyObject_Length(__pyx_v_result); if (__pyx_2 == -1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        __pyx_5 = PyInt_FromSsize_t(__pyx_2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        if (__Pyx_PrintItem(__pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        Py_DECREF(__pyx_5); __pyx_5 = 0;
        if (__Pyx_PrintNewline() < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 51; goto __pyx_L1;}
        goto __pyx_L9;
      }
      __pyx_L9:;
      goto __pyx_L8;
    }
    __pyx_L8:;

    /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":52 */
    for (__pyx_v_i = __pyx_v_i_lo; __pyx_v_i < __pyx_v_i_hi; ++__pyx_v_i) {

      /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":53 */
      __pyx_v_j = (__pyx_v_i + __pyx_v_diagonal);

      /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":54 */
      __pyx_v_k = (__pyx_v_i % __pyx_v_window);

      /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":55 */
      __pyx_v_score -= (__pyx_v_scores[__pyx_v_k]);

      /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":56 */
      (__pyx_v_scores[__pyx_v_k]) = ((__pyx_v_seq1[__pyx_v_i]) == (__pyx_v_seq2[__pyx_v_j]));

      /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":57 */
      __pyx_v_score += (__pyx_v_scores[__pyx_v_k]);

      /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":58 */
      __pyx_3 = (__pyx_v_score >= __pyx_v_threshold);
      if (__pyx_3) {
        __pyx_3 = (!__pyx_v_was_high);
        if (__pyx_3) {

          /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":60 */
          __pyx_v_start = __pyx_f_6cogent_5align_8_compare_cmax(__pyx_v_i_lo,(__pyx_v_i - __pyx_v_window));

          /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":61 */
          __pyx_v_was_high = 1;
          goto __pyx_L13;
        }
        __pyx_L13:;
        goto __pyx_L12;
      }
      /*else*/ {
        __pyx_3 = __pyx_v_was_high;
        if (__pyx_3) {

          /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":64 */
          __pyx_7 = PyInt_FromLong((__pyx_v_start - __pyx_v_end)); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 64; goto __pyx_L1;}
          if (PyObject_Cmp(__pyx_7, __pyx_v_min_gap_length, &__pyx_3) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 64; goto __pyx_L1;}
          __pyx_3 = __pyx_3 < 0;
          Py_DECREF(__pyx_7); __pyx_7 = 0;
          if (__pyx_3) {
            __pyx_1 = PyObject_GetAttr(__pyx_v_result, __pyx_n_pop); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            __pyx_4 = PyObject_CallObject(__pyx_1, 0); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            Py_DECREF(__pyx_1); __pyx_1 = 0;
            __pyx_5 = PyObject_GetIter(__pyx_4); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            Py_DECREF(__pyx_4); __pyx_4 = 0;
            __pyx_7 = __Pyx_UnpackItem(__pyx_5); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            __pyx_1 = PyObject_GetIter(__pyx_7); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            Py_DECREF(__pyx_7); __pyx_7 = 0;
            __pyx_4 = __Pyx_UnpackItem(__pyx_1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            __pyx_3 = PyInt_AsLong(__pyx_4); if (PyErr_Occurred()) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            Py_DECREF(__pyx_4); __pyx_4 = 0;
            __pyx_v_start = __pyx_3;
            __pyx_7 = __Pyx_UnpackItem(__pyx_1); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            Py_DECREF(__pyx_v_forget1);
            __pyx_v_forget1 = __pyx_7;
            __pyx_7 = 0;
            if (__Pyx_EndUnpack(__pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            Py_DECREF(__pyx_1); __pyx_1 = 0;
            __pyx_4 = __Pyx_UnpackItem(__pyx_5); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            __pyx_7 = PyObject_GetIter(__pyx_4); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            Py_DECREF(__pyx_4); __pyx_4 = 0;
            __pyx_1 = __Pyx_UnpackItem(__pyx_7); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            Py_DECREF(__pyx_v_jumped_end);
            __pyx_v_jumped_end = __pyx_1;
            __pyx_1 = 0;
            __pyx_4 = __Pyx_UnpackItem(__pyx_7); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            Py_DECREF(__pyx_v_forget2);
            __pyx_v_forget2 = __pyx_4;
            __pyx_4 = 0;
            if (__Pyx_EndUnpack(__pyx_7) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            Py_DECREF(__pyx_7); __pyx_7 = 0;
            if (__Pyx_EndUnpack(__pyx_5) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 65; goto __pyx_L1;}
            Py_DECREF(__pyx_5); __pyx_5 = 0;
            goto __pyx_L15;
          }
          __pyx_L15:;

          /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":66 */
          __pyx_v_end = (__pyx_v_i - 1);

          /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":67 */
          __pyx_1 = PyObject_GetAttr(__pyx_v_result, __pyx_n_append); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 67; goto __pyx_L1;}
          __pyx_4 = PyInt_FromLong(__pyx_v_start); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 67; goto __pyx_L1;}
          __pyx_7 = PyInt_FromLong((__pyx_v_start + __pyx_v_diagonal)); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 67; goto __pyx_L1;}
          __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 67; goto __pyx_L1;}
          PyTuple_SET_ITEM(__pyx_5, 0, __pyx_4);
          PyTuple_SET_ITEM(__pyx_5, 1, __pyx_7);
          __pyx_4 = 0;
          __pyx_7 = 0;
          __pyx_4 = PyInt_FromLong(__pyx_v_end); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 67; goto __pyx_L1;}
          __pyx_7 = PyInt_FromLong((__pyx_v_end + __pyx_v_diagonal)); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 67; goto __pyx_L1;}
          __pyx_8 = PyTuple_New(2); if (!__pyx_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 67; goto __pyx_L1;}
          PyTuple_SET_ITEM(__pyx_8, 0, __pyx_4);
          PyTuple_SET_ITEM(__pyx_8, 1, __pyx_7);
          __pyx_4 = 0;
          __pyx_7 = 0;
          __pyx_4 = PyTuple_New(2); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 67; goto __pyx_L1;}
          PyTuple_SET_ITEM(__pyx_4, 0, __pyx_5);
          PyTuple_SET_ITEM(__pyx_4, 1, __pyx_8);
          __pyx_5 = 0;
          __pyx_8 = 0;
          __pyx_7 = PyTuple_New(1); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 67; goto __pyx_L1;}
          PyTuple_SET_ITEM(__pyx_7, 0, __pyx_4);
          __pyx_4 = 0;
          __pyx_5 = PyObject_CallObject(__pyx_1, __pyx_7); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 67; goto __pyx_L1;}
          Py_DECREF(__pyx_1); __pyx_1 = 0;
          Py_DECREF(__pyx_7); __pyx_7 = 0;
          Py_DECREF(__pyx_5); __pyx_5 = 0;

          /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":68 */
          __pyx_v_was_high = 0;
          goto __pyx_L14;
        }
        __pyx_L14:;
      }
      __pyx_L12:;
    }

    /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":69 */
    __pyx_3 = __pyx_v_was_high;
    if (__pyx_3) {

      /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":70 */
      __pyx_v_end = (__pyx_v_i - 1);

      /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":71 */
      __pyx_8 = PyObject_GetAttr(__pyx_v_result, __pyx_n_append); if (!__pyx_8) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
      __pyx_4 = PyInt_FromLong(__pyx_v_start); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
      __pyx_1 = PyInt_FromLong((__pyx_v_start + __pyx_v_diagonal)); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
      __pyx_7 = PyTuple_New(2); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
      PyTuple_SET_ITEM(__pyx_7, 0, __pyx_4);
      PyTuple_SET_ITEM(__pyx_7, 1, __pyx_1);
      __pyx_4 = 0;
      __pyx_1 = 0;
      __pyx_5 = PyInt_FromLong(__pyx_v_end); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
      __pyx_4 = PyInt_FromLong((__pyx_v_end + __pyx_v_diagonal)); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
      __pyx_1 = PyTuple_New(2); if (!__pyx_1) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
      PyTuple_SET_ITEM(__pyx_1, 0, __pyx_5);
      PyTuple_SET_ITEM(__pyx_1, 1, __pyx_4);
      __pyx_5 = 0;
      __pyx_4 = 0;
      __pyx_5 = PyTuple_New(2); if (!__pyx_5) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
      PyTuple_SET_ITEM(__pyx_5, 0, __pyx_7);
      PyTuple_SET_ITEM(__pyx_5, 1, __pyx_1);
      __pyx_7 = 0;
      __pyx_1 = 0;
      __pyx_4 = PyTuple_New(1); if (!__pyx_4) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
      PyTuple_SET_ITEM(__pyx_4, 0, __pyx_5);
      __pyx_5 = 0;
      __pyx_7 = PyObject_CallObject(__pyx_8, __pyx_4); if (!__pyx_7) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 71; goto __pyx_L1;}
      Py_DECREF(__pyx_8); __pyx_8 = 0;
      Py_DECREF(__pyx_4); __pyx_4 = 0;
      Py_DECREF(__pyx_7); __pyx_7 = 0;
      goto __pyx_L16;
    }
    __pyx_L16:;
  }
  Py_DECREF(__pyx_6); __pyx_6 = 0;

  /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":72 */
  Py_INCREF(__pyx_v_result);
  __pyx_r = __pyx_v_result;
  goto __pyx_L0;

  __pyx_r = Py_None; Py_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_4);
  Py_XDECREF(__pyx_5);
  Py_XDECREF(__pyx_6);
  Py_XDECREF(__pyx_7);
  Py_XDECREF(__pyx_8);
  __Pyx_AddTraceback("cogent.align._compare.dotplot");
  __pyx_r = 0;
  __pyx_L0:;
  Py_DECREF(__pyx_v_result);
  Py_DECREF(__pyx_v_forget1);
  Py_DECREF(__pyx_v_jumped_end);
  Py_DECREF(__pyx_v_forget2);
  Py_DECREF(__pyx_v_min_gap_length);
  Py_DECREF(__pyx_v_band);
  return __pyx_r;
}

static struct PyMethodDef __pyx_methods[] = {
  {"dotplot", (PyCFunction)__pyx_f_6cogent_5align_8_compare_dotplot, METH_VARARGS|METH_KEYWORDS, __pyx_doc_6cogent_5align_8_compare_dotplot},
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); /*proto*/

PyMODINIT_FUNC init_compare(void); /*proto*/
PyMODINIT_FUNC init_compare(void) {
  __pyx_init_filenames();
  __pyx_m = Py_InitModule4("_compare", __pyx_methods, __pyx_mdoc, 0, PYTHON_API_VERSION);
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  Py_INCREF(__pyx_m);
  __pyx_b = PyImport_AddModule("__builtin__");
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; goto __pyx_L1;};

  /* "/Users/mcdonald/ResearchWork/PyCogent-v1.1/cogent/align/_compare.pyx":21 */
  return;
  __pyx_L1:;
  __Pyx_AddTraceback("cogent.align._compare");
}

static char *__pyx_filenames[] = {
  "_compare.pyx",
};

/* Runtime support code */

static void __pyx_init_filenames(void) {
  __pyx_f = __pyx_filenames;
}

static PyObject *__Pyx_GetName(PyObject *dict, PyObject *name) {
    PyObject *result;
    result = PyObject_GetAttr(dict, name);
    if (!result)
        PyErr_SetObject(PyExc_NameError, name);
    return result;
}

static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb) {
    Py_XINCREF(type);
    Py_XINCREF(value);
    Py_XINCREF(tb);
    /* First, check the traceback argument, replacing None with NULL. */
    if (tb == Py_None) {
        Py_DECREF(tb);
        tb = 0;
    }
    else if (tb != NULL && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto raise_error;
    }
    /* Next, replace a missing value with None */
    if (value == NULL) {
        value = Py_None;
        Py_INCREF(value);
    }
    #if PY_VERSION_HEX < 0x02050000
    if (!PyClass_Check(type))
    #else
    if (!PyType_Check(type))
    #endif
    {
        /* Raising an instance.  The value should be a dummy. */
        if (value != Py_None) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto raise_error;
        }
        /* Normalize to raise <class>, <instance> */
        Py_DECREF(value);
        value = type;
        #if PY_VERSION_HEX < 0x02050000
            if (PyInstance_Check(type)) {
                type = (PyObject*) ((PyInstanceObject*)type)->in_class;
                Py_INCREF(type);
            }
            else {
                PyErr_SetString(PyExc_TypeError,
                    "raise: exception must be an old-style class or instance");
                goto raise_error;
            }
        #else
            type = (PyObject*) type->ob_type;
            Py_INCREF(type);
            if (!PyType_IsSubtype((PyTypeObject *)type, (PyTypeObject *)PyExc_BaseException)) {
                PyErr_SetString(PyExc_TypeError,
                    "raise: exception class must be a subclass of BaseException");
                goto raise_error;
            }
        #endif
    }
    PyErr_Restore(type, value, tb);
    return;
raise_error:
    Py_XDECREF(value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
    return;
}

static PyObject *__Pyx_GetStdout(void) {
    PyObject *f = PySys_GetObject("stdout");
    if (!f) {
        PyErr_SetString(PyExc_RuntimeError, "lost sys.stdout");
    }
    return f;
}

static int __Pyx_PrintItem(PyObject *v) {
    PyObject *f;
    
    if (!(f = __Pyx_GetStdout()))
        return -1;
    if (PyFile_SoftSpace(f, 1)) {
        if (PyFile_WriteString(" ", f) < 0)
            return -1;
    }
    if (PyFile_WriteObject(v, f, Py_PRINT_RAW) < 0)
        return -1;
    if (PyString_Check(v)) {
        char *s = PyString_AsString(v);
        Py_ssize_t len = PyString_Size(v);
        if (len > 0 &&
            isspace(Py_CHARMASK(s[len-1])) &&
            s[len-1] != ' ')
                PyFile_SoftSpace(f, 0);
    }
    return 0;
}

static int __Pyx_PrintNewline(void) {
    PyObject *f;
    
    if (!(f = __Pyx_GetStdout()))
        return -1;
    if (PyFile_WriteString("\n", f) < 0)
        return -1;
    PyFile_SoftSpace(f, 0);
    return 0;
}

static void __Pyx_UnpackError(void) {
    PyErr_SetString(PyExc_ValueError, "unpack sequence of wrong size");
}

static PyObject *__Pyx_UnpackItem(PyObject *iter) {
    PyObject *item;
    if (!(item = PyIter_Next(iter))) {
        if (!PyErr_Occurred())
            __Pyx_UnpackError();
    }
    return item;
}

static int __Pyx_EndUnpack(PyObject *iter) {
    PyObject *item;
    if ((item = PyIter_Next(iter))) {
        Py_DECREF(item);
        __Pyx_UnpackError();
        return -1;
    }
    else if (!PyErr_Occurred())
        return 0;
    else
        return -1;
}

static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        if (!*t->p)
            return -1;
        if (t->i)
            PyString_InternInPlace(t->p);
        ++t;
    }
    return 0;
}

#include "compile.h"
#include "frameobject.h"
#include "traceback.h"

static void __Pyx_AddTraceback(char *funcname) {
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    PyObject *py_globals = 0;
    PyObject *empty_tuple = 0;
    PyObject *empty_string = 0;
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    
    py_srcfile = PyString_FromString(__pyx_filename);
    if (!py_srcfile) goto bad;
    py_funcname = PyString_FromString(funcname);
    if (!py_funcname) goto bad;
    py_globals = PyModule_GetDict(__pyx_m);
    if (!py_globals) goto bad;
    empty_tuple = PyTuple_New(0);
    if (!empty_tuple) goto bad;
    empty_string = PyString_FromString("");
    if (!empty_string) goto bad;
    py_code = PyCode_New(
        0,            /*int argcount,*/
        0,            /*int nlocals,*/
        0,            /*int stacksize,*/
        0,            /*int flags,*/
        empty_string, /*PyObject *code,*/
        empty_tuple,  /*PyObject *consts,*/
        empty_tuple,  /*PyObject *names,*/
        empty_tuple,  /*PyObject *varnames,*/
        empty_tuple,  /*PyObject *freevars,*/
        empty_tuple,  /*PyObject *cellvars,*/
        py_srcfile,   /*PyObject *filename,*/
        py_funcname,  /*PyObject *name,*/
        __pyx_lineno,   /*int firstlineno,*/
        empty_string  /*PyObject *lnotab*/
    );
    if (!py_code) goto bad;
    py_frame = PyFrame_New(
        PyThreadState_Get(), /*PyThreadState *tstate,*/
        py_code,             /*PyCodeObject *code,*/
        py_globals,          /*PyObject *globals,*/
        0                    /*PyObject *locals*/
    );
    if (!py_frame) goto bad;
    py_frame->f_lineno = __pyx_lineno;
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    Py_XDECREF(empty_tuple);
    Py_XDECREF(empty_string);
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}

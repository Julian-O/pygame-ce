/*
  pygame - Python Game Library
  Copyright (C) 2000-2001  Pete Shinners

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Library General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Library General Public License for more details.

  You should have received a copy of the GNU Library General Public
  License along with this library; if not, write to the Free
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  Pete Shinners
  pete@shinners.org
*/

/*
 *  Python Rect Object -- useful 2d rectangle class
 *  a template like file that works with defines and it implements the Rect
 * object
 */
#define PYGAMEAPI_RECT_INTERNAL
#include "pygame.h"

#include "structmember.h"

#include "pgcompat.h"

#include <limits.h>

// #region RectExport
#ifndef RectExport_init
#error RectExport_init needs to be defined
#endif
#ifndef RectExport_subtypeNew4
#error RectExport_subtypeNew4 needs to be defined
#endif
#ifndef RectExport_new
#error RectExport_new needs to be defined
#endif
#ifndef RectExport_dealloc
#error RectExport_dealloc needs to be defined
#endif
#ifndef RectExport_normalize
#error RectExport_normalize needs to be defined
#endif
#ifndef RectExport_pgTwoValuesFromFastcallArgs
#error RectExport_pgTwoValuesFromFastcallArgs needs to be defined
#endif
#ifndef RectExport_move
#error RectExport_move needs to be defined
#endif
#ifndef RectExport_moveIp
#error RectExport_moveIp needs to be defined
#endif
#ifndef RectExport_inflate
#error RectExport_inflate needs to be defined
#endif
#ifndef RectExport_inflateIp
#error RectExport_inflateIp needs to be defined
#endif
#ifndef RectExport_scalebyIp
#error RectExport_scalebyIp needs to be defined
#endif
#ifndef RectExport_scaleby
#error RectExport_scaleby needs to be defined
#endif
#ifndef RectExport_update
#error RectExport_update needs to be defined
#endif
#ifndef RectExport_union
#error RectExport_union needs to be defined
#endif
#ifndef RectExport_unionIp
#error RectExport_unionIp needs to be defined
#endif
#ifndef RectExport_unionall
#error RectExport_unionall needs to be defined
#endif
#ifndef RectExport_unionallIp
#error RectExport_unionallIp needs to be defined
#endif
#ifndef RectExport_collidepoint
#error RectExport_collidepoint needs to be defined
#endif
#ifndef RectExport_colliderect
#error RectExport_colliderect needs to be defined
#endif
#ifndef RectExport_collidelist
#error RectExport_collidelist needs to be defined
#endif
#ifndef RectExport_collidelistall
#error RectExport_collidelistall needs to be defined
#endif
#ifndef RectExport_collideobjectsall
#error RectExport_collideobjectsall needs to be defined
#endif
#ifndef RectExport_collideobjects
#error RectExport_collideobjects needs to be defined
#endif
#ifndef RectExport_RectFromObjectAndKeyFunc
#error RectExport_RectFromObjectAndKeyFunc needs to ne defined
#endif
#ifndef RectExport_collidedict
#error RectExport_collidedict needs to be defined
#endif
#ifndef RectExport_collidedictall
#error RectExport_collidedictall needs to be defined
#endif
#ifndef RectExport_clip
#error RectExport_clip needs to be defined
#endif
#ifndef RectExport_clipline
#error RectExport_clipline needs to be defined
#endif
#ifndef RectExport_RectFromObject
#error RectExport_RectFromObject needs to be defined
#endif
#ifndef RectExport_RectFromFastcallArgs
#error RectExport_RectFromFastcallArgs needs to be defined
#endif
#ifndef RectExport_RectNew
#error RectExport_RectNew needs to be defined
#endif
#ifndef RectExport_do_rects_intresect
#error RectExport_do_rects_intresect needs to be Defined
#endif
#ifndef RectExport_RectNew4
#error RectExport_RectNew4 needs to be defined
#endif
#ifndef RectExport_Normalize
#error RectExport_Normalize needs to be defined
#endif
#ifndef RectExport_contains_internal
#error RectExport_contains_internal needs to be defined
#endif
#ifndef RectExport_contains
#error RectExport_contains needs to be defined
#endif
#ifndef RectExport_containsSeq
#error RectExport_containsSeq needs to be defined
#endif
#ifndef RectExport_clamp
#error RectExport_clamp needs to be defined
#endif
#ifndef RectExport_fit
#error RectExport_fit needs to be defined
#endif
#ifndef RectExport_clampIp
#error RectExport_clampIp needs to be defined
#endif
#ifndef RectExport_reduce
#error RectExport_reduce needs to be defined
#endif
#ifndef RectExport_copy
#error RectExport_copy needs to be defined
#endif
#ifndef RectExport_item
#error RectExport_item needs to be defined
#endif
#ifndef RectExport_assItem
#error RectExport_assItem needs to be defined
#endif
#ifndef RectExport_subscript
#error RectExport_subscript needs to be defined
#endif
#ifndef RectExport_assSubscript
#error RectExport_assSubscript needs to be defined
#endif
#ifndef RectExport_bool
#error RectExport_bool needs to be defined
#endif
#ifndef RectExport_richcompare
#error RectExport_richcompare needs to be defined
#endif
#ifndef RectExport_getwidth
#error RectExport_getwidth needs to be defined
#endif
#ifndef RectExport_setwidth
#error RectExport_setwidth needs to be defined
#endif
#ifndef RectExport_getheight
#error RectExport_getheight needs to be defined
#endif
#ifndef RectExport_setheight
#error RectExport_setheight needs to be defined
#endif
#ifndef RectExport_gettop
#error RectExport_gettop needs to be defined
#endif
#ifndef RectExport_settop
#error RectExport_settop needs to be defined
#endif
#ifndef RectExport_getleft
#error RectExport_getleft needs to be defined
#endif
#ifndef RectExport_setleft
#error RectExport_setleft needs to be defined
#endif
#ifndef RectExport_getright
#error RectExport_getright needs to be defined
#endif
#ifndef RectExport_setright
#error RectExport_setright needs to be defined
#endif
#ifndef RectExport_getbottom
#error RectExport_getbottom needs to be defined
#endif
#ifndef RectExport_setbottom
#error RectExport_setbottom needs to be defined
#endif
#ifndef RectExport_getcenterx
#error RectExport_getcenterx needs to be defined
#endif
#ifndef RectExport_setcenterx
#error RectExport_setcenterx needs to be defined
#endif
#ifndef RectExport_getcentery
#error RectExport_getcentery needs to be defined
#endif
#ifndef RectExport_setcentery
#error RectExport_setcentery needs to be defined
#endif
#ifndef RectExport_gettopleft
#error RectExport_gettopleft needs to be defined
#endif
#ifndef RectExport_settopleft
#error RectExport_settopleft needs to be defined
#endif
#ifndef RectExport_gettopright
#error RectExport_gettopright needs to be defined
#endif
#ifndef RectExport_settopright
#error RectExport_settopright needs to be defined
#endif
#ifndef RectExport_getbottomleft
#error RectExport_getbottomleft needs to be defined
#endif
#ifndef RectExport_setbottomleft
#error RectExport_setbottomleft needs to be defined
#endif
#ifndef RectExport_getbottomright
#error RectExport_getbottomright needs to be defined
#endif
#ifndef RectExport_setbottomright
#error RectExport_setbottomright needs to be defined
#endif
#ifndef RectExport_getmidtop
#error RectExport_getmidtop needs to be defined
#endif
#ifndef RectExport_setmidtop
#error RectExport_setmidtop needs to be defined
#endif
#ifndef RectExport_getmidleft
#error RectExport_getmidleft needs to be defined
#endif
#ifndef RectExport_setmidleft
#error RectExport_setmidleft needs to be defined
#endif
#ifndef RectExport_getmidbottom
#error RectExport_getmidbottom needs to be defined
#endif
#ifndef RectExport_setmidbottom
#error RectExport_setmidbottom needs to be defined
#endif
#ifndef RectExport_getmidright
#error RectExport_getmidright needs to be defined
#endif
#ifndef RectExport_setmidright
#error RectExport_setmidright needs to be defined
#endif
#ifndef RectExport_getcenter
#error RectExport_getcenter needs to be defined
#endif
#ifndef RectExport_setcenter
#error RectExport_setcenter needs to be defined
#endif
#ifndef RectExport_getsize
#error RectExport_getsize needs to be defined
#endif
#ifndef RectExport_setsize
#error RectExport_setsize needs to be defined
#endif
#ifndef RectExport_iterator
#error RectExpor_iterator needs to be defined
#endif
// #endregion

// #region RectImport
#ifndef RectImport_PythonNumberCheck
#error RectImport_PythonNumberCheck
#endif
#ifndef RectImport_PythonNumberAsPrimitiveType
#error RectImport_PythonNumberAsPrimitiveType
#endif
#ifndef RectImport_PrimitiveTypeAsPythonNumber
#error RectImport_PrimitiveTypeAsPythonNumber
#endif
#ifndef RectImport_ObjectName
#error RectImport_ObjectName needs to be defined
#endif
#ifndef RectImport_IntersectRectAndLine
#error RectImport_IntersectRectAndLine needs to be defined
#endif
#ifndef RectImport_RectCheck
#error RectImport_RectCheck needs to be Defined
#endif
#ifndef RectImport_RectCheckExact
#error RectImport_RectCheckExact needs to be Defined
#endif
#ifndef RectImport_primitiveType
#error RectImport_primitiveType needs to be defined
#endif
#ifndef RectImport_innerRectStruct
#error RectImport_innerRectStruct needs to be defined
#endif
#ifndef RectImport_innerPointStruct
#error RectImport_innerPointStruct needs to be defined
#endif
#ifndef RectImport_fourPrimiviteFromObj
#error RectImport_fourPrimiviteFromObj needs to be defined
#endif
#ifndef RectImport_RectObject
#error RectImport_RectObject needs to be defined
#endif
#ifndef RectImport_TypeObject
#error RectImport_TypeObject needs to be Defined
#endif
#ifndef RectImport_primitiveFromObjIndex
#error RectImport_primitiveFromObjIndex needs to be defined
#endif
#ifndef RectImport_twoPrimitivesFromObj
#error RectImport_twoPrimitivesFromObj needs to be Defined
#endif
#ifndef RectImport_PrimitiveFromObj
#error RectImport_PrimitiveFromObj needs to be defined
#endif
#ifndef RectImport_PyBuildValueFormat
#error RectImport_PyBuildValueFormat needs to be defined
#endif
// #endregion

// #region RectOptional
#ifdef RectOptional_FREELIST
#ifndef PYPY_VERSION
#error freelist is currently only supported for PyPy
#endif
#ifndef RectOptional_FreelistlimitNumberName
#error RectOptional_FreelistlimitNumberName needs to be defined as RectOptional_FREELIST is defined
#endif
#ifndef RectOptional_FreelistlimitNumber
#error RectOptional_FreelistlimitNumber needs to be defined as RectOptional_FREELIST is defined
#endif
#ifndef RectOptional_FreelistFreelistName
#error RectOptional_FreelistFreelistName needs to be defined as RectOptional_FREELIST is defined
#endif
#ifndef RectOptional_Freelist_Num
#error RectOptional_Freelist_Num needs to be defined as RectOptional_FREELIST is defined
#endif
#endif  // RectOptional_FREELIST
// #endregion RectOptional

#define PrimitiveType RectImport_primitiveType
#define RectObject RectImport_RectObject
#define TypeObject RectImport_TypeObject
#define InnerRect RectImport_innerRectStruct
#define InnerPoint RectImport_innerPointStruct
#define RectCheck RectImport_RectCheck
#define RectFromObject RectExport_RectFromObject
#define RectFromFastcallArgs RectExport_RectFromFastcallArgs
#define subtype_new4 RectExport_subtypeNew4
#define primitiveFromObjIndex RectImport_primitiveFromObjIndex
#define pgTwoValuesFromFastcallArgs RectExport_pgTwoValuesFromFastcallArgs
#define twoPrimitivesFromObj RectImport_twoPrimitivesFromObj
#define fourPrimivitesFromObj RectImport_fourPrimiviteFromObj
#define PrimitiveFromObj RectImport_PrimitiveFromObj
#define TypeFMT RectImport_PyBuildValueFormat
#define ObjectName RectImport_ObjectName
#define PythonNumberCheck RectImport_PythonNumberCheck
#define PythonNumberAsPrimitiveType RectImport_PythonNumberAsPrimitiveType
#define PythonNumberFromPrimitiveType RectImport_PrimitiveTypeAsPythonNumber
#define PrimitiveTypeAsPythonNumber RectImport_PrimitiveTypeAsPythonNumber

#define pgRectAsRect(x) (((RectObject *)x)->r)

static int
RectExport_do_rects_intresect(InnerRect *A, InnerRect *B)
{
    if (A->w == 0 || A->h == 0 || B->w == 0 || B->h == 0) {
        // zero sized rects should not collide with anything #1197
        return 0;
    }

    // A.left   < B.right  &&
    // A.top    < A.bottom &&
    // A.right  > B.left   &&
    // A.bottom > b.top
    return (MIN(A->x, A->x + A->w) < MAX(B->x, B->x + B->w) &&
            MIN(A->y, A->y + A->h) < MAX(B->y, B->y + B->h) &&
            MAX(A->x, A->x + A->w) > MIN(B->x, B->x + B->w) &&
            MAX(A->y, A->y + A->h) > MIN(B->y, B->y + B->h));
}

#define _pg_do_rects_intersect RectExport_do_rects_intresect

static InnerRect *
RectExport_RectFromObject(PyObject *obj, InnerRect *temp);
static InnerRect *
RectExport_RectFromFastcallArgs(PyObject *const *args, Py_ssize_t nargs,
                                InnerRect *temp);
static PyObject *
RectExport_subtypeNew4(PyTypeObject *type, PrimitiveType x, PrimitiveType y,
                       PrimitiveType w, PrimitiveType h);
static PyObject *
RectExport_new(PyTypeObject *type, PyObject *args, PyObject *kwds);
static void
RectExport_dealloc(RectObject *self);
static int
RectExport_init(RectObject *self, PyObject *args, PyObject *kwds);
static PyObject *
RectExport_RectNew(InnerRect *r);
static PyObject *
RectExport_RectNew4(PrimitiveType x, PrimitiveType y, PrimitiveType w,
                    PrimitiveType h);
static void
RectExport_Normalize(InnerRect *rect);
static PyObject *
RectExport_normalize(RectObject *self, PyObject *args);
static int
RectExport_pgTwoValuesFromFastcallArgs(PyObject *const *args, Py_ssize_t nargs,
                                       PrimitiveType *x, PrimitiveType *y);
static PyObject *
RectExport_move(RectObject *self, PyObject *const *args, Py_ssize_t nargs);
static PyObject *
RectExport_moveIp(RectObject *self, PyObject *const *args, Py_ssize_t nargs);
static PyObject *
RectExport_inflate(RectObject *self, PyObject *args);
static PyObject *
RectExport_inflateIp(RectObject *self, PyObject *args);
static PyObject *
RectExport_scalebyIp(RectObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
RectExport_scaleby(RectObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
RectExport_update(RectObject *self, PyObject *const *args, Py_ssize_t nargs);
static PyObject *
RectExport_union(RectObject *self, PyObject *const *args, Py_ssize_t nargs);
static PyObject *
RectExport_unionIp(RectObject *self, PyObject *const *args, Py_ssize_t nargs);
static PyObject *
RectExport_unionall(RectObject *self, PyObject *args);
static PyObject *
RectExport_unionallIp(RectObject *self, PyObject *args);
static PyObject *
RectExport_collidepoint(RectObject *self, PyObject *const *args,
                        Py_ssize_t nargs);
static InnerRect *
RectExport_RectFromObjectAndKeyFunc(PyObject *obj, PyObject *keyfunc,
                                    InnerRect *temp);
static PyObject *
RectExport_colliderect(RectObject *self, PyObject *const *args,
                       Py_ssize_t nargs);
static PyObject *
RectExport_collidelist(RectObject *self, PyObject *args);
static PyObject *
RectExport_collidelistall(RectObject *self, PyObject *args);
static PyObject *
RectExport_collideobjectsall(RectObject *self, PyObject *args,
                             PyObject *kwargs);
static PyObject *
RectExport_collideobjects(RectObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
RectExport_collidedict(RectObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
RectExport_collidedictall(RectObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
RectExport_clip(RectObject *self, PyObject *const *args, Py_ssize_t nargs);
static int
RectExport_contains_internal(RectObject *self, PyObject *arg);
static PyObject *
RectExport_contains(RectObject *self, PyObject *arg);
static int
RectExport_containsSeq(RectObject *self, PyObject *arg);
static PyObject *
RectExport_clamp(RectObject *self, PyObject *const *args, Py_ssize_t nargs);
static PyObject *
RectExport_fit(RectObject *self, PyObject *const *args, Py_ssize_t nargs);
static PyObject *
RectExport_clampIp(RectObject *self, PyObject *const *args, Py_ssize_t nargs);
static PyObject *
RectExport_reduce(RectObject *self, PyObject *args);
static PyObject *
RectExport_copy(RectObject *self, PyObject *args);
static PyObject *
RectExport_item(RectObject *self, Py_ssize_t i);
static int
RectExport_assItem(RectObject *self, Py_ssize_t i, PyObject *v);
static PyObject *
RectExport_subscript(RectObject *self, PyObject *op);
static int
RectExport_assSubscript(RectObject *self, PyObject *op, PyObject *value);
static int
RectExport_bool(RectObject *self);
static PyObject *
RectExport_richcompare(PyObject *o1, PyObject *o2, int opid);
static PyObject *
RectExport_getwidth(RectObject *self, void *closure);
static int
RectExport_setwidth(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getheight(RectObject *self, void *closure);
static int
RectExport_setheight(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_gettop(RectObject *self, void *closure);
static int
RectExport_settop(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getleft(RectObject *self, void *closure);
static int
RectExport_setleft(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getright(RectObject *self, void *closure);
static int
RectExport_setright(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getbottom(RectObject *self, void *closure);
static int
RectExport_setbottom(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getcenterx(RectObject *self, void *closure);
static int
RectExport_setcenterx(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getcentery(RectObject *self, void *closure);
static int
RectExport_setcentery(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_gettopleft(RectObject *self, void *closure);
static int
RectExport_settopleft(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_gettopright(RectObject *self, void *closure);
static int
RectExport_settopright(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getbottomleft(RectObject *self, void *closure);
static int
RectExport_setbottomleft(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getbottomright(RectObject *self, void *closure);
static int
RectExport_setbottomright(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getmidtop(RectObject *self, void *closure);
static int
RectExport_setmidtop(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getmidleft(RectObject *self, void *closure);
static int
RectExport_setmidleft(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getmidbottom(RectObject *self, void *closure);
static int
RectExport_setmidbottom(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getmidright(RectObject *self, void *closure);
static int
RectExport_setmidright(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getcenter(RectObject *self, void *closure);
static int
RectExport_setcenter(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_getsize(RectObject *self, void *closure);
static int
RectExport_setsize(RectObject *self, PyObject *value, void *closure);
static PyObject *
RectExport_iterator(RectObject *self);

#ifdef RectOptional_FREELIST
const int RectOptional_FreelistlimitNumberName =
    RectOptional_FreelistlimitNumber;
static RectObject
    *RectOptional_FreelistFreelistName[RectOptional_FreelistlimitNumber];
int RectOptional_Freelist_Num = -1;
#endif

static InnerRect *
RectExport_RectFromObject(PyObject *obj, InnerRect *temp)
{
    Py_ssize_t length;

    if (RectCheck(obj)) {
        return &((RectObject *)obj)->r;
    }

    if (pgSequenceFast_Check(obj)) {
        length = PySequence_Fast_GET_SIZE(obj);
        PyObject **items = PySequence_Fast_ITEMS(obj);

        if (length == 4) {
            if (!PrimitiveFromObj(items[0], &temp->x) ||
                !PrimitiveFromObj(items[1], &temp->y) ||
                !PrimitiveFromObj(items[2], &temp->w) ||
                !PrimitiveFromObj(items[3], &temp->h)) {
                return NULL;
            }
            return temp;
        }
        else if (length == 2) {
            if (!twoPrimitivesFromObj(items[0], &temp->x, &temp->y) ||
                !twoPrimitivesFromObj(items[1], &temp->w, &temp->h)) {
                return NULL;
            }
            return temp;
        }
        else if (PyTuple_Check(obj) && length == 1) {
            return RectExport_RectFromObject(items[0], temp);
        }
        else {
            return NULL;
        }
    }
    else if (PySequence_Check(obj)) {
        PyObject *item;
        if ((length = PySequence_Size(obj)) == -1) {
            PyErr_Clear();
            return NULL;
        }

        if (length == 4) {
            item = PySequence_ITEM(obj, 0);
            if (!PrimitiveFromObj(item, &temp->x)) {
                Py_XDECREF(item);
                return NULL;
            }
            Py_DECREF(item);

            item = PySequence_ITEM(obj, 1);
            if (!PrimitiveFromObj(item, &temp->y)) {
                Py_XDECREF(item);
                return NULL;
            }
            Py_DECREF(item);

            item = PySequence_ITEM(obj, 2);
            if (!PrimitiveFromObj(item, &temp->w)) {
                Py_XDECREF(item);
                return NULL;
            }
            Py_DECREF(item);

            item = PySequence_ITEM(obj, 3);
            if (!PrimitiveFromObj(item, &temp->h)) {
                Py_XDECREF(item);
                return NULL;
            }
            Py_DECREF(item);

            return temp;
        }
        else if (length == 2) {
            item = PySequence_ITEM(obj, 0);
            if (!twoPrimitivesFromObj(item, &temp->x, &temp->y)) {
                Py_XDECREF(item);
                return NULL;
            }
            Py_DECREF(item);

            item = PySequence_ITEM(obj, 1);
            if (!twoPrimitivesFromObj(item, &temp->w, &temp->h)) {
                Py_XDECREF(item);
                return NULL;
            }
            Py_DECREF(item);

            return temp;
        }
        /*looks like an arg?*/
        else if (PyTuple_Check(obj) && length == 1) {
            if (!(item = PyTuple_GET_ITEM(obj, 0))) {
                return NULL;
            }
            InnerRect *returnrect = RectExport_RectFromObject(item, temp);
            return returnrect;
        }
    }

    /* Try to get the rect attribute */
    PyObject *rectattr;
    if (!(rectattr = PyObject_GetAttrString(obj, "rect"))) {
        PyErr_Clear();
        return NULL;
    }

    InnerRect *returnrect;
    /*call if it's a method*/
    if (PyCallable_Check(rectattr)) {
        PyObject *rectresult = PyObject_CallObject(rectattr, NULL);
        Py_DECREF(rectattr);
        if (rectresult == NULL) {
            PyErr_Clear();
            return NULL;
        }
        rectattr = rectresult;
    }

    returnrect = RectExport_RectFromObject(rectattr, temp);
    Py_DECREF(rectattr);
    return returnrect;
}

static InnerRect *
RectExport_RectFromFastcallArgs(PyObject *const *args, Py_ssize_t nargs,
                                InnerRect *temp)
{
    /* This function converts a sequence of arguments coming from a fastcall
     * call into a Rect or FRect.
     * */

    if (nargs == 1) {
        return RectFromObject(args[0], temp);
    }
    else if (nargs == 4) {
        if (!PrimitiveFromObj(args[0], &temp->x) ||
            !PrimitiveFromObj(args[1], &temp->y) ||
            !PrimitiveFromObj(args[2], &temp->w) ||
            !PrimitiveFromObj(args[3], &temp->h)) {
            return NULL;
        }
        return temp;
    }
    else if (nargs == 2) {
        if (!twoPrimitivesFromObj(args[0], &temp->x, &temp->y) ||
            !twoPrimitivesFromObj(args[1], &temp->w, &temp->h)) {
            return NULL;
        }
        return temp;
    }
    return NULL;
}

static PyObject *
RectExport_subtypeNew4(PyTypeObject *type, PrimitiveType x, PrimitiveType y,
                       PrimitiveType w, PrimitiveType h)
{
    RectObject *rect;
    rect = (RectObject *)TypeObject.tp_new(type, NULL, NULL);

    if (rect) {
        rect->r.x = x;
        rect->r.y = y;
        rect->r.w = w;
        rect->r.h = h;
    }
    return (PyObject *)rect;
}

static PyObject *
RectExport_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    RectObject *self;

#ifdef RectOptional_FREELIST
    /* Only instances of the base pygame.Rect class are allowed in the
     * current freelist implementation (subclasses are not allowed) */
    if (RectOptional_Freelist_Num > -1 && type == &RectImport_TypeObject) {
        self = RectOptional_FreelistFreelistName[RectOptional_Freelist_Num];
        Py_INCREF(self);
        /* This is so that pypy garbage collector thinks it is a new obj
           TODO: May be a hack. Is a hack.
           See https://github.com/pygame/pygame/issues/430
        */
        ((PyObject *)(self))->ob_pypy_link = 0;
        RectOptional_Freelist_Num--;
    }
    else {
        self = (RectObject *)type->tp_alloc(type, 0);
    }
#else
    self = (RectObject *)type->tp_alloc(type, 0);
#endif

    if (self != NULL) {
        self->r.x = self->r.y = (PrimitiveType)0;
        self->r.w = self->r.h = (PrimitiveType)0;
        self->weakreflist = NULL;
    }
    return (PyObject *)self;
}

static void
RectExport_dealloc(RectObject *self)
{
    if (self->weakreflist != NULL) {
        PyObject_ClearWeakRefs((PyObject *)self);
    }

#ifdef PYPY_VERSION
    /* Only instances of the base pygame.Rect class are allowed in the
     * current freelist implementation (subclasses are not allowed) */
    if (RectOptional_Freelist_Num < RectOptional_FreelistlimitNumberName - 1 &&
        RectImport_RectCheckExact(self)) {
        RectOptional_Freelist_Num++;
        RectOptional_FreelistFreelistName[RectOptional_Freelist_Num] = self;
    }
    else {
        Py_TYPE(self)->tp_free((PyObject *)self);
    }
#else
    Py_TYPE(self)->tp_free((PyObject *)self);
#endif
}

static int
RectExport_init(RectObject *self, PyObject *args, PyObject *kwds)
{
    InnerRect *argrect, temp;

    if (!(argrect = RectFromObject(args, &temp))) {
        PyErr_SetString(PyExc_TypeError, "Argument must be rect style object");
        return -1;
    }

    self->r = *argrect;

    return 0;
}

static PyObject *
RectExport_RectNew(InnerRect *r)
{
    return subtype_new4(&TypeObject, r->x, r->y, r->w, r->h);
}

static PyObject *
RectExport_RectNew4(PrimitiveType x, PrimitiveType y, PrimitiveType w,
                    PrimitiveType h)
{
    return subtype_new4(&TypeObject, x, y, w, h);
}

static void
RectExport_Normalize(InnerRect *rect)
{
    if (rect->w < 0) {
        rect->x += rect->w;
        rect->w = -rect->w;
    }

    if (rect->h < 0) {
        rect->y += rect->h;
        rect->h = -rect->h;
    }
}

static PyObject *
RectExport_normalize(RectObject *self, PyObject *args)
{
    RectExport_Normalize(&pgRectAsRect(self));
    Py_RETURN_NONE;
}

static int
RectExport_pgTwoValuesFromFastcallArgs(PyObject *const *args, Py_ssize_t nargs,
                                       PrimitiveType *x, PrimitiveType *y)
{
    /*Check if there is only one argument*/
    if (nargs == 1) {
        /*Attempt to convert the argument to two floats/integers*/
        if (!twoPrimitivesFromObj(args[0], x, y)) {
            if (!PySequence_Check(args[0])) {
                PyErr_Format(
                    PyExc_TypeError,
                    "Invalid argument. Expected a sequence but got: '%s'",
                    Py_TYPE(args[0])->tp_name);
                return 0;
            }

            Py_ssize_t size = PySequence_Size(args[0]);
            if (size != 2) {
                PyErr_Format(
                    PyExc_TypeError,
                    "Invalid sequence size. Expected size 2 but got: %d",
                    (int)size);
                return 0;
            }

            PyObject *xobj, *yobj;
            if (!(xobj = PySequence_GetItem(args[0], 0))) {
                return 0;
            }
            if (!(yobj = PySequence_GetItem(args[0], 1))) {
                Py_DECREF(xobj);
                return 0;
            }

            PyErr_Format(PyExc_TypeError,
                         "Invalid sequence values. Expected two numeric "
                         "values but got: '%s', '%s'",
                         Py_TYPE(xobj)->tp_name, Py_TYPE(yobj)->tp_name);
            Py_DECREF(xobj);
            Py_DECREF(yobj);
            return 0;
        }
        return 1;
    }
    /*Check if there are two arguments*/
    else if (nargs == 2) {
        /*Attempt to convert the first argument to an float/integer*/
        if (!PrimitiveFromObj(args[0], x)) {
            PyErr_Format(PyExc_TypeError,
                         "The first argument must be numeric (got: '%s')",
                         Py_TYPE(args[0])->tp_name);
            return 0;
        }
        /*Attempt to convert the second argument to a float/integer*/
        if (!PrimitiveFromObj(args[1], y)) {
            PyErr_Format(PyExc_TypeError,
                         "The second argument must be numeric (got: '%s')",
                         Py_TYPE(args[1])->tp_name);
            return 0;
        }
        return 1;
    }
    /*Raise a TypeError for invalid number of arguments*/
    PyErr_Format(PyExc_TypeError,
                 "Function takes at most 2 arguments (%d given)", (int)nargs);
    return 0;
}

static PyObject *
RectExport_move(RectObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    PrimitiveType x, y;

    if (!pgTwoValuesFromFastcallArgs(args, nargs, &x, &y)) {
        return NULL;
    }

    return RectExport_subtypeNew4(Py_TYPE(self), self->r.x + x, self->r.y + y,
                                  self->r.w, self->r.h);
}

static PyObject *
RectExport_moveIp(RectObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    PrimitiveType x, y;

    if (!pgTwoValuesFromFastcallArgs(args, nargs, &x, &y)) {
        return NULL;
    }

    self->r.x += x;
    self->r.y += y;
    Py_RETURN_NONE;
}

static PyObject *
RectExport_inflate(RectObject *self, PyObject *args)
{
    PrimitiveType x, y;

    if (!twoPrimitivesFromObj(args, &x, &y)) {
        return RAISE(PyExc_TypeError, "argument must contain two numbers");
    }

    return RectExport_subtypeNew4(Py_TYPE(self), self->r.x - x / 2,
                                  self->r.y - y / 2, self->r.w + x,
                                  self->r.h + y);
}

static PyObject *
RectExport_inflateIp(RectObject *self, PyObject *args)
{
    PrimitiveType x, y;

    if (!twoPrimitivesFromObj(args, &x, &y)) {
        return RAISE(PyExc_TypeError, "argument must contain two numbers");
    }
    self->r.x -= x / 2;
    self->r.y -= y / 2;
    self->r.w += x;
    self->r.h += y;
    Py_RETURN_NONE;
}

static PyObject *
RectExport_scalebyIp(RectObject *self, PyObject *args, PyObject *kwargs)
{
    float factor_x, factor_y = 0;

    static char *keywords[] = {"x", "y", NULL};

    if (kwargs) {
        PyObject *scale_by = PyDict_GetItemString(kwargs, "scale_by");
        float temp_x, temp_y = 0;

        if (scale_by) {
            if (PyDict_Size(kwargs) > 1) {
                return RAISE(PyExc_TypeError,
                             "The 'scale_by' keyword cannot be combined with "
                             "other arguments.");
            }
            if (!pg_TwoFloatsFromObj(scale_by, &temp_x, &temp_y)) {
                return RAISE(PyExc_TypeError, "number pair expected");
            }
            PyDict_SetItemString(kwargs, "x", PyFloat_FromDouble(temp_x));
            PyDict_SetItemString(kwargs, "y", PyFloat_FromDouble(temp_y));
            PyDict_DelItemString(kwargs, "scale_by");
        }
    }

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "f|f", keywords, &factor_x,
                                     &factor_y)) {
        return RAISE(PyExc_TypeError, "Float values expected.");
    }

    factor_x = factor_x < 0 ? -factor_x : factor_x;
    factor_y = factor_y < 0 ? -factor_y : factor_y;

    factor_y = (factor_y > 0) ? factor_y : factor_x;

    self->r.x = (RectImport_primitiveType)(self->r.x + (self->r.w / 2) -
                                           (self->r.w * factor_x / 2));
    self->r.y = (RectImport_primitiveType)(self->r.y + (self->r.h / 2) -
                                           (self->r.h * factor_y / 2));
    self->r.w = (RectImport_primitiveType)(self->r.w * factor_x);
    self->r.h = (RectImport_primitiveType)(self->r.h * factor_y);
    Py_RETURN_NONE;
}

static PyObject *
RectExport_scaleby(RectObject *self, PyObject *args, PyObject *kwargs)
{
    RectObject *returnRect = (RectObject *)RectExport_subtypeNew4(
        Py_TYPE(self), self->r.x, self->r.y, self->r.w, self->r.h);
    RectExport_scalebyIp(returnRect, args, kwargs);
    return (PyObject *)returnRect;
}

static PyObject *
RectExport_update(RectObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    InnerRect *argrect, temp;

    if (!(argrect = RectFromFastcallArgs(args, nargs, &temp))) {
        return RAISE(PyExc_TypeError, "Argument must be rect style object");
    }

    self->r = *argrect;

    Py_RETURN_NONE;
}

static PyObject *
RectExport_union(RectObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    InnerRect *argrect, temp;
    PrimitiveType x, y, w, h;

    if (!(argrect = RectFromFastcallArgs(args, nargs, &temp))) {
        return RAISE(PyExc_TypeError, "Argument must be rect style object");
    }
    x = MIN(self->r.x, argrect->x);
    y = MIN(self->r.y, argrect->y);
    w = MAX(self->r.x + self->r.w, argrect->x + argrect->w) - x;
    h = MAX(self->r.y + self->r.h, argrect->y + argrect->h) - y;
    return RectExport_subtypeNew4(Py_TYPE(self), x, y, w, h);
}

static PyObject *
RectExport_unionIp(RectObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    InnerRect *argrect, temp;
    PrimitiveType x, y, w, h;

    if (!(argrect = RectFromFastcallArgs(args, nargs, &temp)))
        return RAISE(PyExc_TypeError, "Argument must be rect style object");

    x = MIN(self->r.x, argrect->x);
    y = MIN(self->r.y, argrect->y);
    w = MAX(self->r.x + self->r.w, argrect->x + argrect->w) - x;
    h = MAX(self->r.y + self->r.h, argrect->y + argrect->h) - y;
    self->r.x = x;
    self->r.y = y;
    self->r.w = w;
    self->r.h = h;
    Py_RETURN_NONE;
}

static PyObject *
RectExport_unionall(RectObject *self, PyObject *args)
{
    InnerRect *argrect, temp;
    Py_ssize_t loop, size;
    PyObject *list, *obj;
    PrimitiveType t, l, b, r;

    if (!PyArg_ParseTuple(args, "O", &list)) {
        return NULL;
    }
    if (!PySequence_Check(list)) {
        return RAISE(PyExc_TypeError,
                     "Argument must be a sequence of rectstyle objects.");
    }

    l = self->r.x;
    t = self->r.y;
    r = self->r.x + self->r.w;
    b = self->r.y + self->r.h;
    size = PySequence_Length(list); /*warning, size could be -1 on error?*/
    if (size < 1) {
        if (size < 0) {
            /*Error.*/
            return NULL;
        }
        /*Empty list: nothing to be done.*/
        return RectExport_subtypeNew4(Py_TYPE(self), l, t, r - l, b - t);
    }

    for (loop = 0; loop < size; ++loop) {
        obj = PySequence_GetItem(list, loop);
        if (!obj || !(argrect = RectFromObject(obj, &temp))) {
            Py_XDECREF(obj);
            return RAISE(PyExc_TypeError,
                         "Argument must be a sequence of rectstyle objects.");
        }
        l = MIN(l, argrect->x);
        t = MIN(t, argrect->y);
        r = MAX(r, argrect->x + argrect->w);
        b = MAX(b, argrect->y + argrect->h);
        Py_DECREF(obj);
    }
    return RectExport_subtypeNew4(Py_TYPE(self), l, t, r - l, b - t);
}

static PyObject *
RectExport_unionallIp(RectObject *self, PyObject *args)
{
    InnerRect *argrect, temp;
    Py_ssize_t loop, size;
    PyObject *list, *obj;
    PrimitiveType t, l, b, r;

    if (!PyArg_ParseTuple(args, "O", &list)) {
        return NULL;
    }
    if (!PySequence_Check(list)) {
        return RAISE(PyExc_TypeError,
                     "Argument must be a sequence of rectstyle objects.");
    }

    l = self->r.x;
    t = self->r.y;
    r = self->r.x + self->r.w;
    b = self->r.y + self->r.h;

    size = PySequence_Length(list); /*warning, size could be -1 on error?*/
    if (size < 1) {
        if (size < 0) {
            /*Error.*/
            return NULL;
        }
        /*Empty list: nothing to be done.*/
        Py_RETURN_NONE;
    }

    for (loop = 0; loop < size; ++loop) {
        obj = PySequence_GetItem(list, loop);
        if (!obj || !(argrect = RectFromObject(obj, &temp))) {
            Py_XDECREF(obj);
            return RAISE(PyExc_TypeError,
                         "Argument must be a sequence of rectstyle objects.");
        }
        l = MIN(l, argrect->x);
        t = MIN(t, argrect->y);
        r = MAX(r, argrect->x + argrect->w);
        b = MAX(b, argrect->y + argrect->h);
        Py_DECREF(obj);
    }

    self->r.x = l;
    self->r.y = t;
    self->r.w = r - l;
    self->r.h = b - t;
    Py_RETURN_NONE;
}

static PyObject *
RectExport_collidepoint(RectObject *self, PyObject *const *args,
                        Py_ssize_t nargs)
{
    InnerRect srect = self->r;
    InnerPoint p;

    if (!pgTwoValuesFromFastcallArgs(args, nargs, &p.x, &p.y)) {
        return NULL;
    }

    if ((p.x >= srect.x) && (p.x < (srect.x + srect.w)) && (p.y >= srect.y) &&
        (p.y < (srect.y + srect.h))) {
        Py_RETURN_TRUE;
    }
    Py_RETURN_FALSE;
}

static PyObject *
RectExport_colliderect(RectObject *self, PyObject *const *args,
                       Py_ssize_t nargs)
{
    InnerRect *argrect, temp;

    if (!(argrect = RectFromFastcallArgs(args, nargs, &temp))) {
        return RAISE(PyExc_TypeError, "Argument must be rect style object");
    }

    return PyBool_FromLong(_pg_do_rects_intersect(&self->r, argrect));
}

static PyObject *
RectExport_collidelist(RectObject *self, PyObject *arg)
{
    InnerRect *argrect, *srect = &self->r, temp;
    int loop;

    if (!PySequence_Check(arg)) {
        return RAISE(PyExc_TypeError,
                     "Argument must be a sequence of rectstyle objects.");
    }

    /* If the sequence is a fast sequence, we can use the faster
     * PySequence_Fast_ITEMS() function to get the items. */
    if (pgSequenceFast_Check(arg)) {
        PyObject **items = PySequence_Fast_ITEMS(arg);
        for (loop = 0; loop < PySequence_Fast_GET_SIZE(arg); loop++) {
            if (!(argrect = RectFromObject(items[loop], &temp))) {
                return RAISE(
                    PyExc_TypeError,
                    "Argument must be a sequence of rectstyle objects.");
            }
            if (_pg_do_rects_intersect(srect, argrect)) {
                return PyLong_FromLong(loop);
            }
        }
    }
    /* If the sequence is not a fast sequence, we have to use the slower
     * PySequence_GetItem() function to get the items. */
    else {
        for (loop = 0; loop < PySequence_Length(arg); loop++) {
            PyObject *obj = PySequence_GetItem(arg, loop);

            if (!obj || !(argrect = RectFromObject(obj, &temp))) {
                Py_XDECREF(obj);
                return RAISE(
                    PyExc_TypeError,
                    "Argument must be a sequence of rectstyle objects.");
            }

            Py_DECREF(obj);

            if (_pg_do_rects_intersect(srect, argrect)) {
                return PyLong_FromLong(loop);
            }
        }
    }

    return PyLong_FromLong(-1);
}

static PyObject *
RectExport_collidelistall(RectObject *self, PyObject *arg)
{
    InnerRect *argrect, *srect = &self->r, temp;
    int loop;
    PyObject *ret = NULL;

    if (!PySequence_Check(arg)) {
        return RAISE(PyExc_TypeError,
                     "Argument must be a sequence of rectstyle objects.");
    }

    if (!(ret = PyList_New(0))) {
        return NULL;
    }

    /* If the sequence is a fast sequence, we can use the faster
     * PySequence_Fast_ITEMS() function to get the items. */
    if (pgSequenceFast_Check(arg)) {
        PyObject **items = PySequence_Fast_ITEMS(arg);
        for (loop = 0; loop < PySequence_Fast_GET_SIZE(arg); loop++) {
            if (!(argrect = RectFromObject(items[loop], &temp))) {
                Py_DECREF(ret);
                return RAISE(
                    PyExc_TypeError,
                    "Argument must be a sequence of rectstyle objects.");
            }

            if (_pg_do_rects_intersect(srect, argrect)) {
                PyObject *num = PyLong_FromLong(loop);
                if (!num) {
                    Py_DECREF(ret);
                    return NULL;
                }
                if (PyList_Append(ret, num)) {
                    Py_DECREF(ret);
                    Py_DECREF(num);
                    return NULL; /* Exception already set. */
                }
                Py_DECREF(num);
            }
        }
    }
    /* Slower path for general sequences. */
    else {
        for (loop = 0; loop < PySequence_Length(arg); loop++) {
            PyObject *obj = PySequence_ITEM(arg, loop);

            if (!obj || !(argrect = RectFromObject(obj, &temp))) {
                Py_XDECREF(obj);
                Py_DECREF(ret);
                return RAISE(
                    PyExc_TypeError,
                    "Argument must be a sequence of rectstyle objects.");
            }

            Py_DECREF(obj);

            if (_pg_do_rects_intersect(srect, argrect)) {
                PyObject *num = PyLong_FromLong(loop);
                if (!num) {
                    Py_DECREF(ret);
                    return NULL;
                }
                if (PyList_Append(ret, num)) {
                    Py_DECREF(ret);
                    Py_DECREF(num);
                    return NULL; /* Exception already set. */
                }
                Py_DECREF(num);
            }
        }
    }

    return ret;
}

static InnerRect *
RectExport_RectFromObjectAndKeyFunc(PyObject *obj, PyObject *keyfunc,
                                    InnerRect *temp)
{
    if (keyfunc) {
        PyObject *obj_with_rect =
            PyObject_CallFunctionObjArgs(keyfunc, obj, NULL);
        if (!obj_with_rect) {
            return NULL;
        }

        InnerRect *ret = RectFromObject(obj_with_rect, temp);
        Py_DECREF(obj_with_rect);
        if (!ret) {
            return RAISE(PyExc_TypeError,
                         "Key function must return rect or rect-like objects");
        }
        return ret;
    }
    else {
        InnerRect *ret = RectFromObject(obj, temp);
        if (!ret) {
            return RAISE(PyExc_TypeError,
                         "Sequence must contain rect or rect-like objects");
        }
        return ret;
    }
}

static PyObject *
RectExport_collideobjectsall(RectObject *self, PyObject *args,
                             PyObject *kwargs)
{
    InnerRect *argrect;
    InnerRect temp;
    Py_ssize_t size;
    int loop;
    PyObject *list, *obj;
    PyObject *keyfunc = NULL;
    PyObject *ret = NULL;
    static char *keywords[] = {"list", "key", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|$O:collideobjectsall",
                                     keywords, &list, &keyfunc)) {
        return NULL;
    }

    if (!PySequence_Check(list)) {
        return RAISE(PyExc_TypeError,
                     "Argument must be a sequence of objects.");
    }

    if (keyfunc == Py_None) {
        keyfunc = NULL;
    }

    if (keyfunc && !PyCallable_Check(keyfunc)) {
        return RAISE(PyExc_TypeError,
                     "Key function must be callable with one argument.");
    }

    ret = PyList_New(0);
    if (!ret) {
        return NULL;
    }

    size = PySequence_Length(list);
    if (size == -1) {
        Py_DECREF(ret);
        return NULL;
    }

    for (loop = 0; loop < size; ++loop) {
        obj = PySequence_GetItem(list, loop);

        if (!obj) {
            Py_DECREF(ret);
            return NULL;
        }

        if (!(argrect =
                  RectExport_RectFromObjectAndKeyFunc(obj, keyfunc, &temp))) {
            Py_XDECREF(obj);
            Py_DECREF(ret);
            return NULL;
        }

        if (_pg_do_rects_intersect(&self->r, argrect)) {
            if (0 != PyList_Append(ret, obj)) {
                Py_DECREF(ret);
                Py_DECREF(obj);
                return NULL; /* Exception already set. */
            }
        }
        Py_DECREF(obj);
    }

    return ret;
}

static PyObject *
RectExport_collideobjects(RectObject *self, PyObject *args, PyObject *kwargs)
{
    InnerRect *argrect;
    InnerRect temp;
    Py_ssize_t size;
    int loop;
    PyObject *list, *obj;
    PyObject *keyfunc = NULL;
    static char *keywords[] = {"list", "key", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|$O:collideobjects",
                                     keywords, &list, &keyfunc)) {
        return NULL;
    }

    if (!PySequence_Check(list)) {
        return RAISE(PyExc_TypeError,
                     "Argument must be a sequence of objects.");
    }

    if (keyfunc == Py_None) {
        keyfunc = NULL;
    }

    if (keyfunc && !PyCallable_Check(keyfunc)) {
        return RAISE(PyExc_TypeError,
                     "Key function must be callable with one argument.");
    }

    size = PySequence_Length(list);
    if (size == -1) {
        return NULL;
    }

    for (loop = 0; loop < size; ++loop) {
        obj = PySequence_GetItem(list, loop);

        if (!obj) {
            return NULL;
        }

        if (!(argrect =
                  RectExport_RectFromObjectAndKeyFunc(obj, keyfunc, &temp))) {
            Py_XDECREF(obj);
            return NULL;
        }

        if (_pg_do_rects_intersect(&self->r, argrect)) {
            return obj;
        }
        Py_DECREF(obj);
    }

    Py_RETURN_NONE;
}

static PyObject *
RectExport_collidedict(RectObject *self, PyObject *args, PyObject *kwargs)
{
    InnerRect *argrect, temp;
    Py_ssize_t loop = 0;
    Py_ssize_t values = 0; /* Defaults to expecting keys as rects. */
    PyObject *dict, *key, *val;
    PyObject *ret = NULL;

    char *kwds[] = {"rect_dict", "values", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|p", kwds, &dict,
                                     &values)) {
        return NULL;
    }

    if (!PyDict_Check(dict)) {
        return RAISE(PyExc_TypeError, "first argument must be a dict");
    }

    while (PyDict_Next(dict, &loop, &key, &val)) {
        if (values) {
            if (!(argrect = RectFromObject(val, &temp))) {
                return RAISE(PyExc_TypeError,
                             "dict must have rectstyle values");
            }
        }
        else {
            if (!(argrect = RectFromObject(key, &temp))) {
                return RAISE(PyExc_TypeError, "dict must have rectstyle keys");
            }
        }

        if (_pg_do_rects_intersect(&self->r, argrect)) {
            ret = Py_BuildValue("(OO)", key, val);
            break;
        }
    }

    if (!ret) {
        Py_RETURN_NONE;
    }
    return ret;
}

static PyObject *
RectExport_collidedictall(RectObject *self, PyObject *args, PyObject *kwargs)
{
    InnerRect *argrect, temp;
    Py_ssize_t loop = 0;
    Py_ssize_t values = 0; /* Defaults to expecting keys as rects. */
    PyObject *dict, *key, *val;
    PyObject *ret = NULL;

    char *kwds[] = {"rect_dict", "values", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|p", kwds, &dict,
                                     &values)) {
        return NULL;
    }

    if (!PyDict_Check(dict)) {
        return RAISE(PyExc_TypeError, "first argument must be a dict");
    }

    ret = PyList_New(0);
    if (!ret)
        return NULL;

    while (PyDict_Next(dict, &loop, &key, &val)) {
        if (values) {
            if (!(argrect = RectFromObject(val, &temp))) {
                Py_DECREF(ret);
                return RAISE(PyExc_TypeError,
                             "dict must have rectstyle values");
            }
        }
        else {
            if (!(argrect = RectFromObject(key, &temp))) {
                Py_DECREF(ret);
                return RAISE(PyExc_TypeError, "dict must have rectstyle keys");
            }
        }

        if (_pg_do_rects_intersect(&self->r, argrect)) {
            PyObject *num = Py_BuildValue("(OO)", key, val);
            if (!num) {
                Py_DECREF(ret);
                return NULL;
            }
            if (0 != PyList_Append(ret, num)) {
                Py_DECREF(ret);
                Py_DECREF(num);
                return NULL; /* Exception already set. */
            }
            Py_DECREF(num);
        }
    }

    return ret;
}

static PyObject *
RectExport_clip(RectObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    InnerRect *A, *B, temp;
    PrimitiveType x, y, w, h;

    A = &self->r;
    if (!(B = RectFromFastcallArgs(args, nargs, &temp))) {
        return RAISE(PyExc_TypeError, "Argument must be rect style object");
    }

    x = MAX(A->x, B->x);
    y = MAX(A->y, B->y);
    w = MIN(A->x + A->w, B->x + B->w) - x;
    h = MIN(A->y + A->h, B->y + B->h) - y;

    if (w <= 0 || h <= 0) {
        return RectExport_subtypeNew4(Py_TYPE(self), A->x, A->y, 0, 0);
    }
    return RectExport_subtypeNew4(Py_TYPE(self), x, y, w, h);
}

/* clipline() - crops the given line within the rect
 *
 * Supported argument formats:
 *     clipline(x1, y1, x2, y2) - 4 ints
 *     clipline((x1, y1), (x2, y2)) - 2 sequences of 2 ints
 *     clipline(((x1, y1), (x2, y2))) - 1 sequence of 2 sequences of 2 ints
 *     clipline((x1, y1, x2, y2)) - 1 sequence of 4 ints
 *
 * Returns:
 *     PyObject: containing one of the following tuples
 *         ((x1, y1), (x2, y2)) - tuple of 2 tuples of 2 ints, cropped input
 *                                line if line intersects with rect
 *         () - empty tuple, if no intersection
 */
static PyObject *
RectExport_clipline(RectObject *self, PyObject *args)
{
    PyObject *arg1 = NULL, *arg2 = NULL, *arg3 = NULL, *arg4 = NULL;
    InnerRect *rect = &self->r, *rect_copy = NULL;
    PrimitiveType x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    if (!PyArg_ParseTuple(args, "O|OOO", &arg1, &arg2, &arg3, &arg4)) {
        return NULL; /* Exception already set. */
    }

    if (arg2 == NULL) {
        /* Handles formats:
         *     clipline(((x1, y1), (x2, y2)))
         *     clipline((x1, y1, x2, y2))
         */
        if (!fourPrimivitesFromObj(arg1, &x1, &y1, &x2, &y2)) {
            return NULL; /* Exception already set. */
        }
    }
    else if (arg3 == NULL) {
        /* Handles format: clipline((x1, y1), (x2, y2)) */
        int result = twoPrimitivesFromObj(arg1, &x1, &y1);

        if (!result) {
            return RAISE(PyExc_TypeError,
                         "number pair expected for first argument");
        }

        /* Get the other end of the line. */
        result = twoPrimitivesFromObj(arg2, &x2, &y2);

        if (!result) {
            return RAISE(PyExc_TypeError,
                         "number pair expected for second argument");
        }
    }
    else if (arg4 != NULL) {
        /* Handles format: clipline(x1, y1, x2, y2) */
        int result = PrimitiveFromObj(arg1, &x1);

        if (!result) {
            return RAISE(PyExc_TypeError,
                         "number expected for first argument");
        }

        result = PrimitiveFromObj(arg2, &y1);

        if (!result) {
            return RAISE(PyExc_TypeError,
                         "number expected for second argument");
        }

        result = PrimitiveFromObj(arg3, &x2);

        if (!result) {
            return RAISE(PyExc_TypeError,
                         "number expected for third argument");
        }

        result = PrimitiveFromObj(arg4, &y2);

        if (!result) {
            return RAISE(PyExc_TypeError,
                         "number expected for fourth argument");
        }
    }
    else {
        return RAISE(PyExc_TypeError,
                     "clipline() takes 1, 2, or 4 arguments (3 given)");
    }

    if ((self->r.w < 0) || (self->r.h < 0)) {
        /* Make a copy of the rect so it can be normalized. */
        rect_copy = &pgRectAsRect(RectExport_RectNew(&self->r));

        if (rect_copy == NULL) {
            return RAISE(PyExc_MemoryError, "cannot allocate memory for rect");
        }

        RectExport_Normalize(rect_copy);
        rect = rect_copy;
    }

    if (!RectImport_IntersectRectAndLine(rect, &x1, &y1, &x2, &y2)) {
        Py_XDECREF(rect_copy);
        return PyTuple_New(0);
    }

    Py_XDECREF(rect_copy);
    return Py_BuildValue("((" TypeFMT "" TypeFMT ")(" TypeFMT "" TypeFMT "))",
                         x1, y1, x2, y2);
}

static int
RectExport_contains_internal(RectObject *self, PyObject *arg)
{
    InnerRect *argrect, temp_arg;
    if (!(argrect = RectFromObject((PyObject *)arg, &temp_arg))) {
        return -1;
    }
    return (self->r.x <= argrect->x) && (self->r.y <= argrect->y) &&
           (self->r.x + self->r.w >= argrect->x + argrect->w) &&
           (self->r.y + self->r.h >= argrect->y + argrect->h) &&
           (self->r.x + self->r.w > argrect->x) &&
           (self->r.y + self->r.h > argrect->y);
}

static PyObject *
RectExport_contains(RectObject *self, PyObject *arg)
{
    int ret = RectExport_contains_internal(self, arg);
    if (ret < 0) {
        return RAISE(PyExc_TypeError, "Argument must be rect style object");
    }
    return PyBool_FromLong(ret);
}

static int
RectExport_containsSeq(RectObject *self, PyObject *arg)
{
    if (PythonNumberCheck(arg)) {
        PrimitiveType coord = (PrimitiveType)PythonNumberAsPrimitiveType(arg);
        return coord == self->r.x || coord == self->r.y ||
               coord == self->r.w || coord == self->r.h;
    }
    int ret = RectExport_contains_internal(self, arg);
    if (ret < 0) {
        PyErr_SetString(PyExc_TypeError, "'in <" ObjectName
                                         ">' requires rect style object"
                                         " or int as left operand");
    }
    return ret;
}

static PyObject *
RectExport_clamp(RectObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    InnerRect *argrect, temp;
    PrimitiveType x, y;

    if (!(argrect = RectFromFastcallArgs(args, nargs, &temp))) {
        return RAISE(PyExc_TypeError, "Argument must be rect style object");
    }

    if (self->r.w >= argrect->w) {
        x = argrect->x + argrect->w / 2 - self->r.w / 2;
    }
    else if (self->r.x < argrect->x)
        x = argrect->x;
    else if (self->r.x + self->r.w > argrect->x + argrect->w)
        x = argrect->x + argrect->w - self->r.w;
    else
        x = self->r.x;

    if (self->r.h >= argrect->h) {
        y = argrect->y + argrect->h / 2 - self->r.h / 2;
    }
    else if (self->r.y < argrect->y)
        y = argrect->y;
    else if (self->r.y + self->r.h > argrect->y + argrect->h)
        y = argrect->y + argrect->h - self->r.h;
    else
        y = self->r.y;

    return RectExport_subtypeNew4(Py_TYPE(self), x, y, self->r.w, self->r.h);
}

static PyObject *
RectExport_fit(RectObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    InnerRect *argrect, temp;
    PrimitiveType w, h, x, y;
    float xratio, yratio, maxratio;

    if (!(argrect = RectFromFastcallArgs(args, nargs, &temp))) {
        return RAISE(PyExc_TypeError, "Argument must be rect style object");
    }

    xratio = (float)self->r.w / (float)argrect->w;
    yratio = (float)self->r.h / (float)argrect->h;
    maxratio = (xratio > yratio) ? xratio : yratio;

    w = (PrimitiveType)(self->r.w / maxratio);
    h = (PrimitiveType)(self->r.h / maxratio);

    x = argrect->x + (argrect->w - w) / 2;
    y = argrect->y + (argrect->h - h) / 2;

    return RectExport_subtypeNew4(Py_TYPE(self), x, y, w, h);
}

static PyObject *
RectExport_clampIp(RectObject *self, PyObject *const *args, Py_ssize_t nargs)
{
    InnerRect *argrect, temp;
    PrimitiveType x, y;

    if (!(argrect = RectFromFastcallArgs(args, nargs, &temp))) {
        return RAISE(PyExc_TypeError, "Argument must be rect style object");
    }

    if (self->r.w >= argrect->w) {
        x = argrect->x + argrect->w / 2 - self->r.w / 2;
    }
    else if (self->r.x < argrect->x)
        x = argrect->x;
    else if (self->r.x + self->r.w > argrect->x + argrect->w)
        x = argrect->x + argrect->w - self->r.w;
    else
        x = self->r.x;

    if (self->r.h >= argrect->h) {
        y = argrect->y + argrect->h / 2 - self->r.h / 2;
    }
    else if (self->r.y < argrect->y)
        y = argrect->y;
    else if (self->r.y + self->r.h > argrect->y + argrect->h)
        y = argrect->y + argrect->h - self->r.h;
    else
        y = self->r.y;

    self->r.x = x;
    self->r.y = y;
    Py_RETURN_NONE;
}

/* for pickling */
static PyObject *
RectExport_reduce(RectObject *self, PyObject *args)
{
    return Py_BuildValue("(O(" TypeFMT "" TypeFMT "" TypeFMT "" TypeFMT "))",
                         Py_TYPE(self), (PrimitiveType)self->r.x,
                         (PrimitiveType)self->r.y, (PrimitiveType)self->r.w,
                         (PrimitiveType)self->r.h);
}

/* for copy module */
static PyObject *
RectExport_copy(RectObject *self, PyObject *args)
{
    return RectExport_subtypeNew4(Py_TYPE(self), self->r.x, self->r.y,
                                  self->r.w, self->r.h);
}

/* sequence methods */
static PyObject *
RectExport_item(RectObject *self, Py_ssize_t i)
{
    PrimitiveType *data = (PrimitiveType *)&self->r;

    if (i < 0 || i > 3) {
        if (i > -5 && i < 0) {
            i += 4;
        }
        else {
            return RAISE(PyExc_IndexError, "Invalid rect Index");
        }
    }
    return PythonNumberFromPrimitiveType(data[i]);
}

static int
RectExport_assItem(RectObject *self, Py_ssize_t i, PyObject *v)
{
    PrimitiveType val;
    PrimitiveType *data = (PrimitiveType *)&self->r;

    if (!v) {
        PyErr_SetString(PyExc_TypeError, "item deletion is not supported");
        return -1;
    }

    if (i < 0 || i > 3) {
        if (i > -5 && i < 0) {
            i += 4;
        }
        else {
            PyErr_SetString(PyExc_IndexError, "Invalid rect Index");
            return -1;
        }
    }
    if (!PrimitiveFromObj(v, &val)) {
        PyErr_SetString(PyExc_TypeError, "Must assign numeric values");
        return -1;
    }
    data[i] = val;
    return 0;
}

static PyObject *
RectExport_subscript(RectObject *self, PyObject *op)
{
    PrimitiveType *data = (PrimitiveType *)&self->r;

    if (PyIndex_Check(op)) {
        PyObject *index = PyNumber_Index(op);
        Py_ssize_t i;

        if (index == NULL) {
            return NULL;
        }
        i = PyNumber_AsSsize_t(index, NULL);
        Py_DECREF(index);
        return RectExport_item(self, i);
    }
    else if (op == Py_Ellipsis) {
        return Py_BuildValue("[" TypeFMT "" TypeFMT "" TypeFMT "" TypeFMT "]",
                             data[0], data[1], data[2], data[3]);
    }
    else if (PySlice_Check(op)) {
        PyObject *slice;
        Py_ssize_t start;
        Py_ssize_t stop;
        Py_ssize_t step;
        Py_ssize_t slicelen;
        Py_ssize_t i;
        PyObject *n;

        if (PySlice_GetIndicesEx(op, 4, &start, &stop, &step, &slicelen)) {
            return NULL;
        }

        slice = PyList_New(slicelen);
        if (slice == NULL) {
            return NULL;
        }
        for (i = 0; i < slicelen; ++i) {
            n = PythonNumberFromPrimitiveType(data[start + (step * i)]);
            if (n == NULL) {
                Py_DECREF(slice);
                return NULL;
            }
            PyList_SET_ITEM(slice, i, n);
        }
        return slice;
    }

    return RAISE(PyExc_TypeError, "Invalid Rect slice");
}

static int
RectExport_assSubscript(RectObject *self, PyObject *op, PyObject *value)
{
    if (!value) {
        PyErr_SetString(PyExc_TypeError, "item deletion is not supported");
        return -1;
    }
    if (PyIndex_Check(op)) {
        PyObject *index;
        Py_ssize_t i;

        index = PyNumber_Index(op);
        if (index == NULL) {
            return -1;
        }
        i = PyNumber_AsSsize_t(index, NULL);
        Py_DECREF(index);
        return RectExport_assItem(self, i, value);
    }
    else if (op == Py_Ellipsis) {
        PrimitiveType val;

        if (PrimitiveFromObj(value, &val)) {
            self->r.x = val;
            self->r.y = val;
            self->r.w = val;
            self->r.h = val;
        }
        else if (RectImport_RectCheck(value)) {
            RectObject *rect = (RectObject *)value;

            self->r.x = rect->r.x;
            self->r.y = rect->r.y;
            self->r.w = rect->r.w;
            self->r.h = rect->r.h;
        }
        else if (PySequence_Check(value)) {
            PyObject *item;
            PrimitiveType values[4];
            Py_ssize_t i;

            if (PySequence_Size(value) != 4) {
                PyErr_SetString(PyExc_TypeError, "Expect a length 4 sequence");
                return -1;
            }
            for (i = 0; i < 4; ++i) {
                item = PySequence_ITEM(value, i);
                if (!PrimitiveFromObj(item, values + i)) {
                    PyErr_Format(PyExc_TypeError,
                                 "Expected an integer between %d and %d",
                                 INT_MIN, INT_MAX);
                }
            }
            self->r.x = values[0];
            self->r.y = values[1];
            self->r.w = values[2];
            self->r.h = values[3];
        }
        else {
            PyErr_SetString(PyExc_TypeError,
                            "Expected an integer or sequence");
            return -1;
        }
    }
    else if (PySlice_Check(op)) {
        PrimitiveType *data = (PrimitiveType *)&self->r;
        Py_ssize_t start;
        Py_ssize_t stop;
        Py_ssize_t step;
        Py_ssize_t slicelen;
        PrimitiveType val;
        Py_ssize_t i;

        if (PySlice_GetIndicesEx(op, 4, &start, &stop, &step, &slicelen)) {
            return -1;
        }

        if (PrimitiveFromObj(value, &val)) {
            for (i = 0; i < slicelen; ++i) {
                data[start + step * i] = val;
            }
        }
        else if (PySequence_Check(value)) {
            PyObject *item;
            PrimitiveType values[4];
            Py_ssize_t size = PySequence_Size(value);

            if (size != slicelen) {
                PyErr_Format(PyExc_TypeError, "Expected a length %zd sequence",
                             slicelen);
                return -1;
            }
            for (i = 0; i < slicelen; ++i) {
                item = PySequence_ITEM(value, i);
                if (!PrimitiveFromObj(item, values + i)) {
                    PyErr_Format(PyExc_TypeError,
                                 "Expected an integer between %d and %d",
                                 INT_MIN, INT_MAX);
                }
            }
            for (i = 0; i < slicelen; ++i) {
                data[start + step * i] = values[i];
            }
        }
        else {
            PyErr_SetString(PyExc_TypeError,
                            "Expected an integer or sequence");
            return -1;
        }
    }
    else {
        PyErr_SetString(PyExc_TypeError, "Invalid Rect slice");
        return -1;
    }
    return 0;
}

/* numeric functions */
static int
RectExport_bool(RectObject *self)
{
    return self->r.w != 0 && self->r.h != 0;
}

static PyObject *
RectExport_richcompare(PyObject *o1, PyObject *o2, int opid)
{
    InnerRect *o1rect, *o2rect, temp1, temp2;
    int cmp;

    o1rect = RectFromObject(o1, &temp1);
    if (!o1rect) {
        goto Unimplemented;
    }
    o2rect = RectFromObject(o2, &temp2);
    if (!o2rect) {
        goto Unimplemented;
    }

    if (o1rect->x != o2rect->x) {
        cmp = o1rect->x < o2rect->x ? -1 : 1;
    }
    else if (o1rect->y != o2rect->y) {
        cmp = o1rect->y < o2rect->y ? -1 : 1;
    }
    else if (o1rect->w != o2rect->w) {
        cmp = o1rect->w < o2rect->w ? -1 : 1;
    }
    else if (o1rect->h != o2rect->h) {
        cmp = o1rect->h < o2rect->h ? -1 : 1;
    }
    else {
        cmp = 0;
    }

    switch (opid) {
        case Py_LT:
            return PyBool_FromLong(cmp < 0);
        case Py_LE:
            return PyBool_FromLong(cmp <= 0);
        case Py_EQ:
            return PyBool_FromLong(cmp == 0);
        case Py_NE:
            return PyBool_FromLong(cmp != 0);
        case Py_GT:
            return PyBool_FromLong(cmp > 0);
        case Py_GE:
            return PyBool_FromLong(cmp >= 0);
        default:
            break;
    }

Unimplemented:
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

/*width*/
static PyObject *
RectExport_getwidth(RectObject *self, void *closure)
{
    return PythonNumberFromPrimitiveType(self->r.w);
}

static int
RectExport_setwidth(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!PrimitiveFromObj(value, &val1)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.w = val1;
    return 0;
}

/*height*/
static PyObject *
RectExport_getheight(RectObject *self, void *closure)
{
    return PythonNumberFromPrimitiveType(self->r.h);
}

static int
RectExport_setheight(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!PrimitiveFromObj(value, &val1)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.h = val1;
    return 0;
}

/*top*/
static PyObject *
RectExport_gettop(RectObject *self, void *closure)
{
    return PythonNumberFromPrimitiveType(self->r.y);
}

static int
RectExport_settop(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!PrimitiveFromObj(value, &val1)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.y = val1;
    return 0;
}

/*left*/
static PyObject *
RectExport_getleft(RectObject *self, void *closure)
{
    return PythonNumberFromPrimitiveType(self->r.x);
}

static int
RectExport_setleft(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!PrimitiveFromObj(value, &val1)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.x = val1;
    return 0;
}

/*right*/
static PyObject *
RectExport_getright(RectObject *self, void *closure)
{
    return PythonNumberFromPrimitiveType(self->r.x + self->r.w);
}

static int
RectExport_setright(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!PrimitiveFromObj(value, &val1)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.x = val1 - self->r.w;
    return 0;
}

/*bottom*/
static PyObject *
RectExport_getbottom(RectObject *self, void *closure)
{
    return PythonNumberFromPrimitiveType(self->r.y + self->r.h);
}

static int
RectExport_setbottom(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!PrimitiveFromObj(value, &val1)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.y = val1 - self->r.h;
    return 0;
}

/*centerx*/
static PyObject *
RectExport_getcenterx(RectObject *self, void *closure)
{
    return PythonNumberFromPrimitiveType(self->r.x + (self->r.w / 2));
}

static int
RectExport_setcenterx(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!PrimitiveFromObj(value, &val1)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.x = val1 - (self->r.w / 2);
    return 0;
}

/*centery*/
static PyObject *
RectExport_getcentery(RectObject *self, void *closure)
{
    return PythonNumberFromPrimitiveType(self->r.y + (self->r.h / 2));
}

static int
RectExport_setcentery(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!PrimitiveFromObj(value, &val1)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.y = val1 - (self->r.h / 2);
    return 0;
}

/*topleft*/
static PyObject *
RectExport_gettopleft(RectObject *self, void *closure)
{
    return Py_BuildValue("(" TypeFMT "" TypeFMT ")", self->r.x, self->r.y);
}

static int
RectExport_settopleft(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1, val2;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!twoPrimitivesFromObj(value, &val1, &val2)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.x = val1;
    self->r.y = val2;
    return 0;
}

/*topright*/
static PyObject *
RectExport_gettopright(RectObject *self, void *closure)
{
    return Py_BuildValue("(" TypeFMT "" TypeFMT ")", self->r.x + self->r.w,
                         self->r.y);
}

static int
RectExport_settopright(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1, val2;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!twoPrimitivesFromObj(value, &val1, &val2)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.x = val1 - self->r.w;
    self->r.y = val2;
    return 0;
}

/*bottomleft*/
static PyObject *
RectExport_getbottomleft(RectObject *self, void *closure)
{
    return Py_BuildValue("(" TypeFMT "" TypeFMT ")", self->r.x,
                         self->r.y + self->r.h);
}

static int
RectExport_setbottomleft(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1, val2;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!twoPrimitivesFromObj(value, &val1, &val2)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.x = val1;
    self->r.y = val2 - self->r.h;
    return 0;
}

/*bottomright*/
static PyObject *
RectExport_getbottomright(RectObject *self, void *closure)
{
    return Py_BuildValue("(" TypeFMT "" TypeFMT ")", self->r.x + self->r.w,
                         self->r.y + self->r.h);
}

static int
RectExport_setbottomright(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1, val2;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!twoPrimitivesFromObj(value, &val1, &val2)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.x = val1 - self->r.w;
    self->r.y = val2 - self->r.h;
    return 0;
}

/*midtop*/
static PyObject *
RectExport_getmidtop(RectObject *self, void *closure)
{
    return Py_BuildValue("(" TypeFMT "" TypeFMT ")",
                         self->r.x + (self->r.w / 2), self->r.y);
}

static int
RectExport_setmidtop(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1, val2;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!twoPrimitivesFromObj(value, &val1, &val2)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.x += val1 - (self->r.x + (self->r.w / 2));
    self->r.y = val2;
    return 0;
}

/*midleft*/
static PyObject *
RectExport_getmidleft(RectObject *self, void *closure)
{
    return Py_BuildValue("(" TypeFMT "" TypeFMT ")", self->r.x,
                         self->r.y + (self->r.h / 2));
}

static int
RectExport_setmidleft(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1, val2;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!twoPrimitivesFromObj(value, &val1, &val2)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.x = val1;
    self->r.y += val2 - (self->r.y + (self->r.h / 2));
    return 0;
}

/*midbottom*/
static PyObject *
RectExport_getmidbottom(RectObject *self, void *closure)
{
    return Py_BuildValue("(" TypeFMT "" TypeFMT ")",
                         self->r.x + (self->r.w / 2), self->r.y + self->r.h);
}

static int
RectExport_setmidbottom(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1, val2;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!twoPrimitivesFromObj(value, &val1, &val2)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.x += val1 - (self->r.x + (self->r.w / 2));
    self->r.y = val2 - self->r.h;
    return 0;
}

/*midright*/
static PyObject *
RectExport_getmidright(RectObject *self, void *closure)
{
    return Py_BuildValue("(" TypeFMT "" TypeFMT ")", self->r.x + self->r.w,
                         self->r.y + (self->r.h / 2));
}

static int
RectExport_setmidright(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1, val2;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!twoPrimitivesFromObj(value, &val1, &val2)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.x = val1 - self->r.w;
    self->r.y += val2 - (self->r.y + (self->r.h / 2));
    return 0;
}

/*center*/
static PyObject *
RectExport_getcenter(RectObject *self, void *closure)
{
    return Py_BuildValue("(" TypeFMT "" TypeFMT ")",
                         self->r.x + (self->r.w / 2),
                         self->r.y + (self->r.h / 2));
}

static int
RectExport_setcenter(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1, val2;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!twoPrimitivesFromObj(value, &val1, &val2)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.x += val1 - (self->r.x + (self->r.w / 2));
    self->r.y += val2 - (self->r.y + (self->r.h / 2));
    return 0;
}

/*size*/
static PyObject *
RectExport_getsize(RectObject *self, void *closure)
{
    return Py_BuildValue("(" TypeFMT "" TypeFMT ")", self->r.w, self->r.h);
}

static int
RectExport_setsize(RectObject *self, PyObject *value, void *closure)
{
    PrimitiveType val1, val2;

    if (NULL == value) {
        /* Attribute deletion not supported. */
        PyErr_SetString(PyExc_AttributeError, "can't delete attribute");
        return -1;
    }

    if (!twoPrimitivesFromObj(value, &val1, &val2)) {
        PyErr_SetString(PyExc_TypeError, "invalid rect assignment");
        return -1;
    }
    self->r.w = val1;
    self->r.h = val2;
    return 0;
}

static PyObject *
RectExport_iterator(RectObject *self)
{
    Py_ssize_t i;
    PrimitiveType *data = (PrimitiveType *)&self->r;
    PyObject *iter, *tup = PyTuple_New(4);
    if (!tup) {
        return NULL;
    }
    for (i = 0; i < 4; i++) {
        PyObject *val = PythonNumberFromPrimitiveType(data[i]);
        if (!val) {
            Py_DECREF(tup);
            return NULL;
        }

        PyTuple_SET_ITEM(tup, i, val);
    }
    iter = PyTuple_Type.tp_iter(tup);
    Py_DECREF(tup);
    return iter;
}

#undef RectExport_init
#undef RectExport_subtypeNew4
#undef RectExport_new
#undef RectExport_dealloc
#undef RectExport_normalize
#undef pgTwoValuesFromFastcallArgs
#undef RectExport_move
#undef RectExport_moveIp
#undef RectExport_inflate
#undef RectExport_inflateIp
#undef RectExport_scalebyIp
#undef RectExport_scaleby
#undef RectExport_update
#undef RectExport_union
#undef RectExport_unionIp
#undef RectExport_unionall
#undef RectExport_unionallIp
#undef RectExport_collidepoint
#undef RectExport_colliderect
#undef RectExport_collidelist
#undef RectExport_collidelistall
#undef RectExport_collidedict
#undef RectExport_collidedictall
#undef RectExport_collideobjectsall
#undef RectExport_collideobjects
#undef RectExport_RectFromObjectAndKeyFunc
#undef RectExport_pgTwoValuesFromFastcallArgs
#undef RectExport_clip
#undef RectExport_clipline
#undef RectExport_do_rects_intresect
#undef RectExport_RectFromObject
#undef RectExport_RectFromFastcallArgs
#undef RectExport_RectNew
#undef RectExport_RectNew4
#undef RectExport_Normalize
#undef RectExport_contains_internal
#undef RectExport_contains
#undef RectExport_containsSeq
#undef RectExport_clamp
#undef RectExport_fit
#undef RectExport_clampIp
#undef RectExport_reduce
#undef RectExport_copy
#undef RectExport_item
#undef RectExport_assItem
#undef RectExport_subscript
#undef RectExport_assSubscript
#undef RectExport_bool
#undef RectExport_richcompare
#undef RectExport_getwidth
#undef RectExport_setwidth
#undef RectExport_getheight
#undef RectExport_setheight
#undef RectExport_gettop
#undef RectExport_settop
#undef RectExport_getleft
#undef RectExport_setleft
#undef RectExport_getright
#undef RectExport_setright
#undef RectExport_getbottom
#undef RectExport_setbottom
#undef RectExport_getcenterx
#undef RectExport_setcenterx
#undef RectExport_getcentery
#undef RectExport_setcentery
#undef RectExport_gettopleft
#undef RectExport_settopleft
#undef RectExport_gettopright
#undef RectExport_settopright
#undef RectExport_getbottomleft
#undef RectExport_setbottomleft
#undef RectExport_getbottomright
#undef RectExport_setbottomright
#undef RectExport_getmidtop
#undef RectExport_setmidtop
#undef RectExport_getmidleft
#undef RectExport_setmidleft
#undef RectExport_getmidbottom
#undef RectExport_setmidbottom
#undef RectExport_getmidright
#undef RectExport_setmidright
#undef RectExport_getcenter
#undef RectExport_setcenter
#undef RectExport_getsize
#undef RectExport_setsize
#undef RectExport_iterator

#undef RectImport_PythonNumberCheck
#undef RectImport_PythonNumberAsPrimitiveType
#undef RectImport_PrimitiveTypeAsPythonNumber
#undef RectImport_primitiveType
#undef RectImport_RectCheck
#undef RectImport_RectCheckExact
#undef RectImport_innerRectStruct
#undef RectImport_innerPointStruct
#undef RectImport_fourPrimiviteFromObj
#undef RectImport_primitiveFromObjIndex
#undef RectImport_twoPrimitivesFromObj
#undef RectImport_PrimitiveFromObj
#undef RectImport_IntersectRectAndLine
#undef RectImport_RectObject
#undef RectImport_TypeObject
#undef RectImport_PrimitiveFromObj
#undef RectImport_PyBuildValueFormat
#undef RectImport_ObjectName

#undef PrimitiveType
#undef RectObject
#undef TypeObject
#undef InnerRect
#undef InnerPoint
#undef RectCheck
#undef RectFromObject
#undef RectFromFastcallArgs
#undef subtype_new4
#undef primitiveFromObjIndex
#undef twoPrimitivesFromObj
#undef fourPrimivitesFromObj
#undef PrimitiveFromObj
#undef TypeFMT
#undef pgRectAsRect
#undef _pg_do_rects_intersect
#undef ObjectName
#undef PythonNumberCheck
#undef PythonNumberAsPrimitiveType
#undef PythonNumberFromPrimitiveType
#undef PrimitiveTypeAsPythonNumber

#ifdef RectOptional_FREELIST
#undef RectOptional_FREELIST
#undef RectOptional_FreelistlimitNumberName
#undef RectOptional_FreelistlimitNumber
#undef RectOptional_FreelistFreelistName
#undef RectOptional_Freelist_Num
#endif /* RectOptional_FREELIST */

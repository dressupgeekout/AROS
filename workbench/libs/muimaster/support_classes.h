/*
    Copyright � 2002-2003, The AROS Development Team. All rights reserved.
    $Id$
*/

#ifndef _MUIMASTER_SUPPORT_CLASSES_H
#define _MUIMASTER_SUPPORT_CLASSES_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif

#ifndef CLIB_MACROS_H
#include <clib/macros.h>
#endif

#include "support.h"

#if ZUNE_BUILTIN_ABOUTMUI
#   define ZUNE_ABOUTMUI_DESC (&_MUI_Aboutmui_desc),
#else
#   define ZUNE_ABOUTMUI_DESC
#endif

#if ZUNE_BUILTIN_BOOPSI
#   define ZUNE_BOOPSI_DESC (&_MUI_Boopsi_desc),
#else
#   define ZUNE_BOOPSI_DESC
#endif

#if ZUNE_BUILTIN_BALANCE
#   define ZUNE_BALANCE_DESC (&_MUI_Balance_desc),
#else
#   define ZUNE_BALANCE_DESC
#endif

#if ZUNE_BUILTIN_COLORADJUST
#   define ZUNE_COLORADJUST_DESC (&_MUI_Coloradjust_desc),
#else
#   define ZUNE_COLORADJUST_DESC
#endif

#if ZUNE_BUILTIN_COLORFIELD
#   define ZUNE_COLORFIELD_DESC (&_MUI_Colorfield_desc),
#else
#   define ZUNE_COLORFIELD_DESC
#endif

#if ZUNE_BUILTIN_FRAMEADJUST
#   define ZUNE_FRAMEADJUST_DESC (&_MUI_Frameadjust_desc),
#else
#   define ZUNE_FRAMEADJUST_DESC
#endif

#if ZUNE_BUILTIN_FRAMEDISPLAY
#   define ZUNE_FRAMEDISPLAY_DESC (&_MUI_Framedisplay_desc),
#else
#   define ZUNE_FRAMEDISPLAY_DESC
#endif

#if ZUNE_BUILTIN_GAUGE
#   define ZUNE_GAUGE_DESC (&_MUI_Gauge_desc),
#else
#   define ZUNE_GAUGE_DESC
#endif

#if ZUNE_BUILTIN_ICONLISTVIEW
#   define ZUNE_ICONLISTVIEW_DESC (&_MUI_IconListview_desc),
#else
#   define ZUNE_ICONLISTVIEW_DESC
#endif

#if ZUNE_BUILTIN_IMAGEADJUST
#   define ZUNE_IMAGEADJUST_DESC (&_MUI_Imageadjust_desc),
#else
#   define ZUNE_IMAGEADJUST_DESC
#endif

#if ZUNE_BUILTIN_IMAGEDISPLAY
#   define ZUNE_IMAGEDISPLAY_DESC (&_MUI_Imagedisplay_desc),
#else
#   define ZUNE_IMAGEDISPLAY_DESC
#endif

#if ZUNE_BUILTIN_PENADJUST
#   define ZUNE_PENADJUST_DESC (&_MUI_Penadjust_desc),
#else
#   define ZUNE_PENADJUST_DESC
#endif

#if ZUNE_BUILTIN_PENDISPLAY
#   define ZUNE_PENDISPLAY_DESC (&_MUI_Pendisplay_desc),
#else
#   define ZUNE_PENDISPLAY_DESC
#endif

#if ZUNE_BUILTIN_POPASL
#   define ZUNE_POPASL_DESC (&_MUI_Popasl_desc),
#else
#   define ZUNE_POPASL_DESC
#endif

#if ZUNE_BUILTIN_POPFRAME
#   define ZUNE_POPFRAME_DESC (&_MUI_Popframe_desc),
#else
#   define ZUNE_POPFRAME_DESC
#endif

#if ZUNE_BUILTIN_POPIMAGE
#   define ZUNE_POPIMAGE_DESC (&_MUI_Popimage_desc),
#else
#   define ZUNE_POPIMAGE_DESC
#endif

#if ZUNE_BUILTIN_POPPEN
#   define ZUNE_POPPEN_DESC (&_MUI_Poppen_desc),
#else
#   define ZUNE_POPPEN_DESC
#endif

#if ZUNE_BUILTIN_RADIO
#   define ZUNE_RADIO_DESC (&_MUI_Radio_desc),
#else
#   define ZUNE_RADIO_DESC
#endif

#if ZUNE_BUILTIN_SCALE
#   define ZUNE_SCALE_DESC (&_MUI_Scale_desc),
#else
#   define ZUNE_SCALE_DESC
#endif

#if ZUNE_BUILTIN_SCROLLGROUP
#   define ZUNE_SCROLLGROUP_DESC (&_MUI_Scrollgroup_desc),
#else
#   define ZUNE_SCROLLGROUP_DESC
#endif

#if ZUNE_BUILTIN_SETTINGSGROUP
#   define ZUNE_SETTINGSGROUP_DESC (&_MUI_Settingsgroup_desc),
#else
#   define ZUNE_SETTINGSGROUP_DESC
#endif

#if ZUNE_BUILTIN_VIRTGROUP
#   define ZUNE_VIRTGROUP_DESC (&_MUI_Virtgroup_desc),
#else
#   define ZUNE_VIRTGROUP_DESC
#endif

#if ZUNE_BUILTIN_VOLUMELIST
#   define ZUNE_VOLUMELIST_DESC (&_MUI_Volumelist_desc),
#else
#   define ZUNE_VOLUMELIST_DESC
#endif

#if ZUNE_BUILTIN_DIRLIST
#   define ZUNE_DIRLIST_DESC (&_MUI_Dirlist_desc),
#else
#   define ZUNE_DIRLIST_DESC
#endif

Class *ZUNE_GetBuiltinClass(ClassID className, struct Library *mb);
Class *ZUNE_GetExternalClass(ClassID className, struct Library *mb);
Class *ZUNE_FindBuiltinClass(ClassID className, struct Library *mb);
Class *ZUNE_MakeBuiltinClass(ClassID className, struct Library *mb);

#define ZUNE_AddBuiltinClass(cl, mb)                                         \
do                                                                           \
{                                                                            \
    AddTail((struct List *)&MUIMB(mb)->BuiltinClasses, (struct Node *)(cl)); \
    (cl)->cl_Flags |= CLF_INLIST;                                            \
} while (0)

#define ZUNE_RemoveBuiltinClass(cl, mb) \
    (void)Remove((struct Node *)(cl))

AROS_UFP3
(
    IPTR, metaDispatcher,
    AROS_UFPA(struct IClass *, cl,  A0),
    AROS_UFPA(Object *,        obj, A2),
    AROS_UFPA(Msg     ,        msg, A1)
);


#ifdef __AROS__
#define MCC_Query(x) AROS_LVO_CALL1(struct MUI_CustomClass *,          \
		                    AROS_LCA(LONG, (x), D0),           \
				    struct Library *, mcclib, 5, lib);
#else

struct MUI_CustomClass *MCC_Query(ULONG d0);
#pragma  libcall mcclib MCC_Query 01e 001

#endif

#endif /* _MUIMASTER_SUPPORT_CLASSES_H */


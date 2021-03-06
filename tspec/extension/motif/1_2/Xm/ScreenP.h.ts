# Copyright 2002-2011, The TenDRA Project.
# Copyright 1995-1996, IXI Ltd.
#
# See doc/copyright/ for the full copyright terms.


%%
#ifndef __MOTIF_P_HEADERS
#error Unexpected access to Motif P headers
#endif
%%

+USE "motif/1_2", "Xm/DesktopP.h.ts";
+USE "motif/1_2", "Xm/Screen.h.ts";
+USE "motif/1_2", "Xm/DragIcon.h.ts";

+FIELD (struct) _XmScreenClassPart := { 

	XtPointer		extension;
};

+TYPEDEF _XmScreenClassPart XmScreenClassPart;
+TYPEDEF _XmScreenClassPart *XmScreenClassPartPtr;

+FIELD (struct) _XmScreenClassRec := { 

	CoreClassPart		core_class;
	XmDesktopClassPart	desktop_class;
	XmScreenClassPart	screen_class;
};

+TYPEDEF _XmScreenClassRec XmScreenClassRec;

+TYPE struct _XmDragCursorRec;

+FIELD struct _XmDragCursorRec := { 

	struct _XmDragCursorRec	*next;
	Cursor			cursor;
	XmDragIconObject	stateIcon;
	XmDragIconObject	opIcon;
	XmDragIconObject	sourceIcon;
	Boolean			dirty;
};

+TYPEDEF struct _XmDragCursorRec XmDragCursorRec;
+TYPEDEF struct _XmDragCursorRec *XmDragCursorCache;

+TYPE struct _XmScratchPixmapRec;

+FIELD struct _XmScratchPixmapRec := { 

	struct _XmScratchPixmapRec	*next;
	Pixmap				pixmap;
	Cardinal			depth;
	Dimension			width;
	Dimension			height;
	Boolean				inUse;
};

+TYPEDEF struct _XmScratchPixmapRec XmScratchPixmapRec;
+TYPEDEF struct _XmScratchPixmapRec * XmScratchPixmap;

+FIELD (struct) XmScreenPart := { 

	Boolean			mwmPresent;
	unsigned short		numReparented;
	int			darkThreshold;
	int			foregroundThreshold;
	int			lightThreshold;
	XmDragIconObject	defaultNoneCursorIcon;
	XmDragIconObject	defaultValidCursorIcon;
	XmDragIconObject	defaultInvalidCursorIcon;
	XmDragIconObject	defaultMoveCursorIcon;
	XmDragIconObject	defaultCopyCursorIcon;
	XmDragIconObject	defaultLinkCursorIcon;
	XmDragIconObject	defaultSourceCursorIcon;

	Cursor			nullCursor;
	XmDragCursorRec		*cursorCache;
	Cardinal		maxCursorWidth;
	Cardinal		maxCursorHeight;
	
	Cursor			menuCursor;
	unsigned char		unpostBehavior;
	XFontStruct		*font_struct;
	int			h_unit;
	int			v_unit;
	XmScratchPixmap		scratchPixmaps;
	unsigned char		moveOpaque;
	
	XmDragIconObject	xmStateCursorIcon;
	XmDragIconObject	xmMoveCursorIcon;
	XmDragIconObject	xmCopyCursorIcon;
	XmDragIconObject	xmLinkCursorIcon;
	XmDragIconObject	xmSourceCursorIcon;

	GC			imageGC;
	int			imageGCDepth;
	Pixel			imageForeground;
	Pixel			imageBackground;

	XtPointer		screenInfo;
};

+TYPEDEF XmScreenPart *XmScreenPartPtr;

+FIELD (struct) _XmScreenInfo := {

	XtPointer		menu_state;
	Boolean			destroyCallbackAdded;
};

+TYPEDEF _XmScreenInfo XmScreenInfo;

+EXP lvalue XmScreenClassRec xmScreenClassRec;

+FIELD (struct) _XmScreenRec := { 

	CorePart		core;
	XmDesktopPart		desktop;
	XmScreenPart		screen;
};

+TYPEDEF _XmScreenRec XmScreenRec;

+EXP lvalue XrmQuark _XmInvalidCursorIconQuark;
+EXP lvalue XrmQuark _XmValidCursorIconQuark;
+EXP lvalue XrmQuark _XmNoneCursorIconQuark;
+EXP lvalue XrmQuark _XmDefaultDragIconQuark;
+EXP lvalue XrmQuark _XmMoveCursorIconQuark;
+EXP lvalue XrmQuark _XmCopyCursorIconQuark;
+EXP lvalue XrmQuark _XmLinkCursorIconQuark;

+FUNC XmDragIconObject _XmScreenGetOperationIcon(Widget, unsigned char);
+FUNC XmDragIconObject _XmScreenGetStateIcon(Widget, unsigned char);
+FUNC XmDragIconObject _XmScreenGetSourceIcon(Widget);
+FUNC Pixmap _XmAllocScratchPixmap(XmScreen, Cardinal, Dimension, Dimension);
+FUNC void _XmFreeScratchPixmap(XmScreen, Pixmap);
+FUNC XmDragCursorCache * _XmGetDragCursorCachePtr(XmScreen);
+FUNC void _XmGetMaxCursorSize(Widget,Dimension *, Dimension *);
+FUNC Cursor _XmGetNullCursor(Widget);
+FUNC Cursor _XmGetMenuCursorByScreen(Screen *);
+FUNC Boolean _XmGetMoveOpaqueByScreen(Screen *);
+FUNC unsigned char _XmGetUnpostBehavior(Widget);
+FUNC int _XmGetFontUnit(Screen *, int);
+FUNC void _XmScreenRemoveFromCursorCache(XmDragIconObject);


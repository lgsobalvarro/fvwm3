## Process this file with automake to create Makefile.in

noinst_LIBRARIES = libfvwm3.a

EXTRA_DIST=meson.build

## please keep .c files in largest first order to speed up parallel makes
libfvwm3_a_SOURCES = \
	BidiJoin.h Bindings.h ClientMsg.h ColorUtils.h Colorset.h \
	CombineChars.h Cursor.h Event.h FBidi.h FEvent.h FGettext.h FImage.h \
	FRender.h FRenderInit.h FRenderInterface.h FSMlib.h FScreen.h \
	FShape.h FShm.h FTips.h Fcursor.h FftInterface.h Ficonv.h \
	Flocale.h FlocaleCharset.h Fpng.h Fsvg.h Fxpm.h Grab.h \
	Graphics.h Module.h Parse.h Picture.h PictureBase.h \
	PictureDitherMatrice.h PictureGraphics.h PictureImageLoader.h \
	PictureUtils.h Rectangles.h Strings.h System.h Target.h WinMagic.h \
	XError.h XResource.h charmap.h defaults.h envvar.h fio.h flist.h fqueue.h \
	fsm.h ftime.h fvwm_sys_stat.h fvwm_x11.h fvwmlib.h fvwmrect.h fvwmsignal.h \
	gravity.c gravity.h getpwuid.h lang-strings.h log.h modifiers.h queue.h \
	safemalloc.h setpgrp.h timeout.h vpacket.h wcontext.h wild.h \
	cJSON.h tree.h strtonum.h \
	\
	BidiJoin.c Flocale.c PictureUtils.c FScreen.c Graphics.c \
	PictureGraphics.c Bindings.c FlocaleCharset.c Parse.c \
	PictureImageLoader.c Colorset.c ColorUtils.c CombineChars.c Module.c \
	FRender.c Ficonv.c envvar.c Fft.c  gravity.c log.c \
	XResource.c FEvent.c FImage.c WinMagic.c Target.c Picture.c XError.c \
	fqueue.c fvwmsignal.c System.c PictureBase.c Cursor.c Strings.c \
	fvwmrect.c FRenderInit.c safemalloc.c  FBidi.c \
	wild.c Grab.c Event.c ClientMsg.c setpgrp.c FShape.c \
	FGettext.c Rectangles.c timeout.c flist.c charmap.c wcontext.c \
	modifiers.c fsm.c FTips.c fio.c fvwmlib3.c \
	getpwuid.c cJSON.c strtonum.c

if HOST_MACOS
foo=
else
libfvwm3_a_SOURCES += strlcpy.h strlcat.h strlcpy.c strlcat.c
endif

libfvwm3_a_LIBADD = @LIBOBJS@

AM_CPPFLAGS = -I$(top_srcdir) $(xpm_CFLAGS) $(Xft_CFLAGS) $(X_CFLAGS) \
	$(iconv_CFLAGS) $(Xrender_CFLAGS) $(Bidi_CFLAGS) $(png_CFLAGS) \
	$(rsvg_CFLAGS) $(intl_CFLAGS) $(XRandR_CFLAGS)

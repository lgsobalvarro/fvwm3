## Process this file with automake to create Makefile.in

program_transform_name =

moduledir = @FVWM_MODULEDIR@
configdir = @FVWM_DATADIR@

module_PROGRAMS = FvwmPager
EXTRA_DIST = ConfigFvwmPager meson.build

config_DATA = \
  ConfigFvwmPager

FvwmPager_SOURCES = FvwmPager.c FvwmPager.h x_pager.c fpmonitor.c \
	messages.c init_pager.c x_update.c
FvwmPager_DEPENDENCIES = $(top_builddir)/libs/libfvwm3.a

## Xpm note: while this module may not depend on Xpm explicitly,
## there are sometimes dependencies through functions in libfvwm
## so we might as well link against libXpm, if present.
LDADD = -L$(top_builddir)/libs -lfvwm3 $(Xft_LIBS) $(X_LIBS) $(xpm_LIBS) \
	$(png_LIBS) $(rsvg_LIBS) $(X_PRE_LIBS) $(XRandR_LIBS) -lXext -lX11 \
	$(X_EXTRA_LIBS) -lm $(Xrender_LIBS) $(Xcursor_LIBS) $(iconv_LIBS) \
	$(Bidi_LIBS)

AM_CPPFLAGS = -I$(top_srcdir) $(xpm_CFLAGS) $(png_CFLAGS) $(Xft_CFLAGS) \
	$(X_CFLAGS) $(Xrender_CFLAGS) $(iconv_CFLAGS) $(Bidi_CFLAGS)


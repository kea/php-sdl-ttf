dnl config.m4 for extension sdl_ttf

PHP_ARG_ENABLE([sdl_ttf],
  [whether to enable sdl_ttf support],
  [AS_HELP_STRING([--enable-sdl_ttf],
    [Enable sdl_ttf support])],
  [no])

if test "$PHP_SDL_TTF" != "no"; then
    AC_DEFINE(WITH_SDL_TTF, 1, [Whether you want SDL Mixer])
    AC_MSG_CHECKING([for SDL_ttf.h])
    for i in $PHP_SDL_TTF /usr/local /usr; do
      if test -r $i/include/SDL2/SDL_ttf.h; then
        SDL_TTF_DIR=$i
        AC_DEFINE(HAVE_SDL_TTF_H, 1, [Whether you have SDL2/SDL_ttf.h])
        PHP_ADD_INCLUDE($i/include/SDL2)
      fi
    done

    if test -z "$SDL_TTF_DIR"; then
      AC_MSG_RESULT([not found])
      AC_MSG_ERROR([Please reinstall the SDL_ttf distribution including development files])
    else
      AC_MSG_RESULT([found])
    fi

    AC_CHECK_LIB(SDL2_ttf, TTF_RenderUTF8_Shaded, [
      PHP_ADD_LIBRARY(SDL2_ttf,, SDL_TTF_SHARED_LIBADD)
    ], [
      AC_MSG_ERROR([libSDL2_ttf not found!])
    ])

  AC_DEFINE(HAVE_SDL_TTF, 1, [ Have sdl_ttf support ])

  PHP_SUBST(SDL_TTF_SHARED_LIBADD)

  PHP_NEW_EXTENSION(sdl_ttf, sdl_ttf.c, $ext_shared)
  PHP_ADD_EXTENSION_DEP(sdl_ttf, sdl)
fi

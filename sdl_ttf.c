/* sdl_ttf extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include <SDL_ttf.h>
#include "php_sdl_ttf.h"
#include "sdl_ttf_arginfo.h"

zend_bool convert_sdl_version_to_php_array(SDL_version *version, zval *version_array) {

	if (version) {
		array_init(version_array);
		add_assoc_long(version_array, "major", version->major);
		add_assoc_long(version_array, "minor", version->minor);
		add_assoc_long(version_array, "patch", version->patch);

		return 1;
	}
	ZVAL_NULL(version_array);
	return 0;
}

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif


/** {{{ TTF_Font */
static zend_class_entry *ttf_font_ce = NULL;
static zend_object_handlers php_ttf_font_object_handlers;

typedef struct _php_ttf_font_object {
	TTF_Font *ttf_font;
	zend_object std;
} php_ttf_font_object;

static php_ttf_font_object *php_ttf_font_object_from_zend_object(zend_object *zobj)
{
	return ((php_ttf_font_object*)(zobj + 1)) - 1;
}

static zend_object *php_ttf_font_object_to_zend_object(php_ttf_font_object *obj)
{
	return ((zend_object*)(obj + 1)) - 1;
}

TTF_Font* php_ttf_font_from_zval_p(zval* zp)
{
	return php_ttf_font_object_from_zend_object(Z_OBJ_P(zp))->ttf_font;
}

static zend_object *php_ttf_font_object_create(zend_class_entry *ce)
{
	php_ttf_font_object *obj = zend_object_alloc(sizeof(php_ttf_font_object), ce);
	zend_object *zobj = php_ttf_font_object_to_zend_object(obj);

	obj->ttf_font = NULL;
	zend_object_std_init(zobj, ce);
	object_properties_init(zobj, ce);
	zobj->handlers = &php_ttf_font_object_handlers;

	return zobj;
}

static void php_ttf_font_object_free(zend_object *zobj)
{
	php_ttf_font_object *obj = php_ttf_font_object_from_zend_object(zobj);

	if (obj->ttf_font) {
		TTF_CloseFont(obj->ttf_font);
		obj->ttf_font = NULL;
	}

	zend_object_std_dtor(zobj);
}

static zend_function *php_ttf_font_object_get_constructor(zend_object *object)
{
	zend_throw_error(NULL, "You cannot initialize a TTF_Font object except through helper functions");
	return NULL;
}

static void php_ttf_font_minit_helper(void)
{
	ttf_font_ce = register_class_TTF_Font();
	ttf_font_ce->create_object = php_ttf_font_object_create;

	memcpy(&php_ttf_font_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	php_ttf_font_object_handlers.clone_obj = NULL;
	php_ttf_font_object_handlers.free_obj = php_ttf_font_object_free;
	php_ttf_font_object_handlers.get_constructor = php_ttf_font_object_get_constructor;
	php_ttf_font_object_handlers.offset = XtOffsetOf(php_ttf_font_object, std);
}

/** }}} */


/** {{{ SDL_RWops */
static zend_class_entry *sdl_rwops_ce = NULL;
static zend_object_handlers php_sdl_rwops_object_handlers;

typedef struct _php_sdl_rwops_object {
	SDL_RWops *sdl_rwops;
	zend_object std;
} php_sdl_rwops_object;

static php_sdl_rwops_object *php_sdl_rwops_object_from_zend_object(zend_object *zobj)
{
	return ((php_sdl_rwops_object*)(zobj + 1)) - 1;
}

static zend_object *php_sdl_rwops_object_to_zend_object(php_sdl_rwops_object *obj)
{
	return ((zend_object*)(obj + 1)) - 1;
}

SDL_RWops* php_sdl_rwops_from_zval_p(zval* zp)
{
	return php_sdl_rwops_object_from_zend_object(Z_OBJ_P(zp))->sdl_rwops;
}

static zend_object *php_sdl_rwops_object_create(zend_class_entry *ce)
{
	php_sdl_rwops_object *obj = zend_object_alloc(sizeof(php_sdl_rwops_object), ce);
	zend_object *zobj = php_sdl_rwops_object_to_zend_object(obj);

	obj->sdl_rwops = NULL;
	zend_object_std_init(zobj, ce);
	object_properties_init(zobj, ce);
	zobj->handlers = &php_sdl_rwops_object_handlers;

	return zobj;
}

static void php_sdl_rwops_object_free(zend_object *zobj)
{
	php_sdl_rwops_object *obj = php_sdl_rwops_object_from_zend_object(zobj);

	if (obj->sdl_rwops) {
		// @todo implement free es. TTF_CloseFont(obj->sdl_rwops);
		obj->sdl_rwops = NULL;
	}

	zend_object_std_dtor(zobj);
}

static zend_function *php_sdl_rwops_object_get_constructor(zend_object *object)
{
	zend_throw_error(NULL, "You cannot initialize a SDL_RWops object except through helper functions");
	return NULL;
}

static void php_sdl_rwops_minit_helper(void)
{
	sdl_rwops_ce = register_class_SDL_RWops();
	sdl_rwops_ce->create_object = php_sdl_rwops_object_create;

	memcpy(&php_sdl_rwops_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	php_sdl_rwops_object_handlers.clone_obj = NULL;
	php_sdl_rwops_object_handlers.free_obj = php_sdl_rwops_object_free;
	php_sdl_rwops_object_handlers.get_constructor = php_sdl_rwops_object_get_constructor;
	php_sdl_rwops_object_handlers.offset = XtOffsetOf(php_sdl_rwops_object, std);
}

/** }}} */


/** {{{ SDL_Color */
static zend_class_entry *sdl_color_ce = NULL;
static zend_object_handlers php_sdl_color_object_handlers;

typedef struct _php_sdl_color_object {
	SDL_Color *sdl_color;
	zend_object std;
} php_sdl_color_object;

static php_sdl_color_object *php_sdl_color_object_from_zend_object(zend_object *zobj)
{
	return ((php_sdl_color_object*)(zobj + 1)) - 1;
}

static zend_object *php_sdl_color_object_to_zend_object(php_sdl_color_object *obj)
{
	return ((zend_object*)(obj + 1)) - 1;
}

SDL_Color* php_sdl_color_from_zval_p(zval* zp)
{
	return php_sdl_color_object_from_zend_object(Z_OBJ_P(zp))->sdl_color;
}

static zend_object *php_sdl_color_object_create(zend_class_entry *ce)
{
	php_sdl_color_object *obj = zend_object_alloc(sizeof(php_sdl_color_object), ce);
	zend_object *zobj = php_sdl_color_object_to_zend_object(obj);

	obj->sdl_color = NULL;
	zend_object_std_init(zobj, ce);
	object_properties_init(zobj, ce);
	zobj->handlers = &php_sdl_color_object_handlers;

	return zobj;
}

static void php_sdl_color_object_free(zend_object *zobj)
{
	php_sdl_color_object *obj = php_sdl_color_object_from_zend_object(zobj);

	if (obj->sdl_color) {
		// @todo implement free es. TTF_CloseFont(obj->sdl_color);
		obj->sdl_color = NULL;
	}

	zend_object_std_dtor(zobj);
}

static zend_function *php_sdl_color_object_get_constructor(zend_object *object)
{
	zend_throw_error(NULL, "You cannot initialize a SDL_Color object except through helper functions");
	return NULL;
}

static void php_sdl_color_minit_helper(void)
{
	sdl_color_ce = register_class_SDL_Color();
	sdl_color_ce->create_object = php_sdl_color_object_create;

	memcpy(&php_sdl_color_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	php_sdl_color_object_handlers.clone_obj = NULL;
	php_sdl_color_object_handlers.free_obj = php_sdl_color_object_free;
	php_sdl_color_object_handlers.get_constructor = php_sdl_color_object_get_constructor;
	php_sdl_color_object_handlers.offset = XtOffsetOf(php_sdl_color_object, std);
}

/** }}} */


/** {{{ SDL_Surface */
static zend_class_entry *sdl_surface_ce = NULL;
static zend_object_handlers php_sdl_surface_object_handlers;

typedef struct _php_sdl_surface_object {
	SDL_Surface *sdl_surface;
	zend_object std;
} php_sdl_surface_object;

static php_sdl_surface_object *php_sdl_surface_object_from_zend_object(zend_object *zobj)
{
	return ((php_sdl_surface_object*)(zobj + 1)) - 1;
}

static zend_object *php_sdl_surface_object_to_zend_object(php_sdl_surface_object *obj)
{
	return ((zend_object*)(obj + 1)) - 1;
}

SDL_Surface* php_sdl_surface_from_zval_p(zval* zp)
{
	return php_sdl_surface_object_from_zend_object(Z_OBJ_P(zp))->sdl_surface;
}

static zend_object *php_sdl_surface_object_create(zend_class_entry *ce)
{
	php_sdl_surface_object *obj = zend_object_alloc(sizeof(php_sdl_surface_object), ce);
	zend_object *zobj = php_sdl_surface_object_to_zend_object(obj);

	obj->sdl_surface = NULL;
	zend_object_std_init(zobj, ce);
	object_properties_init(zobj, ce);
	zobj->handlers = &php_sdl_surface_object_handlers;

	return zobj;
}

static void php_sdl_surface_object_free(zend_object *zobj)
{
	php_sdl_surface_object *obj = php_sdl_surface_object_from_zend_object(zobj);

	if (obj->sdl_surface) {
		// @todo implement free es. TTF_CloseFont(obj->sdl_surface);
		obj->sdl_surface = NULL;
	}

	zend_object_std_dtor(zobj);
}

static zend_function *php_sdl_surface_object_get_constructor(zend_object *object)
{
	zend_throw_error(NULL, "You cannot initialize a SDL_Surface object except through helper functions");
	return NULL;
}

static void php_sdl_surface_minit_helper(void)
{
	sdl_surface_ce = register_class_SDL_Surface();
	sdl_surface_ce->create_object = php_sdl_surface_object_create;

	memcpy(&php_sdl_surface_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	php_sdl_surface_object_handlers.clone_obj = NULL;
	php_sdl_surface_object_handlers.free_obj = php_sdl_surface_object_free;
	php_sdl_surface_object_handlers.get_constructor = php_sdl_surface_object_get_constructor;
	php_sdl_surface_object_handlers.offset = XtOffsetOf(php_sdl_surface_object, std);
}

/** }}} */


/** {{{ SDL_bool */
static zend_class_entry *sdl_bool_ce = NULL;
static zend_object_handlers php_sdl_bool_object_handlers;

typedef struct _php_sdl_bool_object {
	SDL_bool *sdl_bool;
	zend_object std;
} php_sdl_bool_object;

static php_sdl_bool_object *php_sdl_bool_object_from_zend_object(zend_object *zobj)
{
	return ((php_sdl_bool_object*)(zobj + 1)) - 1;
}

static zend_object *php_sdl_bool_object_to_zend_object(php_sdl_bool_object *obj)
{
	return ((zend_object*)(obj + 1)) - 1;
}

SDL_bool* php_sdl_bool_from_zval_p(zval* zp)
{
	return php_sdl_bool_object_from_zend_object(Z_OBJ_P(zp))->sdl_bool;
}

static zend_object *php_sdl_bool_object_create(zend_class_entry *ce)
{
	php_sdl_bool_object *obj = zend_object_alloc(sizeof(php_sdl_bool_object), ce);
	zend_object *zobj = php_sdl_bool_object_to_zend_object(obj);

	obj->sdl_bool = NULL;
	zend_object_std_init(zobj, ce);
	object_properties_init(zobj, ce);
	zobj->handlers = &php_sdl_bool_object_handlers;

	return zobj;
}

static void php_sdl_bool_object_free(zend_object *zobj)
{
	php_sdl_bool_object *obj = php_sdl_bool_object_from_zend_object(zobj);

	if (obj->sdl_bool) {
		// @todo implement free es. TTF_CloseFont(obj->sdl_bool);
		obj->sdl_bool = NULL;
	}

	zend_object_std_dtor(zobj);
}

static zend_function *php_sdl_bool_object_get_constructor(zend_object *object)
{
	zend_throw_error(NULL, "You cannot initialize a SDL_bool object except through helper functions");
	return NULL;
}

static void php_sdl_bool_minit_helper(void)
{
	sdl_bool_ce = register_class_SDL_bool();
	sdl_bool_ce->create_object = php_sdl_bool_object_create;

	memcpy(&php_sdl_bool_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	php_sdl_bool_object_handlers.clone_obj = NULL;
	php_sdl_bool_object_handlers.free_obj = php_sdl_bool_object_free;
	php_sdl_bool_object_handlers.get_constructor = php_sdl_bool_object_get_constructor;
	php_sdl_bool_object_handlers.offset = XtOffsetOf(php_sdl_bool_object, std);
}

/** }}} */


/** {{{ SDL_version */
static zend_class_entry *sdl_version_ce = NULL;
static zend_object_handlers php_sdl_version_object_handlers;

typedef struct _php_sdl_version_object {
	SDL_version *sdl_version;
	zend_object std;
} php_sdl_version_object;

static php_sdl_version_object *php_sdl_version_object_from_zend_object(zend_object *zobj)
{
	return ((php_sdl_version_object*)(zobj + 1)) - 1;
}

static zend_object *php_sdl_version_object_to_zend_object(php_sdl_version_object *obj)
{
	return ((zend_object*)(obj + 1)) - 1;
}

SDL_version* php_sdl_version_from_zval_p(zval* zp)
{
	return php_sdl_version_object_from_zend_object(Z_OBJ_P(zp))->sdl_version;
}

static zend_object *php_sdl_version_object_create(zend_class_entry *ce)
{
	php_sdl_version_object *obj = zend_object_alloc(sizeof(php_sdl_version_object), ce);
	zend_object *zobj = php_sdl_version_object_to_zend_object(obj);

	obj->sdl_version = NULL;
	zend_object_std_init(zobj, ce);
	object_properties_init(zobj, ce);
	zobj->handlers = &php_sdl_version_object_handlers;

	return zobj;
}

static void php_sdl_version_object_free(zend_object *zobj)
{
	php_sdl_version_object *obj = php_sdl_version_object_from_zend_object(zobj);

	if (obj->sdl_version) {
		// @todo implement free es. TTF_CloseFont(obj->sdl_version);
		obj->sdl_version = NULL;
	}

	zend_object_std_dtor(zobj);
}

static zend_function *php_sdl_version_object_get_constructor(zend_object *object)
{
	zend_throw_error(NULL, "You cannot initialize a SDL_version object except through helper functions");
	return NULL;
}

static void php_sdl_version_minit_helper(void)
{
	sdl_version_ce = register_class_SDL_version();
	sdl_version_ce->create_object = php_sdl_version_object_create;

	memcpy(&php_sdl_version_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	php_sdl_version_object_handlers.clone_obj = NULL;
	php_sdl_version_object_handlers.free_obj = php_sdl_version_object_free;
	php_sdl_version_object_handlers.get_constructor = php_sdl_version_object_get_constructor;
	php_sdl_version_object_handlers.offset = XtOffsetOf(php_sdl_version_object, std);
}

/** }}} */

PHP_FUNCTION(TTF_Linked_Version)
{
    ZEND_PARSE_PARAMETERS_NONE();

    const SDL_version * result = TTF_Linked_Version();

    zend_object *cresult = php_sdl_version_object_create(sdl_version_ce);
        RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_ByteSwappedUNICODE)
{
    zend_long swapped;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_LONG(swapped)
    ZEND_PARSE_PARAMETERS_END();

    TTF_ByteSwappedUNICODE(swapped);
}
PHP_FUNCTION(TTF_Init)
{
    ZEND_PARSE_PARAMETERS_NONE();

    int result = TTF_Init();

    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_OpenFont)
{
    char *file = NULL;
    size_t file_len = 0;
    zend_long ptsize;

    ZEND_PARSE_PARAMETERS_START(2, 2);
        Z_PARAM_STRING(file, file_len)
        Z_PARAM_LONG(ptsize)
    ZEND_PARSE_PARAMETERS_END();


    TTF_Font * result = TTF_OpenFont((const char*)file, ptsize);


    zend_object *cresult = php_ttf_font_object_create(ttf_font_ce);
        RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_OpenFontIndex)
{
    char *file = NULL;
    size_t file_len = 0;
    zend_long ptsize;
    zend_long index;

    ZEND_PARSE_PARAMETERS_START(3, 3);
        Z_PARAM_STRING(file, file_len)
        Z_PARAM_LONG(ptsize)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();

    TTF_Font * result = TTF_OpenFontIndex((const char*)file, ptsize, index);

    zend_object *cresult = php_ttf_font_object_create(ttf_font_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_OpenFontRW)
{
    zval *SRC;
    SDL_RWops *src;
    zend_long freesrc;
    zend_long ptsize;

    ZEND_PARSE_PARAMETERS_START(3, 3);
        Z_PARAM_OBJECT_OF_CLASS(SRC, sdl_rwops_ce)
        Z_PARAM_LONG(freesrc)
        Z_PARAM_LONG(ptsize)
    ZEND_PARSE_PARAMETERS_END();
    src = php_sdl_rwops_from_zval_p(SRC);

    TTF_Font * result = TTF_OpenFontRW(src, freesrc, ptsize);

    zend_object *cresult = php_ttf_font_object_create(ttf_font_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_OpenFontIndexRW)
{
    zval *SRC;
    SDL_RWops *src;
    zend_long freesrc;
    zend_long ptsize;
    zend_long index;

    ZEND_PARSE_PARAMETERS_START(4, 4);
        Z_PARAM_OBJECT_OF_CLASS(SRC, sdl_rwops_ce)
        Z_PARAM_LONG(freesrc)
        Z_PARAM_LONG(ptsize)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();
    src = php_sdl_rwops_from_zval_p(SRC);

    TTF_Font * result = TTF_OpenFontIndexRW(src, freesrc, ptsize, index);

    zend_object *cresult = php_ttf_font_object_create(ttf_font_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_GetFontStyle)
{
    zval *FONT;
    TTF_Font *font;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    int result = TTF_GetFontStyle((const TTF_Font*)font);

    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_SetFontStyle)
{
    zval *FONT;
    TTF_Font *font;
    zend_long style;

    ZEND_PARSE_PARAMETERS_START(2, 2);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_LONG(style)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    TTF_SetFontStyle(font, style);
}
PHP_FUNCTION(TTF_GetFontOutline)
{
    zval *FONT;
    TTF_Font *font;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    int result = TTF_GetFontOutline((const TTF_Font*)font);

    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_SetFontOutline)
{
    zval *FONT;
    TTF_Font *font;
    zend_long outline;

    ZEND_PARSE_PARAMETERS_START(2, 2);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_LONG(outline)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    TTF_SetFontOutline(font, outline);
}
PHP_FUNCTION(TTF_GetFontHinting)
{
    zval *FONT;
    TTF_Font *font;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    int result = TTF_GetFontHinting((const TTF_Font*)font);

    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_SetFontHinting)
{
    zval *FONT;
    TTF_Font *font;
    zend_long hinting;

    ZEND_PARSE_PARAMETERS_START(2, 2);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_LONG(hinting)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    TTF_SetFontHinting(font, hinting);
}
PHP_FUNCTION(TTF_FontHeight)
{
    zval *FONT;
    TTF_Font *font;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    int result = TTF_FontHeight((const TTF_Font*)font);

    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_FontAscent)
{
    zval *FONT;
    TTF_Font *font;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    int result = TTF_FontAscent((const TTF_Font*)font);

    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_FontDescent)
{
    zval *FONT;
    TTF_Font *font;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    int result = TTF_FontDescent((const TTF_Font*)font);

    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_FontLineSkip)
{
    zval *FONT;
    TTF_Font *font;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    int result = TTF_FontLineSkip((const TTF_Font*)font);

    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_GetFontKerning)
{
    zval *FONT;
    TTF_Font *font;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    int result = TTF_GetFontKerning((const TTF_Font*)font);

    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_SetFontKerning)
{
    zval *FONT;
    TTF_Font *font;
    zend_long allowed;

    ZEND_PARSE_PARAMETERS_START(2, 2);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_LONG(allowed)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    TTF_SetFontKerning(font, allowed);
}
PHP_FUNCTION(TTF_FontFaces)
{
    zval *FONT;
    TTF_Font *font;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    long result = TTF_FontFaces((const TTF_Font*)font);

    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_FontFaceIsFixedWidth)
{
    zval *FONT;
    TTF_Font *font;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    int result = TTF_FontFaceIsFixedWidth((const TTF_Font*)font);

    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_FontFaceFamilyName)
{
    zval *FONT;
    TTF_Font *font;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    char * result = TTF_FontFaceFamilyName((const TTF_Font*)font);

    RETURN_STRING(result);
}
PHP_FUNCTION(TTF_FontFaceStyleName)
{
    zval *FONT;
    TTF_Font *font;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    char * result = TTF_FontFaceStyleName((const TTF_Font*)font);

    RETURN_STRING(result);
}
PHP_FUNCTION(TTF_GlyphIsProvided)
{
    zval *FONT;
    TTF_Font *font;
    zend_long ch;

    ZEND_PARSE_PARAMETERS_START(2, 2);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_LONG(ch)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    int result = TTF_GlyphIsProvided((const TTF_Font*)font, ch);

    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_SizeText)
{
    zval *FONT;
    TTF_Font *font;
    char *text = NULL;
    size_t text_len = 0;
    zval *z_w = NULL;
    int w;
    zval *z_h = NULL;
    int h;

    ZEND_PARSE_PARAMETERS_START(4, 4);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_STRING(text, text_len)
        Z_PARAM_ZVAL(z_w)
        Z_PARAM_ZVAL(z_h)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    int result = TTF_SizeText(font, (const char*)text, &w, &h);

    ZEND_TRY_ASSIGN_REF_LONG(z_w, w);
    ZEND_TRY_ASSIGN_REF_LONG(z_h, h);
    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_SizeUTF8)
{
    zval *FONT;
    TTF_Font *font;
    char *text = NULL;
    size_t text_len = 0;
    zval *z_w = NULL;
    int w;
    zval *z_h = NULL;
    int h;

    ZEND_PARSE_PARAMETERS_START(4, 4);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_STRING(text, text_len)
        Z_PARAM_ZVAL(z_w)
        Z_PARAM_ZVAL(z_h)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    int result = TTF_SizeUTF8(font, (const char*)text, &w, &h);

    ZEND_TRY_ASSIGN_REF_LONG(z_w, w);
    ZEND_TRY_ASSIGN_REF_LONG(z_h, h);
    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_SizeUNICODE)
{
    zval *FONT;
    TTF_Font *font;
    zval *z_text = NULL;
    Uint16 text;
    zval *z_w = NULL;
    int w;
    zval *z_h = NULL;
    int h;

    ZEND_PARSE_PARAMETERS_START(4, 4);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_ZVAL(z_text)
        Z_PARAM_ZVAL(z_w)
        Z_PARAM_ZVAL(z_h)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    int result = TTF_SizeUNICODE(font, &text, &w, &h);

    ZEND_TRY_ASSIGN_REF_LONG(z_text, text);
    ZEND_TRY_ASSIGN_REF_LONG(z_w, w);
    ZEND_TRY_ASSIGN_REF_LONG(z_h, h);
    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_RenderText_Solid)
{
    zval *FONT;
    TTF_Font *font;
    char *text = NULL;
    size_t text_len = 0;
    zval *FG;
    SDL_Color *fg;

    ZEND_PARSE_PARAMETERS_START(3, 3);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_STRING(text, text_len)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);
    SDL_Surface * result = TTF_RenderText_Solid(font, (const char*)text, *fg);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderUTF8_Solid)
{
    zval *FONT;
    TTF_Font *font;
    char *text = NULL;
    size_t text_len = 0;
    zval *FG;
    SDL_Color *fg;

    ZEND_PARSE_PARAMETERS_START(3, 3);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_STRING(text, text_len)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);
    SDL_Surface * result = TTF_RenderUTF8_Solid(font, (const char*)text, *fg);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderUNICODE_Solid)
{
    zval *FONT;
    TTF_Font *font;
    zval *z_text = NULL;
    Uint16 text;
    zval *FG;
    SDL_Color *fg;

    ZEND_PARSE_PARAMETERS_START(3, 3);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_ZVAL(z_text)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);
    SDL_Surface * result = TTF_RenderUNICODE_Solid(font, &text, *fg);

    ZEND_TRY_ASSIGN_REF_LONG(z_text, text);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderGlyph_Solid)
{
    zval *FONT;
    TTF_Font *font;
    zend_long ch;
    zval *FG;
    SDL_Color *fg;

    ZEND_PARSE_PARAMETERS_START(3, 3);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_LONG(ch)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);
    SDL_Surface * result = TTF_RenderGlyph_Solid(font, ch, *fg);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderText_Shaded)
{
    zval *FONT;
    TTF_Font *font;
    char *text = NULL;
    size_t text_len = 0;
    zval *FG;
    SDL_Color *fg;
    zval *BG;
    SDL_Color *bg;

    ZEND_PARSE_PARAMETERS_START(4, 4);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_STRING(text, text_len)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
        Z_PARAM_OBJECT_OF_CLASS(BG, sdl_color_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);
    bg = php_sdl_color_from_zval_p(BG);
    SDL_Surface * result = TTF_RenderText_Shaded(font, (const char*)text, *fg, *bg);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderUTF8_Shaded)
{
    zval *FONT;
    TTF_Font *font;
    char *text = NULL;
    size_t text_len = 0;
    zval *FG;
    SDL_Color *fg;
    zval *BG;
    SDL_Color *bg;

    ZEND_PARSE_PARAMETERS_START(4, 4);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_STRING(text, text_len)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
        Z_PARAM_OBJECT_OF_CLASS(BG, sdl_color_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);
    bg = php_sdl_color_from_zval_p(BG);
    SDL_Surface * result = TTF_RenderUTF8_Shaded(font, (const char*)text, *fg, *bg);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderUNICODE_Shaded)
{
    zval *FONT;
    TTF_Font *font;
    zval *z_text = NULL;
    Uint16 text;
    zval *FG;
    SDL_Color *fg;
    zval *BG;
    SDL_Color *bg;

    ZEND_PARSE_PARAMETERS_START(4, 4);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_ZVAL(z_text)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
        Z_PARAM_OBJECT_OF_CLASS(BG, sdl_color_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);
    bg = php_sdl_color_from_zval_p(BG);
    SDL_Surface * result = TTF_RenderUNICODE_Shaded(font, &text, *fg, *bg);

    ZEND_TRY_ASSIGN_REF_LONG(z_text, text);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderGlyph_Shaded)
{
    zval *FONT;
    TTF_Font *font;
    zend_long ch;
    zval *FG;
    SDL_Color *fg;
    zval *BG;
    SDL_Color *bg;

    ZEND_PARSE_PARAMETERS_START(4, 4);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_LONG(ch)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
        Z_PARAM_OBJECT_OF_CLASS(BG, sdl_color_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);
    bg = php_sdl_color_from_zval_p(BG);
    SDL_Surface * result = TTF_RenderGlyph_Shaded(font, ch, *fg, *bg);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderText_Blended)
{
    zval *FONT;
    TTF_Font *font;
    char *text = NULL;
    size_t text_len = 0;
    zval *FG;
    SDL_Color *fg;

    ZEND_PARSE_PARAMETERS_START(3, 3);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_STRING(text, text_len)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);
    SDL_Surface * result = TTF_RenderText_Blended(font, (const char*)text, *fg);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderUTF8_Blended)
{
    zval *FONT;
    TTF_Font *font;
    char *text = NULL;
    size_t text_len = 0;
    zval *FG;
    SDL_Color *fg;

    ZEND_PARSE_PARAMETERS_START(3, 3);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_STRING(text, text_len)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);
    SDL_Surface * result = TTF_RenderUTF8_Blended(font, (const char*)text, *fg);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderUNICODE_Blended)
{
    zval *FONT;
    TTF_Font *font;
    zval *z_text = NULL;
    Uint16 text;
    zval *FG;
    SDL_Color *fg;

    ZEND_PARSE_PARAMETERS_START(3, 3);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_ZVAL(z_text)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);
    SDL_Surface * result = TTF_RenderUNICODE_Blended(font, &text, *fg);

    ZEND_TRY_ASSIGN_REF_LONG(z_text, text);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderText_Blended_Wrapped)
{
    zval *FONT;
    TTF_Font *font;
    char *text = NULL;
    size_t text_len = 0;
    zval *FG;
    SDL_Color *fg;
    zend_long wrapLength;

    ZEND_PARSE_PARAMETERS_START(4, 4);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_STRING(text, text_len)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
        Z_PARAM_LONG(wrapLength)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);

    SDL_Surface * result = TTF_RenderText_Blended_Wrapped(font, (const char*)text, *fg, wrapLength);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderUTF8_Blended_Wrapped)
{
    zval *FONT;
    TTF_Font *font;
    char *text = NULL;
    size_t text_len = 0;
    zval *FG;
    SDL_Color *fg;
    zend_long wrapLength;

    ZEND_PARSE_PARAMETERS_START(4, 4);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_STRING(text, text_len)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
        Z_PARAM_LONG(wrapLength)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);

    SDL_Surface * result = TTF_RenderUTF8_Blended_Wrapped(font, (const char*)text, *fg, wrapLength);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderUNICODE_Blended_Wrapped)
{
    zval *FONT;
    TTF_Font *font;
    zval *z_text = NULL;
    Uint16 text;
    zval *FG;
    SDL_Color *fg;
    zend_long wrapLength;

    ZEND_PARSE_PARAMETERS_START(4, 4);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_ZVAL(z_text)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
        Z_PARAM_LONG(wrapLength)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    fg = php_sdl_color_from_zval_p(FG);
    SDL_Surface * result = TTF_RenderUNICODE_Blended_Wrapped(font, &text, *fg, wrapLength);
    ZEND_TRY_ASSIGN_REF_LONG(z_text, text);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_RenderGlyph_Blended)
{
    zval *FONT;
    TTF_Font *font;
    zend_long ch;
    zval *FG;
    SDL_Color *fg;

    ZEND_PARSE_PARAMETERS_START(3, 3);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_LONG(ch)
        Z_PARAM_OBJECT_OF_CLASS(FG, sdl_color_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    fg = php_sdl_color_from_zval_p(FG);
    SDL_Surface * result = TTF_RenderGlyph_Blended(font, ch, *fg);

    zend_object *cresult = php_sdl_surface_object_create(sdl_surface_ce);
    RETURN_OBJ(cresult);
}
PHP_FUNCTION(TTF_CloseFont)
{
    zval *FONT;
    TTF_Font *font;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    TTF_CloseFont(font);
}
PHP_FUNCTION(TTF_Quit)
{
    ZEND_PARSE_PARAMETERS_NONE();
    TTF_Quit();
}
PHP_FUNCTION(TTF_WasInit)
{
    ZEND_PARSE_PARAMETERS_NONE();
    int result = TTF_WasInit();
    RETURN_LONG(result);
}
PHP_FUNCTION(TTF_GetFontKerningSizeGlyphs)
{
    zval *FONT;
    TTF_Font *font;
    zend_long previous_ch;
    zend_long ch;

    ZEND_PARSE_PARAMETERS_START(3, 3);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_LONG(previous_ch)
        Z_PARAM_LONG(ch)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);
    int result = TTF_GetFontKerningSizeGlyphs(font, previous_ch, ch);

    RETURN_LONG(result);
}

PHP_FUNCTION(TTF_GlyphMetrics)
{
    zval *FONT;
    TTF_Font *font;

    zend_long previous_ch;
    zend_long ch;

    zval *z_minx = NULL;
    int minx;
    zval *z_maxx = NULL;
    int maxx;
    zval *z_miny = NULL;
    int miny;
    zval *z_maxy = NULL;
    int maxy;
    zval *z_advance = NULL;
    int advance;

    ZEND_PARSE_PARAMETERS_START(7, 7);
        Z_PARAM_OBJECT_OF_CLASS(FONT, ttf_font_ce)
        Z_PARAM_LONG(ch)
        Z_PARAM_ZVAL(z_minx)
        Z_PARAM_ZVAL(z_maxx)
        Z_PARAM_ZVAL(z_miny)
        Z_PARAM_ZVAL(z_maxy)
        Z_PARAM_ZVAL(z_advance)
    ZEND_PARSE_PARAMETERS_END();
    font = php_ttf_font_from_zval_p(FONT);

    int result = TTF_GlyphMetrics(font, ch, &minx, &maxx, &miny, &maxy, &advance);
    ZEND_TRY_ASSIGN_REF_LONG(z_minx, minx);
    ZEND_TRY_ASSIGN_REF_LONG(z_maxx, maxx);
    ZEND_TRY_ASSIGN_REF_LONG(z_miny, miny);
    ZEND_TRY_ASSIGN_REF_LONG(z_maxy, maxy);
    ZEND_TRY_ASSIGN_REF_LONG(z_advance, advance);

    RETURN_LONG(result);
}

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(sdl_ttf)
{
    php_ttf_font_minit_helper();
    int init = TTF_Init();

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(sdl_ttf)
{
#if defined(ZTS) && defined(COMPILE_DL_SDL_TTF)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(sdl_ttf)
{
char buffer[128];
	SDL_version compile_version;
	const SDL_version *link_version = TTF_Linked_Version();
	SDL_TTF_VERSION(&compile_version);

	php_info_print_table_start();
	php_info_print_table_row(2, "SDL_ttf support", "enabled");
	php_info_print_table_row(2, "SDL_ttf PHP extension version", PHP_SDL_TTF_VERSION);
	snprintf(buffer, sizeof(buffer), "%d.%d.%d", link_version->major, link_version->minor, link_version->patch);
	php_info_print_table_row(2, "SDL_ttf linked version", buffer);
	snprintf(buffer, sizeof(buffer), "%d.%d.%d", compile_version.major, compile_version.minor, compile_version.patch);
	php_info_print_table_row(2, "SDL_ttf compiled version", buffer);
	php_info_print_table_end();}
/* }}} */

/* {{{ sdl_ttf_module_entry */
zend_module_entry sdl_ttf_module_entry = {
	STANDARD_MODULE_HEADER,
	"sdl_ttf",					/* Extension name */
	ext_functions,				/* zend_function_entry */
	PHP_MINIT(sdl_ttf),			/* PHP_MINIT - Module initialization */
	NULL,						/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(sdl_ttf),			/* PHP_RINIT - Request initialization */
	NULL,						/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(sdl_ttf),			/* PHP_MINFO - Module info */
	PHP_SDL_TTF_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SDL_TTF
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(sdl_ttf)
#endif

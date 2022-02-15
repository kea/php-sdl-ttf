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

PHP_FUNCTION(TTF_Linked_Version)
{
	zval version_array;

	ZEND_PARSE_PARAMETERS_NONE();

    SDL_version *link_version = TTF_Linked_Version();
    convert_sdl_version_to_php_array(link_version, &version_array);

	RETURN_COPY_DEREF(&version_array);
}

#if SDL_TTF_VERSION_ATLEAST(2, 0, 18)

PHP_FUNCTION(TTF_GetFreeTypeVersion)
{
	zval *z_major = NULL;
	int major;
	zval *z_minor = NULL;
	int minor;
	zval *z_patch = NULL;
	int patch;

	ZEND_PARSE_PARAMETERS_START(3, 3);
		Z_PARAM_ZVAL(z_major)
		Z_PARAM_ZVAL(z_minor)
		Z_PARAM_ZVAL(z_patch)
	ZEND_PARSE_PARAMETERS_END();

	TTF_GetFreeTypeVersion(&major, &minor, &z_patch);

	ZEND_TRY_ASSIGN_REF_LONG(z_major, major);
	ZEND_TRY_ASSIGN_REF_LONG(z_minor, minor);
	ZEND_TRY_ASSIGN_REF_LONG(z_patch, patch);
}

#endif

PHP_FUNCTION(TTF_OpenFont)
{
    char *file = NULL;
    size_t file_len = 0;

    zend_long ptsize;

    ZEND_PARSE_PARAMETERS_START(2, 2);
        Z_PARAM_STRING(file, file_len)
        Z_PARAM_LONG(ptsize)
    ZEND_PARSE_PARAMETERS_END();

    TTF_OpenFont((const char*)file, ptsize);
}



/** TTF_Font */
static zend_class_entry *ttf_font_ce = NULL;
static zend_object_handlers php_ttf_font_object_handlers;

typedef struct _php_ttf_font_object {
	TTF_Font *font;
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

static zend_object *php_ttf_font_object_create(zend_class_entry *ce)
{
	php_ttf_font_object *obj = zend_object_alloc(sizeof(php_ttf_font_object), ce);
	zend_object *zobj = php_ttf_font_object_to_zend_object(obj);

	obj->font = NULL;
	zend_object_std_init(zobj, ce);
	object_properties_init(zobj, ce);
	zobj->handlers = &php_ttf_font_object_handlers;

	return zobj;
}

static void php_ttf_font_object_free(zend_object *zobj)
{
	php_ttf_font_object *obj = php_ttf_font_object_from_zend_object(zobj);

	if (obj->font) {
		TTF_CloseFont(obj->font);
		obj->font = NULL;
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

	/* setting up the object handlers for the GdFont class */
	memcpy(&php_ttf_font_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	php_ttf_font_object_handlers.clone_obj = NULL;
	php_ttf_font_object_handlers.free_obj = php_ttf_font_object_free;
	php_ttf_font_object_handlers.get_constructor = php_ttf_font_object_get_constructor;
	php_ttf_font_object_handlers.offset = XtOffsetOf(php_ttf_font_object, std);
}

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
	NULL,						/* PHP_MINIT - Module initialization */
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

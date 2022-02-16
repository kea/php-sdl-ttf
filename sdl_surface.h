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
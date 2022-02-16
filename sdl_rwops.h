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

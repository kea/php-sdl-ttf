/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 451fcfbf238670d111623c1179bd39e7ac1b42c7 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_Linked_Version, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#if SDL_TTF_VERSION_ATLEAST(2, 0, 18)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_GetFreeTypeVersion, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, major, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, minor, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, patch, IS_LONG, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_TTF_OpenFont, 0, 2, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, ptsize, IS_LONG, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(TTF_Linked_Version);
#if SDL_TTF_VERSION_ATLEAST(2, 0, 18)
ZEND_FUNCTION(TTF_GetFreeTypeVersion);
#endif
ZEND_FUNCTION(TTF_OpenFont);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(TTF_Linked_Version, arginfo_TTF_Linked_Version)
#if SDL_TTF_VERSION_ATLEAST(2, 0, 18)
	ZEND_FE(TTF_GetFreeTypeVersion, arginfo_TTF_GetFreeTypeVersion)
#endif
	ZEND_FE(TTF_OpenFont, arginfo_TTF_OpenFont)
	ZEND_FE_END
};


static const zend_function_entry class_TTF_Font_methods[] = {
	ZEND_FE_END
};

static zend_class_entry *register_class_TTF_Font(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "TTF_Font", class_TTF_Font_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	return class_entry;
}

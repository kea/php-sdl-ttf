/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 6d37e7c1ca5735946c004a42f721c3622634343a */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_TTF_Linked_Version, 0, 0, SDL_version, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_ByteSwappedUNICODE, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, swapped, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_Init, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_TTF_OpenFont, 0, 2, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, ptsize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_TTF_OpenFontIndex, 0, 3, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, ptsize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_TTF_OpenFontRW, 0, 3, TTF_Font, 0)
	ZEND_ARG_OBJ_INFO(0, src, SDL_RWops, 0)
	ZEND_ARG_TYPE_INFO(0, freesrc, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ptsize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_TTF_OpenFontIndexRW, 0, 4, TTF_Font, 0)
	ZEND_ARG_OBJ_INFO(0, src, SDL_RWops, 0)
	ZEND_ARG_TYPE_INFO(0, freesrc, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ptsize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_GetFontStyle, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_SetFontStyle, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, style, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_TTF_GetFontOutline arginfo_TTF_GetFontStyle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_SetFontOutline, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, outline, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_TTF_GetFontHinting arginfo_TTF_GetFontStyle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_SetFontHinting, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, hinting, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_TTF_FontHeight arginfo_TTF_GetFontStyle

#define arginfo_TTF_FontAscent arginfo_TTF_GetFontStyle

#define arginfo_TTF_FontDescent arginfo_TTF_GetFontStyle

#define arginfo_TTF_FontLineSkip arginfo_TTF_GetFontStyle

#define arginfo_TTF_GetFontKerning arginfo_TTF_GetFontStyle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_SetFontKerning, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, allowed, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_TTF_FontFaces arginfo_TTF_GetFontStyle

#define arginfo_TTF_FontFaceIsFixedWidth arginfo_TTF_GetFontStyle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_FontFaceFamilyName, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
ZEND_END_ARG_INFO()

#define arginfo_TTF_FontFaceStyleName arginfo_TTF_FontFaceFamilyName

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_GlyphIsProvided, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, ch, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_GlyphMetrics, 0, 7, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, ch, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, minx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, maxx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, miny, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, maxy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, advance, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_SizeText, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(1, w, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, h, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_TTF_SizeUTF8 arginfo_TTF_SizeText

#define arginfo_TTF_SizeUNICODE arginfo_TTF_SizeText

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_TTF_RenderText_Solid, 0, 3, SDL_Surface, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, fg, SDL_Color, 0)
ZEND_END_ARG_INFO()

#define arginfo_TTF_RenderUTF8_Solid arginfo_TTF_RenderText_Solid

#define arginfo_TTF_RenderUNICODE_Solid arginfo_TTF_RenderText_Solid

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_TTF_RenderGlyph_Solid, 0, 3, SDL_Surface, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, ch, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, fg, SDL_Color, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_TTF_RenderText_Shaded, 0, 4, SDL_Surface, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, fg, SDL_Color, 0)
	ZEND_ARG_OBJ_INFO(0, bg, SDL_Color, 0)
ZEND_END_ARG_INFO()

#define arginfo_TTF_RenderUTF8_Shaded arginfo_TTF_RenderText_Shaded

#define arginfo_TTF_RenderUNICODE_Shaded arginfo_TTF_RenderText_Shaded

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_TTF_RenderGlyph_Shaded, 0, 4, SDL_Surface, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, ch, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, fg, SDL_Color, 0)
	ZEND_ARG_OBJ_INFO(0, bg, SDL_Color, 0)
ZEND_END_ARG_INFO()

#define arginfo_TTF_RenderText_Blended arginfo_TTF_RenderText_Solid

#define arginfo_TTF_RenderUTF8_Blended arginfo_TTF_RenderText_Solid

#define arginfo_TTF_RenderUNICODE_Blended arginfo_TTF_RenderText_Solid

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_TTF_RenderText_Blended_Wrapped, 0, 4, SDL_Surface, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, fg, SDL_Color, 0)
	ZEND_ARG_TYPE_INFO(0, wrapLength, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_TTF_RenderUTF8_Blended_Wrapped arginfo_TTF_RenderText_Blended_Wrapped

#define arginfo_TTF_RenderUNICODE_Blended_Wrapped arginfo_TTF_RenderText_Blended_Wrapped

#define arginfo_TTF_RenderGlyph_Blended arginfo_TTF_RenderGlyph_Solid

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_CloseFont, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_Quit, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_TTF_WasInit arginfo_TTF_Init

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_GetFontKerningSizeGlyphs, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, font, TTF_Font, 0)
	ZEND_ARG_TYPE_INFO(0, previous_ch, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ch, IS_LONG, 0)
ZEND_END_ARG_INFO()

#if SDL_TTF_VERSION_ATLEAST(2, 0, 18)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_TTF_GetFreeTypeVersion, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, major, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, minor, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, patch, IS_LONG, 0)
ZEND_END_ARG_INFO()
#endif


ZEND_FUNCTION(TTF_Linked_Version);
ZEND_FUNCTION(TTF_ByteSwappedUNICODE);
ZEND_FUNCTION(TTF_Init);
ZEND_FUNCTION(TTF_OpenFont);
ZEND_FUNCTION(TTF_OpenFontIndex);
ZEND_FUNCTION(TTF_OpenFontRW);
ZEND_FUNCTION(TTF_OpenFontIndexRW);
ZEND_FUNCTION(TTF_GetFontStyle);
ZEND_FUNCTION(TTF_SetFontStyle);
ZEND_FUNCTION(TTF_GetFontOutline);
ZEND_FUNCTION(TTF_SetFontOutline);
ZEND_FUNCTION(TTF_GetFontHinting);
ZEND_FUNCTION(TTF_SetFontHinting);
ZEND_FUNCTION(TTF_FontHeight);
ZEND_FUNCTION(TTF_FontAscent);
ZEND_FUNCTION(TTF_FontDescent);
ZEND_FUNCTION(TTF_FontLineSkip);
ZEND_FUNCTION(TTF_GetFontKerning);
ZEND_FUNCTION(TTF_SetFontKerning);
ZEND_FUNCTION(TTF_FontFaces);
ZEND_FUNCTION(TTF_FontFaceIsFixedWidth);
ZEND_FUNCTION(TTF_FontFaceFamilyName);
ZEND_FUNCTION(TTF_FontFaceStyleName);
ZEND_FUNCTION(TTF_GlyphIsProvided);
ZEND_FUNCTION(TTF_GlyphMetrics);
ZEND_FUNCTION(TTF_SizeText);
ZEND_FUNCTION(TTF_SizeUTF8);
ZEND_FUNCTION(TTF_SizeUNICODE);
ZEND_FUNCTION(TTF_RenderText_Solid);
ZEND_FUNCTION(TTF_RenderUTF8_Solid);
ZEND_FUNCTION(TTF_RenderUNICODE_Solid);
ZEND_FUNCTION(TTF_RenderGlyph_Solid);
ZEND_FUNCTION(TTF_RenderText_Shaded);
ZEND_FUNCTION(TTF_RenderUTF8_Shaded);
ZEND_FUNCTION(TTF_RenderUNICODE_Shaded);
ZEND_FUNCTION(TTF_RenderGlyph_Shaded);
ZEND_FUNCTION(TTF_RenderText_Blended);
ZEND_FUNCTION(TTF_RenderUTF8_Blended);
ZEND_FUNCTION(TTF_RenderUNICODE_Blended);
ZEND_FUNCTION(TTF_RenderText_Blended_Wrapped);
ZEND_FUNCTION(TTF_RenderUTF8_Blended_Wrapped);
ZEND_FUNCTION(TTF_RenderUNICODE_Blended_Wrapped);
ZEND_FUNCTION(TTF_RenderGlyph_Blended);
ZEND_FUNCTION(TTF_CloseFont);
ZEND_FUNCTION(TTF_Quit);
ZEND_FUNCTION(TTF_WasInit);
ZEND_FUNCTION(TTF_GetFontKerningSizeGlyphs);
#if SDL_TTF_VERSION_ATLEAST(2, 0, 18)
ZEND_FUNCTION(TTF_GetFreeTypeVersion);
#endif


static const zend_function_entry ext_functions[] = {
	ZEND_FE(TTF_Linked_Version, arginfo_TTF_Linked_Version)
	ZEND_FE(TTF_ByteSwappedUNICODE, arginfo_TTF_ByteSwappedUNICODE)
	ZEND_FE(TTF_Init, arginfo_TTF_Init)
	ZEND_FE(TTF_OpenFont, arginfo_TTF_OpenFont)
	ZEND_FE(TTF_OpenFontIndex, arginfo_TTF_OpenFontIndex)
	ZEND_FE(TTF_OpenFontRW, arginfo_TTF_OpenFontRW)
	ZEND_FE(TTF_OpenFontIndexRW, arginfo_TTF_OpenFontIndexRW)
	ZEND_FE(TTF_GetFontStyle, arginfo_TTF_GetFontStyle)
	ZEND_FE(TTF_SetFontStyle, arginfo_TTF_SetFontStyle)
	ZEND_FE(TTF_GetFontOutline, arginfo_TTF_GetFontOutline)
	ZEND_FE(TTF_SetFontOutline, arginfo_TTF_SetFontOutline)
	ZEND_FE(TTF_GetFontHinting, arginfo_TTF_GetFontHinting)
	ZEND_FE(TTF_SetFontHinting, arginfo_TTF_SetFontHinting)
	ZEND_FE(TTF_FontHeight, arginfo_TTF_FontHeight)
	ZEND_FE(TTF_FontAscent, arginfo_TTF_FontAscent)
	ZEND_FE(TTF_FontDescent, arginfo_TTF_FontDescent)
	ZEND_FE(TTF_FontLineSkip, arginfo_TTF_FontLineSkip)
	ZEND_FE(TTF_GetFontKerning, arginfo_TTF_GetFontKerning)
	ZEND_FE(TTF_SetFontKerning, arginfo_TTF_SetFontKerning)
	ZEND_FE(TTF_FontFaces, arginfo_TTF_FontFaces)
	ZEND_FE(TTF_FontFaceIsFixedWidth, arginfo_TTF_FontFaceIsFixedWidth)
	ZEND_FE(TTF_FontFaceFamilyName, arginfo_TTF_FontFaceFamilyName)
	ZEND_FE(TTF_FontFaceStyleName, arginfo_TTF_FontFaceStyleName)
	ZEND_FE(TTF_GlyphIsProvided, arginfo_TTF_GlyphIsProvided)
	ZEND_FE(TTF_GlyphMetrics, arginfo_TTF_GlyphMetrics)
	ZEND_FE(TTF_SizeText, arginfo_TTF_SizeText)
	ZEND_FE(TTF_SizeUTF8, arginfo_TTF_SizeUTF8)
	ZEND_FE(TTF_SizeUNICODE, arginfo_TTF_SizeUNICODE)
	ZEND_FE(TTF_RenderText_Solid, arginfo_TTF_RenderText_Solid)
	ZEND_FE(TTF_RenderUTF8_Solid, arginfo_TTF_RenderUTF8_Solid)
	ZEND_FE(TTF_RenderUNICODE_Solid, arginfo_TTF_RenderUNICODE_Solid)
	ZEND_FE(TTF_RenderGlyph_Solid, arginfo_TTF_RenderGlyph_Solid)
	ZEND_FE(TTF_RenderText_Shaded, arginfo_TTF_RenderText_Shaded)
	ZEND_FE(TTF_RenderUTF8_Shaded, arginfo_TTF_RenderUTF8_Shaded)
	ZEND_FE(TTF_RenderUNICODE_Shaded, arginfo_TTF_RenderUNICODE_Shaded)
	ZEND_FE(TTF_RenderGlyph_Shaded, arginfo_TTF_RenderGlyph_Shaded)
	ZEND_FE(TTF_RenderText_Blended, arginfo_TTF_RenderText_Blended)
	ZEND_FE(TTF_RenderUTF8_Blended, arginfo_TTF_RenderUTF8_Blended)
	ZEND_FE(TTF_RenderUNICODE_Blended, arginfo_TTF_RenderUNICODE_Blended)
	ZEND_FE(TTF_RenderText_Blended_Wrapped, arginfo_TTF_RenderText_Blended_Wrapped)
	ZEND_FE(TTF_RenderUTF8_Blended_Wrapped, arginfo_TTF_RenderUTF8_Blended_Wrapped)
	ZEND_FE(TTF_RenderUNICODE_Blended_Wrapped, arginfo_TTF_RenderUNICODE_Blended_Wrapped)
	ZEND_FE(TTF_RenderGlyph_Blended, arginfo_TTF_RenderGlyph_Blended)
	ZEND_FE(TTF_CloseFont, arginfo_TTF_CloseFont)
	ZEND_FE(TTF_Quit, arginfo_TTF_Quit)
	ZEND_FE(TTF_WasInit, arginfo_TTF_WasInit)
	ZEND_FE(TTF_GetFontKerningSizeGlyphs, arginfo_TTF_GetFontKerningSizeGlyphs)
#if SDL_TTF_VERSION_ATLEAST(2, 0, 18)
	ZEND_FE(TTF_GetFreeTypeVersion, arginfo_TTF_GetFreeTypeVersion)
#endif
	ZEND_FE_END
};


static const zend_function_entry class_TTF_Font_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_SDL_RWops_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_SDL_bool_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_SDL_version_methods[] = {
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

static zend_class_entry *register_class_SDL_RWops(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "SDL_RWops", class_SDL_RWops_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	return class_entry;
}

static zend_class_entry *register_class_SDL_bool(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "SDL_bool", class_SDL_bool_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	return class_entry;
}

static zend_class_entry *register_class_SDL_version(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "SDL_version", class_SDL_version_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	return class_entry;
}

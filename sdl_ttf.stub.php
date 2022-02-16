<?php

/** @generate-class-entries */

function TTF_Linked_Version(): SDL_version {};
function TTF_ByteSwappedUNICODE(int $swapped): void {};
function TTF_Init(): int {};
function TTF_OpenFont(string $file, int $ptsize): TTF_Font {};
function TTF_OpenFontIndex(string $file, int $ptsize, int $index): TTF_Font {};
function TTF_OpenFontRW(SDL_RWops $src, int $freesrc, int $ptsize): TTF_Font {};
function TTF_OpenFontIndexRW(SDL_RWops $src, int $freesrc, int $ptsize, int $index): TTF_Font {};
function TTF_GetFontStyle(TTF_Font $font): int {};
function TTF_SetFontStyle(TTF_Font $font, int $style): void {};
function TTF_GetFontOutline(TTF_Font $font): int {};
function TTF_SetFontOutline(TTF_Font $font, int $outline): void {};
function TTF_GetFontHinting(TTF_Font $font): int {};
function TTF_SetFontHinting(TTF_Font $font, int $hinting): void {};
function TTF_FontHeight(TTF_Font $font): int {};
function TTF_FontAscent(TTF_Font $font): int {};
function TTF_FontDescent(TTF_Font $font): int {};
function TTF_FontLineSkip(TTF_Font $font): int {};
function TTF_GetFontKerning(TTF_Font $font): int {};
function TTF_SetFontKerning(TTF_Font $font, int $allowed): void {};
function TTF_FontFaces(TTF_Font $font): int {};
function TTF_FontFaceIsFixedWidth(TTF_Font $font): int {};
function TTF_FontFaceFamilyName(TTF_Font $font): string {};
function TTF_FontFaceStyleName(TTF_Font $font): string {};
function TTF_GlyphIsProvided(TTF_Font $font, int $ch): int {};
function TTF_GlyphMetrics(TTF_Font $font, int $ch, int &$minx, int &$maxx, int &$miny, int &$maxy, int &$advance): int {};
function TTF_SizeText(TTF_Font $font, string $text, int &$w, int &$h): int {};
function TTF_SizeUTF8(TTF_Font $font, string $text, int &$w, int &$h): int {};
function TTF_SizeUNICODE(TTF_Font $font, int &$text, int &$w, int &$h): int {};
function TTF_RenderText_Solid(TTF_Font $font, string $text, SDL_Color $fg): SDL_Surface {};
function TTF_RenderUTF8_Solid(TTF_Font $font, string $text, SDL_Color $fg): SDL_Surface {};
function TTF_RenderUNICODE_Solid(TTF_Font $font, int &$text, SDL_Color $fg): SDL_Surface {};
function TTF_RenderGlyph_Solid(TTF_Font $font, int $ch, SDL_Color $fg): SDL_Surface {};
function TTF_RenderText_Shaded(TTF_Font $font, string $text, SDL_Color $fg, SDL_Color $bg): SDL_Surface {};
function TTF_RenderUTF8_Shaded(TTF_Font $font, string $text, SDL_Color $fg, SDL_Color $bg): SDL_Surface {};
function TTF_RenderUNICODE_Shaded(TTF_Font $font, int &$text, SDL_Color $fg, SDL_Color $bg): SDL_Surface {};
function TTF_RenderGlyph_Shaded(TTF_Font $font, int $ch, SDL_Color $fg, SDL_Color $bg): SDL_Surface {};
function TTF_RenderText_Blended(TTF_Font $font, string $text, SDL_Color $fg): SDL_Surface {};
function TTF_RenderUTF8_Blended(TTF_Font $font, string $text, SDL_Color $fg): SDL_Surface {};
function TTF_RenderUNICODE_Blended(TTF_Font $font, int &$text, SDL_Color $fg): SDL_Surface {};
function TTF_RenderText_Blended_Wrapped(TTF_Font $font, string $text, SDL_Color $fg, int $wrapLength): SDL_Surface {};
function TTF_RenderUTF8_Blended_Wrapped(TTF_Font $font, string $text, SDL_Color $fg, int $wrapLength): SDL_Surface {};
function TTF_RenderUNICODE_Blended_Wrapped(TTF_Font $font, int &$text, SDL_Color $fg, int $wrapLength): SDL_Surface {};
function TTF_RenderGlyph_Blended(TTF_Font $font, int $ch, SDL_Color $fg): SDL_Surface {};
function TTF_CloseFont(TTF_Font $font): void {};
function TTF_Quit(): void {};
function TTF_WasInit(): int {};
function TTF_GetFontKerningSizeGlyphs(TTF_Font $font, int $previous_ch, int $ch): int {};

#if SDL_TTF_VERSION_ATLEAST(2, 0, 18)
function TTF_GetFreeTypeVersion(int &$major, int &$minor, int &$patch): void {}
#endif

final class TTF_Font {}
final class SDL_RWops {}
final class SDL_Color {}
final class SDL_Surface {}
final class SDL_bool {}
final class SDL_version {}

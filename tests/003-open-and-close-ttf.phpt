--TEST--
TTF_OpenFont and TTF_CloseFont
--EXTENSIONS--
sdl
sdl_ttf
--FILE--
<?php

$font = TTF_OpenFont('/wrong.font.ttf', 12);
echo ($font instanceof TTF_Font ? "Font open and return type is TTF_Font\n" : "Error: font not opened!\n");
var_dump(SDL_GetError());
SDL_SetError("");

$file = __DIR__.'/SourceCodePro-Medium.ttf';
$font = TTF_OpenFont($file, 12);
echo ($font instanceof TTF_Font ? "Font open and return type is TTF_Font\n" : "Error: font not opened!\n");
var_dump(SDL_GetError());

//function TTF_OpenFontIndex(string $file, int $ptsize, int $index): TTF_Font {};
//function TTF_OpenFontRW(SDL_RWops $src, int $freesrc, int $ptsize): TTF_Font {};
//function TTF_OpenFontIndexRW(SDL_RWops $src, int $freesrc, int $ptsize, int $index): TTF_Font {};
//function TTF_FontFaces(TTF_Font $font): int {};

echo "Font Faces: ".TTF_FontFaces($font)."\n";
echo "Font Faces is fixed width: ".TTF_FontFaceIsFixedWidth($font)."\n";
echo "Font Faces family name: ".TTF_FontFaceFamilyName($font)."\n";
echo "Font Faces style name: ".TTF_FontFaceStyleName($font)."\n";
echo "The glyph Σ is provided: ".TTF_GlyphIsProvided($font, ord('Σ'))."\n";
echo "Font Faces metrics: ".TTF_GlyphMetrics($font, ord('Σ'), $minx, $maxx, $miny, $maxy, $advance)."\n";
var_dump($minx, $maxx, $miny, $maxy, $advance);

echo "TTF site text: ".TTF_SizeText($font, "This is a text", $w, $h);
echo "    width: $w, height $h\n";
echo "TTF size UTF8: ".TTF_SizeUTF8($font, "This is a text", $w, $h);
echo "    width: $w, height $h\n";
$string = "This is a text";
echo "TTF size UNICODE: ".TTF_SizeUNICODE($font, $string, $w, $h);
echo "    width: $w, height $h\n";

TTF_CloseFont($font);
?>
--EXPECT--
Error: font not opened!
string(29) "Couldn't open /wrong.font.ttf"
Font open and return type is TTF_Font
string(0) ""
Font Faces: 1
Font Faces is fixed width: 4
Font Faces family name: Source Code Pro
Font Faces style name: Medium
The glyph Σ is provided: 128
Font Faces metrics: 0
int(1)
int(7)
int(0)
int(11)
int(7)
TTF site text: 0    width: 98, height 16
TTF size UTF8: 0    width: 98, height 16
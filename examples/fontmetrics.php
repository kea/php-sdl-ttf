<?php

$file = __DIR__.'/../Roboto-Medium.ttf';
$font = TTF_OpenFont($file, 12);

//echo ($font instanceof TTF_Font ? "Font open and return type is TTF_Font\n" : "Error: font not opened!\n");
//var_dump(SDL_GetError());

//$font = TTF_OpenFontIndex($file, 12, 1);
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

$surface = TTF_RenderText_Blended($font, "Ciao!", new SDL_Color(200, 200, 200, 255));
echo (string)$surface."\n";

echo "TTF site text: ".TTF_SizeText($font, "This is a text", $w, $h);
echo "    width: $w, height $h\n";
echo "TTF size UTF8: ".TTF_SizeUTF8($font, "This is a text", $w, $h);
echo "    width: $w, height $h\n";

// /!\ Wrong /!\
// echo "TTF size UNICODE: ".TTF_SizeUNICODE($font, "This is a text", $w, $h);
// echo "    width: $w, height $h\n";

TTF_CloseFont($font);

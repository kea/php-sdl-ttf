<?php

declare(strict_types=1);

const WINDOW_WIDTH = 800;
const WINDOW_HEIGHT = 500;

error_reporting(E_ALL);

if (!extension_loaded('SDL')) {
    echo "No SDL";
    exit(-1);
}
if (!extension_loaded('SDL_ttf')) {
    echo "No SDL_ttf";
    exit(-2);
}

if (!file_exists(__DIR__.'/../Roboto-Medium.ttf')) {
    echo "You have to download the Roboto-Medium font from google\n";
}

SDL_Init(SDL_INIT_VIDEO);
$window = SDL_CreateWindow(
    "TTF Font test",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    SDL_WINDOW_SHOWN
);
$renderer = SDL_CreateRenderer($window, 0, SDL_RENDERER_ACCELERATED);

SDL_SetRenderDrawColor($renderer, 0x41, 0x19, 0x10, 0);
SDL_RenderClear($renderer);

$fonts = [];
$textures = [];
$surfaces = [];
$rects = [];

$font = TTF_OpenFont(__DIR__.'/../Roboto-Medium.ttf', 12);
$fontName = TTF_FontFaceFamilyName($font);
$fontStyleName = TTF_FontFaceStyleName($font);
TTF_CloseFont($font);

$colors = [
    18 => new SDL_Color(0xF0, 0xD0, 0xA0, 255),
    28 => new SDL_Color(0xdb, 0xa8, 0x33, 255),
    42 => new SDL_Color(0xd7, 0x6b, 0x2b, 255),
    68 => new SDL_Color(0xce, 0x4b, 0x2d, 255),
];

foreach ([18, 28, 42, 68] as $i) {
    // TTF_SetFontSize requires SDL_ttf 2.0.18+
    $font = TTF_OpenFont(__DIR__.'/../Roboto-Medium.ttf', $i);
    $surfaceT = TTF_RenderUTF8_Blended(
        $font, "Ciao \u{039a}\u{039e}\u{039b}! ".$fontName.' '.$fontStyleName.' '.$i, $colors[$i]
    );
    $textureT = SDL_CreateTextureFromSurface($renderer, $surfaceT);
    $rectT = new SDL_Rect(20, 30 + (int)($i*2), $surfaceT->clip_rect->w, $surfaceT->clip_rect->h);

    $fonts[] = $font;
    $textures[] = $textureT;
    $surfaces[] = $surfaceT;
    $rects[] = $rectT;
}

$event = new SDL_Event;
while (true) {
    SDL_RenderClear($renderer);
    if (SDL_PollEvent($event) && $event->type == SDL_QUIT) {
        break;
    }
    foreach ($fonts as $i => $font) {
        if (SDL_RenderCopy($renderer, $textures[$i], $surfaces[$i]->clip_rect, $rects[$i]) != 0) {
            echo SDL_GetError(), PHP_EOL;
        }
    }
    SDL_RenderPresent($renderer);
    SDL_Delay(200);
}

foreach ($fonts as $i => $font) {
    SDL_FreeSurface($surfaces[$i]);
    TTF_CloseFont($font);
}
SDL_DestroyRenderer($renderer);
SDL_DestroyWindow($window);
SDL_Quit();
<?php

declare(strict_types=1);

const WINDOW_WIDTH = 800;
const WINDOW_HEIGHT = 800;

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

SDL_SetRenderDrawColor($renderer, 0, 100, 0, 0);
SDL_RenderClear($renderer);

$fonts = [];
$textures = [];
$surfaces = [];
$rects = [];

for ($i = 18; $i < 150; $i+=5+$i/3) {
    $font = TTF_OpenFont(__DIR__.'/../Roboto-Medium.ttf', (int)$i);
    $surfaceT = TTF_RenderText_Blended($font, "Ciao! ".((int)$i), new SDL_Color(230, 230, 230, 255));
    $textureT = SDL_CreateTextureFromSurface($renderer, $surfaceT);
    $rectT = new SDL_Rect(100, 100 + (int)($i*2), $surfaceT->clip_rect->w, $surfaceT->clip_rect->h);

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
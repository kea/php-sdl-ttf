<?php

/** @generate-class-entries */

function TTF_Linked_Version(): array {}

#if SDL_TTF_VERSION_ATLEAST(2, 0, 18)
function TTF_GetFreeTypeVersion(int &$major, int &$minor, int &$patch): void {}
#endif

function TTF_OpenFont(string $file, int $ptsize): TTF_Font {};

final class TTF_Font {}

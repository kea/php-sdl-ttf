# SDL_ttf PHP Extension
[SDL_mixer](https://www.libsdl.org/projects/SDL_ttf/) for PHP add support for TrueType (.ttf) font files with Simple Directmedia Layer (SDL).

It requires SDL PHP Extension.

## Building

```bash
$ phpize
$ ./configure --enable-sdl_ttf
$ make
$ make install
```

Run tests with installed PHP (avoids skipped tests):

```
$ php run-tests.php --show-diff -q
```

## Requirements

Require PHP 8+ and SDL PHP extension

```
$ pecl install sdl-devel
```
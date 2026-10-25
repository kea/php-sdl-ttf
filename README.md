# SDL_ttf PHP Extension
[SDL_mixer](https://www.libsdl.org/projects/SDL_ttf/) for PHP add support for TrueType (.ttf) font files with Simple Directmedia Layer (SDL).

It requires SDL PHP Extension.

## Installing with PIE

Install with [PIE](https://github.com/php/pie) (PHP Installer for Extensions):

```bash
$ pie install kea/php-sdl-ttf
```

The SDL_ttf development files (e.g. `libsdl2-ttf-dev` on Debian/Ubuntu) and the SDL PHP extension must be installed first.

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

Run tests with docker:

```bash
$ docker build --build-arg PHP_VERSION=8.4 -t php-sdl-ttf:8.4 .
$ docker run --rm php-sdl-ttf:8.4
```

## Requirements

Require PHP 8+ and SDL PHP extension

```
$ pecl install sdl-devel
```
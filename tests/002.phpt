--TEST--
TTF_WasInit
--EXTENSIONS--
sdl
sdl_ttf
--FILE--
<?php
$ret = TTF_WasInit();

var_dump($ret);
?>
--EXPECT--
int(1)

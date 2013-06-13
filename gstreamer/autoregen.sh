#!/bin/sh
./autogen.sh --enable-maintainer-mode --disable-gtk-doc --disable-nls --disable-docbook --disable-tests --disable-examples --disable-debug --disable-debugutils --enable-failing-tests --disable-loadsave --enable-poisoning $@

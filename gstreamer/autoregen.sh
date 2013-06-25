#!/bin/sh
./autogen.sh --disable-gtk-doc --disable-nls --disable-docbook --disable-tests --disable-benchmarks --disable-examples --disable-debug --disable-debugutils --enable-failing-tests --disable-loadsave --enable-poisoning $@

#!/bin/bash

SOURCE_DIR="$1"
GIT_DIR="$2"
CONFIGURE_EXTRA_ARGS=("${@:(3)}") # The argument list, except the firts two
GIT_VERSION_FILE="$GIT_DIR/VERSION"

compile() {
    local build_dir
    build_dir="$SOURCE_DIR/libffcall-$(cat $GIT_VERSION_FILE)/builddir" &&
    mkdir "$build_dir" &&
    (
        cd "$build_dir" &&
        ../configure --cache-file=config.cache "${CONFIGURE_EXTRA_ARGS[@]}" &&
        make &&
        make check
    )
    return $?
}

download_source() {
    local filename; filename="libffcall-$(cat "$GIT_VERSION_FILE").tar.gz" &&
	# Sometimes Windows (WSL) gets mad if we get the file using this method and 
	# ``make`` fails, unless you untar it using 7zip or something on windows
    wget -qO- "https://ftp.gnu.org/gnu/libffcall/$filename" \
        | tar -xz -C "$SOURCE_DIR" -v
    return $?
}

download_source &&
compile
exit $?


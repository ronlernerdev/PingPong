#!/usr/bin/env fish

set PROJECT_ROOT (pwd)
set BUILD_DIR "$PROJECT_ROOT/build"
set SUBPROJECT_DIR "$PROJECT_ROOT/subprojects"
set RAYLIB_DIR "$SUBPROJECT_DIR/raylib"
set RAYLIB_SRC "$RAYLIB_DIR/src"

echo "PROJECT_ROOT  = $PROJECT_ROOT"
echo "BUILD_DIR     = $BUILD_DIR"
echo "SUBPROJECTS   = $SUBPROJECT_DIR"
echo "RAYLIB        = $RAYLIB_DIR"
echo "RAYLIB_SRC    = $RAYLIB_SRC"

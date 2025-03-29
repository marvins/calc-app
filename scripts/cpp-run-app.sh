#!/usr/bin/env bash

PRE_CMD=''

for ARG in "$@"; do
    case $ARG in
        --gdb)
            PRE_CMD="gdb --args"
            ;;
        *)
            echo "error: Unsupported argument (${ARG})"
            exit 1
            ;;
    esac
done

#  Launch with standard flags
${PRE_CMD} ./build/bin/terminus_toolbox -c data/options.uconsole.cfg -v 

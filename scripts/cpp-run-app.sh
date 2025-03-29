#!/usr/bin/env bash

PRE_CMD=''

CONFIG_PATH='./data/options.picocalc.cfg'

for ARG in "$@"; do
    case $ARG in
        --gdb)
            PRE_CMD="gdb --args"
            ;;
        
        --uconsole)
            CONFIG_PATH='./data/options.uconsole.cfg'
            ;;

        --pico)
            CONFIG_PATH='./data/options.picocalc.cfg'
            ;;
        *)
            echo "error: Unsupported argument (${ARG})"
            exit 1
            ;;
    esac
done

#  Launch with standard flags
${PRE_CMD} ./build/bin/terminus_toolbox -c ${CONFIG_PATH} -vv

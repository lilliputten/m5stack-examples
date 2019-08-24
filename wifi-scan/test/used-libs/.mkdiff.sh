#!/bin/sh
# @changed 2019.08.24, 03:11

for NAME in *.{cpp,c,h}; do

    echo -n "${NAME} ... "

    if [ -f "${NAME}.orig" ]; then
        diff -wbu "${NAME}.orig" "${NAME}" > "${NAME}.diff"
        if [ -s "${NAME}.diff" ]; then
            echo "OK"
        else
            echo "NO CHANGES"
            rm -f "${NAME}.diff"
        fi
    else
        echo "SKIPPED (no .orig file)"
    fi

done

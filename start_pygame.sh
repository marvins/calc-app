#!/bin/bash

. venv/bin/activate

python python/core/main.py -v -l app.log -c ./data/options.uconsole.cfg

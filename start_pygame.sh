#!/bin/bash

. venv/bin/activate

python core/game/main.py -v -l app.log -c ./data/options.uconsole.cfg

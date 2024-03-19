#!/bin/bash
NAME=~/Pictures/Screenshots/$(date +%a_%F_%R).png
scrot $NAME -e 'notify-send -t 2000 -u critical --icon='$NAME' --app-name=ScreenShot $f'
#notify-send 'Picture taken!' "It was saved at $NAME" --icon=camera-photo

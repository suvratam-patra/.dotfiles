#!/bin/sh
# A dwm_bar function to show the master volume of ALSA
# Joe Standring <git@joestandring.com>
# GNU GPLv3

# Dependencies: alsa-utils
dwm_sound () {
    STATUS=$(pactl get-sink-volume @DEFAULT_SINK@ | grep -Po '\d+(?=%)' | head -n 1) 
    if [ $STATUS -ge 100 ];
        then
        pactl set-sink-volume @DEFAULT_SINK@ 100%
    else
        pactl set-sink-volume @DEFAULT_SINK@ +10%
    fi
}
dwm_sound

#!/bin/bash
function run {
 if ! pgrep $1 ;
  then
    $@&
  fi
}

slstatus &
#dwmblocks &
#export LANG=en_US.utf-8
#xset -dpms &
#xset s off &

run "nm-applet"
#run "pasystray"
run "blueman-applet"
run "barrier"
run "flameshot"
run "numlockx on"
# run "pamac-tray"
# run "variety"
# run "pulseaudio"
# run "pamac-tray"
#run "volumeicon"
#run "dex $HOME/.config/autostart/*.desktop"
#run "$HOME/.config/slstatus/slstatus"
#dunst -conf ~/.config/dunst/dunstrc &
# run "blueberry-tray"
# run "/usr/bin/notify-send"
# run "/usr/lib/xfce4/notifyd/xfce4-notifyd"
#run "/usr/lib/policykit-1-gnome/polkit-gnome-authentication-agent-1"
sxhkd -c ~/.config/dwm/sxhkd/sxhkdrc &
picom --experimental-backends -b --config ~/.config/dwm/picom.conf &
feh --randomize --bg-fill ~/.config/dwm/Wallpaper/* &
sleep 0.3
xfce4-panel --disable-wm-check
# xargs xwallpaper --stretch < ~/.config/dwm/Wallpaper &
# eval $(gnome-keyring-daemon -s --components=pkcs11,secrets,ssh,gpg) &

#while true
 #do
#done

#run "nitrogen --restore"
#run "conky -c $HOME/.config/dwm/system-overview"
#you can set wallpapers in themes as well
#wallpaper for other Arch based systems
#feh --bg-fill /usr/share/archlinux-tweak-tool/data/wallpaper/wallpaper.png &
#run applications from startup

#run "insync start"
#run "spotify"
#run "ckb-next -b"
#run "discord"
#run "telegram-desktop"

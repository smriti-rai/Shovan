//To show the running proesses using "ps" command
#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[1024];

    // Run the "ps" command and pipe the output to our program
    fp = popen("ps", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return 1;
    }

    // Read the output of the "ps" command and print it to the console
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // Close the pipe and exit the program
    pclose(fp);
    return 0;
}

/* output:
 PID TTY          TIME CMD
    984 ?        00:00:00 systemd
    985 ?        00:00:00 (sd-pam)
    993 ?        00:00:00 gnome-keyring-d
    997 ?        00:00:01 dbus-daemon
    998 ?        00:00:02 xfce4-session
   1016 ?        00:00:00 gvfsd
   1021 ?        00:00:00 gvfsd-fuse
   1030 ?        00:00:00 at-spi-bus-laun
   1036 ?        00:00:00 dbus-daemon
   1038 ?        00:00:00 xfconfd
   1044 ?        00:00:00 at-spi2-registr
   1049 ?        00:00:00 ssh-agent
   1056 ?        00:00:00 gpg-agent
   1063 ?        00:00:17 xfwm4
   1073 ?        00:00:00 pulseaudio
   1080 ?        00:00:02 xfce4-panel
   1086 ?        00:00:07 Thunar
   1091 ?        00:00:03 panel-8-whisker
   1095 ?        00:00:03 panel-9-pulseau
   1096 ?        00:00:01 panel-2-actions
   1097 ?        00:00:02 panel-10-power-
   1104 ?        00:00:00 gsettings-helpe
   1112 ?        00:00:05 xfdesktop
   1153 ?        00:00:01 xfce4-power-man
   1154 ?        00:00:01 msm_notifier
   1162 ?        00:00:00 xdg-desktop-por
   1166 ?        00:00:00 xdg-document-po
   1169 ?        00:00:00 xdg-permission-
   1179 ?        00:00:00 gvfs-udisks2-vo
   1180 ?        00:00:03 xdg-desktop-por
   1181 ?        00:00:02 xfce4-clipman
   1183 ?        00:00:02 tint2
   1188 ?        00:00:00 xcape
   1200 ?        00:00:00 xiccd
   1201 ?        00:00:01 pamac-tray
   1207 ?        00:00:02 nm-applet
   1212 ?        00:00:01 xfce4-notifyd
   1217 ?        00:00:00 agent
   1219 ?        00:00:04 zeitgeist-datah
   1238 ?        00:00:01 light-locker
   1239 ?        00:00:03 blueman-applet
   1241 ?        00:00:01 polkit-gnome-au
   1264 ?        00:00:00 gvfs-afc-volume
   1273 ?        00:00:00 gvfs-gphoto2-vo
   1303 ?        00:00:00 gvfs-mtp-volume
   1311 ?        00:00:00 zeitgeist-daemo
   1316 ?        00:00:01 xdg-desktop-por
   1324 ?        00:00:00 zeitgeist-fts
   1372 ?        00:00:00 pipewire
   1375 ?        00:00:00 gvfsd-trash
   1387 ?        00:00:00 dconf-service
   1391 ?        00:00:00 gvfsd-metadata
   1448 ?        00:00:00 obexd
   1452 ?        00:00:03 blueman-tray
   1503 ?        00:01:07 brave
   1505 ?        00:00:00 chrome_crashpad
   1507 ?        00:00:00 chrome_crashpad
   1513 ?        00:00:00 brave
   1514 ?        00:00:00 brave
   1516 ?        00:00:00 brave
   1537 ?        00:00:37 brave
   1540 ?        00:00:06 brave
   1587 ?        00:00:00 brave
   1598 ?        00:00:00 brave
   1631 ?        00:00:01 brave
   1678 ?        00:00:01 xfsettingsd
   1679 ?        00:00:03 brave
   1780 ?        00:05:14 brave
   1792 ?        00:00:00 brave
   1808 ?        00:00:00 brave
   1859 ?        00:00:37 sublime_text
   1914 ?        00:00:01 plugin_host-3.3
   1917 ?        00:00:02 plugin_host-3.8
   1994 ?        00:00:00 gvfsd-network
   2011 ?        00:00:00 gvfsd-dnssd
   2706 ?        00:00:00 run
   2713 ?        00:00:00 ps
   */
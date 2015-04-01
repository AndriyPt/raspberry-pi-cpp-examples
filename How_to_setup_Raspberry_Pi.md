# How to setup Raspberry Pi without USB keyboard, mouse, HDMI monitor and TV #

Raspberry can be setup using home computer or laptop which is running different OS. We will use Ubuntu PC.

  * [Here](http://www.learn2crack.com/2013/08/setup-sd-card-for-raspberry-pi.html) you can find how to install Raspbian on micro SD card from PC.
  * Insert created micro SD card to your Raspberry Pi
  * Connect Ethernet LAN cable
  * Connect micro USB adapter 5V 2A and plug it in

<a href='Hidden comment: 
command to setup additional items of configuration
sudo raspi-config
select to extend partition in micro SD card to the whole card
select to start GUI by default after boot
select Internationalization
Locale issue in apt-get
sudo vim /etc/default/locale add
LANGUAGE=en_US.UTF-8
LC_ALL=en_US.UTF-8
LANG=en_US.UTF-8
LC_TYPE=en_US.UTF-8
reboot
'></a>
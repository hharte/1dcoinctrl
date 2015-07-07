#!/usr/bin/expect
#
# Western Electric 1D Coin Controller
# Copyright (c) 2015 Howard M. Harte, WZ2Q.
# https://github.com/hharte/1dcoinctrl
#
# Expect script to refund coins in hopper.

log_user 0
set timeout 5

spawn telnet 192.168.0.22 23000
send "\r"
expect -re ">"
send "3\r"
expect -re ">"
exit 0

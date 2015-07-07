#!/usr/bin/expect
#
# Western Electric 1D Coin Controller
# Copyright (c) 2015 Howard M. Harte, WZ2Q.
# https://github.com/hharte/1dcoinctrl
#
# Check for stuck coin in hopper.
# Returns 0 no coin in hopper.
#         1 coin in hopper.
#         >1 any error.

log_user 0
set timeout 5

spawn telnet 192.168.0.22 23000
send "\r"
expect -re ">"
send "6\r"
expect -re "Test Status: no coin" { exit 0 } \
  expect -re "Test Status: STUCK COIN" { exit 1 } \
  timeout { puts "error: timeout waiting for status."; exit 2 } \
  eof { puts "error: eof"; exit 3 }

#!/usr/bin/expect
#
# Western Electric 1D Coin Controller
# Copyright (c) 2015 Howard M. Harte, WZ2Q.
# https://github.com/hharte/1dcoinctrl
#
# Check for initial rate deposited into payphone.
# Returns 0 if initial rate has been deposited.
#         1 if initial rate has not been deposited.
#         >1 any error.

log_user 0
set timeout 1

spawn telnet 192.168.0.22 23000
send "\r"
expect -re ">"
send "5\r"
expect -re "Test Status: insufficient funds" { exit 1 } \
  expect -re "Test Status: INITIAL RATE DEPOSITED" { exit 0 } \
  timeout { puts "error: timeout waiting for status."; exit 2 } \
  eof { puts "error: eof"; exit 3 }

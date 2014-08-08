BZTimer
=======

A flexible multi alarm timer application in Qt5/QWidget

This timer was originally created for N900 for the purpose of interval running. It uses a text based alarm input format to allow for some flexibility in defining multiple alarms with relative ease and little UI.

Alarm format
------------

An alarm is composed of expressions separated by whitespace. Each expression contains one or more atoms separated by a single dash (-). 

Each atom represents a duration in the format "00h00m00s", for example "1h23m18s". Atoms may be abbreviated by skippiing zero values, for example "5s", "1h2s" or "6m12s". 

An expression will create alarms at the intervals defined by the atoms. For example an expression "5s-10s" would create two alarms: one at 5 seconds and the other 10 seconds later at 15 seconds. Each expression starts its first atom at zero time, so "5s 10s" creates alarms at 5 seconds and 10 seconds.

An expression may be set as looping by appending a plus (+). For example, the expression "5s+" would create alarms every 5 seconds, namely at 5s, 10s, 15s, 20s... and so on.

As a more complete example, the alarm string "3m 10s-2m30s+ 1h+" would create one alarm at 3 minutes, a repeating sequence of alarms like 10s, 2m40s, 2m50s, 5m20s... and last an alarm every full hour.

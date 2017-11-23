#!/bin/sh

###########################################################
#
# Log files cleaning script. This script is intended to be at
# scrpt directory which has a neighbour called log where log
# files are stored with names like gbd.date.log. 
# The script deletes all files modified after more than 7 days
# to keep one week recent logs
#
##########################################################


GBD_PATH=`dirname $0`

find $GBD_PATH/../log -name "gbd.*.log" -type f -mtime +7 -exec rm -f {} \;


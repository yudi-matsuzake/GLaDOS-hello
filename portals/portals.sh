#!/bin/bash

inicialize_screen_size(){
	LINE=`xrandr -q | grep Screen`
	WIDTH=`echo ${LINE} | awk '{ print $8 }'`
	HEIGHT=`echo ${LINE} | awk '{ print $10 }' | awk -F"," '{ print $1 }'`
}

inicialize_screen_size

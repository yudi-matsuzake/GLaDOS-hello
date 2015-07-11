#!/bin/bash

portal(){
	echo "The cake is a lie" ;
}

#sleep 10
aplay sounds/GLaDOS_00_part1_entry-1.wav sounds/GLaDOS_00_part1_entry-7.wav &> /dev/null

#p=$(portal)

cd portals
./portal
#gnome-terminal --tab -e "/bin/bash -c 'cd portals/ ./portal;  exec /bin/bash -i'"
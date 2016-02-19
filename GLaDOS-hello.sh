#!/bin/bash

portal(){
	echo "The cake is a lie" ;
}

#sleep 10
aplay sounds/GLaDOS_00_part1_entry-1.wav sounds/GLaDOS_00_part1_entry-7.wav &> /dev/null &
echo "Hello and, again, welcome to the Aperture Science computer-aided enrichment center." | beep -cl 75 -f 100
echo "Stand back. The portal will open in" | beep -cl 75 -f 100
echo "three..." | beep -cl 75 -f 100 ; sleep 0.5
echo "two..." | beep -cl 75 -f 100 ; sleep 0.5
echo "one..." | beep -cl 75 -f 100

wait
cd portals
./portal
#gnome-terminal --tab -e "/bin/bash -c 'cd portals/ ./portal;  exec /bin/bash -i'"

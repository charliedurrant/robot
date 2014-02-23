#!/bin.bash
if [ -f robot-install.sh ]
then
 rm robot-install.sh
fi
#DOWNLOAD_URL=http://192.168.56.1/identity-linux/
#DOWNLOAD_URL=http://192.168.1.135/identity-linux/
#DOWNLOAD_URL=http://192.168.1.135/identity-linux/
DOWNLOAD_URL=http://192.168.1.10/robot/linux/
wget --no-cache ${DOWNLOAD_URL}robot-install.sh
bash robot-install.sh ${DOWNLOAD_URL}




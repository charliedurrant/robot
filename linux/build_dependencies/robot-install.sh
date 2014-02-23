#!/bin/bash          
#tells system this is a bash file
#search cache apt-cache search blah
#output make file output make &> results.txt
#create patches http://jungels.net/articles/diff-patch-ten-minutes.html


#!/bin/bash
function system_version()
{
	ARCH=$(uname -m)
	KERNAL=$(uname -r)
	OS = "UNKNOWN"
	OS_VERSION = ""
	if [ -f /etc/lsb-release ]; then
					OS=$(lsb_release -s -d)					
	elif [ -f /etc/debian_version ]; then
					OS_VERSION="$(cat /etc/debian_version)"
					OS="DEBIAN"
	elif [ -f /etc/redhat-release ]; then					
					OS_VERSION=`cat /etc/redhat-release`
					OS="REDHAT"
	else
					OS="$(uname -s)"
					OS_VERSION = "$(uname -r)"
	fi
}

system_version

echo
echo ---------------- ROBOT INSTALL ----------------
echo 
echo Settings:
echo 

INSTALL_ROOT=0
INSTALL_BUILD_ENVIRONMENT=0
INSTALL_SAMBA=0
INSTALL_SDL2=0
INSTALL_SDL2_IMAGE=0
INSTALL_SDL2_MIXER=0
INSTALL_SDL2_TTF=1

DOWNLOAD_URL=${1}

echo "Operating system:" ${OS} ${OS_VERSION}
echo "Download URL:" ${DOWNLOAD_URL}
echo "Install Root account:" ${INSTALL_ROOT}
echo "Install Build Environment:" ${INSTALL_BUILD_ENVIRONMENT}
echo "Install SAMBA :" ${INSTALL_SAMBA}
echo "Install SDL2:" ${INSTALL_SDL2}

sleep 2s
echo 

if [ ${INSTALL_ROOT} -eq "1" ]
then
	echo
	echo ---------------- INSTALL ROOT ACCOUNT ----------------
	echo 
	sudu -i
	passwd root
	sudo reboot	
fi


if [ ${INSTALL_BUILD_ENVIRONMENT} -eq "1" ]
then
	echo
	echo ---------------- INSTALL BUILD ENVIRONMENT ----------------
	echo 
	apt-get -y install sudo
	sudo apt-get update 
	sudo apt-get upgrade 
	sudo apt-get install -y gzip unzip  #TODO: check needed
	sudo apt-get install -y build-essential
	sudo apt-get install -y autoconf
	sudo apt-get install -y libraspberrypi0 libraspberrypi-bin libraspberrypi-dev		
	
	sudo apt-get install g++-4.7
	sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.6 60 --slave /usr/bin/g++ g++ /usr/bin/g++-4.6
	sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.7 40 --slave /usr/bin/g++ g++ /usr/bin/g++-4.7
	sudo update-alternatives --config gcc
	
fi

if [ ${INSTALL_SAMBA} -eq "1" ]
then
	echo
  echo ---------------- INSTALL SAMBA ----------------
  ec
	
	if [ -f smb.conf ]
	then
	 rm smb.conf
	fi
	
	sudo wget --output-document=smb.conf --no-cache ${DOWNLOAD_URL}/linux/smb.conf.txt
	
	sudo apt-get -y install sysvconfig 
	sudo apt-get -y install samba
	sudo apt-get -y install smbclient
	sudo apt-get -y install samba-common-bin
	sudo smbpasswd -a root
	
	cp smb.conf /etc/samba/smb.conf
	sudo service samba restart
	smbclient -L 127.0.0.1
fi


if [ ${INSTALL_SDL2} -eq "1" ]
then
	#see SDL2-2.0.1 README-raspberrypi.txt
	apt-get install -y libudev-dev libasound2-dev
	if [ ${OS} == "DEBIAN" ] 
	then
		sudo apt-get install -y mesa-common-dev
		sudo apt-get install -y freeglut3-dev
	fi
	
	#only required for autogen.sh see http://www.raspberrpi.org/phpBB3/viewtopic.php?t=58180&p=469283

	echo ---------------- BUILD SDL2 ----------------
	if [ ! -f SDL2-2.0.1.tar.gz ]
	then
		wget http://www.libsdl.org/release/SDL2-2.0.1.tar.gz
		tar -xvf SDL2-2.0.1.tar.gz
	fi
	
	cd SDL2-2.0.1
	./configure
	make install
	ldconfig
	cd ..
fi

if [ ${INSTALL_SDL2_IMAGE} -eq "1" ]
then
	echo ---------------- BUILD SDL2_image ----------------
	if [ ! -f SDL2_image-2.0.0.tar.gz ]
	then
		wget http://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.0.tar.gz
		tar -xvf SDL2_image-2.0.0.tar.gz
	fi
	apt-get install -y libpng12-0 libpng12-dev libpng3
  apt-get install -y libjpeg8 libjpeg8-dev
	apt-get install -y libtiff5 libtiff5-dev
	apt-get install -y libwebp2 libwebp-dev
	
	cd SDL2_image-2.0.0
	./configure
	make install
	cd ..
fi

if [ ${INSTALL_SDL2_MIXER} -eq "1" ]
then
	echo ------------- BUILD SDL2_mixer AND SMPEG -------------
	if [ ! -f SDL2_mixer-2.0.0.tar.gz ]	
	then
		wget http://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.0.tar.gz
		tar -xvf SDL2_mixer-2.0.0.tar.gz
	fi
	apt-get install -y libmodplug1 libmodplug-dev
	apt-get install -y libfluidsynth1 libfluidsynth-dev
	apt-get install -y libvorbis libvorbis-dev
	apt-get install -y libflac8 libflac-dev
	
	
	cd SDL2_mixer-2.0.0

	echo ---------------- BUILD SMPEG ----------------
	cd external/smpeg2-2.0.0
	./configure
	make install

	echo ---------------- BUILD SDL2_mixer --------------
	cd ../..
	#CFLAGS required on debian due to SDL build bug not finding modplug.h
	#reaspberry pi is the first -I and debian is the second
	./configure CFLAGS="-I/usr/local/include/libmodplug/ -I/usr/include/libmodplug/"
	make install
	ldconfig
	cd ..
fi
	
if [ ${INSTALL_SDL2_TTF} -eq "1" ]	
then
	echo ---------------- BUILD SDL2_ttf --------------
	if [ ! -f SDL2_ttf-2.0.12.tar.gz ]	
	then
		wget http://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.12.tar.gz
		tar -xvf SDL2_ttf-2.0.12.tar.gz
	fi
	
	cd SDL2_ttf-2.0.12
	./configure
	make install
	ldconfig
	cd ..
fi

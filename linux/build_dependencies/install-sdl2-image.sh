if [ ${INSTALL_SDL2_IMAGE} -eq "1" ]
	echo ---------------- BUILD SDL2_image ----------------
	apt-get install -y libpng12-0 libpng12-dev libpng3
  apt-get install -y libjpeg8 libjpeg8-dev
	apt-get install -y libtiff5 libtiff5-dev
	apt-get install -y libwebp2 libwebp-dev
	
	cd SDL2_image-2.0.0
	./configure
	make install
	cd ..
fi
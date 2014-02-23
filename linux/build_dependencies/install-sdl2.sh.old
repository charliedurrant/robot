
#see SDL2-2.0.1 README-raspberrypi.txt
#apt-get install libudev-dev libasound2-dev
#apt-get install libraspberrypi0 libraspberrypi-bin libraspberrypi-dev
#only required for autogen.sh see http://www.raspberrpi.org/phpBB3/viewtopic.php?t=58180&p=469283
#apt-get install autoconf

echo ****** Build SDL2 **************
#wget http://www.libsdl.org/release/SDL2-2.0.1.tar.gz
#tar -xvf SDL2-2.0.1.tar.gz
#cd SDL2-2.0.1
#./configure
#make install
#cd ..


echo ***** Build SDL2_image *******
#apt-get install libpng12-0 libpng12-dev libpng3
#apt-get install libjpeg8 libjpeg8-dev
#apt-get install libtiff5 libtiff5-dev
#apt-get install libwebp2 libwebp-dev
#wget http://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.0.tar.gz
#tar -xvf SDL2_image-2.0.0.tar.gz
#cd SDL2_image-2.0.0
# note needed as this is a release version, help on raspberyy pi site is wrong bash autogen.sh
#./configure
#make install
#cd ..



echo ***** SDL2_mixer dependencies ****
#apt-get install libmodplug1 libmodplug-dev
#apt-get install libfluidsynth1 libfluidsynth-dev
#apt-get install libvorbis libvorbis-dev
#apt-get install libflac8 libflac-dev


echo ************* Build SDL2_mixer **************
#wget http://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.0.tar.gz
#tar -xvf SDL2_mixer-2.0.0.tar.gz
#cd SDL2_mixer-2.0.0

echo ******** Compile smpeg3 from SDL_mixer source ***
#cd external/smpeg2-2.0.0
#./configure
#make install

#cd ../..
#CFLAGS required on debian due to SDL build bug not finding modplug.h
#./configure CFLAGS="-I/usr/local/include/libmodplug/"
#make install
#cd ..


echo ***** GUIlib and SDL_net not possible with latest source ****
echo ***** GUILib ******
#wget http://www.libsdl.org/projects/GUIlib/src/GUIlib-1.2.1.tar.gz
##tar -xvf GUIlib-1.2.1.tar.gz
#cd GUIlib-1.2.1
#./configure
#make install
#cd ..

echo ******* SDL_net ********
#wget http://www.libsdl.org/projects/SDL_net/release/SDL2_net-2.0.0.tar.gz
#tar -xvf SDL2_net-2.0.0.tar.gz
#cd SDL2_net-2.0.0
#./configure
#make install
#cd ..

echo ***** SDL_ttf ********
#wget http://libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.12.tar.gz
#tar -xvf SDL2_ttf-2.0.12.tar.gz
#cd SDL2_ttf-2.0.12
#./configure
#make install
#cd ..

echo *****  compile test app *****
#wget http://lazyfoo.net/tutorials/SDL/39_tiling/39_tiling.zip
unzip 39_tiling.zip

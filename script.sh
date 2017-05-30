sudo apt-get update
sudo apt-get git-core libnss-mdns libavahi-compat-libdnssd-dev.
wget https://nodejs.org/dist/latest-v7.x/node-v7.10.0-linux-armv7l.tar.gz 
tar -xvf node-v7.10.0-linux-armv7l.tar.gz 
cd node-v7.10.0-linux-armv7l.tar.gz 
sudo cp -R * /usr/local/
cd ..
sudo npm config set registry http://registry.npmjs.org/
sudo npm install -g node-gyp

sudo git clone https://github.com/KhaosT/HAP-NodeJS.git

cd HAP-NodeJS

sudo npm rebuild
sudo npm install
sudo node Core.js

cd
sudo wget https://goo.gl/YxjrLJ
sudo mv YxjrLJ setupLight
sudo chmod +x setupLight
sudo chmod 777 setupLight
sudo ./setupLight
cd HAP-NodeJS
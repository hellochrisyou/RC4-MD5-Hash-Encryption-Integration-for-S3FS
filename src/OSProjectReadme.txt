Go to S3FS Folder and "make" to compile

below are configurations and commands used for this particular assigment:



diff original.jpeg different.jpeg -s

openssl rc4 -e -nosalt -nopad -md md5 -k remember -in check.jpeg -out different.jpeg

//compiling standalone RC4
g++ -g md5.cpp -lssl -lcrypto

//adding bash directory path
PATH=$PATH:/home/chris/s3fs-fuse-master/s3fs-fuse/src

//mounting
s3fs chrisyoubucket ~/s3fs-fuse-master/s3fs-fuse/mountpoint -o passwd_file=~/passwd.passwd-s3fs -o umask=0000 -o allow_other

//unmount
sudo umount /home/chris/s3fs-fuse-master/s3fs-fuse/mountpoint

fusermount -u ~/s3fs-fuse-master/s3fs-fuse/mountpoint

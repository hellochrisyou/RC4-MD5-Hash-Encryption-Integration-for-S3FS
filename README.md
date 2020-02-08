<img  src="https://chrisyou-backup-website.s3.amazonaws.com/assets/github-preview/s3fs/final-s3fs.png" width="100%"/>

# Development
1. Programmed stand-alone rc4 + md5 hash (algorithm used from open-ssl library) encryption program that would encrypt and decrypt any type of file.
2. Installed S3FS on Linux machine
3. Implemented stand-alone algorithm into s3fs code-base 
4. Registered S3 bucket in AWS as remote storage for S3FS

# Result
1. Mount bucket onto local drive
2. Place any type of file into the mounted bucket (encrypted or decrypted)
3. Check S3 bucket for file to see if it the encryption/decryption was reversed.
4. Tested a file vice versa, placing file in s3 bucket.
<img  src="https://chrisyou-backup-website.s3.amazonaws.com/assets/S3FS/s3fs-ebs.png" width="100%"/>


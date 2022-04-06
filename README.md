<img  src="https://chrisyou-backup-website.s3.amazonaws.com/assets/github-preview/s3fs/final-s3fs.png" width="100%"/>

## Development
1. Developed (in C) a stand-alone RC4 + MD5 Hash (algorithm used from open-ssl library) encryption program that would encrypt and decrypt any type of file (including images)
<img  src="https://storage.googleapis.com/static-images-703/S3FS-Stand-Alone.png" width="50%"/>
2. S3FS installed in a <b>Linux</b> environment
<img  src="https://storage.googleapis.com/static-images-703/S3fS-install-s3fs.png" width="35%"/>
3. Integrate stand-alone algorithm (RC4 + MD5 Hash) into S3FS code-base (which would <b>enable encrypting/decrypting any files that is modified in a mounted bucket</b>)
### Superimpose the stand-alone algorithm (from step #1) within S3FS pre-existing codebase
#### Function Implementation
<img  src="https://storage.googleapis.com/static-images-703/S3FS-implementation-2.png" width="50%"/>
<hr>
#### Calling Function
<img  src="https://storage.googleapis.com/static-images-703/S3FS-implementation-2.png" width="50%"/>
<hr>
#### Calling Function
<img  src="https://storage.googleapis.com/static-images-703/S3FS-implementation-3.png" width="50%"/>
<hr>
4. Registered S3 bucket in AWS as remote storage for S3FS
## Result
1. Mount bucket onto local drive
2. Place any type of file into the mounted bucket (encrypted or decrypted)
3. Check S3 bucket for file to see if it the encryption/decryption was reversed
4. Tested a file vice versa, placing file in s3 bucket
## Infrastructure
<img  src="https://chrisyou-backup-website.s3.amazonaws.com/assets/S3FS/s3fs-diagram.png" width="100%"/>

The below diagram, shows how both EBS and S3 buckets appears to a Linux operating system.
<img  src="https://chrisyou-backup-website.s3.amazonaws.com/assets/S3FS/s3fs-ebs.png" width="50%"/>


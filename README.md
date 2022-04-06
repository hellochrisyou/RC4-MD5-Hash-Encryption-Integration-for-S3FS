/play secret
<img  src="https://chrisyou-backup-website.s3.amazonaws.com/assets/github-preview/s3fs/final-s3fs.png" width="100%"/>

<h2>Development</h2>
1. Developed (in C) a stand-alone RC4 + MD5 Hash (algorithm used from open-ssl library) encryption program that would encrypt and decrypt any type of file (including images)
<img  src="https://storage.googleapis.com/static-images-703/S3FS-Stand-Alone.png" width="50%"/>
2. S3FS installed in a <b>Linux</b> environment
<blockquote><b>sudo apt-get install s3fs</b></blockquote>
3. Integrate stand-alone algorithm (RC4 + MD5 Hash) into S3FS code-base (which would <b>enable encrypting/decrypting any files that is modified in a mounted bucket</b>)
<br>
<br>
<ul>
<li>RC4/MD5 Implementation
<img  src="https://storage.googleapis.com/static-images-703/S3FS-implementation-1.png" width="100%"/>
</li>
<br>
<li>Implementing RC4/MD5 Function
<img  src="https://storage.googleapis.com/static-images-703/S3FS-implementation-2.png" width="100%"/>
</li>
<li>Implementing RC4/MD5 Function
<img  src="https://storage.googleapis.com/static-images-703/S3FS-implementation-3.png" width="100%"/>
</li>
</ul>
<br>
4. Generate the access key ID and secret access key in AWS
5. <img  src="https://storage.googleapis.com/static-images-703/S3FS-key.png" width="50%"/>
6. Registered S3 bucket in AWS as remote storage for S3FS
<br>
<br>
<h2>Result</h2>
1. Mount bucket onto local drive
2. Place any type of file into the mounted bucket (encrypted or decrypted)
3. Check S3 bucket for file to see if it the encryption/decryption was reversed
4. Tested a file vice versa, placing file in s3 bucket
<br>
<br>
<h2>Infrastructure</h2>
<img  src="https://chrisyou-backup-website.s3.amazonaws.com/assets/S3FS/s3fs-diagram.png" width="100%"/>

The below diagram, shows how both EBS and S3 buckets appears to a Linux operating system.
<img  src="https://chrisyou-backup-website.s3.amazonaws.com/assets/S3FS/s3fs-ebs.png" width="50%"/>


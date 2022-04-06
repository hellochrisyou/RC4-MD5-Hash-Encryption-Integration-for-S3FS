<img  src="https://chrisyou-backup-website.s3.amazonaws.com/assets/github-preview/s3fs/final-s3fs.png" width="100%"/>
<h2>Technical Background</h2>
<blockquote>
<br>  Amazon S3 (Simple Storage Services) is a scalable cloud storage service from Amazon Web Services (AWS) used by many customers in the world. The basic unit of data storage in Amazon S3 is a bucket. You can create multiple buckets in Amazon S3 cloud storage and configure permissions for users who need to access the buckets. By default, users can access data stored in Amazon S3 buckets by using the AWS web interface.
<br><br>  However, a user may need to access a bucket in Amazon S3 cloud by using the interface of an operating system such as Linux or Windows. Access to Amazon S3 cloud storage from the command line of an operating system is useful for working in operating systems that don’t have a graphical user interface (GUI), in particular <i>virtual machines running in the public cloud. <b>It is also useful for automating tasks such as copying files or making data backups.</b></i> 
 <br><br>  <b>This readme explains how to mount Amazon S3 cloud storage to a local directory on a Linux machine to allow using Amazon S3 for file sharing without a web browser.</b> 
 <br><br>  S3FS, a special solution based on FUSE (file system in user space), was developed to mount S3 buckets to directories of Linux operating systems <b><i>similarly to the way you mount CIFS or NFS share as a network drive.</i>/</b> S3FS is a free and open source solution. After mounting Amazon S3 cloud storage with S3FS to your Linux machine, you can use cp, mv, rm, and other commands in the Linux console to operate with files as you do when working with mounted local or network drives. 
</blockquote>
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
6. Go back to the Ubuntu console to create a configuration file for storing the AWS access key and secret access key needed to mount an S3 bucket with S3FS.
<blockquote><b>echo ACCESS_KEY:SECRET_ACCESS_KEY > PATH_TO_FILE</b></blockquote>
7. Set correct permissions for the passwd-s3fs file where the access keys are stored:
<blockquote><b>chmod 600 ~/.passwd-s3fs</b></blockquote>
8. Create the directory (mount point) that will be used as a mount point for your S3 bucket
<blockquote><b>mkdir ~/s3-bucket</b></blockquote>
9. Register S3 bucket in AWS as remote storage for S3FS
<blockquote><b>s3fs bucket-name /path/to/mountpoint -o passwd_file=/path/passwd-s3fs</b></blockquote>
<br>
<br>
<h2>Validation</h2>
<div>1. Mount bucket onto local drive</div>
<div>2. Place any type of file into the mounted bucket (encrypted or decrypted)</div>
<div>3. Check S3 bucket for file to see if it the encryption/decryption was reversed</div>
<div>4. Tested a file vice versa, placing file in s3 bucket</div>
<br>
<br>
<h2>Infrastructure Diagram</h2>
<img  src="https://chrisyou-backup-website.s3.amazonaws.com/assets/S3FS/s3fs-diagram.png" width="100%"/>

The below diagram, shows how both EBS and S3 buckets appears to a Linux operating system.
<img  src="https://chrisyou-backup-website.s3.amazonaws.com/assets/S3FS/s3fs-ebs.png" width="50%"/>



/play secret
<img  src="https://chrisyou-backup-website.s3.amazonaws.com/assets/github-preview/s3fs/final-s3fs.png" width="100%"/>

<h2>Development</h2>
1. Developed (in C) a stand-alone RC4 + MD5 Hash (algorithm used from open-ssl library) encryption program that would encrypt and decrypt any type of file (including images)
<img  src="https://storage.googleapis.com/static-images-703/S3FS-Stand-Alone.png" width="50%"/>
2. S3FS installed in a <b>Linux</b> environment
<img  src="https://storage.googleapis.com/static-images-703/S3fS-install-s3fs.png" width="35%"/>
3. Integrate stand-alone algorithm (RC4 + MD5 Hash) into S3FS code-base (which would <b>enable encrypting/decrypting any files that is modified in a mounted bucket</b>)
<br>
<br>
<ul>
<li>RC4/MD5 Implementation
```//Encryption-Decryption Function
void convert(int fd){
string pass = "convert";

//md5 hashing
unsigned char digest[MD5_DIGEST_LENGTH];
char in[sizeof(pass)];
strcpy(in,pass.c_str());
MD5((unsigned char*)&in, strlen(in), (unsigned char*)&digest);

//read from file
int fileLength = lseek(fd, 0, SEEK_END);

unsigned char* fcontents;
fcontents = (unsigned char*) calloc(fileLength, sizeof(char));

if (0 == (pread(fd , fcontents, fileLength, 0))){
cout << "SORRY" << endl;
free (fcontents);
}

//convert to string
string change(reinterpret_cast<char const*>(fcontents), fileLength);

//encryption-decryption
RC4_KEY key;
int length = change.length();
unsigned char *buff = (unsigned char*)malloc(length-1);
memset(buff, 0, length-1);
RC4_set_key(&key, sizeof(digest) ,(const unsigned char*)digest);
RC4(&key, length, (const unsigned char*)change.c_str(), buff);
string result((char*)buff, length);
pwrite(fd, result.c_str(), fileLength, 0);
free (buff);
}```
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
4. Registered S3 bucket in AWS as remote storage for S3FS
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


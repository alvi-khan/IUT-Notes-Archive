#!/bin/sh

echo 'Please modify File1.txt before continuing.'

echo 'Please enter a directory: '
read newPath
cp ./parent/sub1/sub2/sub3/child/File1.txt $newPath/File2.txt

chmod u+wx,g+wx,o+wx  ./parent/sub1/sub2/sub3/child/File1.txt
chmod u+wx,g+wx,o+wx  $newPath/File2.txt
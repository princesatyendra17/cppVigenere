#!/bin/bash

if [ -f vigenere ]
	then
		build=$((`sed -r 's/^([0-9]+\.){2}/''/g' version` + 1))
		version=`sed -r "s/[0-9]+$/$build/g" version`
		echo "Version updated to $version"
		echo $version > version
fi

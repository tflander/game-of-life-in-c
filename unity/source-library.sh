#!/bin/sh

LIBRARYSRC=../unity-src

git clone https://github.com/ThrowTheSwitch/Unity.git ${LIBRARYSRC}

cp ${LIBRARYSRC}/src/* .
cp ${LIBRARYSRC}/extras/fixture/src/* .

rm -rf ${LIBRARYSRC}
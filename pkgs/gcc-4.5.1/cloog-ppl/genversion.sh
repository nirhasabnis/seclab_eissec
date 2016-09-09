#! /bin/sh
srcdir=/media/work_stonybrook/labwork/gcc-4.5.1/cloog-ppl
PACKAGE=cloog
VERSION=0.15

if test -f $srcdir/.git/HEAD; then
    GIT_REPO="$srcdir/.git"
    GIT_HEAD_ID=`GIT_DIR=$GIT_REPO git describe`
elif test -f $srcdir/CLOOG_HEAD; then
    GIT_HEAD_ID=`cat $srcdir/CLOOG_HEAD`
else
    GIT_HEAD_ID="$PACKAGE-$VERSION-UNKNOWN"
fi

echo $GIT_HEAD_ID | sed -e 's/cloog-//'

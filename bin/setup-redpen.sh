#!/bin/bash

URL=https://api.github.com/repos/redpen-cc/redpen/releases/latest
OUTPUT_TEMP_FILE=redpen.json

curl -s $URL > $OUTPUT_TEMP_FILE

FILE_NAME=`cat $OUTPUT_TEMP_FILE | jq -r ".assets[] | select (.name | test(\"${spruce_type}\")) | .name"`
DOWNLOAD_URL=`cat $OUTPUT_TEMP_FILE | jq -r ".assets[] | select (.name | test(\"${spruce_type}\")) | .browser_download_url"`

curl -OL $DOWNLOAD_URL
tar xvf $FILE_NAME
rm $FILE_NAME $OUTPUT_TEMP_FILE

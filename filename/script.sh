#
#
# Script to print user information who currently login , current date & time
#

#!/usr/bin/env bash
end=$(date -d "10 minutes" +%s);

## Run until the desired time has passed.
while [ $(date +%s) -lt "$end" ]; do 
    ## Launch a new wget process if there are
    ## less than 70 running. This assumes there
    ## are no other active wget processes.
    if [ $(pgrep -c wget) -lt 70 ]; then
        wget www.facebook.com 2>/dev/null &
    fi
done# Edit this to be the username 
 

#!/bin/bash

# Production Web Server Log Cleanup Script
# Tasks:
# 1. Mask 16-digit credit card numbers
# 2. Replace HTTP/1.0 with HTTP/1.1
# 3. Remove comment lines starting with #

LOG_FILE="server_access.log"

# Check if log file exists
if [ ! -f "$LOG_FILE" ]; then
    echo "Error: $LOG_FILE not found."
    exit 1
fi

# Perform cleanup in-place
sed -i \
-e 's/\([0-9]\{4\}\)-\?[0-9]\{4\}-\?[0-9]\{4\}-\?[0-9]\{4\}/XXXX-XXXX-XXXX-XXXX/g' \
-e 's/HTTP\/1\.0/HTTP\/1.1/g' \
-e '/^#/d' \
"$LOG_FILE"

echo "Log cleanup completed successfully."

#!/bin/sh
# Usage: compile_and_report.sh <CC> <CFLAGS> <SRC> <OUT> <TOTAL> <BUILD_DIR>
CC="$1"
CFLAGS="$2"
SRC="$3"
OUT="$4"
TOTAL="$5"
BUILD_DIR="$6"

mkdir -p "$(dirname "$OUT")"

# compile quietly, but capture output on failure
if ! $CC $CFLAGS -c "$SRC" -o "$OUT" >/tmp/compile.log 2>&1; then
    printf "\n\033[31m[ERROR] Compilation failed for %s\033[0m\n" "$SRC"
    cat /tmp/compile.log
    exit 1
fi

# update counter
count_file="$BUILD_DIR/count"
if [ ! -f "$count_file" ]; then
    echo 0 > "$count_file"
fi

# increment atomically
prev=$(cat "$count_file")
new=$((prev + 1))
echo "$new" > "$count_file"

percent=$(( new * 100 / TOTAL ))

# print progress (carriage return)
printf "\r\033[35m[BUILD]\033[0m %d/%d (%d%%) %s" "$new" "$TOTAL" "$percent" "$(basename "$SRC")"

# once done, print newline
if [ "$new" -eq "$TOTAL" ]; then
    printf "\n"
fi

exit 0

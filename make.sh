# Gets all files that end in .h and .cpp
files="$(find . -type f | grep -v '\./\.git' | grep -v "\.gch" | grep -E '\.cpp|\.h|\.hpp|\.cxx|\.cc|\.hh|\.hxx' | sort -r | sed -n -e 'H;${x;s/\n/ /g;s/^,//;p;}')"

g++ $files -lcurses -Wall -Wextra -Werror -o cge.out

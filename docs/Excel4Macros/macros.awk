#!/usr/bin/awk -f

BEGIN {
	print "# Index of Excel 4 Macro Functions" > "README.md"
	print >> "README.md"
}


/^Return to/ { skip }
/==/ {
	if (file) {
		#print "Previous ["file"]("file".md)  "
		print "close "file".md"
		close(file".md")
		print "["file"]("file".md)  " >> "README.md"
	}
	file = prev
	print file > file".md"
	print $0 >> file".md"
}
!/==/ {
	prev = $1
	gsub(/,/, "", prev)
	print >> file".md"
 }
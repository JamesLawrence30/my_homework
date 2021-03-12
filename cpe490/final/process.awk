BEGIN {
	milliseconds = 0
	average = 0

	count = 1
	newline = "\n* * * * * * * *\n"
	print newline, "#", count
}

{
	if($1 == "traceroute" && milliseconds != 0) {
		print "\nSeconds:", milliseconds/1000
		count++
		print newline, "#", count
	}

	else if($5 == "ms" && $9 == "ms" && $13 == "ms") {
		print $3
		average = ($4 + $8 + $12) / 3
		print "Time:", average
		milliseconds = milliseconds + average
	}

	else if($5 == "ms" && $7 == "ms" && $9 == "ms") {
		print $3
		average = ($4 + $6 + $8) / 3
		print "Time:", average
		milliseconds = milliseconds+ $4 + $6 + $8
	}

	else if($5 == "ms" && $7 == "ms") {
		print $3
		average = ($4 + $6) / 3
		print "Time:", average
		milliseconds = milliseconds+ $4 + $6
	}

	else {
	}
}

END {
		print "\nSeconds:", milliseconds/1000
		count++
		print newline

}

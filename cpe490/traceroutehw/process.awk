BEGIN {
	ORS=",\n"
}

{
	if($5 == "ms" && $7 == "ms" && $9 == "ms") {
		print $4
		print $6
		print $8
	}
	else if($5 == "ms" && $7 == "ms") {
		print $4
		print $6
	}
	else {
	}
}

END {
}

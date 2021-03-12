BEGIN {
	minTime = 999999999

	count = 0
	bestRouteCount = 0
}

{
	if($1 == "Seconds:" && $2 < minTime) {
		minTime = $2
		bestRouteCount = count
	}

	else if($1 == "*") {
		count++
	}

	else {
	}
}

END {
	print "Best route is #", bestRouteCount
	print "In time:", minTime
}

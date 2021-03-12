BEGIN {
	arr[3]
}

{
	if ($1 == 64){
		split($8, arr,"=")
		print arr[2]
	}
}

END {
}

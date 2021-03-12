BEGIN {
	arr[4]
}

{
	if ($1 == 64){
		
		split($8, arr,"=")
		a = arr[2]

		split($6, arr,"=")
		b = arr[2]
		
		print(b,",",a,",")
	}
}

END {
}

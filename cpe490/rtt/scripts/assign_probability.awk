BEGIN{
	MAX=86400
	count=0
}

{
	count++
	print $1, count/MAX
}

END{

}

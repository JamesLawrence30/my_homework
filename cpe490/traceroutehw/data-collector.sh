for ((i=0;i<288;i++))
do
	echo "Performing traceroute # $i"
	traceroute moskva.beeline.ru >> raw_data
	sleep 15s
done

for ((i=1;i<6;i++))
do
	echo "Performing traceroute # $i"
	traceroute moskva.beeline.ru >> raw_data
	sleep 2s
done

awk -f process.awk raw_data > processed_data

awk -f best_route.awk processed_data > best_route

echo ""
cat best_route
ping -c 10 www.walmart.com > bash_raw_data
awk -f process.awk bash_raw_data | sort -n > bash_sorted_data
awk -f assign_probability.awk bash_sorted_data  > bash_cdf_ready

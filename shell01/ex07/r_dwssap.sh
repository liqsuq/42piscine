cat /etc/passwd | sed '/^#/d' | awk 'NR%2==0' | awk -F: '{print $1}' | rev | sort -r | awk "NR==$FT_LINE1,NR==$FT_LINE2" | sed -z 's/\n/, /g' | sed 's/, $/./'

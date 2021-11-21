BEGIN {print "Start to scan file"}
{print $1 "," $NF}
END{print "END-", FILENAME}

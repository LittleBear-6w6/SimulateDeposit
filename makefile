semiannual-compounding: semiannual-compounding.c
	$(CC) --coverage -o semiannual-compounding semiannual-compounding.c
	
test: semiannual-compounding
	./semiannual-compounding < Test/testinput.txt >testoutput.txt
	if diff testoutput.txt Test/indicator.txt ; then echo "Result:OK"; echo 0 ; else echo "Result:NG"; exit 1; fi

clean: 
	rm -f testoutput.txt semiannual-compounding

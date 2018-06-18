#------------------------------------------------------------------------------
#
#
#------------------------------------------------------------------------------

build:
	gcc main.c expAvg.c -o main

clean:
	rm -rf main expAvg_log.csv

iterate:
	make clean && make build && ./main

plot:
	python3 ./python/plot_data.py expAvg_log.csv

all: countingRhyme

countingRhyme: operationsForList.o countingRhyme.o
	gcc -Wall -Wextra -O3 operationsForList.o countingRhyme.o -o countingRhyme

operationsForList.o: operationsForList.c
	gcc -Wall -Wextra -O3 -c operationsForList.c

countingRhyme.o: countingRhyme.c
	gcc -Wall -Wextra -O3 -c countingRhyme.c

clean:
	rm -f *.o countingRhyme
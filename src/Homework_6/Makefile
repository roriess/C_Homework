all: sortedList

sortedList: operationsForSortedList.o sortedList.o
	gcc -Wall -Wextra -O3 operationsForSortedList.o sortedList.o -o sortedList

operationsForSortedList.o: operationsForSortedList.c
	gcc -Wall -Wextra -O3 -c operationsForSortedList.c

sortedList.o: sortedList.c
	gcc -Wall -Wextra -O3 -c sortedList.c

clean:
	rm -f *.o sortedList

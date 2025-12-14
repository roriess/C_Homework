all: balanceCheck

balanceCheck: advancedBalanceOfBrackets.o implementationOfStack.o
	gcc -Wall -Wextra advancedBalanceOfBrackets.o implementationOfStack.o -o balanceCheck

advancedBalanceOfBrackets.o: advancedBalanceOfBrackets.c
	gcc -Wall -Wextra -c advancedBalanceOfBrackets.c

implementationOfStack.o: implementationOfStack.c
	gcc -Wall -Wextra -c implementationOfStack.c

clean:
	rm -f *.o balanceCheck

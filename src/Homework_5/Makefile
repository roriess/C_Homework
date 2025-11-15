all: shuntingYard

shuntingYard: checkingForASymbol.o implementationOfStack.o shuntingYard.o
	gcc -Wall -Wextra checkingForASymbol.o implementationOfStack.o shuntingYard.o -o shuntingYard

checkingForASymbol.o: checkingForASymbol.c
	gcc -Wall -Wextra -c checkingForASymbol.c

shuntingYard.o: shuntingYard.c
	gcc -Wall -Wextra -c shuntingYard.c

implementationOfStack.o: implementationOfStack.c
	gcc -Wall -Wextra -c implementationOfStack.c

clean:
	rm -f *.o shuntingYard

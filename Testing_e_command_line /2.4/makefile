esegui_testsuite.out: utili.o vettore.o esegui_test.out test_suite.o
		gcc utili.o vettore.o test_suite.o -o esegui_testsuite.out
esegui_test.out: utili.o vettore.o test_somma_vet.o
		gcc utili.o vettore.o test_somma_vet.o -o esegui_test.out
utili.o: utili.c
		gcc -c utili.c
vettore.o: vettore.c
		gcc -c vettore.c
test_somma_vet.o: test_somma_vet.c
		gcc -c test_somma_vet.c
esegui_testsuite.o: esegui_testsuite.c
		gcc -c esegui_testsuite.c
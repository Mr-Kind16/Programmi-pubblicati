esegui_testsuite.out: utili.o test_suite.o esegui_test.out
		gcc utili.o test_suite.o -o esegui_testsuite.out
		
esegui_test.out: utili.o vettore.o test_inserisci_elemento.o
		gcc utili.o vettore.o test_inserisci_elemento.o -o esegui_test.out
test_suite.o: test_suite.c
		gcc -c test_suite.c
utili.o: utili.c
		gcc -c utili.c
vettore.o: vettore.c
		gcc -c vettore.c
test_inserisci_elemento.o: test_inserisci_elemento.c
		gcc -c test_inserisci_elemento.c
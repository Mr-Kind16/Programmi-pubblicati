esegui_testsuit.out: utili.o test_suit.o esegui_test.out
		gcc utili.o test_suit.o -o esegui_testsuit.out
		
esegui_test.out: utili.o vettore.o test_ordina_array.o
		gcc utili.o vettore.o test_ordina_array.o -o esegui_test.out
test_suit.o: test_suit.c
		gcc -c test_suit.c
utili.o: utili.c
		gcc -c utili.c
vettore.o: vettore.c
		gcc -c vettore.c
test_ordina_array.o: test_ordina_array.c
		gcc -c test_ordina_array.c
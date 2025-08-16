CC=gcc
CFLAGS=-Wall -Wextra -g

# Diretórios
Q1_DIR=questao01
Q2_DIR=questao02-03
Q4_DIR=questao04

# Alvos
all: menu questao01/questao01.o questao02-03/questao02-03.o questao04/questao04.o

menu: menu.c
	$(CC) $(CFLAGS) -o menu.o menu.c

$(Q1_DIR)/questao01.o: $(Q1_DIR)/questao01.c $(Q1_DIR)/aluno.c $(Q1_DIR)/aluno.h
	$(CC) $(CFLAGS) -o $(Q1_DIR)/questao01.o $(Q1_DIR)/questao01.c $(Q1_DIR)/aluno.c

$(Q2_DIR)/questao02-03.o: $(Q2_DIR)/questao02-03.c $(Q2_DIR)/lista.c $(Q2_DIR)/lista.h
	$(CC) $(CFLAGS) -o $(Q2_DIR)/questao02-03.o $(Q2_DIR)/questao02-03.c $(Q2_DIR)/lista.c

$(Q4_DIR)/questao04.o: $(Q4_DIR)/questao04.c $(Q4_DIR)/pilha.c $(Q4_DIR)/pilha.h
	$(CC) $(CFLAGS) -o $(Q4_DIR)/questao04.o $(Q4_DIR)/questao04.c $(Q4_DIR)/pilha.c

clean:
	rm -f menu $(Q1_DIR)/*.o $(Q2_DIR)/*.o $(Q4_DIR)/*.o

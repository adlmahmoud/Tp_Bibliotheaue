# --- VARIABLES ---
CC = gcc
CFLAGS = -Wall -Wextra -Iinc
# -Iinc dit à gcc de chercher les .h dans le dossier inc/

# Fichiers sources et objets
SRC = src/main.c src/bibliotheque.c
OBJ = obj/main.o obj/bibliotheque.o
EXEC = bin/app

# --- REGLES ---

# Cible par défaut (ce qui se lance quand tu tapes 'make')
all: $(EXEC)

# Création de l'exécutable (Linkage)
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compilation de main.c en main.o
obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

# Compilation de bibliotheque.c en bibliotheque.o
obj/bibliotheque.o: src/bibliotheque.c
	$(CC) $(CFLAGS) -c src/bibliotheque.c -o obj/bibliotheque.o

# Nettoyage (pour recommencer à zéro)
clean:
	rm -f obj/*.o bin/*

# Règle pour lancer directement
run: all
	./$(EXEC)
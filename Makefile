# 1. VARIABILI PRINCIPALI
CC       = cc
CFLAGS   = -Wall -Wextra -Werror
TARGET   = a.out

# 2. SELEZIONE AUTOMATICA DEI FILE
# Trova tutti i file .c nella cartella corrente
SRCS     = $(wildcard *.c)
# Sostituisce l'estensione .c con .o per i file oggetto
OBJS     = $(SRCS:.c=.o)

# 3. REGOLE DI COMPILAZIONE
.PHONY: all clean run

# Regola di default (eseguita quando scrivi solo 'make')
all: $(TARGET)

# Link dell'eseguibile finale
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilazione dei singoli file .c in .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 4. PULIZIA DEI FILE GENERATI
clean:
	rm -f $(OBJS) $(TARGET)

# 5. REGOLA PER COMPILARE AVVIARE RAPIDAMENTE
run: all
	./$(TARGET)

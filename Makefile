CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPS = enfermagem/enfermagem.h medico/medico.h pasciente/pasciente.h
OBJ = output/ED-lista2-questao01.o output/enfermagem/enfermagem.o output/medico/medico.o output/pasciente/pasciente.o
EXECUTABLE = output/ED-lista2-questao01

output/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)

compilar: 
		if not exist output\enfermagem (mkdir output\enfermagem)
		if not exist output\medico (mkdir output\medico)
		if not exist output\pasciente (mkdir output\pasciente)
		$(MAKE) $(EXECUTABLE)

exec: compilar
		./$(EXECUTABLE)
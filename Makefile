CC := gcc

football.exe: football.c football_main.c
	$(CC) -o football.exe football_main.c football.c
	./football.exe

temperature.exe: temperature.c temperature_main.c
	$(CC) -o temperature.exe temperature_main.c temperature.c
	./temperature.exe

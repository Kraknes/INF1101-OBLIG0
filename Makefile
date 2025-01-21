CC = gcc
BIN = bin/app

SRC := $(wildcard src/*.c) #kan legge til flere filer her også, wildcard tar alle filer som slutter på *.c
# := expande til hele uttrykket med en gang, = recursive expanding, må sette variabler etterhvert før den blir brukt 
OBJ := $(patsubst src/%.c, obj/%.o, $(SRC)) # linker objekter til programmer, % linker er lik typ wildcard (*), endrer alle c filer i /src til til obj/ med .o fil

CFLAGS += -g -Og #legger til alle variabler / -Og er optimalisering for debugging
 # c2x er en C standar, jo nyere versjon jo mer inkludert. fjern denne eller oppdater før oppgaven din

.PHONY: all
.PHONY: clean
.PHONY: debug
.PHONY: dirs
.PHONY: distclean

all: dirs $(BIN)

$(BIN): $(SRC) #Den filen er avhengig av SRC mappa
	$(CC) $(CFLAGS) $(SRC) -Iinclude -o $(BIN) 
#"-Iinclude finner aller filer i mappen" 


debug: 
	echo Hello debug


dirs:
	mkdir -p bin
	mkdir -p obj

clean: $(BIN)
	rm ./bin/*.exe

distclean:
	rm -rf bin
	rm -rf obj
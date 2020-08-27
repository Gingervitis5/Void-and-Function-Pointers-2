CC = gcc

MAIN = cscd240Lab15.c

EXE = lab15

all:	$(EXE)

$(EXE):	./utils/fileUtils.c ./utils/fileUtils.h ./utils/utils.c ./utils/utils.h ./words/word.c ./words/word.h ./genericArray/genericArray.c ./genericArray/genericArray.h $(MAIN)
	${CC} -m32 ./utils/fileUtils.c ./utils/utils.c ./words/word.c ./genericArray/genericArray.c $(MAIN) -o $(EXE)


clean:
	rm -rf lab15

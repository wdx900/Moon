objects = main.o utf8-character.o base-character.o gbk-character.o buffer-pool.o file-reader.o base-tokenizer.o ngram-tokenizer.o
#objects = %.o:%.cpp

moon:$(objects)
	g++ -o $@ $^ -I./include/

main.o:./src/main.cpp ./include/utf8-character.h ./include/trie-node.h
	g++ -c ./src/main.cpp -I./include/ 

utf8-character.o:./src/utf8-character.cpp ./include/utf8-character.h 
	g++ -c $< -I./include/ 

gbk-character.o:./src/gbk-character.cpp ./include/gbk-character.h
	g++ -c $< -I./include/ 

base-character.o:./src/base-character.cpp ./include/base-character.h
	g++ -c $< -I./include/

buffer-pool.o:./src/buffer-pool.cpp ./include/buffer-pool.h
	g++ -c $< -I./include/

file-reader.o:./src/file-reader.cpp ./include/file-reader.h
	g++ -c $< -I./include/

base-tokenizer.o:./src/base-tokenizer.cpp ./include/base-tokenizer.h
	g++ -c $< -I./include/

ngram-tokenizer.o:./src/ngram-tokenizer.cpp ./include/ngram-tokenizer.h
	g++ -c $< -I./include/ 


clean:
	rm -rf test $(objects) 


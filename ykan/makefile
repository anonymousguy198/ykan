#this is the makefile to compile YKAN

#compiler
cc=gcc
#output file name
outputFileName=ykan
#build stabile

stabile:
	$(cc) main.c init/init.c -lglfw -lvulkan -o $(outputFileName)

debug:
	$(cc) main.c init/init.c -lglfw -lvulkan -o $(outputFileName)

#quic test build and run
test:
	$(cc) main.c init/init.c -lglfw -lvulkan -o $(outputFileName)
	./$(outputFileName)

	#removes th file after it stops running
	rm $(outputFileName)

clean:
	rm $(outputFileName)

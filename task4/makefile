#This is a comment

OBJ=test.o curve.o

TARGET=a.exe

#This compiles each c file into an object file
%.o: %.c
	gcc -c -o $@ $< #compile program on the right($<) to program on the left($@)

#This links the objects into an exectuable
# -o mean: "output file name"
$(TARGET): $(OBJ)
	gcc -o $@ $^

#to compile type "make program" in command
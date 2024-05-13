windows:
	g++ -Iinclude -Iinclude/GLFW -Iinclude/glad -Iinclude/headers -Llib -o main src/*.cpp src/*.c -lglfw3dll

linux:
	g++ -Iinclude -Iinclude/GLFW -Iinclude/glad -Iinclude/headers -o main src/*.cpp src/*.c -lglfw -lGL -ldl -lm -lpthread -lX11 -lXrandr -lXi -lXxf86vm

clean:
	rm -rf main *.o *.exe

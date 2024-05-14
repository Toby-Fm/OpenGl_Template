windows:
	g++ -Iinclude -Iinclude/GLFW -Iinclude/glad -Iinclude/headers -Llib -o main src/*.cpp src/*.c -lglfw3dll

linux:
	g++ -Iinclude -Iinclude/GLFW -Iinclude/glad -Iinclude/headers -o main src/*.cpp src/*.c -lglfw -lGL -ldl -lm -lpthread -lX11 -lXrandr -lXi -lXxf86vm

clean:
	rm -rf main *.o *.exe

linux-install:
	sudo apt-get install build-essential cmake -y
	mkdir -p ~/Downloads/repos
	git clone https://github.com/glfw/glfw.git ~/Downloads/repos/glfw
	sudo apt-get install libglfw3-dev libglfw3 libxi-dev libxkbcommon-dev libxxf86vm-dev libgl1-mesa-dev xorg-dev libxinerama-dev libxcursor-dev -y
	cd ~/Downloads/repos/glfw && cmake -S . -B build && cmake --build build && sudo cmake --install build
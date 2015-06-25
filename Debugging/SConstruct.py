Program(target="Example01", source=["Example01.cpp"], CCFLAGS = ['-fno-stack-protector', '-std=c++11', '-g'])
Program(target="Example02", source=["Example02.cpp"], CCFLAGS = ['-w', '-std=c++11', '-g', '-O0'])
Program(target="Example03", source=["Example03.cpp"], CCFLAGS = ['-std=c++11', '-g'])
Program(target="Example04", source=["Example04.cpp"], CCFLAGS = ['-std=c++11', '-g', '-O0'])
Program(target="Example05", source=["Example05.cpp"], CCFLAGS = ['-w', '-std=c++11', '-g'])
Program(target="Example06", source=["Example06.cpp"], CCFLAGS = ['-O0', '-std=c++11', '-g'], LINKFLAGS = ['-pg'])


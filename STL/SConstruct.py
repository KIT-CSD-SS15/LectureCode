import glob
import os

for source_file in glob.glob('*.cpp'):
    Program(target=os.path.splitext(source_file)[0], source=[source_file], CCFLAGS="-std=c++11 -Wall")



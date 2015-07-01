import os
import glob

thread_link_flags = ['-pthread'] if 'Linux' in os.uname() else []
cc_flags = ['-std=c++11']

for source in glob.glob('*.cpp'):
    Program(target=source.split('.')[0], source=[source],
            CCFLAGS = cc_flags, LINKFLAGS = thread_link_flags)

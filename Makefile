CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
TARGET = praktik2

SOURCES = zadanievse/main.cpp \
          zadanievse/process/procmain.cpp \
          zadanievse/process/procmod.cpp \
          zadanievse/process/procdvoich.cpp \
          zadanievse/process/proc_ex_euclid.cpp \
          zadanievse/process/proc_ex_euclidC.cpp \
          zadanievse/process/proc_elgamal.cpp \
          zadanievse/mod/mod.cpp \
          zadanievse/mod/dvoich.cpp \
          zadanievse/optional/opional_func.cpp \
          zadanievse/euclid/ex_euclid.cpp \
          zadanievse/euclid/ex_euclidC.cpp \
          zadanievse/elgamal/encrypt.cpp \
          zadanievse/elgamal/decrypt.cpp \
          zadanievse/proc_console/encrypt_consol.cpp \
          zadanievse/proc_console/decrypt_console.cpp \
          zadanievse/proc_file/encrypt_file.cpp \
          zadanievse/proc_file/decrypt_file.cpp

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

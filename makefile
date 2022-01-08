# Makefile для программы testcmp
# Имя компилятора (cc или gcc для языка C, g++ для C++)
CC = g++
# Имя редактора связей (cc, gcc или g++)
# Вызывается через драйвер системы программирования, 
# когда на её вход подаются объектные модули
LD = g++
# Флаги компилятора
# -g — включить режим отладочной компиляции
# -Wall - вывод всех предупреждений и ошибок при компиляции 
# -pedantic – строгое соответствие стандарту языка
# -std=c++17 – стандарт языка программирования C++ исходных файлов 
CCFLAGS = -g -Wall -pedantic -std=c++17

# флаги связывающего загрузчика (не указаны) 
LDFLAGS =

# Выбор всех файлов *.cpp
CPP = $(wildcard *.cpp)

# Выбор всех файлов *.h
H = $(wildcard *.h)

# Объекты
OBJ = $(subst .cpp,.o,$(CPP))

# Варианты суффиксов
.SUFFIXES: .cpp .o

# Цели-действия
#.PHONY: all clean

# Исполняемый файл
PROG = testcmp

testcmp: testcmp.o mycomplex.o
	$(LD) $(LDFLAGS) -o testcmp testcmp.o mycomplex.o

testcmp.o: testcmp.cpp mycomplex.h
	$(CC) $(CCFLAGS) -c testcmp.cpp

mycomplex.o: mycomplex.cpp mycomplex.h
	$(CC) $(CCFLAGS) -c mycomplex.cpp

# Автоматическое удаление старых версий файлов компиляции
clean:
	rm -f $(OBJ) $(PROG) *.o

# Makefile ��� ��������� testcmp
# ��� ����������� (cc ��� gcc ��� ����� C, g++ ��� C++)
CC = g++
# ��� ��������� ������ (cc, gcc ��� g++)
# ���������� ����� ������� ������� ����������������, 
# ����� �� � ���� �������� ��������� ������
LD = g++
# ����� �����������
# -g � �������� ����� ���������� ����������
# -Wall - ����� ���� �������������� � ������ ��� ���������� 
# -pedantic � ������� ������������ ��������� �����
# -std=c++17 � �������� ����� ���������������� C++ �������� ������ 
CCFLAGS = -g -Wall -pedantic -std=c++17

# ����� ������������ ���������� (�� �������) 
LDFLAGS =

# ����� ���� ������ *.cpp
CPP = $(wildcard *.cpp)

# ����� ���� ������ *.h
H = $(wildcard *.h)

# �������
OBJ = $(subst .cpp,.o,$(CPP))

# �������� ���������
.SUFFIXES: .cpp .o

# ����-��������
#.PHONY: all clean

# ����������� ����
PROG = testcmp

testcmp: testcmp.o mycomplex.o
	$(LD) $(LDFLAGS) -o testcmp testcmp.o mycomplex.o

testcmp.o: testcmp.cpp mycomplex.h
	$(CC) $(CCFLAGS) -c testcmp.cpp

mycomplex.o: mycomplex.cpp mycomplex.h
	$(CC) $(CCFLAGS) -c mycomplex.cpp

# �������������� �������� ������ ������ ������ ����������
clean:
	rm -f $(OBJ) $(PROG) *.o

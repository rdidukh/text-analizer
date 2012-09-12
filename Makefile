SRC=./src
OUT=./out

CXX = g++
CXXFLAGS = -Wall
INCLUDE = ./include/
TARGET = text-analizer

all: $(SRC)/$(TARGET)

$(SRC)/$(TARGET): $(SRC)/main.o $(SRC)/Utf8.o
	$(CXX) $^ -o $(SRC)/$(TARGET)
	cp $(SRC)/*.o $(SRC)/$(TARGET) $(OUT)/

$(SRC)/main.o: $(SRC)/main.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -c -o $@

$(SRC)/Utf8.o: $(SRC)/Utf8.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -c -o $@

$(SRC)/main.cpp:
$(SRC)/Utf8.cpp:

clean:
	rm ./*~ $(INCLUDE)/*~ $(SRC)/*~ $(SRC)/*.o $(SRC)/$(TARGET) $(OUT)/*.o $(OUT)/$(TARGET)


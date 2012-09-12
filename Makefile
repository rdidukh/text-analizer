SRC=./src
OUT=./out

CXX = g++
CXXFLAGS = -Wall
INCLUDE = -I./include/
TARGET = text-analizer

all: $(TARGET)

$(TARGET): $(SRC)/main.o
	$(CXX) $^ -o $(SRC)/$(TARGET)
	cp $(SRC)/*.o $(SRC)/$(TARGET) $(OUT)/

main.o: $(SRC)/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(SRC)/$< -c -o $(SRC)/$@

main.cpp:

clean:
	rm $(SRC)/*~ $(SRC)/*.o $(SRC)/$(TARGET) $(OUT)/*.o $(OUT)/$(TARGET)


SRC=./src
#OUT=./out

CXX = g++
CXXFLAGS = -Wall
INCLUDE = ./include/
TARGET = text-analizer

all: $(SRC)/$(TARGET)

$(SRC)/$(TARGET): $(SRC)/main.o $(SRC)/Utf8Char.o $(SRC)/Utf8String.o
	$(CXX) $^ -o $(SRC)/$(TARGET)
#	cp $(SRC)/*.o $(SRC)/$(TARGET) $(OUT)/

$(SRC)/main.o: $(SRC)/main.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -c -o $@

$(SRC)/Utf8Char.o: $(SRC)/Utf8Char.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -c -o $@

$(SRC)/Utf8String.o: $(SRC)/Utf8String.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -c -o $@

$(SRC)/main.cpp:
$(SRC)/Utf8Char.cpp:
$(SRC)/Utf8String.cpp:

clean:
	rm ./*~ $(INCLUDE)/*~ $(SRC)/*~ $(SRC)/*.o $(SRC)/$(TARGET) # $(OUT)/*.o $(OUT)/$(TARGET)


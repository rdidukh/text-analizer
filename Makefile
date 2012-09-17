SRC=./src
#OUT=./out

CXX = g++
CXXFLAGS = -Wall
INCLUDE = ./include/
TARGET = text-analizer

all: $(TARGET)

$(TARGET): $(SRC)/main.o $(SRC)/Utf8Char.o $(SRC)/Utf8Charset.o $(SRC)/Utf8RussianAlphabetCharset.o $(SRC)/Utf8String.o
	$(CXX) $^ -o $(TARGET)
#	cp $(SRC)/*.o $(SRC)/$(TARGET) $(OUT)/

$(SRC)/main.o: $(SRC)/main.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -c -o $@

$(SRC)/Utf8Char.o: $(SRC)/Utf8Char.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -c -o $@

$(SRC)/Utf8Charset.o: $(SRC)/Utf8Charset.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -c -o $@

$(SRC)/Utf8RussianAlphabetCharset.o: $(SRC)/Utf8RussianAlphabetCharset.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -c -o $@

$(SRC)/Utf8String.o: $(SRC)/Utf8String.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -c -o $@

$(SRC)/main.cpp:
$(SRC)/Utf8Char.cpp:
$(SRC)/Utf8Charset.cpp:
$(SRC)/Utf8RussianAlphabetCharset.cpp:
$(SRC)/Utf8String.cpp:

clean:
	-rm -f ./*~ $(INCLUDE)/*~ $(SRC)/*~ $(SRC)/*.o $(TARGET) # $(OUT)/*.o $(OUT)/$(TARGET)

.PHONY: clean

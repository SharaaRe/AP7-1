CC=g++ -g
STD=-std=c++11 -Wall -pedantic -I$(INCLUDE_DIR)
CF=$(STD)
# BUILD_DIR=build
SRC = APHTTP/
TEMPLATE_DIR=.template

all: $(BUILD_DIR) APHTTP.o

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)template_parser.o: $(SRC)utils/template_parser.cpp $(INCLUDE_DIR)/template_parser.hpp $(SRC)utils/request.cpp $(INCLUDE_DIR)/request.hpp $(INCLUDE_DIR)/utilities.hpp $(SRC)utils/utilities.cpp
	$(CC) $(CF) -c $(SRC)utils/template_parser.cpp -o $(BUILD_DIR)template_parser.o

$(BUILD_DIR)response.o: $(SRC)utils/response.cpp $(INCLUDE_DIR)/response.hpp $(INCLUDE_DIR)/include.hpp
	$(CC) $(CF) -c $(SRC)utils/response.cpp -o $(BUILD_DIR)response.o

$(BUILD_DIR)request.o: $(SRC)utils/request.cpp $(INCLUDE_DIR)/request.hpp $(INCLUDE_DIR)/include.hpp $(INCLUDE_DIR)/utilities.hpp
	$(CC) $(CF) -c $(SRC)utils/request.cpp -o $(BUILD_DIR)request.o

$(BUILD_DIR)utilities.o: $(SRC)utils/utilities.cpp $(INCLUDE_DIR)/utilities.hpp
	$(CC) $(CF) -c $(SRC)utils/utilities.cpp -o $(BUILD_DIR)utilities.o

$(BUILD_DIR)server.o: $(SRC)server/server.cpp $(INCLUDE_DIR)/server.hpp $(INCLUDE_DIR)/route.hpp $(INCLUDE_DIR)/utilities.hpp $(INCLUDE_DIR)/response.hpp $(INCLUDE_DIR)/request.hpp $(INCLUDE_DIR)/include.hpp $(INCLUDE_DIR)/template_parser.hpp $(SRC)utils/template_parser.cpp
	$(CC) $(CF) -c $(SRC)server/server.cpp -o $(BUILD_DIR)server.o

$(BUILD_DIR)route.o: $(SRC)server/route.cpp $(INCLUDE_DIR)/route.hpp $(INCLUDE_DIR)/utilities.hpp $(INCLUDE_DIR)/response.hpp $(INCLUDE_DIR)/request.hpp $(INCLUDE_DIR)/include.hpp
	$(CC) $(CF) -c $(SRC)server/route.cpp -o $(BUILD_DIR)route.o



APHTTP.o:  $(BUILD_DIR)response.o $(BUILD_DIR)request.o $(BUILD_DIR)utilities.o $(BUILD_DIR)server.o $(BUILD_DIR)route.o $(BUILD_DIR)template_parser.o
	ld -r -o $(BUILD_DIR)APHTTP.o  $(BUILD_DIR)response.o $(BUILD_DIR)request.o $(BUILD_DIR)utilities.o $(BUILD_DIR)server.o $(BUILD_DIR)route.o $(BUILD_DIR)template_parser.o  

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null

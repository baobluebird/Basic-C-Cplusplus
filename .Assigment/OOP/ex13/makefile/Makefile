#name file execute
TARGET = employees_manager
#name compiler
CXX = g++
#compiler flag
CXXFLAGS = -Wall -std=c++17
#folder source file and header
SRC_DIR = src
INC_DIR = include
#list source file
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/employees.cpp $(SRC_DIR)/employees_manager.cpp $(SRC_DIR)/certificate.cpp $(SRC_DIR)/employees_manager_utils.cpp $(SRC_DIR)/experience.cpp $(SRC_DIR)/fresher.cpp $(SRC_DIR)/intern.cpp
#list object file
OBJ = $(SRC:.cpp=.o)
#Create executable file
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)
#Compile .cpp file to .o object file
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@
#Remove all object file
clean:
	rm -f $(OBJ) $(TARGET)
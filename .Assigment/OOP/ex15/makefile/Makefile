#name file execute
TARGET = university_manager
#name compiler
CXX = g++
#compiler flag
CXXFLAGS = -Wall -std=c++17
#folder source file and header
SRC_DIR = src
INC_DIR = include
#list source file
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/faculty.cpp $(SRC_DIR)/part_time_student.cpp $(SRC_DIR)/regular_student.cpp $(SRC_DIR)/student_university.cpp $(SRC_DIR)/study_result.cpp $(SRC_DIR)/university.cpp  
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
# Имя исполняемого файла
TARGET = game_of_life

# Компилятор и флаги
CXX = g++
CXXFLAGS = -O2 -Wall -std=c++11

# Исходные файлы
SRCS = Cell.cpp board.cpp game_of_life.cpp

# Объектные файлы (преобразуются из исходных файлов)
OBJS = $(SRCS:.cpp=.o)

# Правило по умолчанию
all: $(TARGET)

# Правило для создания исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Правило для компиляции исходных файлов в объектные
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для очистки сгенерированных файлов
clean:
	rm -f $(TARGET) $(OBJS)

# Правило для пересборки (вызов `make clean` и `make`)
rebuild: clean all

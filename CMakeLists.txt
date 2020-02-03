cmake_minimum_required(VERSION 3.16.3) # Проверка версии CMake.


project(life)

									# Если версия установленой программы
add_subdirectory(Game)									# старее указаной, произайдёт аварийный выход.

add_executable(life main.cpp)		# Создает исполняемый файл с именем main
									# из исходника main.cpp

target_link_libraries(life game)



cmake CMakeLists.txt
cmake --install .
cmake --build .
copy src\*.txt Debug\*.txt
cd Debug\
V1_0.exe
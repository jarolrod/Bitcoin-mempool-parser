cmake_minimum_required(VERSION 3.15)
project(JarolRodriguez_ChaincodeChallenge)

set(CMAKE_CXX_STANDARD 14)

add_executable(JarolRodriguez_ChaincodeChallenge
        main.cpp Transaction/Transaction.cpp
        Transaction/Transaction.h Helper/Common.h
        Parser/CSVReader/CSVReader.cpp
        Parser/CSVReader/CSVReader.h
        Assembler/Assembler.cpp
        Assembler/Assembler.h
        Assembler/PriorityQueue/PriorityQueue.cpp Assembler/PriorityQueue/PriorityQueue.h)
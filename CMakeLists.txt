cmake_minimum_required(VERSION 3.6)
project(adv_cpp_hs16)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        exercise1/HelloWorld.h
        exercise1/HelloWorld.cpp
        exercise2/fraction.cpp
        exercise2/fraction.h
        exercise2/fractionTestDriver.cpp
        exercise2/fractionTestDriver.h
        exercise2/interactiveFraction.cpp
        exercise2/interactiveFraction.h
        utils/inputUtils.cpp 
	    utils/inputUtils.h
        exercise3/pvector.cpp
        exercise3/pvectorRunner.cpp
        exercise5/RPN.cpp
        exercise5/RPNRunner.cpp
        exercise5/RPN.h
        exercise5/RPNRunner.h
        exercise6/templateRNP.cpp
        exercise6/templateRNP.h
        exercise3.1/pvector_traits.cpp
        exercise3.1/pvectorRunner_traits.cpp
        exercise3.1/persistence_traits.cpp
        exercise3.1/pset.cpp 
	    exercise3.1/psetRunner.cpp
		3.2_spell_checker/spellChecker.cc
		3.2_spell_checker/spellChecker.h
		3.4_connect4/playfield.h
		3.4_connect4/playfield.cpp
		3.4_connect4/connect4game.cpp
		3.4_connect4/connect4game.h
		tests/connect4tests.cpp 3.4_connect4/player.cpp)
add_executable(adv_cpp_hs16 ${SOURCE_FILES})
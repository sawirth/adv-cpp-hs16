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
        exercise2.5/pRNP.h
        exercise2.5/pvectorRNP.h
        exercise2.5/pRNPRunner.cpp
        exercise2.5/pRNPRunner.h
        utils/inputUtils.cpp
	 	utils/inputUtils.h
        exercise3/pvector.cpp
        exercise3/pvectorRunner.cpp
        exercise5/RPN.cpp
        exercise5/RPNRunner.cpp
        exercise5/RPN.h
        exercise5/RPNRunner.h
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
		tests/connect4tests.cpp
		3.4_connect4/player.cpp
        exercise6/templateRPN.h
        exercise3.1/persistence_traits.cpp
        exercise6/templateRPNRunner.cpp
		3.4_connect4/humanPlayer.cpp
		3.4_connect4/computerPlayer.cpp
        exercise6/templateRPNRunner.h
		exercise4.1/merger.h
		3.4_connect4/connect4Utils.cpp
		4.1_find_if/find_if_Benchmark.cpp
		4.1_find_if/find_if_Benchmark.h
        5.2_under_the_hood/normal.cpp
        exercise4.5/somefunction_t.cpp
        exercise2.2/inlineFunction.h 5.1_Emulating_pointers/dumb_pointer.cpp 5.1_Emulating_pointers/smart_pointer.cpp 6.4_RPN<complex>/templateRPNcomplex.h 6.4_RPN<complex>/templateRPNcomplexRunner.cpp 6.4_RPN<complex>/templateRPNcomplexRunner.h 5.1_Emulating_pointers/reference_counting.cpp 5.1_Emulating_pointers/emulatingPointersRunner.cpp 5.1_Emulating_pointers/emulatingPointersRunner.h 5.1_Emulating_pointers/tester.cpp 7.2_Stack_and_Inheritance/Stack.cpp)

add_executable(adv_cpp_hs16 ${SOURCE_FILES})
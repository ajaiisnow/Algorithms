# -*- Makefile -*-

CXX = g++
CXX_FLAGS = -g -Wall -std=c++2a -Werror

all: clean\
    longest_substring.app \
	heapsort.app qsort.app\
	longest_pal_substr.app\
	permutation.app\
	subset.app\
	long_cmn_seq.app\
	long_non_rep_substr.app\
	BinaryTreeReversal.app\
	MedianSortedArray.app

longest_substring.app:
	$(CXX) $(CXX_FLAGS) longest_substring.cpp -o longest_substring.app

heapsort.app:
	$(CXX) $(CXX_FLAGS) HeapSort.cpp -o heapsort.app

qsort.app:
	$(CXX) $(CXX_FLAGS) QSort.cpp -o qsort.app

longest_pal_substr.app:
	$(CXX) $(CXX_FLAGS) LongestPalSub.cpp -o longest_pal_substr.app

permutation.app:
	$(CXX) $(CXX_FLAGS) Permutation.cpp -o permutation.app

subset.app:
	$(CXX) $(CXX_FLAGS) SubSets.cpp -o subset.app

long_cmn_seq.app:
	$(CXX) $(CXX_FLAGS) LongestCommonSubsequence.cpp -o long_cmn_seq.app

long_non_rep_substr.app:
	$(CXX) $(CXX_FLAGS) LongestNonRepeatingSubString.cpp -o long_non_rep_substr.app

BinaryTreeReversal.app:
	$(CXX) $(CXX_FLAGS) BinaryTreeReveral.cpp BinaryTreeReveral.h -o BinaryTreeReversal.app

MedianSortedArray.app:
	$(CXX) $(CXX_FLAGS) MedianOfTwosortedArrays.cpp -o MedianSortedArray.app

clean:
	rm -vf *.o *.app
MergeOverlappingIntervals: MergeOverlappingIntervals.o
	g++ -g -o MergeOverlappingIntervals.exe MergeOverlappingIntervals.o -pthread    

MergeOverlappingIntervals.o: MergeOverlappingIntervals/MergeOverlappingIntervals.cpp
	g++ -g  -c -pthread MergeOverlappingIntervals/MergeOverlappingIntervals.cpp

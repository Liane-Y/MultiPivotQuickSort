NUM="100000"
echo $NUM
echo $NUM > datain.txt
g++ data.cpp ; ./a.out  < datain.txt > data.txt
g++ -O0 QuickSort.cpp ; ./a.out < data.txt
g++ -O0 2-pivot_QS.cpp ; ./a.out < data.txt

NUM="200000"
echo $NUM
echo $NUM > datain.txt
g++ data.cpp ; ./a.out  < datain.txt > data.txt
g++ -O0 QuickSort.cpp ; ./a.out < data.txt
g++ -O0 2-pivot_QS.cpp ; ./a.out < data.txt

NUM="500000"
echo $NUM
echo $NUM > datain.txt
g++ data.cpp ; ./a.out  < datain.txt > data.txt
g++ -O0 QuickSort.cpp ; ./a.out < data.txt
g++ -O0 2-pivot_QS.cpp ; ./a.out < data.txt

NUM="1000000"
echo $NUM
echo $NUM > datain.txt
g++ data.cpp ; ./a.out  < datain.txt > data.txt
g++ -O0 QuickSort.cpp ; ./a.out < data.txt
g++ -O0 2-pivot_QS.cpp ; ./a.out < data.txt

NUM="2000000"

echo $NUM
echo $NUM > datain.txt
g++ data.cpp ; ./a.out  < datain.txt > data.txt
g++ -O0 QuickSort.cpp ; ./a.out < data.txt
g++ -O0 2-pivot_QS.cpp ; ./a.out < data.txt


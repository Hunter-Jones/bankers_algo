# Bankers
Solves the producer Bankers algorithm in Linux using C++</br>

Bankers algorithm is used to detect safe states to avoid deadlock scenarios<br>

To run the program run `make` to run the makefile</br>

Which will run the code</br> 
```
g++ banker.cpp -o banker
./banker
```

Which will show results like
```
Safe sequence: p1 p3 p4 p0 p2 
```

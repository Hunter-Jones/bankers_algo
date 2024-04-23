banker: banker.cpp
	g++ banker.cpp -o banker

run: banker
	./banker

clean:
	rm -f banker
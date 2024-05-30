image_gen:
	rm -rf image.ppm main.o
	touch image.ppm
	g++ ray-tracing-main.cpp -o main.o
	./main.o > image.ppm
	code image.ppm
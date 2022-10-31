default:
	@gcc pi.c -o pi
test:
	@mkdir -p tests
	@`pwd`/./pi 10000 > `pwd`/tests/10000.log
	@`pwd`/./pi 20000 > `pwd`/tests/20000.log
clean:
	@rm -f pi
	@rm -f *.out

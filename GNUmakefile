default:
	@gcc pi.c -o pi
test: default
	@mkdir -p tests
	@`pwd`/./pi 1     > `pwd`/tests/1.log
	@`pwd`/./pi 10    > `pwd`/tests/10.log
	@`pwd`/./pi 100   > `pwd`/tests/100.log
	@`pwd`/./pi 1000  > `pwd`/tests/1000.log
	@`pwd`/./pi 10000 > `pwd`/tests/10000.log
	@`pwd`/./pi 20000 > `pwd`/tests/20000.log
clean:
	@rm -f pi
	@rm -f *.out

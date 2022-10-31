default:
	@gcc pi.c -o pi
test: default tests
tests:
	@mkdir -p logs
	@`pwd`/./pi 1      > `pwd`/logs/1.log
	@`pwd`/./pi 10     > `pwd`/logs/10.log
	@`pwd`/./pi 100    > `pwd`/logs/100.log
	@`pwd`/./pi 1000   > `pwd`/logs/1000.log
	@`pwd`/./pi 10000  > `pwd`/logs/10000.log
	@`pwd`/./pi 20000  > `pwd`/logs/20000.log
	#@`pwd`/./pi 100000 > `pwd`/logs/100000.log
	@git diff
clean:
	@rm -f pi
	@rm -f *.out

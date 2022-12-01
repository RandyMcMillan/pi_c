default:
	$(MAKE) clean
	@gcc pi.c -o pi
test: default tests
tests: pi
	@mkdir -p logs
	@`pwd`/./pi 1      > `pwd`/logs/1.log
	@`pwd`/./pi 5      > `pwd`/logs/5.log
	@`pwd`/./pi 9      > `pwd`/logs/9.log
	@`pwd`/./pi 17     > `pwd`/logs/17.log
	@`pwd`/./pi 21     > `pwd`/logs/21.log
	@`pwd`/./pi 25     > `pwd`/logs/25.log
	@`pwd`/./pi 29     > `pwd`/logs/29.log
	@`pwd`/./pi 33     > `pwd`/logs/33.log
	@`pwd`/./pi 37     > `pwd`/logs/37.log
	@`pwd`/./pi 41     > `pwd`/logs/41.log
	@`pwd`/./pi 45     > `pwd`/logs/45.log
	@`pwd`/./pi 100    > `pwd`/logs/100.log
	@`pwd`/./pi 1000   > `pwd`/logs/1000.log
	@`pwd`/./pi 10000  > `pwd`/logs/10000.log
	@`pwd`/./pi 20000  > `pwd`/logs/20000.log
# 	@git diff
time:
	@mkdir -p logs
	@time `pwd`/./pi 100000 > `pwd`/logs/100000.log
	@git diff
clean:
	@rm -f pi
	@rm -f *.out

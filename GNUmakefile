default:
	$(MAKE) clean
	@gcc pi.c -o pi
test: default tests
.PHONY:tests
tests: pi
	@mkdir -p logs
	@`pwd`/./pi        > `pwd`/logs/pi.log
	@`pwd`/./pi 1      > `pwd`/logs/1.log
	@`pwd`/./pi 5      > `pwd`/logs/5.log
	@`pwd`/./pi 9      > `pwd`/logs/9.log
	@`pwd`/./pi 13     > `pwd`/logs/13.log
	@`pwd`/./pi 17     > `pwd`/logs/17.log
	@`pwd`/./pi 21     > `pwd`/logs/21.log
	@`pwd`/./pi 25     > `pwd`/logs/25.log
	@`pwd`/./pi 29     > `pwd`/logs/29.log
	@`pwd`/./pi 33     > `pwd`/logs/33.log
	@`pwd`/./pi 37     > `pwd`/logs/37.log
	@`pwd`/./pi 41     > `pwd`/logs/41.log
	@`pwd`/./pi 45     > `pwd`/logs/45.log
	@`pwd`/./pi 49     > `pwd`/logs/49.log
	@`pwd`/./pi 53     > `pwd`/logs/53.log
	@`pwd`/./pi 57     > `pwd`/logs/57.log
	@`pwd`/./pi 61     > `pwd`/logs/61.log
	@`pwd`/./pi 65     > `pwd`/logs/65.log
	@`pwd`/./pi 69     > `pwd`/logs/69.log
	@`pwd`/./pi 73     > `pwd`/logs/73.log
	@`pwd`/./pi 77     > `pwd`/logs/77.log
	@`pwd`/./pi 81     > `pwd`/logs/81.log
	@`pwd`/./pi 85     > `pwd`/logs/85.log
	@`pwd`/./pi 89     > `pwd`/logs/89.log
	@`pwd`/./pi 93     > `pwd`/logs/93.log
	@`pwd`/./pi 97     > `pwd`/logs/97.log
	@`pwd`/./pi 101    > `pwd`/logs/101.log
	@`pwd`/./pi 1001   > `pwd`/logs/1001.log
	@`pwd`/./pi 10001  > `pwd`/logs/10001.log
	@git diff
clean:
	@rm -f pi
	@rm -f *.out

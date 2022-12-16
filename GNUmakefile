SHELL									:= /bin/bash

PWD										?= pwd_unknown

THIS_DIR=$(dir $(abspath $(firstword $(MAKEFILE_LIST))))
export THIS_DIR

TIME									:= $(shell date +%s)
export TIME

ifeq ($(project),)
PROJECT_NAME							:= $(notdir $(PWD))
else
PROJECT_NAME							:= $(project)
endif
export PROJECT_NAME

GIT_USER_NAME							:= $(shell git config user.name)
export GIT_USER_NAME
GIT_USER_EMAIL							:= $(shell git config user.email)
export GIT_USER_EMAIL
GIT_SERVER								:= https://github.com
export GIT_SERVER
GIT_PROFILE								:= $(shell git config user.name)
export GIT_PROFILE
GIT_BRANCH								:= $(shell git rev-parse --abbrev-ref HEAD)
export GIT_BRANCH
GIT_HASH								:= $(shell git rev-parse --short HEAD)
export GIT_HASH
GIT_PREVIOUS_HASH						:= $(shell git rev-parse --short HEAD^1)
export GIT_PREVIOUS_HASH
GIT_REPO_ORIGIN							:= $(shell git remote get-url origin)
export GIT_REPO_ORIGIN
GIT_REPO_NAME							:= $(PROJECT_NAME)
export GIT_REPO_NAME
GIT_REPO_PATH							:= $(HOME)/$(GIT_REPO_NAME)
export GIT_REPO_PATH
##command		description
-:help
	@git submodule update --init --recursive
help:## help
	@sed -n 's/^##//p' ${MAKEFILE_LIST} | column -t -s ':' |  sed -e 's/^##/ /'
	@echo
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "\033[36m%-15s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)
all: pi depends## all pi depends
.PHONY:pi
pi:type## pi type
	$(MAKE) clean
	@gcc pi.c -o pi
depends: gmp mpfr## depends
.PHONY:gmp-chudnovsky.c
gmp-chudnovsky.c:## gmp-chudnovsky
	@cc $@
.PHONY:gmp
gmp:## gmp
	@pushd gmp && ./autogen.sh && ./configure --prefix=$(PWD) && popd
	$(MAKE) install-recursive -C gmp
.PHONY:mpfr
mpfr:## mpfr
	@pushd mpfr && ./autogen.sh && ./configure --prefix=$(PWD) && popd
	$(MAKE) install-recursive -C mpfr
.PHONY:type
type:## type
	@gcc type.c -o type
.PHONY:test
test: -## test -
	@`pwd`/./pi 1000 10000 > `pwd`/logs/1000.10000.log
.PHONY:tests
tests: pi## tests pi
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
#	@git diff
.PHONY:tests-100000
tests-100000: pi ## tests-100000
	@`pwd`/./pi 100000  > `pwd`/logs/100000.log
	@`pwd`/./pi 100000  > `pwd`/logs/10000X.log
.PHONY:tests-100001
tests-100001: pi ## tests-100001
	@`pwd`/./pi 100000  > `pwd`/logs/100001.log
	@`pwd`/./pi 100001  > `pwd`/logs/10000X.log
.PHONY:tests-10000X
tests-10000X: pi ## tests-10000X
	@time $(MAKE) tests-100000
	@time $(MAKE) tests-100001

-include Makefile

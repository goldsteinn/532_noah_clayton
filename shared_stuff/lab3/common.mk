SHELL=/bin/bash

BASE_DIR=${CURDIR}
CONFIG_DIR=$(BASE_DIR)/config
INCLUDE_DIR=$(BASE_DIR)/lib/include/
COMPILE_CONF_FILE=$(BASE_DIR)/config/compile-config.h

LIBEVENT_INCLUDE_DIR=$(BASE_DIR)/libevent_include/include/
LIBEVENT_LD_DIR=$(BASE_DIR)/libevent_include/lib/

OBJ_DIR=$(BASE_DIR)/.obj
BIN_DIR=${CURDIR}/bin

#set debug mode, all the options because typing "DEBUG_MODE" or
#"DEBUG" might be cumbersome ...
D=0
DEBUG=0
DEBUG_MODE=0
ifneq ($(D), 0)
DEBUG=$(D)
endif
ifneq ($(DEBUG), 0)
DEBUG_MODE=$(DEBUG)
endif

W=0
WC=0
WITH_CONSTANTS=0
ifneq ($(W), 0)
WC=$(W)
endif
ifneq ($(WC), 0)
WITH_CONSTANTS=$(WC)
endif


#gcc for lyfe
CC=module load gcc-7.3.0; g++

#debug vs non debug flags
ifeq ($(DEBUG_MODE), 0)
CFLAGS=-O3 -std=c++11 -Wall -Wno-pointer-arith -Wno-unused-function -D_GNU_SOURCE -I$(CONFIG_DIR) -I$(INCLUDE_DIR) -I$(LIBEVENT_INCLUDE_DIR) 
else
CFLAGS=-O0 -std=c++11 -Wall -Wno-pointer-arith -Wno-unused-function -g3 -DDEBUG -D_GNU_SOURCE -I$(CONFIG_DIR) -I$(INCLUDE_DIR) -I$(LIBEVENT_INCLUDE_DIR) 
endif

#ldflags
LDFLAGS=-lpthread -lm -rdynamic -L$(LIBEVENT_LD_DIR) -levent -levent_pthreads -Wl,-R$(LIBEVENT_LD_DIR)

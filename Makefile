CONFIGDIR := $(shell pwd)/config
BUILDDIR  := $(shell pwd)/build
CONFIG    := AMD64
PERL      := /usr/bin/env perl

all: buildconfig boot_stub

boot_stub:
	cd sys/boot && $(MAKE)

buildconfig:
	@$(PERL) util/buildconfig $(CONFIGDIR)/$(CONFIG) > mk.config

distclean:
	-@$(RM) -v mk.config


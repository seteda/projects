########################################################################################
# MAKE FILE FOR QR APPLICATION CONFIG
########################################################################################
TOP = /home/thanhtung/workspace/qr_server
ERLANG_TOOL = /opt/OTP18
########################################################################################
# DON NOT FIX ME
########################################################################################
RM = rm -rf 
CP = cp
ERLC = $(ERLANG_TOOL)/bin/erlc
ERL = $(ERLANG_TOOL)/bin/erl
ERLCFLAGS = -Wall +debug_info -pa ebin
ERLANG_CFLAGS = -I$(ERLANG_TOOL)/lib/erlang/usr/include
EBIN = ebin
APP = ebin/qr_server.app
SRC = src

TARGETS_1 = $(ERL_SRC:%.erl=$(EBIN)/%.beam)

ERL_SRC = \
$(SRC)/qr_app.erl \
$(SRC)/qr_sup.erl \
$(SRC)/qr_worker.erl \
$(SRC)/qr_db.erl \
$(SRC)/qr_user.erl 

########################################################################################
# MAKE
########################################################################################
all: $(TARGETS_1) $(APP)
	@echo 'Building target: $@'
	@echo 'Finished building target: $@'
	@echo ' '

########################################################################################
# BUILDING .ERL TO .BEAM
########################################################################################
$(APP):	qr_server.app
	@echo 'Building target: $@'
	$(CP) qr_server.app $(APP)
	@echo 'Finished building target: $@'
	@echo ' '

$(EBIN)/%.beam: %.erl
	@echo 'Building target: $@'
	$(ERLC) $(ERLCFLAGS) -o $(EBIN) $<
	@echo 'Finished building target: $@'
	@echo ' '

run:
	$(ERL) -pa $(EBIN)

clean:
	@echo 'remove output file'
	$(RM) ebin/*.beam
	$(RM) ebin/*.app

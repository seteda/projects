########################################################################################
# MAKE FILE FOR QR APPLICATION CONFIG
########################################################################################
TOP = /home/thanhtung/workspace/qr_server
ERLANG_TOOL = /opt/tools/OTP17
########################################################################################
# DON NOT FIX ME
########################################################################################
RM = rm -rf 
CP = cp
ERLC = $(ERLANG_TOOL)/bin/erlc
ERL = $(ERLANG_TOOL)/bin/erl
ERLCFLAGS = -Wall +debug_info -pa $(TOP)/ebin
ERLANG_CFLAGS = -I$(ERLANG_TOOL)/lib/erlang/usr/include
BEAMDIR = $(TOP)/ebin
APP = $(BEAMDIR)/qr_server.app
SRC = $(TOP)/src

ERL_SRC = \
$(SRC)/qr_app.erl \
$(SRC)/qr_sup.erl \
$(SRC)/qr_worker.erl \
$(SRC)/qr_db.erl \
$(SRC)/qr_user.erl 


ERL_BEAMS = \
$(BEAMDIR)/qr_app.beam \
$(BEAMDIR)/qr_sup.beam \
$(BEAMDIR)/qr_worker.beam \
$(BEAMDIR)/qr_db.beam \
$(BEAMDIR)/qr_user.beam 

########################################################################################
# MAKE
########################################################################################
all: $(ERL_BEAMS) $(APP)
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

$(BEAMDIR)/%.beam: $(SRC)/%.erl
	@echo 'Building target: $@'
	$(ERLC) $(ERLCFLAGS) -o $(BEAMDIR) $<
	@echo 'Finished building target: $@'
	@echo ' '

run:
	$(ERL) $(BEAMDIR)

clean:
	@echo 'remove output file'
	$(RM) $(BEAMDIR)/*.beam
	$(RM) $(BEAMDIR)/*.app
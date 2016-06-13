%% @author thanhtung
%% @doc @todo Add description to qr.hrl.

-ifndef(qr).
-define(qr,true).

-define(DEBUG(Format),io:format(Format)).
-define(DEBUG(Format,Args),io:format(Format,Args)).

-define(QR_VERSION,qr_version_tab).
-record(qr_ver,{
	id		= 0				::	non_neg_integer(),	%% id of data
	version	= 0				::	non_neg_integer(),	%% version of qr code generated
	level	= 0				::	non_neg_integer(),	%% level of qr code generated
	numeric_Mode = 0		::	non_neg_integer(),	%% number byte in numberic_mode
	alphanumeric_Mode = 0	::	non_neg_integer(),	%% number byte in alphanumeric_Mode
	byte_Mode	= 0			::	non_neg_integer(),	%% number byte in byte_Mode
	kanji_Mode = 0			::	non_neg_integer()	%% number byte in kanji_Mode
}).

-define(QR_PROCESS,qr_process_tab).
-record(qr_process_tab,{
	id = 0					:: non_neg_integer(),	%% id of data
	pid						:: pid()				%% pid of process
}).

-endif.
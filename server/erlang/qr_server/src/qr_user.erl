%% @author thanhtung
%% @doc @todo Add description to user.


-module(qr_user).
-include("../include/qr.hrl").

%% ====================================================================
%% API functions
%% ====================================================================
-export([
		 get_version/2
		 ]).



%% ====================================================================
%% Internal functions
%% ====================================================================
get_version(Version,Level) ->
	case gen_server:call(qr_worker,{get_version,Version,Level}) of
		received_ok ->
			?DEBUG("Received Reply ok~n"),
			ok;
		_ ->
			?DEBUG("Received Reply FALSE~n"),
			false
	end.


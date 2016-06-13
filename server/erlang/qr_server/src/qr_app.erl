%% @author thanhtung
%% @doc @todo Add description to qr_app.


-module(qr_app).
-behaviour(application).
-export([
		 start/0,
		 start/2, 
		 stop/1]).

%% ====================================================================
%% API functions
%% ====================================================================
-export([]).


-include("../include/qr.hrl").
%% ====================================================================
%% Behavioural functions
%% ====================================================================

%% start/2
%% ====================================================================
%% @doc <a href="http://www.erlang.org/doc/apps/kernel/application.html#Module:start-2">application:start/2</a>
-spec start(Type :: normal | {takeover, Node} | {failover, Node}, Args :: term()) ->
	{ok, Pid :: pid()}
	| {ok, Pid :: pid(), State :: term()}
	| {error, Reason :: term()}.
%% ====================================================================
start() ->
	application:start(qr_server).

start(Type, StartArgs) ->
    case qr_sup:start_link(StartArgs) of
		{ok, Pid} ->
			?DEBUG("QR application started~n"),
			?DEBUG("init ets process table~n"),
			ets:new(?QR_PROCESS,[named_table,public,{write_concurrency,true},{read_concurrency,true}]),
			qr_sup:add_worker(),
			{ok, Pid};
		Error ->
			?DEBUG("QR application ERROR STARTING~n"),
			Error
    end.

%% stop/1
%% ====================================================================
%% @doc <a href="http://www.erlang.org/doc/apps/kernel/application.html#Module:stop-1">application:stop/1</a>
-spec stop(State :: term()) ->  Any :: term().
%% ====================================================================
stop(State) ->
	init:stop(1).

%% ====================================================================
%% Internal functions
%% ====================================================================



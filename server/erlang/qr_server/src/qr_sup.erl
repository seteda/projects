%% @author thanhtung
%% @doc @todo Add description to qr_sub.


-module(qr_sup).
-behaviour(supervisor).
-export([init/1]).

-include("../include/qr.hrl").
%% ====================================================================
%% API functions
%% ====================================================================
-export([init/1]).

-export([
		 start_link/1,
		 add_worker/0
		]).

start_link(_arg) ->
	supervisor:start_link({local, ?MODULE}, ?MODULE, []).
%% ====================================================================
%% Behavioural functions
%% ====================================================================

%% init/1
%% ====================================================================
%% @doc <a href="http://www.erlang.org/doc/man/supervisor.html#Module:init-1">supervisor:init/1</a>
-spec init(Args :: term()) -> Result when
	Result :: {ok, {SupervisionPolicy, [ChildSpec]}} | ignore,
	SupervisionPolicy :: {RestartStrategy, MaxR :: non_neg_integer(), MaxT :: pos_integer()},
	RestartStrategy :: one_for_all
					 | one_for_one
					 | rest_for_one
					 | simple_one_for_one,
	ChildSpec :: {Id :: term(), StartFunc, RestartPolicy, Type :: worker | supervisor, Modules},
	StartFunc :: {M :: module(), F :: atom(), A :: [term()] | undefined},
	RestartPolicy :: permanent
				   | transient
				   | temporary,
	Modules :: [module()] | dynamic.
%% ====================================================================
init(_Arg) ->
	{ok,{{one_for_one,0,1}, []}}.

add_worker() ->
	Arg = data_in_here_for_init,
	Spec = {qr_worker,						%% child_id
			{qr_worker, start_link,[Arg]}, 	%% start
			permanent, 						%% restart:child process is always restarted
			3000, 							%% shutdown with time out
			worker, 						%% type 
			[qr_worker] 					%% module
			},
	supervisor:start_child(?MODULE,Spec).

%% ====================================================================
%% Internal functions
%% ====================================================================



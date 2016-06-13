1. About project
name app:	qr_server
version: 	1.0
otp_ver:	OTP 17.4.0
base on:	kernel and stdlib

2. Desciption:
qr_server.app:	description about application
qr_app:			start application from here
qr_sub:			manage child process (start/add/delete,...)
qr_db:			define recode and macro here
qr_worker:		main work as server
qr_user:		main work as client

3. Run for test:
# this test is request get_version from client (qr_user) and receive respond from server with message:received_ok
cd main directory as worksapce/qr_server
make
cd ebin/
erl
qr_app:start().
qr_user:get_version(14,1).
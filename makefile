all:
	gcc -g3 -o F1AP_Server F1AP_Server.c -L. libF1AP_18_4.so libsicore.so -I./ -lpthread -lsctp -Wl,-rpath .
	gcc -g3 -o F1AP_Client F1AP_Client.c F1AP_test.c -L. libF1AP_18_4.so libsicore.so -I./ -lpthread -lsctp -Wl,-rpath .

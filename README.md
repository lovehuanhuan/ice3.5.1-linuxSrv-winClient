windos端引入include lib和bin（目标文件）



# ice3.5.1-linuxSrv-winClient
$ g++ -I. -o server demo.cpp server.cpp -lIce -lIceUtil -lpthread
$ g++ -I. -o client demo.cpp client.cpp -lIce -lIceUtil -lpthread
$ ./server

$./client
Hello World!

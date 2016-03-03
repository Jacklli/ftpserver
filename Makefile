ftpserver: fileoperator.o ftpserver.cpp serverconnection.o servercore.o
	g++ fileoperator.o ftpserver.cpp serverconnection.o servercore.o -o ftpserver
fileoperator.o: fileoperator.h fileoperator.cpp
serverconnection.o: serverconnection.h serverconnection.cpp
servercore.o: servercore.h servercore.cpp
clean:
	rm -rf *.o ftpserver

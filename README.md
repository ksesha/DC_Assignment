# DC__Assignment

Simple RPC program to demonstrate a dicitionary.

This RPC program supports 3 remote procedures:

	insertw : inserts a word and it's meaning into the ditionary.
	lookupw : returns the meaning for a given word if found in the dictionary.
	deletew : Removes a word from the dicitonary if present.


FILES:
-----

rdict.h:            Header file for the RPC program, this file was created by rpcgen.

rdict_clnt.c:       the client stubs, this file was created by rpcgen.

rdict_client.c:     the main client program. I had to write this (although
			        running "rpcgen -C -Sc" creates a template for this code). 
			        This client just calls each of the remote procedures once and
			        prints out the results. Remember that when calling the client
			        stubs, you must pass pointers and the return value is a pointer.
			        When in doubt - look at the client stubs and see what they expect!

rdict.x:            this is the RPC protocol definition file. Although it looks like
			        'C', it is not! This file is run through the C preprocessor and
			        the result is processed by rpcgen. rpcgen will create a header
			        file named rdict.h containing data structure definitions and
			        function prototypes for the C code generated. The generated
			        C code is created in the files rdict_clnt.c (which contains the
			        client stubs) and rdict_svc.c (which contains the main program
			        for the server). rpcgen also creates any needed XDR filter functions
			        in the file rdict_xdr.c

rdict_svc.c:        the server main program, this was created by rpcgen.

rdict_server.c:     the actual remote procedures. I had to write these, 
			        although "rpcgen -C -Ss" is a great start. The important thing
			        here is to make sure the functions your create expect the
			        right kind of parameters and return the right thing. With RPC,
			        everything has to be a pointer - the procedure argument is 
			        a pointer to the type your declared in the .x file, and the 
			        return value is a pointer to the return type you declare in
			        the .x file.

rdict_xdr.c:        the XDR filter(s) needed for this application, this file
                    was created by rpcgen.

Makefile:           This has two targets:

			The below target will compile the client and server that are needed namely, rdict_client and rdict_server

				make all

			The below target cleans up the *.o files, core if any and rdict_client and rdict_server.

				make clean					




-----------------------------------------------------------------------------------------
Execution
-----------------------------------------------------------------------------------------

Once you have generated the binaries with make(make all), you should trigger:


	./rdict_server

	OR

	./rdict_server &	(If you wish to invoke the client in the same putty, terminal)

Post this, invoke the client as follows:


	./rdict_client          ( In the same terminal, if the rdict_server binary is put into 
				  the backgroud(& as the end), or open a fresh terminal; besides 
                                  the server rdict_server and invoke rdict_client)


--------------------------------------------------------------------------------------------
Environment Tested
--------------------------------------------------------------------------------------------
Linux centos.server.com 3.10.0-123.13.2.el7.x86_64 #1 SMP Thu Dec 18 14:09:13 UTC 2014 x86_64 x86_64 x86_64 GNU/Linux



--------------------------------------------------------------------------------------------
Sample Output
--------------------------------------------------------------------------------------------

[cent@centos assignment]$ ./rdict_server &

[1] 12614

[cent@centos assignment]$ ./rdict_client 


/*------------------------------------------------------------------------
* Welcome to the dictionary simulation
* Enter 'i' to insert a word and its meaning
* Enter 'l' to lookup for the meaning of the given word
* Enter 'r' to remove the word from the dictionary
* Enter 'q' to quit
* Note: Words and meaning cannot exceed 50 words
/*------------------------------------------------------------------------

Option:i

Enter the word:Apple

Enter the meaning:This is a fruit

Apple inserted.


/*------------------------------------------------------------------------
* Welcome to the dictionary simulation
* Enter 'i' to insert a word and its meaning
* Enter 'l' to lookup for the meaning of the given word
* Enter 'r' to remove the word from the dictionary
* Enter 'q' to quit
* Note: Words and meaning cannot exceed 50 words
/*------------------------------------------------------------------------

Option:i

Enter the word:Carrot

Enter the meaning:This is a veggie

Carrot inserted.


/*------------------------------------------------------------------------
* Welcome to the dictionary simulation
* Enter 'i' to insert a word and its meaning
* Enter 'l' to lookup for the meaning of the given word
* Enter 'r' to remove the word from the dictionary
* Enter 'q' to quit
* Note: Words and meaning cannot exceed 50 words
/*------------------------------------------------------------------------

Option:l

Enter the word:Carrot

Meaning: This is a veggie


/*------------------------------------------------------------------------
* Welcome to the dictionary simulation
* Enter 'i' to insert a word and its meaning
* Enter 'l' to lookup for the meaning of the given word
* Enter 'r' to remove the word from the dictionary
* Enter 'q' to quit
* Note: Words and meaning cannot exceed 50 words
/*------------------------------------------------------------------------

Option:l

Enter the word:Roy

Roy was not found.



/*------------------------------------------------------------------------
* Welcome to the dictionary simulation
* Enter 'i' to insert a word and its meaning
* Enter 'l' to lookup for the meaning of the given word
* Enter 'r' to remove the word from the dictionary
* Enter 'q' to quit
* Note: Words and meaning cannot exceed 50 words
/*------------------------------------------------------------------------

Option:r

Enter the word:Apple

Apple deleted.


/*------------------------------------------------------------------------
* Welcome to the dictionary simulation
* Enter 'i' to insert a word and its meaning
* Enter 'l' to lookup for the meaning of the given word
* Enter 'r' to remove the word from the dictionary
* Enter 'q' to quit
* Note: Words and meaning cannot exceed 50 words
/*------------------------------------------------------------------------

Option:l

Enter the word:Apple

Apple was not found.


/*------------------------------------------------------------------------
* Welcome to the dictionary simulation
* Enter 'i' to insert a word and its meaning
* Enter 'l' to lookup for the meaning of the given word
* Enter 'r' to remove the word from the dictionary
* Enter 'q' to quit
* Note: Words and meaning cannot exceed 50 words
/*------------------------------------------------------------------------

Option:q

program quits.



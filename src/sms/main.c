/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10.08.2016 17:38:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <fos/dbg.h>
#include <stdlib.h>
#include	<stdio.h>
#include	<fos/ringbuffer.h>
#include <fos/config.h>
#include	<fos/print.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netdb.h>
#include	<unistd.h>
#include	<fcntl.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */


int test_check_debug();
void test_debug();
void test_log_err();
void test_log_info();
int test_check(char *file_name);
int test_sentinel(int code);
int test_check_mem();
int test_check_debug();
void test_log_warn();
int client_connect(char *host, char *port);
int nonblock(int fd);

struct tagbstring NL = bsStatic("\n");
struct tagbstring CRLF = bsStatic("\r\n");

int main(int argc, char *argv[])
{
        fd_set allreads;
        fd_set readmask;
        int socket = 0;
        int rc = 0;
        RingBuffer *in_rb = RingBuffer_create(1024 * 10);
        RingBuffer *sock_rb = RingBuffer_create(1024 * 10);
        check(argc == 3, "USAGE: c-project host port");
        socket = client_connect(argv[1],argv[2]);
        check(socket >= 0, "connect to %s:%s failed.",argv[1],argv[2] );
        FD_ZERO(&allreads);
        FD_SET(socket,&allreads);
        FD_SET(0,&allreads);
        while(1) {
                readmask = allreads;
                rc = select(socket + 1, &readmask, NULL, NULL, NULL);
                check(rc >= 0, "select failed.");

                if(FD_ISSET(0, &readmask)) {
                        rc = read_some(in_rb, 0, 0);
                        check_debug(rc != -1, "Failed to read from stdin.");
                }

                if(FD_ISSET(socket, &readmask)) {
                        rc = read_some(sock_rb, socket, 0);
                        check_debug(rc != -1, "Failed to read from socket.");
                }

                while(!RingBuffer_empty(sock_rb)) {
                        rc = write_some(sock_rb, 1, 0);
                        check_debug(rc != -1, "Failed to write to stdout.");
                }

                while(!RingBuffer_empty(in_rb)) {
                        rc = write_some(in_rb, socket, 1);
                        check_debug(rc != -1, "Failed to write to socket.");
                }
        }
        return EXIT_SUCCESS;

error:
        return 1;
}                               /* ----------  end of function main  ---------- */
int client_connect(char *host, char *port)
{
        int rc = 0;
        struct addrinfo *addr = NULL;

        rc = getaddrinfo(host, port, NULL, &addr);
        check(rc == 0, "Failed to lookup %s:%s", host, port);

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        check(sock >= 0, "Cannot create a socket.");

        rc = connect(sock, addr->ai_addr, addr->ai_addrlen);
        check(rc == 0, "Connect failed.");

        rc = nonblock(sock);
        check(rc == 0, "Can't set nonblocking.");

        freeaddrinfo(addr);
        return sock;

error:
        freeaddrinfo(addr);
        return -1;
}

int nonblock(int fd) 
{
        int flags = fcntl(fd, F_GETFL, 0);
        check(flags >= 0, "Invalid flags on nonblock.");

        int rc = fcntl(fd, F_SETFL, flags | O_NONBLOCK);
        check(rc == 0, "Can't set nonblocking.");

        return 0;
error:
        return -1;
}

int read_some(RingBuffer *buffer, int fd, int is_socket)
{
        int rc = 0;

        if(RingBuffer_available_data(buffer) == 0) {
                buffer->start = buffer->end = 0;
        }

        if(is_socket) {
                rc = recv(fd, RingBuffer_starts_at(buffer), RingBuffer_available_space(buffer), 0);
        } else {
                rc = read(fd, RingBuffer_starts_at(buffer), RingBuffer_available_space(buffer));
        }

        check(rc >= 0, "Failed to read from fd: %d", fd);

        RingBuffer_commit_write(buffer, rc);

        return rc;

error:
        return -1;
}


int write_some(RingBuffer *buffer, int fd, int is_socket)
{
        int rc = 0;
        bstring data = RingBuffer_get_all(buffer);

        check(data != NULL, "Failed to get from the buffer.");
        check(bfindreplace(data, &NL, &CRLF, 0) == BSTR_OK, "Failed to replace NL.");

        if(is_socket) {
                rc = send(fd, bdata(data), blength(data), 0);
        } else {
                rc = write(fd, bdata(data), blength(data));
        }

        check(rc == blength(data), "Failed to write everything to fd: %d.", fd);
        bdestroy(data);

        return rc;

error:
        return -1;
}

void test_debug()
{
        // notice you don't need the \n
        debug("I have Brown Hair.");

        // passing in arguments like printf
        debug("I am %d years old.", 37);
}


void test_log_err()
{
        log_err("I believe everything is broken.");
        log_err("There are %d problems in %s.", 0, "space");
}

void test_log_warn()
{
        log_warn("You can safely ignore this.");
        log_warn("Maybe consider looking at: %s.", "/etc/passwd");
}

void test_log_info()
{
        log_info("Well I did something mundane.");
        log_info("It happened %f times today.", 1.3f);
}

int test_check(char *file_name)
{
        FILE *input = NULL;
        char *block = NULL;

        block = malloc(100);
        check_mem(block); // should work

        input = fopen(file_name,"r");
        check(input, "Failed to open %s.", file_name);

        free(block);
        fclose(input);
        return 0;

error:
        if(block) free(block);
        if(input) fclose(input);
        return -1;
}


int test_sentinel(int code)
{
        char *temp = malloc(100);
        check_mem(temp);

        switch(code) {
                case 1:
                        log_info("It worked.");
                        break;
                default:
                        sentinel("I shouldn't run.");
        }

        free(temp);
        return 0;

error:
        if(temp) free(temp);
        return -1;
}


int test_check_mem()
{
        char *test = NULL;
        check_mem(test);

        free(test);
        return 1;

error:
        return -1;
}

int test_check_debug()
{
        int i = 0;
        check_debug(i != 0, "Oops, I was 0.");

        return 0;
error:
        return -1;
}


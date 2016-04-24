CC		=	gcc
SRCSERVER	=	server.c
SRCCLIENT	=	client.c
NAMESERVER	=	serveur
NAMECLIENT	=	client
OBJSERVER	=	$(SRCSERVER:.c=.o)
OBJCLIENT	=	$(SRCCLIENT:.c=.o)
CFLAGS		+=	-I. -W -Wall -pedantic
LDFLAGS		+=	-L./ -lmy

all: $(NAMESERVER) $(NAMECLIENT)

$(NAMECLIENT): $(OBJCLIENT)
		$(CC) -o $(NAMECLIENT) $(OBJCLIENT) $(LDFLAGS)

$(NAMESERVER): $(OBJSERVER)
		$(CC) -o $(NAMESERVER) $(OBJSERVER) $(LDFLAGS)

clean:
	rm -f $(OBJCLIENT) $(OBJSERVER) *~

fclean: clean
	rm -f $(NAMESERVER) $(NAMECLIENT)

re: fclean all

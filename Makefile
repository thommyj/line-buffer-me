.PHONY: all
all: line-buffer-me.so

line-buffer-me.so: line-buffer-me.c
	$(CC) -Wall -Wextra -Os -fPIC -shared line-buffer-me.c -Wl,-soname,line-buffer-me.so -Wl,--hash-style=gnu -o line-buffer-me.so

install:
	install -d $(DESTDIR)
	install -m 0755 line-buffer-me.so $(DESTDIR)/

.PHONY: clean
clean:
	rm -f line-buffer-me.so ${OBJS} $(SRCS:.c=.d)


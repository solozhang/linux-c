#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<fcntl.h>
int main(void)
{
    char c;
//    char a = 'b';
//    c = &a;
    int len = 0;
    int ret;
    int fd;
    fd = open("txt", O_RDONLY| O_CREAT);
    if(ret < 0)
    {
        printf("open error\n");
        exit(0);
    }
    while(len < 4096)
    {
        ret = read(fd, &c, sizeof(char));
        printf("%c", c);
        if (ret < 0)
        {
            printf("read error\n");
            exit(1);
        }
        len++;
//        printf("%d\n",lseek(fd,0,1));
        if(len == 4096)
        {
            ret = lseek(fd, 0, 0);
            if (ret < 0)
            {
                printf("write error\n");
                exit(1);
            }
            len = 0;
        }
    }
    close(fd);
    return 0;
}

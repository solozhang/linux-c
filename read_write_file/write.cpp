#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<fcntl.h>
int main(void)
{
    char c = 'A';
//    char a = 'b';
//    c = &a;
    int len = 0;
    int ret;
    int fd;
    fd = open("txt", O_WRONLY| O_CREAT);
    if(ret < 0)
    {
        printf("open error\n");
        exit(0);
    }
    while(len < 4096)
    {
        ret = write(fd, &c, sizeof(char));
        if (ret < 0)
        {
            printf("write error\n");
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
            truncate("txt", 0);
            len = 0;
            c++;
        }
    }
    close(fd);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <regex.h>

int r(char *test_str,char *reg_str)
//test_str为测试字符，reg_str为正则表达式
{
    char ebuff[256];
    int ret;
    int cflags;
    regex_t reg;

    cflags = REG_EXTENDED | REG_ICASE | REG_NOSUB;

    ret = regcomp(&reg, reg_str, cflags);
    if (ret)
    {   
        regerror(ret, &reg, ebuff, 256);
        fprintf(stderr, "%s\n", ebuff);
        goto end;
    }   

    ret = regexec(&reg, test_str, 0, NULL, 0);
    if (ret)
    {
        regerror(ret, &reg, ebuff, 256);
        fprintf(stderr, "%s\n", ebuff);
        goto end;
    }   
        
    regerror(ret, &reg, ebuff, 256);
    fprintf(stderr, "result is:%s\n", ebuff);

	return 1;

end:
    regfree(&reg);
    return 0;
}
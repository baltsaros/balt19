int        ft_str_is_alpha(char *str)
{
    int        i;
    char  *tmp;
    
    tmp = str;

    i = 0;
    while (tmp[i] != '\0')
    {
        if ((tmp[i] < 'A') || (tmp[i] > 'z'))
        {
            return 0;
        }
        if ((tmp[i] <= 'Z' ) || (tmp[i] >= 'a'))
        {
            i++;
        }
        else
        {
            return (0);
        }
    }    
    return (1);
}

int        main()
{
    char    *str;

    str = "test";
    ft_str_is_alpha(str);
}
int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int int_in_range(int n, int min, int max) {
    if (n < min)
        return 0;
    if (n > max)
        return 0;
    return 1;
}

int ft_sqrt(int n) {
    if (n < 0)
        return -1;
    if (n == 0 || n == 1)
        return n;
    long x = n;
    long y = (x + 1) / 2;
    while (y < x) {
        x = y;
        y = (x + n / x) / 2;
    }
    return (int)x;
}
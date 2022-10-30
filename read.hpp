inline int read() {
    int ret = 0, fl = 0;
    char ch;
    if ((ch = getchar()) == '-') fl = 1;
    else if (ch >= '0' && ch <= '9') ret = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') ret = ret * 10 + (ch - '0');
    return fl ? -ret : ret;
}

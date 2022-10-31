int main()
{
    int a[10][10];
    int N, M;

    scanf("%d %d", &N, &M);
    
    int Ibeg = 0, Ifin = 0, Jbeg = 0, Jfin = 0;
    
    int k = 1;
    int i = 0;
    int j = 0;

    while (k <= N * M){
        a[i][j] = k;
        if (i == Ibeg && j < M - Jfin - 1)
            ++j;
        else if (j == M - Jfin - 1 && i < N - Ifin - 1)
            ++i;
        else if (i == N - Ifin - 1 && j > Jbeg)
            --j;
        else
            --i;

        if ((i == Ibeg + 1) && (j == Jbeg) && (Jbeg != M - Jfin - 1)){
            ++Ibeg;
            ++Ifin;
            ++Jbeg;
            ++Jfin;
        }
        ++k;
    }
    
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j)
            printf("%3d", a[i][j]);
        printf("\n");
    }

    return 0;
}

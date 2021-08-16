void fatorial(int num);
int main()
{
    int num;
    printf("Digite o numero para calcular o fatorial:");
    scanf("%d",&num);
    fatorial(num);
    getch();
    return 0;
}

void fatorial(int num)
{
    int calcFat = 1;
    if(num == 0)
    {
        calcFat = 1;
    }
    else
    {
        while(num > 0)
        {
            calcFat *= num;
            num--;
        }
    }
    printf("O fatorial e %d",calcFat);
}

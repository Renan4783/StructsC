#include <stdio.h>
#include <stdlib.h>

int menu (void);
int selecao (void);

typedef struct
{
    int cod;
    char nome[50];
    char sexo[1];
    float dtnasc;
    int grau;
    int escalao;
    int Q_idio;
    int prod;
    float salario;
} funcio;

int cadastro (funcio *cadfuncio, int *n);
int salvar (funcio *cadfuncio, int n);
int relatorio (funcio *cadfuncio, int n);

int main (void)
{
    printf("Bem vindo ao programa da empresa X\n");
    menu();
    selecao();
    main();
    return 0;
}

int menu (void)
{
    printf("\n");
    printf("Escolha uma das opcoes do programa:\n");
    printf("(C)adastro de funcionarios\n");
    printf("(R)elatorios de funcionarios\n");
    printf("(S)air do programa\n");
    printf("\n");
}

int selecao (void)
{
    int n;
    funcio *cadfuncio;
    char s;
    printf("Selecao: ");
    scanf("%s", &s);
    printf("Digite o numero de usuarios a serem cadastrados ou pesquisados: ");
    scanf("%d", &n);
    cadfuncio=malloc(n*sizeof(funcio));
    if ((s=='C') || s=='c')
    {
        cadastro(cadfuncio, n);
    }
    if ((s=='R') || s=='r')
    {
        relatorio(cadfuncio, n);
    }
    if ((s=='S') || s=='s')
    {
        exit(1);
    }
}

int cadastro (funcio *cadfuncio, int *n)
{
    FILE *arq;
    int i=0;
    if((arq=fopen("dados.txt","w"))==NULL)
    {
        printf("\nERRO: Nao foi possivel abrir o arquivo de dados\n");
        exit(1);
    }
    for (i=0; i<n; i++);
    {
        printf("\n");
        printf("Codigo do %do funcionario (Consulte antes para nao haver conflitos): ", i);
        scanf("%d%*c", &cadfuncio[i].cod);
        printf("\n");
        printf("Nome do funcionario: ");
        scanf("%49[^\n]%*c", cadfuncio[i].nome);
        printf("\n");
        printf("Data de nascimento (Use o formato aaaa.mm): ");
        scanf("%f", &cadfuncio[i].dtnasc);
        printf("\n");
        printf("Grau de escolaridade (1:Fundamental 2:Medio 3:Bacharel 4:Mestre 5:Doutor): ");
        scanf("%d%*c", &cadfuncio[i].grau);
        printf("\n");
        printf("Cargo de ocupacao (Escalao): ");
        scanf("%d%*c", &cadfuncio[i].escalao);
        printf("\n");
        printf("Quantidade de idiomas que domina (Numeral): ");
        scanf("%d%*c", &cadfuncio[i].Q_idio);
        printf("\n");
        printf("Produtividade do funcionario: ");
        scanf("%d%*c", &cadfuncio[i].prod);
        printf("\n");
        fwrite(&cadfuncio, sizeof(funcio), 1, arq);
        printf("----------------------------------------");
    }
}

int relatorio (funcio *cadfuncio)
{
    FILE *arq;
    int i, list;
    if((arq=fopen("dados.txt","r"))==NULL)
    {
        printf("\nERRO: Nao foi possivel abrir o arquivo de dados\n");
        exit(1);
    }
    for (i=0; i<n; i++)
    {
        list=fread(&cadfuncio, sizeof(funcio), 1, arq);
        if (list!=1)
        {
            if (feof(arq))
            {
                break;
            }
            printf("Erro na leitura de arquivo\n");
        }
        printf("TESTE\n");
        printf("Codigo:%d", cadfuncio[i].cod);
        printf("Nome:%d", cadfuncio[i].nome);
        printf("Escalao:%d", cadfuncio[i].escalao);
        printf("Grau:%d", cadfuncio[i].grau);
        printf("Sexo:%d", cadfuncio[i].sexo);
        printf("Q.Idiomas:%d", cadfuncio[i].Q_idio);
        printf("Produtividade:%d", cadfuncio[i].prod);
        printf("Data Nasc.:%d", cadfuncio[i].dtnasc);
        printf("\n");
    }
}

/*
int salvar (funcio *cadfuncio, int n)
{
    FILE *arq;
    int i, save;
    for (i=0; i<n; i++)
    {
        save=
        if (save!=1)
        {
            printf("Erro na escrita de arquivo\n");
        }
    }
    printf("\n");
    printf("Cadastro executado com sucesso!");
}
*/
